#include<iostream>
#include<vector>

using namespace std;

typedef struct Mystruct
{
	int address;//��ַ
	int data;//����
	int next;//��һ��Ԫ��
}Node;

int main()
{
	int first, n, k;
	//������±��������ĵ�ַ���������Խ�ʡʱ�䣬���˳��洢���ñ���Ѱ����һ���ڵ�ᳬʱ
	Node N[100000];
	vector<Node>n1;//��ֵ
	vector<Node>n2;//0��k�Ľڵ�
	vector<Node>n3;//����k��
	Node tem;//��һ���ڵ�
	cin >> first >> n >> k;

	for (int i = 0; i < n; i++)
	{
		Node d;
		scanf("%d %d %d", &d.address,&d.data ,&d.next);
		N[d.address] = d;
	}

	tem = N[first];//��һ���ڵ�

	for (int i = 0; i < n; i++)//����
	{
		if (tem.data < 0)
			n1.push_back(tem);
		else if (tem.data >= 0 && tem.data <= k)
			n2.push_back(tem);
		else
			n3.push_back(tem);

		if (tem.next == -1)//һ��Ҫ�ж�һ�£���Ϊ���������еĲ���������
			break;

		tem = N[tem.next];
	}

	n1.insert(n1.end(), n2.begin(), n2.end());//����vector��ƴ��
	n1.insert(n1.end(), n3.begin(), n3.end());

	for(int i=0;i<n1.size()-1;i++)
		printf("%05d %d %05d\n", n1[i].address, n1[i].data,n1[i+1].address);//���������������һ���ڵ�ĵ�ַ
	printf("%05d %d -1\n", n1[n1.size() - 1].address, n1[n1.size() - 1].data);
	return 0;
}