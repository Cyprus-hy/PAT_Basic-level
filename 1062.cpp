#include<iostream>
#include<vector>

using namespace std;

int gcd(int a, int b)//计算最大公约数
{
	return b == 0 ? a : gcd(b, a % b);
}


int main()
{
	double n1, m1, n2, m2;
	int k;
	scanf("%lf/%lf %lf/%lf", &n1, &m1, &n2, &m2);
	cin >> k;
	vector<int> tem;

	if (n1*m2 > n2*m1)//输入的数据可能是第一个大第二个小
	{
		swap(n1, n2);
		swap(m1, m2);
	}

	for (int i = 1; i < k; i++)
	{
		//利用乘法来判断大小，如果用除法的话精度可能不够
		if (n1*k<m1*i && n2*k>m2*i && gcd(i,k) == 1)//两个数互质等价于两个数最大公约数为1
			tem.push_back(i);
	}

	for (int i = 0; i < tem.size(); i++)
	{
		if (i)
			cout << " ";
		printf("%d/%d", tem[i], k);
	}
	return 0;
}