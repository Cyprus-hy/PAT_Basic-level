#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>a;
	vector<int>b;

	//��������
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
	//�ҵ��м���������������Ǵ�С����˳������һ��Ԫ���±�
	for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++)
		;

	//�ҵ���i+1��ʼ��һ��a[j]��b[j]����ȵ�Ԫ��
	for (j = i + 1; j < n&&a[j] == b[j]; j++)
		;

	//����������ʱ�����Ԫ�ش��򲻱䣬���鲢����ʱ�����Ԫ�ش����ı�
	if (j == n) {
		cout << "Insertion Sort" << endl;
		//��һ�ֲ�������ֻ������һ��Ԫ�ؼ��ɣ�ע��sort�ĵڶ�������
		sort(a.begin(), a.begin() + i + 2);
	}
	else {
		cout << "Merge Sort" << endl;
		int k = 1, flag = 1;
		while (flag) {
			flag = 0;
			for (i = 0; i < n; i++) {//ѭ������ʼ���б�Ϊ�м�������ѭ��һ�μ���
				if (a[i] != b[i])
					flag = 1;
			}
			k = k * 2;
			for (i = 0; i < n / k; i++)
				sort(a.begin() + i * k, a.begin() + (i + 1) * k);//��ÿһ����Ԫ������
			sort(a.begin() + n / k * k, a.begin() + n);//��ĩβ����������������Ԫ������
		}
	}
	for (j = 0; j < n; j++) {
		if (j != 0) printf(" ");
		printf("%d", a[j]);
	}
	return 0;
}