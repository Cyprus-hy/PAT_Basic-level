#include<iostream>
#include<math.h>

using namespace std;

//乘法结果可能会溢出
typedef long long int ll;

//求最大公约数
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a%b);
}

//格式化输出
void output(ll a, ll b)
{
	//寻找最大公约数并化简
	ll c = gcd(a, b);
	a /= c;
	b /= c;

	//化成假分数
	ll k = a / b;
	ll m=a%b;

	//负号要在分子
	if (a > 0 && b < 0)
	{
		a = -1*a;
		b = -1 * b;
	}

	//负数
	if (a < 0)
	{
		//小于1的数
		if (!k)
			printf("(%lld/%lld)", a, b);
		//大于1的数
		else
		{
			//可以整除
			if (!m)
				printf("(%lld)", k);
			//不能整除
			else
			{
				a %= b;//注意此时分子要小于分母
				printf("(%lld %lld/%lld)", k, abs(a), b);
			}	
		}
	}

	//0
	else if(a==0)
	{
		printf("0");
	}

	//正数
	else
	{
		if (!k)
			printf("%lld/%lld", a, b);
		else
		{
			if (!m)
				printf("%lld", k);
			else
			{
				a %= b;
				printf("%lld %lld/%lld", k, a, b);
			}
				
		}
	}
		
}

int main()
{
	ll a1, b1, a2, b2;
	scanf("%lld/%lld", &a1, &b1);
	scanf("%lld/%lld", &a2, &b2);

	//加法
	ll a3 = a1 * b2 + a2 * b1;
	ll b3 = b1 * b2;
	output(a1, b1);
	printf(" + ");
	output(a2, b2);
	printf(" = ");
	output(a3, b3);
	cout << endl;

	//减法
	ll a4 = a1 * b2 - a2 * b1;
	ll b4 = b1 * b2;
	output(a1, b1);
	printf(" - ");
	output(a2, b2);
	printf(" = ");
	output(a4, b4);
	cout << endl;

	//乘法
	ll a5 = a1 * a2;
	ll b5 = b1 * b2;
	output(a1, b1);
	printf(" * ");
	output(a2, b2);
	printf(" = ");
	output(a5, b5);
	cout << endl;

	//除法
	ll a6 = a1 * b2;
	ll b6 = a2 * b1;
	output(a1, b1);
	printf(" / ");
	output(a2, b2);
	printf(" = ");

	if (!a2)
		printf("Inf");
	else
		output(a6, b6);
	cout << endl;
	return 0;
}