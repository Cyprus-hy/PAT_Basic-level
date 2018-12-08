#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

//从大到小排列
bool cmp(int a, int b)
{
	return a > b ? true : false;
}

int main()
{
	int N;
	vector<int> num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		//存入数据
		int a;
		cin >> a;
		num.push_back(a);
	}

	//求得矩阵的行与列
	int root = sqrt(N);
	int m, n;
	//m,n差值最小时，它们肯定在平方根附近
	//注意应该先计算出n，再计算出m
	for (int i = root; i >= 1; i--)
	{
		if (N%i == 0)
		{
			n = i;
			break;
		}
	}
	m = N / n;

	sort(num.begin(), num.end(), cmp);//排序

	int sum = 0, count = 0, quan = 2 * m + 2 * n - 4;//矩阵第一圈有2 * m + 2 * n - 4个数字
	//记录矩阵一共有多少圈
	for (int i = 1; sum < N; i++)
	{
		sum += quan;
		quan -= 8;//更新每一圈的个数
		count = i;
	}

	//存储在一个二维的vector中
	vector<vector<int>>matrix(m, vector<int>(n));
	int pos = 0;
	for (int i = 0; i < count; i++)
	{
		//先向右遍历，注意一定要判断pos>N,因为N=3时就会有错误
		for (int j = i; j < n - i && pos < N; j++)
		{
			matrix[i][j] = num[pos];
			pos++;
		}

		//再向下遍历
		for (int j = i + 1; j < m - i && pos < N; j++)
		{
			matrix[j][n - 1 - i] = num[pos];
			pos++;
		}

		//再向左遍历
		for (int j = n - 2 - i; j >= i && pos < N; j--)
		{
			matrix[m - 1 - i][j] = num[pos];
			pos++;
		}

		//最后向上遍历
		for (int j = m - 2 - i; j > i&&pos < N; j--)
		{
			matrix[j][i] = num[pos];
			pos++;
		}
	}

	//输出
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		cout << matrix[i][n - 1] << endl;
	}
	return 0;
}