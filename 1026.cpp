#include<iostream>

using namespace std;

int main()
{
	double a, b,time;
	int h, m, s;
	cin >> a >> b;
	time = (b - a) / 100;//��double�ͣ���֤���ݾ���
	h = time / 3600;//Сʱ
	m = (time - 3600 * h) / 60;
	s = (time - 3600 * h - m * 60) + 0.5;//��������
	if (h < 10)//һλ����Ҫ���в�ȫ
		cout << "0";
	cout << h << ":";
	if (m < 10)
		cout << "0";
	cout << m << ":";
	if (s < 10)
		cout << "0";
	cout << s << endl;
	return 0;
}