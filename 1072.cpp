#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n, m, things[6] = { 0 },count1=0,count2=0;//things记录要收缴的物品，count1为学生数，count2为物品数
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		cin >> things[i];

	for (int i = 0; i < n; i++)
	{
		string name;
		//count为该位学生被缴物品数，tem存放学生被缴纳的物品
		int count=0,k, tem[6] = { 0 };

		cin >> name >> k;
		for (int j = 0; j < k; j++)
		{
			int a;
			cin >> a;
			for (int x = 0; x < m; x++)//是否在缴纳物品的清单中
			{
				if (a == things[x])
				{
					count2++;//缴纳物品数加1
					tem[count] = a;
					count++;
					break;
				}
			}
		}

		if (count)
		{
			count1++;//存在问题学生数加1
			cout << name << ":";
			for (int j = 0; j < count; j++)//输出缴纳物品
				printf(" %04d",tem[j]);//注意输出格式
			cout << endl;
		}
	}

	cout << count1 << " " << count2 << endl;
	return 0;
}