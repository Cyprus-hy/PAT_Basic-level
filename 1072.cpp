#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n, m, things[6] = { 0 },count1=0,count2=0;//things��¼Ҫ�սɵ���Ʒ��count1Ϊѧ������count2Ϊ��Ʒ��
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		cin >> things[i];

	for (int i = 0; i < n; i++)
	{
		string name;
		//countΪ��λѧ��������Ʒ����tem���ѧ�������ɵ���Ʒ
		int count=0,k, tem[6] = { 0 };

		cin >> name >> k;
		for (int j = 0; j < k; j++)
		{
			int a;
			cin >> a;
			for (int x = 0; x < m; x++)//�Ƿ��ڽ�����Ʒ���嵥��
			{
				if (a == things[x])
				{
					count2++;//������Ʒ����1
					tem[count] = a;
					count++;
					break;
				}
			}
		}

		if (count)
		{
			count1++;//��������ѧ������1
			cout << name << ":";
			for (int j = 0; j < count; j++)//���������Ʒ
				printf(" %04d",tem[j]);//ע�������ʽ
			cout << endl;
		}
	}

	cout << count1 << " " << count2 << endl;
	return 0;
}