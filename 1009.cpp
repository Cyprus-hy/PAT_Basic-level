#include<iostream>
#include<string>

using namespace std;

int main()
{
	int count=1, a[80] = { 0 };//��ǿո�λ��
	string s;
	getline(cin, s);
	a[0] = -1;//�ַ�����ʼλ��
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			a[count] = i;//�ո�λ��
			count++;//�ո����
		}
	}
	a[count] = s.length();//����¼���ַ���ĩβ��λ��
	for (int j = count -1; j >= 0; j--)//�ӵ����ڶ����ո�λ�ÿ�ʼ
	{
		for (int k = a[j] + 1; k < a[j + 1]; k++)//��������ո�������
			cout << s[k];
		if (j != 0)
			cout << " ";//ĩβ�޿ո�
		else
			cout << endl;
	}
	return 0;
}