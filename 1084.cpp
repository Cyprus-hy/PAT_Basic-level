#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	int n;
	cin >> s >> n;

	for (int i = 0; i < n-1; i++)
	{
		string tem ;//���ڴ�ű任�������
		for (int j = 0; j < s.length(); )
		{
			tem += s[j];//���ȴ��ǰһ���ĳλ����
			int count = 0;
			//�����������ж��ٸ�
			while (s[j] == tem[tem.length()-1])//�����µ�����ʱ�˳�����
			{
				j++;
				count++;
			}
			tem += count + '0';//�����ֵĸ���
		}
		s = tem;
	}

	cout << s << endl;
	return 0;
}