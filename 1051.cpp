#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double r1, p1, r2, p2,A,B;
	cin >> r1 >> p1 >> r2 >> p2;
	B = r1 * r2*sin(p1 + p2);
	A = r1 * r2*cos(p1 + p2);
	cout << A << " " << B << endl;
	if (A > -0.005&&A < 0)//һ��Ҫ���ǵ���A��-0.005��0ʱ��������������-0.00
		cout << "0.00";
	else
		printf("%.2f", A);
	
	if (B >= -0.005)
		printf("+%.2fi\n", fabs(B));//��A���ж�ͬ��ҲҪ��fabs(B)
	else
		printf("-%.2fi\n", fabs(B));

	return 0;
}