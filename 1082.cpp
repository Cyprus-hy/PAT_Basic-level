#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double max = 0, min = 10000;//����
	int n,first = 0, last = 0;//������
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int team, x, y;
		cin >> team >> x>> y;
		double res;
		res = sqrt(pow(x, 2)+pow(y, 2));//���㵽���ĵľ���

		if (res > max)//����
		{
			max = res;
			last = team;
		}

		else if (res < min)//�ھ�
		{
			min = res;
			first = team;
		}
	}

	printf("%04d %04d\n", first, last);
	return 0;
}