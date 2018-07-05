#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(int a, int b)//从大到小的排序
{
	return a > b;
}

int main()
{
	int n,max=0,flag=0;
	vector<int> tem;//存放每天骑行的公里数
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d",&a);
		tem.push_back(a);
		//max是骑行公里数的最大值与天数两者的更小者，爱丁顿数必然小于等于max
		if (a > max)
			max = a;
	}
	max = (max > n) ? n : max;
	//公里数从大到小的排序
	sort(tem.begin(),tem.end(),cmp);
	//注意爱丁顿数不一定是某一个骑行公里数
	for (; max>0; max--)
	{
		for (int i = 0; i < n; i++)
		{
			if (tem[i] > max&&tem[i + 1] <= max)
			{
				//i+1是骑行公里数大于max的天数，注意天数大于等于max即可，不需要等于max
				if (i + 1 >= max)
					flag = 1;
				break;
			}
		}
		  
		if (flag)//已经找到艾丁顿数
			break;
	}

	cout << max << endl;
	return 0;
}