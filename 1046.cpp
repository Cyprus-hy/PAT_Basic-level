#include<iostream>

using namespace std;

typedef struct Mystruct
{
	int a_say;//�׺�
	int a_hua;//�׻�
	int b_say;//�Һ�
	int b_hua;//�һ�
}Game;

int main()
{
	int n,count1=0,count2=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Game tem;
		cin >> tem.a_say >> tem.a_hua >> tem.b_say >> tem.b_hua;
		if (tem.a_hua == tem.a_say + tem.b_say&&tem.b_hua != tem.a_say + tem.b_say)//��Ӯ
			count2++;
		else if (tem.a_hua != tem.a_say + tem.b_say&&tem.b_hua == tem.a_say + tem.b_say)//��Ӯ
			count1++;
	}
	cout << count1 << " " << count2<<endl;
	return 0;
}