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

		if (!flag)//���������Ĳ��ټ���
		{
			if (x == 0)//�����
			{
				printf("Game Over.\n");
				flag = 1;
			}
			else
			{
				if (x < t)//�����ע�������еĳ�����
					printf("Not enough tokens.  Total = %d.\n", x);
				else
				{
					if ((n1 > n2&&b == 0) || (n1 < n2&&b == 1))//���Ӯ
					{
						x += t;
						printf("Win %d!  Total = %d.\n", t, x);
					}

					else//�����
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