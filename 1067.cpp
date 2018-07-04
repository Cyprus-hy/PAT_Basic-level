#include<iostream>
#include<string>

using namespace std;

int main()
{
	string ans;
	int n,count=0;
	cin >> ans >> n;
	getchar();//吃掉上一行输入的换行符

	while(true)
	{
		string s;
		getline(cin,s);//注意输入可能存在空白字符
		count++;

		if (s == "#")//遇到#就立刻退出，不能输出wrong answer
			break;

		if (s == ans)//成功进入
		{
			cout << "Welcome in\n";
			break;
		}
		else
		{
			cout << "Wrong password: " << s << endl;
		}
		//如果错误n次，在输出wrong answer后立刻输出账户被锁定，不要管接下来的输出了
		if (count == n)
		{
			cout << "Account locked\n";
			break;
		}
	}

	return 0;
}

