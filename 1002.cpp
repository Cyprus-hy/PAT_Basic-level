#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int count = 0, sum = 0, tem[50] = { 0 };
	string c[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu"};//���ֶ�Ӧ��ƴ��
	for (int i = 0; i < s.length(); i++)
		sum += s[i] - '0';//���
	for (; sum != 0; count++)
	{
		tem[count] = sum % 10;//�õ�ÿһλ������
		sum /= 10;
	}
	for (int j = count - 1; j > 0; j--)
		cout << c[tem[j]] << " ";//�������ÿһλ
	cout << c[tem[0]] << endl;
	return 0;
}