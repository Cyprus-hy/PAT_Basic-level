#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int m, n, s,a;
	cin >> m >> n >> s;
	vector<string> temp;
	a = s;//����s

	for (int i = 1; i <= m; i++)
	{
		string ss;
		cin >> ss;
		int flag = 0;

		for (int j = 0; j < temp.size(); j++)//֮ǰ������Ѿ��й�����
		{
			if (temp[j] == ss)
			{
				flag = 1;
				break;
			}
		}

		if (i == s && !flag)//���е������֮ǰҲû�й���
		{
			temp.push_back(ss);
			s += n;//�н����Ϊn
		}
		else if (i == s && flag)//���е������֮ǰ�й���
			s++;
			
	}

	if (m < a)//û�����н�
		cout << "Keep going..." << endl;
	else
	{
		for (int i = 0; i < temp.size(); i++)
			cout << temp[i] << endl;
	}
	return 0;
}