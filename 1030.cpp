#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n,p;
	vector<int> num;
	vector<long long int>max;
	int count = 1;
	cin >> n >> p;

	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		num.push_back(c);


		long long int res = (long long int)c*(long long int)p;
		max.push_back(res);
	}

	sort(num.begin(), num.end());//��С��������
	sort(max.begin(), max.end());

	//��ǰ�����������ÿһ��������С�����ҵ������������¼��ʱ�������г��ȣ�ֱ���ҵ����ֵ
	for (int i = 0; i < n; i++)
	{
		long long int temp = max[i];
		//�����ǰ��С������ɵ��������еĳ���С��count�Ͳ��ñȽ���
		if (i+count-1<n&&num[i + count - 1] <= temp)
		{
			//�ҵ���ǰ��С����Ӧ�������
			for (int j = n - 1; j >= 0; j--)
			{
				if (temp >= num[j])
				{
					count = j - i + 1;
					break;
				}
			}
		}
		
	}

	cout << count << endl;
	return 0;
}