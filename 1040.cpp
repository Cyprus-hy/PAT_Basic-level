#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string s;
	int sum = 0;
	getline(cin, s);

	//��¼ÿ��A֮ǰ�ж��ٸ�P��ÿ��T֮ǰ�ж��ٸ�A
	int p = 0, a=0, t = 0;
	vector<int>pbeforea;
	vector<int>abeforet;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'T')
			t++;
	}

	//����ÿһ��A����¼��ǰ���ж��ٸ�P�������ж��ٸ�T��������˼�Ϊ���A����ɵ�PAT����������ۼӼ���
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'P')
			p++;
		else if (s[i] == 'A')
		{
			a++;
			sum += p * t % 1000000007;
			sum %= 1000000007;
		}
		else
		{
			t--;
		}
	}

	cout << sum << endl;
	return 0;
}