#include<iostream>
#include<string>

using namespace std;

int main()
{
	string ans;
	int n,count=0;
	cin >> ans >> n;
	getchar();//�Ե���һ������Ļ��з�

	while(true)
	{
		string s;
		getline(cin,s);//ע��������ܴ��ڿհ��ַ�
		count++;

		if (s == "#")//����#�������˳����������wrong answer
			break;

		if (s == ans)//�ɹ�����
		{
			cout << "Welcome in\n";
			break;
		}
		else
		{
			cout << "Wrong password: " << s << endl;
		}
		//�������n�Σ������wrong answer����������˻�����������Ҫ�ܽ������������
		if (count == n)
		{
			cout << "Account locked\n";
			break;
		}
	}

	return 0;
}

