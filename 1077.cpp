#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int count = 0, score=0, a, num[100] = { 0 };
		double  res=0;//�Ƚ������ΪС����ת�������������⾫�ȴ���
		cin >> a;

		for (int j = 1; j < n; j++)
		{
			int b;
			cin >> b;
			if (0 <=b &&b<= m)
				num[count++] = b;//�����������ķ�����������
		}

		sort(num, num + count);//����

		for (int k = 1; k < count - 1; k++)//��ȥ���ֵ����Сֵ
			res += num[k];

		res = (res / (count - 2) + a) / 2;
		score = res+0.5;//��������С��ת������������ֱ��ת��������������ֱ�ӽ�ȡ��
		cout << score << endl;
	}
	return 0;
}