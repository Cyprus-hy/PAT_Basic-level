#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	getchar();
	string low[13] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };//��λ
	string high[12] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };//��λ��λ
	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		if (s[0] >= '0'&&s[0] <= '9')//������ת������
		{
			int a = 0;
			vector<int>b;

			stringstream ss;//�ַ���ת���ɵ�ʮ������
			ss << s;
			ss >> a;
			ss.clear();

			do//ת����13����
			{
				int temp = a % 13;
				a /= 13;
				b.push_back(temp);
			} while (a != 0);

			if (b[0] == 0)
			{
				if (b.size() == 2)
					cout << high[b[1] - 1] << endl;
				else
					cout << "tret\n";
			}
			else
			{
				for (int j = b.size() - 1; j >= 1; j--)//�������
				{
					cout << high[b[j] - 1] << " ";
				}
				cout << low[b[0]] << endl;
			}
			
		}

		else//������ת������
		{
			if (s == "tret")//0Ҫ��������
				cout << "0\n";

			else if(s.length()==3)//һλ�Ļ�����
			{
				for (int j = 1; j < 13; j++)
				{
					if (low[j] == s)
					{
						cout << j << endl;
						break;
					}
				}

				for (int j = 0; j < 13; j++)//ע������ܿ�
				{
					if (high[j] == s)
					{
						cout << (j+1)*13 << endl;
						break;
					}
				}
			}

			else//һλ���ϻ�����
			{
				int sum = 0;
				for (int j = 0; j < s.length(); j = j + 4)
				{
					if (j + 4 >= s.length())//���λ
					{
						for (int k = 0; k < 13; k++)
						{
							if (s[j] == low[k][0] && s[j + 1] == low[k][1] && s[j + 2] == low[k][2])//Ѱ����ȵ��ַ���
							{
								sum = sum*13+k;
								break;
							}
						}
					}

					else//��λ
					{
						for (int k = 0; k < 12; k++)
						{
							if (s[j] == high[k][0] && s[j + 1] == high[k][1] && s[j + 2] == high[k][2])//Ѱ����ȵ��ַ���
							{
								sum = sum * 13 + k + 1;
								break;
							}
						}
					}
				}
				cout << sum << endl;
			}
		}
	}
	return 0;
}