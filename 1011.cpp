#include<iostream>
#include<string>
using namespace std;

typedef struct Mystruct
{
	long long int a;
	long long int b;
	long long int c;
	string res;
}Num;

int main()
{
	int i_num;
	cin >> i_num;
	Num *tem = new Num[i_num];
	for (int i = 0; i < i_num; i++)
		cin >> tem[i].a >> tem[i].b >> tem[i].c;
	for (int j = 0; j < i_num; j++)
	{
		if (tem[j].a + tem[j].b > tem[j].c)
			tem[j].res = "true";
		else
			tem[j].res = "false";
	}
	for (int k = 0; k < i_num; k++)
		cout << "Case #" << k + 1 << ": " << tem[k].res << endl;
	delete[]tem;
	return 0;
}