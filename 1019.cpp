#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	string s;
	cin >> s;

	//������λʱǰ����0
	while (s.length() < 4)
	{
		s.append("0");
	}

	//��λ�����
	if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3])
	{
		cout<<s<<" - "<<s<<" = "<<"0000\n";
	}

	else
	{
		int num1 = 0, num2 = 0;
		do {
			sort(s.begin(), s.end());//��С��������
			string temp = s;
			reverse(s.begin(),s.end());//��ת
			
			//�ַ���תint
			stringstream ss;
			ss << s;
			ss >> num1;
			ss.clear();
			ss << temp;
			ss >> num2;
			ss.clear();

			printf("%04d - %04d = %04d\n", num1, num2,num1-num2);

			ss << (num1 - num2);
			ss >> s;
			s.insert(0, 4 - s.length(), '0');//ע��ÿ�θ��µ�ʱ��ҲҪ��0
			ss.clear();//����s
		} while (num1 - num2!=6174);
	}
}