#include<iostream>
#include<math.h>

using namespace std;

//�˷�������ܻ����
typedef long long int ll;

//�����Լ��
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a%b);
}

//��ʽ�����
void output(ll a, ll b)
{
	//Ѱ�����Լ��������
	ll c = gcd(a, b);
	a /= c;
	b /= c;

	//���ɼٷ���
	ll k = a / b;
	ll m=a%b;

	//����Ҫ�ڷ���
	if (a > 0 && b < 0)
	{
		a = -1*a;
		b = -1 * b;
	}

	//����
	if (a < 0)
	{
		//С��1����
		if (!k)
			printf("(%lld/%lld)", a, b);
		//����1����
		else
		{
			//��������
			if (!m)
				printf("(%lld)", k);
			//��������
			else
			{
				a %= b;//ע���ʱ����ҪС�ڷ�ĸ
				printf("(%lld %lld/%lld)", k, abs(a), b);
			}	
		}
	}

	//0
	else if(a==0)
	{
		printf("0");
	}

	//����
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

	//�ӷ�
	ll a3 = a1 * b2 + a2 * b1;
	ll b3 = b1 * b2;
	output(a1, b1);
	printf(" + ");
	output(a2, b2);
	printf(" = ");
	output(a3, b3);
	cout << endl;

	//����
	ll a4 = a1 * b2 - a2 * b1;
	ll b4 = b1 * b2;
	output(a1, b1);
	printf(" - ");
	output(a2, b2);
	printf(" = ");
	output(a4, b4);
	cout << endl;

	//�˷�
	ll a5 = a1 * a2;
	ll b5 = b1 * b2;
	output(a1, b1);
	printf(" * ");
	output(a2, b2);
	printf(" = ");
	output(a5, b5);
	cout << endl;

	//����
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