#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n, m, score[100] = { 0 };
	string answer;//��ȷ��
	cin >> n >> m;

	for (int i = 0; i < m; i++)//����ÿһ����ķ���
		cin >> score[i];

	for (int j = 0; j < m; j++)
	{
		char c;
		cin >> c;
		answer += c;//��ȷ�����ַ����洢
	}

	for (int i = 0; i < n; i++)
	{
		int sum = 0;//ÿһλѧ���ĳɼ�
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == answer[j])//�жϴ��Ƿ���ȷ
				sum += score[j];
		}
		cout << sum<<endl;
	}
	return 0;
}