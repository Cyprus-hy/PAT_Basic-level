#include<iostream>
#include<vector>

using namespace std;

int gcd(int a, int b)//�������Լ��
{
	return b == 0 ? a : gcd(b, a % b);
}


int main()
{
	double n1, m1, n2, m2;
	int k;
	scanf("%lf/%lf %lf/%lf", &n1, &m1, &n2, &m2);
	cin >> k;
	vector<int> tem;

	if (n1*m2 > n2*m1)//��������ݿ����ǵ�һ����ڶ���С
	{
		swap(n1, n2);
		swap(m1, m2);
	}

	for (int i = 1; i < k; i++)
	{
		//���ó˷����жϴ�С������ó����Ļ����ȿ��ܲ���
		if (n1*k<m1*i && n2*k>m2*i && gcd(i,k) == 1)//���������ʵȼ������������Լ��Ϊ1
			tem.push_back(i);
	}

	for (int i = 0; i < tem.size(); i++)
	{
		if (i)
			cout << " ";
		printf("%d/%d", tem[i], k);
	}
	return 0;
}