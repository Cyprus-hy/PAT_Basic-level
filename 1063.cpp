#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n;
	double max=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		double a, b;
		cin >> a >> b;
		if (max < sqrt(pow(a, 2) + pow(b, 2)))//Ñ°ÕÒ×î´óÖµ
			max = sqrt(pow(a, 2) + pow(b, 2));
	}
	printf("%.2f\n", max);
	return 0;
}