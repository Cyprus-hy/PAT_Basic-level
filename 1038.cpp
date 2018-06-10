#include<iostream>

using namespace std;

int main()
{
	int num,k;
	cin >> num;
	int n[101] = { 0 }, c[100000] = { 0 };
	for (int i = 0; i < num; i++)
	{
		int a;
		cin >> a;
		n[a]++;//桶排序思想，计数
	}
	cin >> k;
	for (int i = 0; i < k; i++)//要查找的数字
	{
		cin >> c[i];
	}
	for(int i=0;i<k-1;i++)//注意格式
		cout << n[c[i]] <<" ";
	cout << n[c[k - 1]] << endl;
	return 0;
}