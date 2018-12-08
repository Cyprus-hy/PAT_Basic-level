#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

//�Ӵ�С����
bool cmp(int a, int b)
{
	return a > b ? true : false;
}

int main()
{
	int N;
	vector<int> num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		//��������
		int a;
		cin >> a;
		num.push_back(a);
	}

	//��þ����������
	int root = sqrt(N);
	int m, n;
	//m,n��ֵ��Сʱ�����ǿ϶���ƽ��������
	//ע��Ӧ���ȼ����n���ټ����m
	for (int i = root; i >= 1; i--)
	{
		if (N%i == 0)
		{
			n = i;
			break;
		}
	}
	m = N / n;

	sort(num.begin(), num.end(), cmp);//����

	int sum = 0, count = 0, quan = 2 * m + 2 * n - 4;//�����һȦ��2 * m + 2 * n - 4������
	//��¼����һ���ж���Ȧ
	for (int i = 1; sum < N; i++)
	{
		sum += quan;
		quan -= 8;//����ÿһȦ�ĸ���
		count = i;
	}

	//�洢��һ����ά��vector��
	vector<vector<int>>matrix(m, vector<int>(n));
	int pos = 0;
	for (int i = 0; i < count; i++)
	{
		//�����ұ�����ע��һ��Ҫ�ж�pos>N,��ΪN=3ʱ�ͻ��д���
		for (int j = i; j < n - i && pos < N; j++)
		{
			matrix[i][j] = num[pos];
			pos++;
		}

		//�����±���
		for (int j = i + 1; j < m - i && pos < N; j++)
		{
			matrix[j][n - 1 - i] = num[pos];
			pos++;
		}

		//���������
		for (int j = n - 2 - i; j >= i && pos < N; j--)
		{
			matrix[m - 1 - i][j] = num[pos];
			pos++;
		}

		//������ϱ���
		for (int j = m - 2 - i; j > i&&pos < N; j--)
		{
			matrix[j][i] = num[pos];
			pos++;
		}
	}

	//���
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		cout << matrix[i][n - 1] << endl;
	}
	return 0;
}