#include<iostream>
#include<string>

using namespace std;

typedef struct Mystruct
{
	string str1;
	string str2;
	string str3;
	string str4;
}Time;

int main()
{
	Time t;
	cin >> t.str1 >> t.str2 >> t.str3 >> t.str4;
	string day[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	int pos=0;
	for (int i = 0; i < t.str1.length() && i < t.str2.length(); i++)
	{
		if (t.str1[i] == t.str2[i] && t.str1[i] - 'A' >= 0 && t.str1[i] - 'G' <= 0)//Ѱ�ҵ�һ����ȵĴ�д��ĸ
		{
			cout << day[t.str1[i] - 'A'] << " "; //������A��G֮��
			pos = i;//��¼��λ��
			break;
		}
	}
	for (int j = pos + 1; j < t.str1.length() && j < t.str2.length(); j++)
	{
		if (t.str1[j] == t.str2[j])
		{
			if (t.str1[j] - '0' >= 0 && t.str2[j] - '9' <= 0)//��ͬ��������
			{
				cout << "0" << t.str1[j] << ":";
				break;
			}
			else if (t.str1[j] - 'A' >= 0 && t.str2[j] - 'N' <= 0)//��ͬ���Ǵ�д��ĸ,������A��N֮��,�ӵ�
			{
				cout << t.str1[j] - 'A' + 10 << ":";
				break;
			}
		}
	}
	for (int k = 0; k < t.str3.length() && k < t.str4.length(); k++)
	{
		if (t.str3[k] == t.str4[k])
		{
			if ((t.str3[k] - 'a' >= 0 && t.str3[k] - 'z' <= 0) || (t.str3[k] - 'A' >= 0 && t.str3[k] - 'Z' <= 0))//��֤��Ӣ����ĸ
			{
				if (k < 10)
					cout << "0" << k << endl;//����ǰ���Ƿ��0
				else
					cout << k << endl;
				break;
			}	
		}
	}
	return 0;
}