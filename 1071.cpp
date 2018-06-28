#include<iostream>

using namespace std;

int main()
{
	int s, k,x,flag=0;
	cin >> s >> k;
	x = s;

	for (int i = 0; i < k; i++)
	{
		int n1, b, t, n2;
		cin >> n1 >> b >> t >> n2;

		if (!flag)//输光了下面的不再继续
		{
			if (x == 0)//输光了
			{
				printf("Game Over.\n");
				flag = 1;
			}
			else
			{
				if (x < t)//玩家下注超过持有的筹码量
					printf("Not enough tokens.  Total = %d.\n", x);
				else
				{
					if ((n1 > n2&&b == 0) || (n1 < n2&&b == 1))//玩家赢
					{
						x += t;
						printf("Win %d!  Total = %d.\n", t, x);
					}

					else//玩家输
					{
						x -= t;
						printf("Lose %d.  Total = %d.\n", t, x);
					}
				}
			}
		}
	}
	return 0;
}