#include<iostream>
#include<cmath>
#include<algorithm>
//Ҫ�����ӵĳ��������Ӧ����Խ���������۵�����Խ�٣�Խ�̵������۵�����Խ��
using namespace std;

int main()
{
	int n, res,num[10000] = { 0 };
	double sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);//��������С��������

	/*�ʼѡ������̵����ӣ������ܹ��۵�n-1�Σ�����������۵�����
	��ǰһ���Ļ����ϼ�һ���������ֻ��Ҫ�۵�һ��*/
	sum += num[0] * pow(0.5, n - 1);
	for (int i = 1; i < n; i++)
		sum += num[i] * pow(0.5, n - i);

	res = sum;//����ȡ��
	printf("%d\n", res);
	return 0;
}