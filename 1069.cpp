#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int m, n, s,a;
	cin >> m >> n >> s;
	vector<string> temp;
	a = s;//备份s

	for (int i = 1; i <= m; i++)
	{
		string ss;
		cin >> ss;
		int flag = 0;

		for (int j = 0; j < temp.size(); j++)//之前这个人已经中过奖了
		{
			if (temp[j] == ss)
			{
				flag = 1;
				break;
			}
		}

		if (i == s && !flag)//抽中的这个人之前也没中过奖
		{
			temp.push_back(ss);
			s += n;//中奖间隔为n
		}
		else if (i == s && flag)//抽中的这个人之前中过奖
			s++;
			
	}

	if (m < a)//没有人中奖
		cout << "Keep going..." << endl;
	else
	{
		for (int i = 0; i < temp.size(); i++)
			cout << temp[i] << endl;
	}
	return 0;
}