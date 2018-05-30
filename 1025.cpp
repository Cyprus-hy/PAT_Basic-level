#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

typedef struct Mystruct
{
	string address;//物理地址
	int data;//数据
	string next;//下一个元素的地址
	int pos;//位置，相当于数组下标，从1开始
}List;

bool cmp(List m, List n)//自定义比较函数
{
	return (m.pos > n.pos) ? true : false;
}

int main()
{
	int tem;
	vector<List> l, s;
	string first;
	int n, k,count=0;
	cin >> first >> n >> k;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		List t;
		cin >> t.address >> t.data >> t.next;
		t.pos = -1;//初始化
		if (t.address == first)//找到第一个链表节点
		{
			tem = i;//记录下第一个节点
		}
		l.push_back(t);
	}
	for(;l[tem].next!="-1";count++)
	{
		l[tem].pos = count;//下标，便于进行分割反转
		s.push_back(l[tem]);
		for (int j = 0; j < n; j++)
		{
			if (l[j].address == l[tem].next)//寻找下一个节点
			{
				tem = j;
				break;
			}
		}
	} 
	l[tem].pos = count;
	s.push_back(l[tem]);//加入最后一个节点
	a = (count+1) / k;
	b = (count + 1) % k;//最后的不需要进行反转
	for (int i = 0; i < a; i++)//再每k个进行反转，从大到小
		sort(s.begin()+i*k, s.begin() +(i+1)*k, cmp);
	if (n == count + 1)//不存在剩下的部分
	{
		for (int i = 0; i < count; i++)
			s[i].next = s[i + 1].address;//修改节点的指针域
		s[count].next = "-1";
	}
	else//存在剩下的部分
	{
		for (int i = 0; i < a*k; i++)
			s[i].next = s[i + 1].address;//修改节点的指针域
	}
	for (int i = 0; i <=count; i++)
		cout << s[i].address <<" "<< s[i].data << " " << s[i].next << endl;
	return 0;
}