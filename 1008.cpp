#include<iostream>

using namespace std;

int main()
{
	int n, m, num[200] = { 0 };
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		num[i + n] = num[i];//��һ������������ݱ���
	}
	for (int j = n; j < 2 * n; j++)
		num[(j - n + m) % n] = num[j];//ѭ���ƶ�ʵ������һ��ȡģ�Ĺ���
	for (int k = 0; k < n-1; k++)
		cout << num[k] << " ";
	cout << num[n - 1] << endl;
	return 0;
}