#include<iostream>
#include<map>
#include<vector>

using namespace std;

vector<vector<int>>things(100000);
map<int, vector<int>>BadThings;//与一个物品不兼容的可能有多个物品

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		things[a].push_back(b);
	}
	
	for (int i = 0;i<100000;i++)
		BadThings[i] = things[i];

	for (int i = 0; i < m; i++)
	{
		int k,flag = 1;
		cin >> k;
		int goods[100000] = { 0 };
		for (int j = 0; j < k; j++)
		{
			int a;
			cin >> a;
			goods[a] = 1;
		}

		for (int p = 0; p < 100000; p++)
		{
			if (goods[p])
			{
				for (int q = 0; q < BadThings[p].size(); q++)
				{
					if (goods[BadThings[p][q]])//与其不相容的物品出现在清单中
					{
						flag = 0;
						break;
					}
				}
			}

			if (!flag)
				break;
		}

		if (flag)
			cout << "Yes\n";
		else
			cout << "No\n";

	}

	return 0;
}