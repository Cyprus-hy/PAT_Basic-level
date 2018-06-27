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
		sum += a * 10 * (n - 1) + a * (n - 1);//对于每一个数字，它在十位上出现的次数为n-1，个位上出现的次数也为n-1
	}
	cout << sum << endl;
	return 0;
}