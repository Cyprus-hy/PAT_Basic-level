#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	int sum = 0,count1=0,count2=0;
	getline(cin, s);//��getline����
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a'&&s[i] <= 'z')//�����ִ�Сд����Ӣ����ĸ��ź�
			sum += s[i] - 'a'+1;
		else if(s[i] >= 'A'&&s[i] <= 'Z')
			sum += s[i] - 'A' + 1;
	}

	while (sum != 0)//ʮ����ת�ɶ�����
	{
		if (sum % 2 == 0)
			count1++;
		else
			count2++;
		sum /= 2;
	}

	cout << count1 << " " << count2 << endl;

	return 0;
}
