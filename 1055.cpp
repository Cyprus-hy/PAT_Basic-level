#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

typedef struct Mystruct//�洢ÿ���˵����������
{
	string name;
	int height;
}Stu;

bool cmp(Stu s1, Stu s2)//��ÿ���˵���ߴӸߵ���������������ͬ����Ϊ�ֵ���С�ĸ���
{
	if (s1.height > s2.height)
		return true;
	else if (s1.height == s2.height&&s1.name< s2.name)//�ֵ���
		return true;
	else
		return false;
}

int main()
{
	int n, k,row,pos=0;
	cin >> n >> k;
	row = n / k;//ÿ�е�ѧ������
	vector<Stu> tem;

	for (int i = 0; i < n; i++)//��������
	{
		Stu s;
		cin >> s.name >> s.height;
		tem.push_back(s);
	}

	sort(tem.begin(), tem.end(), cmp);//��ߴӸߵ�������

	int last = n - (k - 1)*row;//���һ�ŵ�����
	vector<Stu> temp(last);//�洢ÿһ�е�ѧ��
	int left, right,i=1;
	left = last / 2;//�м��λ��
	right = last / 2;
	temp[left] = tem[0];//��ߵ���վ���м�

	for (; i < last; i++)//����������ҵ�˳�����η�ÿһ���ˣ�����ż�ж�
	{
		if (i % 2 == 0)//ż�����ұ�
		{
			right++;
			temp[right] = tem[i];
		}
		else//���������
		{
			left--;
			temp[left] = tem[i];
		}
	}

	for (int i = 0; i < last - 1; i++)//������һ��
		cout << temp[i].name << " ";
	cout << temp[last - 1].name << endl;

	for (int m = 1; m < k; m++)//���֮���k-1��
	{
		pos = row / 2;//�м�λ��
		left = right = pos;
		temp[pos] = tem[i++];//��ߵ������м�
		for (int j = 1; j < row; j++, i++)//����������ҵ�˳�����η�ÿһ���ˣ�����ż�ж�
		{
			if (j % 2 == 0)//ż�����ұ�
			{
				right++;
				temp[right] = tem[i];
			}
			else//���������
			{
				left--;
				temp[left] = tem[i];
			}
		}
		for (int z = 0; z < row-1; z++)//���
			cout << temp[z].name << " ";
		cout << temp[row - 1].name << endl;
	}

	return 0;
}