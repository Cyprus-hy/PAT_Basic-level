#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n,count=0,a,b;
	cin >> n;
	vector<int> num;//���������
	vector<int> res;//��������������
	vector<int> max;//�������ң�ÿһλ������ݵ����ֵ
	vector<int>min;//��������ÿһλ�����ұߵ���Сֵ

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d",&a);
		num.push_back(a);//vector�洢��������
	}
	
	a = num[0];//��Сֵ��ʼ��
	b = num[n - 1];//���ֵ��ʼ��
	max.push_back(0);//��һ�����������Сֵ��Ϊ0
	min.push_back(1000000001);//���һ�������ұ����ֵΪ�����

	for (int i = 0; i < n-1; i++)//Ѱ��ÿһλ������ֵ��ע�⵽n-2��������Ϊn-1�������κ��������
	{
		if (num[i] > a)
			a = num[i];
		max.push_back(a);
	}

	for (int i = n - 1; i > 0; i--)//Ѱ��ÿһλ�ұ���Сֵ��ע�⵽1��������Ϊ0�������κ������ұ�
	{
		if (num[i] < b)
			b = num[i];
		min.push_back(b);
	}

	for (int i = 0; i < n; i++)
	{
		if (num[i] > max[i] && num[i] < min[n - 1 - i])//��Ԫ�������������������ֵ�󣬱��ұ���СֵС
		{
			res.push_back(num[i]);
			count++;
		}
	}

	cout << count << endl;
	//sort(res.begin(), res.end());���ý�������ʵ������������Ԫ�����������Ȼ�ǵ�����
	if (count)
	{
		for (int i = 0; i < count - 1; i++)
			printf("%d ", res[i]);
		cout << res[count - 1] << endl;
	}
	else//0����Ԫ��ʱ�򵥶����ǣ���Ҫ���һ�пո�
		cout << endl;

	return 0;
}