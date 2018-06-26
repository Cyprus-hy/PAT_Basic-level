#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n,count=0,a,b;
	cin >> n;
	vector<int> num;//输入的数据
	vector<int> res;//满足条件的数据
	vector<int> max;//从左往右，每一位左边数据的最大值
	vector<int>min;//从右往左，每一位数据右边的最小值

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d",&a);
		num.push_back(a);//vector存储所有数据
	}
	
	a = num[0];//最小值初始化
	b = num[n - 1];//最大值初始化
	max.push_back(0);//第一个数据左边最小值设为0
	min.push_back(1000000001);//最后一个数据右边最大值为无穷大

	for (int i = 0; i < n-1; i++)//寻找每一位左边最大值，注意到n-2结束，因为n-1不会是任何数的左边
	{
		if (num[i] > a)
			a = num[i];
		max.push_back(a);
	}

	for (int i = n - 1; i > 0; i--)//寻找每一位右边最小值，注意到1结束，因为0不会是任何数的右边
	{
		if (num[i] < b)
			b = num[i];
		min.push_back(b);
	}

	for (int i = 0; i < n; i++)
	{
		if (num[i] > max[i] && num[i] < min[n - 1 - i])//主元满足的条件，比左边最大值大，比右边最小值小
		{
			res.push_back(num[i]);
			count++;
		}
	}

	cout << count << endl;
	//sort(res.begin(), res.end());不用进行排序，实际上若满足主元的条件，其必然是递增的
	if (count)
	{
		for (int i = 0; i < count - 1; i++)
			printf("%d ", res[i]);
		cout << res[count - 1] << endl;
	}
	else//0个主元的时候单独考虑，需要输出一行空格
		cout << endl;

	return 0;
}