#include<iostream>

using namespace std;

int main()
{
	int num,k;
	cin >> num;
	int n[101] = { 0 }, c[100000] = { 0 };
	for (int i = 0; i < num; i++)
	{
		int a;
		cin >> a;
		n[a]++;//Ͱ����˼�룬����
	}
	cin >> k;
	for (int i = 0; i < k; i++)//Ҫ���ҵ�����
	{
		cin >> c[i];
	}
	for(int i=0;i<k-1;i++)//ע���ʽ
		cout << n[c[i]] <<" ";
	cout << n[c[k - 1]] << endl;
	return 0;
}