#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>a;
	vector<int>b;

	//输入数据
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		a.push_back(m);
	}
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		b.push_back(m);
	}

	int i, j;
	//找到中间序列满足从左到右是从小到大顺序的最后一个元素下标
	for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++)
		;

	//找到从i+1开始第一个a[j]与b[j]不相等的元素
	for (j = i + 1; j < n&&a[j] == b[j]; j++)
		;

	//做插入排序时后面的元素次序不变，而归并排序时后面的元素次序会改变
	if (j == n) {
		cout << "Insertion Sort" << endl;
		//下一轮插入排序只需再排一个元素即可，注意sort的第二个参数
		sort(a.begin(), a.begin() + i + 2);
	}
	else {
		cout << "Merge Sort" << endl;
		int k = 1, flag = 1;
		while (flag) {
			flag = 0;
			for (i = 0; i < n; i++) {//循环到初始序列变为中间序列再循环一次即可
				if (a[i] != b[i])
					flag = 1;
			}
			k = k * 2;
			for (i = 0; i < n / k; i++)
				sort(a.begin() + i * k, a.begin() + (i + 1) * k);//对每一部分元素排序
			sort(a.begin() + n / k * k, a.begin() + n);//对末尾不足子序列数量的元素排序
		}
	}
	for (j = 0; j < n; j++) {
		if (j != 0) printf(" ");
		printf("%d", a[j]);
	}
	return 0;
}