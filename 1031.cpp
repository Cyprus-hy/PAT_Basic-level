#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n, count = 0, w[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 }, flag[100] = { 0 };
	string s[100];
	char c[11] = { '1','0','X','9','8','7','6','5','4','3','2' };//��Ӧ��У��λ
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < 17; j++)
			sum += w[j]*(s[i][j] - '0');//��Ȩ���
		if (s[i][17] != c[sum % 11])//�ж�У��λ�Ƿ���ȷ
		{
			count++;
			flag[i] = 1;//�����ַ����������е��±�
		}
	}
	if (count != 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (flag[i])
				cout << s[i] << endl;
		}
	}
	else
		cout << "All passed\n";
	return 0;
}