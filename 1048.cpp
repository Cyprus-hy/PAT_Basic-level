#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string a, b,c;
	cin >> a >> b;
	int len_a = a.length();
	int len_b = b.length();
	char str[13] = { '0','1','2','3','4','5','6','7','8','9','J','Q','K' };//�����ֵ��ַ���ת��

	for (int i = 0; i < len_a / 2; i++)//��Ϊ��λ�ǵ�һλ���������ǿ����Ƚ��ַ����ߵ�һ��
		swap(a[i], a[len_a - 1 - i]);
	for (int i = 0; i < len_b / 2; i++)
		swap(b[i], b[len_b - 1 - i]);

	if (len_a < len_b)//���ڳ��ȸ��̵��ַ�������Ҫ���䲹0��ע��append�������÷�
		a.append(len_b - len_a, '0');
	else
		b.append(len_a - len_b, '0');

	for (int i = 0; i < a.length(); i++)
	{
		int x = 0;
		if (i % 2 == 0)//��Ϊ�����ڵ�0λ�����Զ���ż�Ĳ���ǡ���෴
			x = (a[i] - '0' + b[i] - '0') % 13;
		else
			x = (b[i] - a[i] + 10) % 10;
		c += str[x];
	}

	for (int i = c.length() - 1; i >= 0; i--)//֮ǰ�����˵ߵ������������Ҫ����
		cout << c[i];
	cout << endl;

	return 0;
}