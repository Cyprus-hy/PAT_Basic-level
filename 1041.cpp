#include<iostream>
#include<string>

using namespace std;

typedef struct Mystruct
{
	string ID;//׼��֤��
	int i_try;//�Ի���λ��
	int i_test;//������λ��
}Stu;

int main()
{
	int n, m;
	Stu temp[1000];
	cin >> n;
	for (int i = 0; i < n; i++)//����ÿ��ѧ������Ϣ
		cin >> temp[i].ID >> temp[i].i_try >> temp[i].i_test;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		for (int j = 0; j < n; j++)//����Ѱ�Ҹ�ѧ����׼��֤���Լ�������λ��
		{
			if (temp[j].i_try == a)
			{
				cout << temp[j].ID <<" "<<temp[j].i_test << endl;
				break;
			}
		}
	}

	return 0;
}