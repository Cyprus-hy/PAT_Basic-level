#include<iostream>
#include<string>

using namespace std;

int main()
{
	string a;//�������ַ�����ʾ
	int b, num[1000] = { 0 }, count = 0, res[1000] = { 0 };
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++)
		num[i] = a[i] - '0';//���ַ���ÿһλת��������
	if (a.length() != 1)
	{
		for (int j = 0; j < a.length() - 1; )//ע����С��a.length()-1
		{
			if (num[j] >= b)//����Ҫ��λ
			{
				res[count] = num[j] / b;//���
				num[j] = num[j] % b;//����������λ
				count++;//�̵�λ��
			}
			else//��λ
			{
				res[count] = (10 * num[j] + num[j + 1]) / b;
				num[j + 1] = (10 * num[j] + num[j + 1]) % b;
				count++;
				j++;//��Ҫ��λʱ��������һλ
			}
		}
	}
	else//һλ��ʱ��Ҫ�����ж�
	{
		res[count] = num[0]/b;
		count++;
		num[0] = num[0] % b;
	}
	for (int k = 0; k < count; k++)
		cout << res[k];//������
	cout << " " << num[a.length() - 1] << endl;
	return 0;
}