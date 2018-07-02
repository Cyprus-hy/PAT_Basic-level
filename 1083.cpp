#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n, count[10001] = { 0 };
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		count[abs(a - i)]++;//记录差值的出现次数
	}

	for (int i = 10000; i >= 0; i--)
	{
		if(count[i]>=2)//要有重复则出现次数要大于等于2
			cout << i << " " << count[i] << endl;
	}
	return 0;
}