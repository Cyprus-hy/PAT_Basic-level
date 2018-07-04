#include<iostream>
#include<vector>

using namespace std;

typedef struct Mystruct
{
	int address;//地址
	int data;//数据
	int next;//下一个元素
}Node;

int main()
{
	int first, n, k;
	//数组的下标就是数组的地址，这样可以节省时间，如果顺序存储再用遍历寻找下一个节点会超时
	Node N[100000];
	vector<Node>n1;//负值
	vector<Node>n2;//0到k的节点
	vector<Node>n3;//大于k的
	Node tem;//第一个节点
	cin >> first >> n >> k;

	for (int i = 0; i < n; i++)
	{
		Node d;
		scanf("%d %d %d", &d.address,&d.data ,&d.next);
		N[d.address] = d;
	}

	tem = N[first];//第一个节点

	for (int i = 0; i < n; i++)//分类
	{
		if (tem.data < 0)
			n1.push_back(tem);
		else if (tem.data >= 0 && tem.data <= k)
			n2.push_back(tem);
		else
			n3.push_back(tem);

		if (tem.next == -1)//一定要判断一下，因为所给数据有的不在链表中
			break;

		tem = N[tem.next];
	}

	n1.insert(n1.end(), n2.begin(), n2.end());//三个vector的拼接
	n1.insert(n1.end(), n3.begin(), n3.end());

	for(int i=0;i<n1.size()-1;i++)
		printf("%05d %d %05d\n", n1[i].address, n1[i].data,n1[i+1].address);//第三个数据输出下一个节点的地址
	printf("%05d %d -1\n", n1[n1.size() - 1].address, n1[n1.size() - 1].data);
	return 0;
}