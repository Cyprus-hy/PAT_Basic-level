#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(int a, int b)//�Ӵ�С������
{
	return a > b;
}

int main()
{
	int n,max=0,flag=0;
	vector<int> tem;//���ÿ�����еĹ�����
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d",&a);
		tem.push_back(a);
		//max�����й����������ֵ���������ߵĸ�С�ߣ�����������ȻС�ڵ���max
		if (a > max)
			max = a;
	}
	max = (max > n) ? n : max;
	//�������Ӵ�С������
	sort(tem.begin(),tem.end(),cmp);
	//ע�Ⱞ��������һ����ĳһ�����й�����
	for (; max>0; max--)
	{
		for (int i = 0; i < n; i++)
		{
			if (tem[i] > max&&tem[i + 1] <= max)
			{
				//i+1�����й���������max��������ע���������ڵ���max���ɣ�����Ҫ����max
				if (i + 1 >= max)
					flag = 1;
				break;
			}
		}
		  
		if (flag)//�Ѿ��ҵ���������
			break;
	}

	cout << max << endl;
	return 0;
}