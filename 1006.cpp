#include<iostream>

using namespace std;

int main()
{
	int i_num, a[3] = { 0 };
	cin >> i_num;
	for (int i = 2; i_num != 0; i--)//����õ���λ����ÿһλ
	{
		a[i] = i_num % 10;
		i_num /= 10;
	}
	for (int j = 0; j < a[0]; j++)//��λ���
		cout << "B";
	for (int j = 0; j < a[1]; j++)//ʮλ���
		cout << "S";
	for (int j = 1; j <= a[2]; j++)//��λ���
		cout << j;
	cout << endl;
	return 0;
}