#include<iostream>

using namespace std;

int main()
{
	int n,real=1,row=3;
	char c;
	cin >> n >> c;
	for (;real<=n; row += 2)
		real += row * 2;
	real -= (row-2) * 2;//ʵ�ʴ�ӡ�ķ�����
	row -= 4;//��ӡ������
	for (int i = row; i >=3; i -=2 )//��ӡ�ϰ벿��
	{
		for (int j = 0; j < (row - i) / 2; j++)//�ո�
			cout << " ";
		for (int j = 0; j < i; j++)
			cout << c;
		cout << endl;
	}
	for (int i = 1; i <= row; i += 2)//�°벿��
	{
		for (int j = 0; j < (row - i) / 2; j++)
			cout << " ";
		for (int j = 0; j < i; j++)
			cout << c;
		cout << endl;
	}
	cout << n - real << endl;
	return 0;
}