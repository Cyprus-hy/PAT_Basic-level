#include<iostream>

using namespace std;

int main()
{
	int n;
	double sum=0;
	cin >> n;
	for (int i = 0; i < n; i++)//�ҹ��ɿ��Է��֣��ӵ�0λ����n-1λ��ÿһλ���ֵĴ���Ϊ(i+1)*(n-i),ֱ�������;ͺ�
	{
		double a;
		cin >> a;
		sum += a * (i + 1)*(n - i);//����ǰ����������i*(n-i)�����Լ���ʱ���ֳ���n-i��
	}
	printf("%.2f\n", sum);
	return 0;
}