#include<iostream>

using namespace std;

int main()
{
	int a, b, d, sum, trans[100] = { 0 },i=99;
	cin >> a >> b >> d;
	sum = a + b;
	if (sum != 0)
	{
		while (sum != 0)
		{
			trans[i] = sum % d;
			sum /= d;
			i--;
		}
		for (i++; i <= 99; i++)
			cout << trans[i];
		cout << endl;
	}
	else
		cout << "0" << endl;
	return 0;
}