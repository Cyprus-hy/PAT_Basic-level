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
		count[abs(a - i)]++;//��¼��ֵ�ĳ��ִ���
	}

	for (int i = 10000; i >= 0; i--)
	{
		if(count[i]>=2)//Ҫ���ظ�����ִ���Ҫ���ڵ���2
			cout << i << " " << count[i] << endl;
	}
	return 0;
}