#include<iostream>
#include<string>

using namespace std;

const int max = 120;

int main()
{
	int n,flag=0,lang1=0,lang2=0;
	cin >> n;
	int say[max] = { 0 }, real[max] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		cin >> say[i];//cin可以读入带正号的数字
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				for (int s = 1; s <= n; s++)//初始化
					real[s] = s;
				
				int count = 0, flag1 = 0, flag2 = 0;
				real[i] = i * (-1);
				real[j] = j * (-1);

				for (int k = 1; k <= n; k++)
				{
					if (real[k] < 0 && say[k] != real[abs(say[k])])//狼人说谎
					{
						count++;
						flag1 = 1;
					}

					if (real[k] > 0 && say[k] != real[abs(say[k])])//好人说谎
					{
						count++;
						flag2 = 1;
					}
				}

				if (count == 2 && flag1&&flag2)//满足一个好人说谎一个坏人说谎的条件
				{
					flag = 1;
					lang1 = i;
					lang2 = j;
					break;
				}
			}
		}

		if (flag)
			break;
	}

	if (flag)
		cout << lang1 << " " << lang2 << endl;
	else
		cout << "No Solution\n";
	return 0;
}