#include<iostream>

#define ROUND(a) (int)(a+0.5)

using namespace std;

int main()
{
	int num;
	char c;
	cin >> num >> c;
	for (int i = 0; i < num; i++)//��һ��
		cout << c;
	cout << endl;
	for (int i = 0; i < ROUND(num / 2.0) - 2; i++)//�м�
	{
		cout << c;
		for (int j = 0; j < num - 2; j++)
			cout << " ";
		cout << c << endl;
	}
	for (int i = 0; i < num; i++)//���һ��
		cout << c;
	cout << endl;
	return 0;
}