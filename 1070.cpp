#include<iostream>
#include<cmath>
#include<algorithm>
//要让绳子的长度最大，则应该让越长的绳子折叠次数越少，越短的绳子折叠次数越多
using namespace std;

int main()
{
	int n, res,num[10000] = { 0 };
	double sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);//将绳长从小到大排序

	/*最开始选两根最短的绳子，它们总共折叠n-1次，后面的绳子折叠次数
	在前一根的基础上减一，最长的绳子只需要折叠一次*/
	sum += num[0] * pow(0.5, n - 1);
	for (int i = 1; i < n; i++)
		sum += num[i] * pow(0.5, n - i);

	res = sum;//向下取整
	printf("%d\n", res);
	return 0;
}