#include<iostream>

using namespace std;

typedef struct Mystruct
{
	int a_say;//¼×º°
	int a_hua;//¼×»®
	int b_say;//ÒÒº°
	int b_hua;//ÒÒ»®
}Game;

int main()
{
	int n,count1=0,count2=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Game tem;
		cin >> tem.a_say >> tem.a_hua >> tem.b_say >> tem.b_hua;
		if (tem.a_hua == tem.a_say + tem.b_say&&tem.b_hua != tem.a_say + tem.b_say)//¼×Ó®
			count2++;
		else if (tem.a_hua != tem.a_say + tem.b_say&&tem.b_hua == tem.a_say + tem.b_say)//ÒÒÓ®
			count1++;
	}
	cout << count1 << " " << count2<<endl;
	return 0;
}