#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n, num=0,count[100] = { 0 };
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		int sum = 0;
		cin >> s;
		for (int j = 0; j < s.length(); j++)//���λ���ֵĺ�
			sum += s[j] - '0';

		if (!count[sum])//���֮ǰ�Ѿ����ֹ��Ͳ�������
			num++;
		count[sum]++;//���ֵĴ���
	}

	cout << num<<endl;

	for (int i = 0; i < 100; i++)
	{
		if (count[i])//���ֹ�
		{
			num--;
			cout << i;
			if (num)//���һ��Ԫ�ز�������ո�
				cout << " ";
			else
				cout << endl;
		}
	}

	return 0;
}