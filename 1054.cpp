#include<iostream>

using namespace std;

bool IsLeagal(char *c)//�ж��ַ����Ƿ�Ϸ�
{
	int flag = 1, point=0,count = 0,i=0;

	if (c[0] == '-')//����ʱֱ��������һ���ַ�
		i++;

	for (; c[i] != '\0'; i++)
	{
		if ((c[i]<'0' || c[i]>'9') && c[i] != '.')//�ַ����д������ֺ�С������Ϊ���ַ�
		{
			flag = 0; 
			break;
		}

		else
		{
			if (point)//ͳ��С��������λ��
				count++;

			if (c[i] == '.' && point)//�ٴγ���С����
			{
				flag = 0;
				break;
			}

			if (c[i] == '.' && !point)//��һ�γ���С����
				point = 1;

			if (count > 2)//С�����λ��������λ
			{
				flag = 0;
				break;
			}
		}
	}
	//atof��������ֱ�ӽ��ַ�����ת����С��
	if (atof(c) < -1000 || atof(c) > 1000)
		flag = 0;

	return flag;
}

int main()
{
	double n,  sum = 0,res;
	int count = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char c[100];
		scanf("%s", c);
		if (IsLeagal(c))
		{
			count++;
			sum += atof(c);
		}
		else
			printf("ERROR: %s is not a legal number\n", c);
	}

	if (!count)
		cout << "The average of 0 numbers is Undefined\n";
	else if(count==1)//һ��Ҫע��ֻ��һ����ʱ�������number��һ��������numbers
		printf("The average of %d number is %.2lf\n", count, sum);
	else
	{
		res = sum / count;
		printf("The average of %d numbers is %.2lf\n", count, res);
	}
	return 0;
}