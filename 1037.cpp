#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;//�ַ����洢
	long long int a1=0,b1=0,c1=0,sum1=0, a2=0, b2=0, c2=0, sum2=0;
	int i = 0, j = 0,flag=0;
	for (; s1[i] != '.'; i++)//ÿһλ
		a1 = a1 * 10 + s1[i] - '0';
	for(i++; s1[i] != '.';i++)
		b1 = b1 * 10 + s1[i] - '0';
	for (i++; i<s1.length(); i++)
		c1 = c1 * 10 + s1[i] - '0';
	sum1 = a1 * 17 * 29 + b1 * 29 + c1;//����С��λ���ر�ʾ

	for (; s2[j] != '.'; j++)//ÿһλ
		a2 = a2 * 10 + s2[j] - '0';
	for (j++; s2[j] != '.'; j++)
		b2 = b2 * 10 + s2[j] - '0';
	for (j++; j<s2.length(); j++)
		c2 = c2 * 10 + s2[j] - '0';
	sum2 = a2 * 17 * 29 + b2 * 29 + c2;//����С��λ���ر�ʾ

	if (sum1 > sum2)//�жϴ�С����֤���Ϊsum2
	{
		long long int t;
		t = sum1;
		sum1 = sum2;
		sum2 = t;
		flag = 1;
	}

	long long int res = sum2 - sum1;
	long long int a3 = res / 493, b3 = (res - a3 * 493) / 29,c3=res-a3*493-b3*29;//���
	
	if (!flag)//�Ƿ��������
		cout << a3 << "." << b3 << "." << c3 << endl;
	else
		cout << "-"<<a3 << "." << b3 << "." << c3 << endl;
	return 0;
}