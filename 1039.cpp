#include<iostream>
#include<string>

using namespace std;

int main()
{
	int res=0,count1[62] = { 0 }, count2[62] = { 0 };
	string s1, s2;//�ַ����洢
	cin >> s1 >> s2;

	for (int i = 0; i < s1.length(); i++)//��¼��ÿ���ַ�����ÿ���ַ����ֵĴ���
	{
		if (s1[i] - '0' >= 0 && s1[i] - '9' <= 0)
			count1[s1[i] - '0']++;
		else if (s1[i] - 'a' >= 0 && s1[i] - 'z' <= 0)
			count1[s1[i] - 'a' + 10]++;
		else
			count1[s1[i] - 'A' + 36]++;
	}
	
	for (int i = 0; i < s2.length(); i++)
	{
		if (s2[i] - '0' >= 0 && s2[i] - '9' <= 0)
			count2[s2[i] - '0']++;
		else if (s2[i] - 'a' >= 0 && s2[i] - 'z' <= 0)
			count2[s2[i] - 'a' + 10]++;
		else
			count2[s2[i] - 'A' + 36]++;
	}

	for (int i = 0; i < 62; i++)//�������ַ����Ա�
	{
		if (count2[i] != 0 && count2[i]>=count1[i])//�ж�С����Ҫ���鴮��̯�����鴮���Ƿ�����Լ������
			res += count2[i] - count1[i];
	}

	if (!res)//��ȫ����
		cout << "Yes " << s1.length() - s2.length() << endl;
	else//��res������
		cout << "No " << res << endl;
	return 0;
}