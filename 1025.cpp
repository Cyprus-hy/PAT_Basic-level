#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

typedef struct Mystruct
{
	string address;//�����ַ
	int data;//����
	string next;//��һ��Ԫ�صĵ�ַ
	int pos;//λ�ã��൱�������±꣬��1��ʼ
}List;

bool cmp(List m, List n)//�Զ���ȽϺ���
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
		t.pos = -1;//��ʼ��
		if (t.address == first)//�ҵ���һ������ڵ�
		{
			tem = i;//��¼�µ�һ���ڵ�
		}
		l.push_back(t);
	}
	for(;l[tem].next!="-1";count++)
	{
		l[tem].pos = count;//�±꣬���ڽ��зָת
		s.push_back(l[tem]);
		for (int j = 0; j < n; j++)
		{
			if (l[j].address == l[tem].next)//Ѱ����һ���ڵ�
			{
				tem = j;
				break;
			}
		}
	} 
	l[tem].pos = count;
	s.push_back(l[tem]);//�������һ���ڵ�
	a = (count+1) / k;
	b = (count + 1) % k;//���Ĳ���Ҫ���з�ת
	for (int i = 0; i < a; i++)//��ÿk�����з�ת���Ӵ�С
		sort(s.begin()+i*k, s.begin() +(i+1)*k, cmp);
	if (n == count + 1)//������ʣ�µĲ���
	{
		for (int i = 0; i < count; i++)
			s[i].next = s[i + 1].address;//�޸Ľڵ��ָ����
		s[count].next = "-1";
	}
	else//����ʣ�µĲ���
	{
		for (int i = 0; i < a*k; i++)
			s[i].next = s[i + 1].address;//�޸Ľڵ��ָ����
	}
	for (int i = 0; i <=count; i++)
		cout << s[i].address <<" "<< s[i].data << " " << s[i].next << endl;
	return 0;
}