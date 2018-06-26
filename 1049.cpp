#include<iostream>

using namespace std;

int main()
{
	int n;
	double sum=0;
	cin >> n;
	for (int i = 0; i < n; i++)//找规律可以发现，从第0位到第n-1位，每一位出现的次数为(i+1)*(n-i),直接相乘求和就好
	{
		double a;
		cin >> a;
		sum += a * (i + 1)*(n - i);//在它前面它出现了i*(n-i)，它自己的时候又出现n-i次
	}
	printf("%.2f\n", sum);
	return 0;
}