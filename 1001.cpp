#include<iostream>

using namespace std;

int main()
{
	int i_num,i_count=0;
	cin >> i_num;
	while (i_num != 1)
	{
		if (i_num % 2 == 0)
		{
			i_num = i_num / 2;//偶数算法
			i_count++;
		}
		else
		{
			i_num = (3 * i_num + 1) / 2;//奇数算法
			i_count++;
		}
	}
	cout << i_count << endl;
	return 0;
}