#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	//s���ڴ�����ۿڶ�Ӧ�ķ��ż���ע��ÿ�����Ű���1��4���ǿ��ַ�������s�Ƕ�ά��vector����
	vector<vector<string>> s;
	int k;

	for (int i = 0; i < 3; i++)
	{
		string ss;
		getline(cin, ss);
		vector<string> tem;
		int k = 0;
		for (int j = 0; j < ss.length();j++)
		{
			if (ss[j] == '[')
			{
				while (k++ < ss.length())
				{
					if (ss[k] == ']')
						break;
				}
				//����������������֮����ַ����������ţ�����tem�У�substr��һ����������ʼλ�ã�
				//�ڶ��������ǳ���
				tem.push_back(ss.substr(j + 1, k - j - 1));
			}
		}
		s.push_back(tem);
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		//ע������������Ƿ�Ϸ����ж�
		if (a > s[0].size() || a <= 0 || b > s[1].size() || b <= 0 || c > s[2].size() || c <= 0 ||
			d > s[1].size() || d <= 0 || e > s[0].size() || e <= 0)
		{
			cout<<"Are you kidding me? @\\/@" << endl; 
		}
		else//ע�����������
		{
			cout << s[0][a-1] << "(" << s[1][b-1] << s[2][c-1] << s[1][d-1] << ")" << s[0][e-1] << endl;
		}
	}
	return 0;
}