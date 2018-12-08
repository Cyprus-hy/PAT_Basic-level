#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n,p;
	vector<int> num;
	vector<long long int>max;
	int count = 1;
	cin >> n >> p;

	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		num.push_back(c);


		long long int res = (long long int)c*(long long int)p;
		max.push_back(res);
	}

	sort(num.begin(), num.end());//从小到大排序
	sort(max.begin(), max.end());

	//从前往后遍历，用每一个数做最小数，找到其最大数并记录此时完美数列长度，直到找到最大值
	for (int i = 0; i < n; i++)
	{
		long long int temp = max[i];
		//如果当前最小数能组成的完美数列的长度小于count就不用比较了
		if (i+count-1<n&&num[i + count - 1] <= temp)
		{
			//找到当前最小数对应的最大数
			for (int j = n - 1; j >= 0; j--)
			{
				if (temp >= num[j])
				{
					count = j - i + 1;
					break;
				}
			}
		}
		
	}

	cout << count << endl;
	return 0;
}