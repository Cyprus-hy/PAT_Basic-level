#include<iostream>

using namespace std;

int main()
{
	int n,sum=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		sum += a * 10 * (n - 1) + a * (n - 1);//����ÿһ�����֣�����ʮλ�ϳ��ֵĴ���Ϊn-1����λ�ϳ��ֵĴ���ҲΪn-1
	}
	cout << sum << endl;
	return 0;
}