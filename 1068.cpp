#include<iostream>
#include<map>
#include<cmath>

using namespace std;

//判断该点的颜色与其周围 8 个相邻像素的颜色差是否充分大
bool isRed(int i, int j, int v[][1002], int tol) {
	if (abs(v[i - 1][j - 1] - v[i][j]) <= tol) { // 左上角
		return false;
	}
	if (abs(v[i][j - 1] - v[i][j]) <= tol) { // 上
		return false;
	}
	if (abs(v[i + 1][j - 1] - v[i][j]) <= tol) { // 右上角
		return false;
	}
	if (abs(v[i + 1][j] - v[i][j]) <= tol) { // 右
		return false;
	}
	if (abs(v[i + 1][j + 1] - v[i][j]) <= tol) { // 右下角
		return false;
	}
	if (abs(v[i][j + 1] - v[i][j]) <= tol) { // 下
		return false;
	}
	if (abs(v[i - 1][j + 1] - v[i][j]) <= tol) { // 左下角
		return false;
	}
	if (abs(v[i - 1][j] - v[i][j]) <= tol) { // 左
		return false;
	}
	else 
		return true;
}



int main()
{
	int m, n, x,y,tol, flag = 0;
	map<int, int> count;//记录每个颜色出现的次数
	//开大两个长度，这道题很坑，必须判断边缘的颜色情况，且对于边缘像素来说，只需判断它的八个方位中存在
	//像素点，不存在的默认像素差充分大
	int c[1002][1002] = { 0 };
	cin >> m >> n >> tol;
	//初始化像素值很小，保证对于边缘像素来说其不存在的方位上像素差充分大
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
			if (count[c[i][j]] == 1&&isRed(i,j,c,tol))//满足条件
			{
				flag++;
				x = i;
				y = j;
			}
				
			if (flag > 1)//有超过一个满足条件的像素点
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