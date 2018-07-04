#include<iostream>
#include<map>
#include<cmath>

using namespace std;

//�жϸõ����ɫ������Χ 8 ���������ص���ɫ���Ƿ��ִ�
bool isRed(int i, int j, int v[][1002], int tol) {
	if (abs(v[i - 1][j - 1] - v[i][j]) <= tol) { // ���Ͻ�
		return false;
	}
	if (abs(v[i][j - 1] - v[i][j]) <= tol) { // ��
		return false;
	}
	if (abs(v[i + 1][j - 1] - v[i][j]) <= tol) { // ���Ͻ�
		return false;
	}
	if (abs(v[i + 1][j] - v[i][j]) <= tol) { // ��
		return false;
	}
	if (abs(v[i + 1][j + 1] - v[i][j]) <= tol) { // ���½�
		return false;
	}
	if (abs(v[i][j + 1] - v[i][j]) <= tol) { // ��
		return false;
	}
	if (abs(v[i - 1][j + 1] - v[i][j]) <= tol) { // ���½�
		return false;
	}
	if (abs(v[i - 1][j] - v[i][j]) <= tol) { // ��
		return false;
	}
	else 
		return true;
}



int main()
{
	int m, n, x,y,tol, flag = 0;
	map<int, int> count;//��¼ÿ����ɫ���ֵĴ���
	//�����������ȣ������ܿӣ������жϱ�Ե����ɫ������Ҷ��ڱ�Ե������˵��ֻ���ж����İ˸���λ�д���
	//���ص㣬�����ڵ�Ĭ�����ز��ִ�
	int c[1002][1002] = { 0 };
	cin >> m >> n >> tol;
	//��ʼ������ֵ��С����֤���ڱ�Ե������˵�䲻���ڵķ�λ�����ز��ִ�
	for (int i = 0; i < 1002; i++)
	{
		for (int j = 0; j < 1002; j++)
			c[i][j] = -10000000;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &c[i][j]);
			count[c[i][j]]++;
		}
	}

	for (int i = 1; i <= n ; i++)
	{
		for (int j = 1; j <= m ; j++)
		{
			if (count[c[i][j]] == 1&&isRed(i,j,c,tol))//��������
			{
				flag++;
				x = i;
				y = j;
			}
				
			if (flag > 1)//�г���һ���������������ص�
				break;
		}

		if (flag > 1)
			break;
	}

	if (flag == 0)
		cout << "Not Exist\n";
	else if (flag == 1)
		printf("(%d, %d): %d\n", y, x, c[x][y]);
	else
		cout << "Not Unique\n";
	return 0;
}