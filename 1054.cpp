#include<iostream>

using namespace std;

bool IsLeagal(char *c)//判断字符串是否合法
{
	int flag = 1, point=0,count = 0,i=0;

	if (c[0] == '-')//负数时直接跳过第一个字符
		i++;

	for (; c[i] != '\0'; i++)
	{
		if ((c[i]<'0' || c[i]>'9') && c[i] != '.')//字符串中存在数字和小数点以为的字符
		{
			flag = 0; 
			break;
		}

		else
		{
			if (point)//统计小数点后面的位数
				count++;

			if (c[i] == '.' && point)//再次出现小数点
			{
				flag = 0;
				break;
			}

			if (c[i] == '.' && !point)//第一次出现小数点
				point = 1;

			if (count > 2)//小数点后位数大于两位
			{
				flag = 0;
				break;
			}
		}
	}
	//atof函数可以直接将字符数组转化成小数
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
	else if(count==1)//一定要注意只有一个数时输出的是number，一个以上是numbers
		printf("The average of %d number is %.2lf\n", count, sum);
	else
	{
		res = sum / count;
		printf("The average of %d numbers is %.2lf\n", count, res);
	}
	return 0;
}