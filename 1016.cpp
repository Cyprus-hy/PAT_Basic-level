#include<iostream>
#include<string>

using namespace std;

int main()
{
	int Da, Db, Pa=0, Pb=0;
	string  A, B;
	cin >> A >> Da >> B >> Db;
	for (int i = 0; i < A.length(); i++)
	{
		if (A[i] - '0' == Da)
			Pa = Pa * 10 + Da;//得到Pa
	}
	for (int j = 0; j < B.length(); j++)
	{
		if (B[j] - '0' == Db)
			Pb = Pb * 10 + Db;//得到Pb
	}
	cout << Pa + Pb << endl;
	return 0;
}