#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

typedef struct Mystruct//存储每个人的姓名与身高
{
	string name;
	int height;
}Stu;

bool cmp(Stu s1, Stu s2)//对每个人的身高从高到低排序，如果身高相同则认为字典序小的更高
{
	if (s1.height > s2.height)
		return true;
	else if (s1.height == s2.height&&s1.name< s2.name)//字典序
		return true;
	else
		return false;
}

int main()
{
	int n, k,row,pos=0;
	cin >> n >> k;
	row = n / k;//每行的学生人数
	vector<Stu> tem;

	for (int i = 0; i < n; i++)//输入数据
	{
		Stu s;
		cin >> s.name >> s.height;
		tem.push_back(s);
	}

	sort(tem.begin(), tem.end(), cmp);//身高从高到低排序

	int last = n - (k - 1)*row;//最后一排的人数
	vector<Stu> temp(last);//存储每一行的学生
	int left, right,i=1;
	left = last / 2;//中间的位置
	right = last / 2;
	temp[left] = tem[0];//最高的人站在中间

	for (; i < last; i++)//按照先左后右的顺序依次放每一个人，用奇偶判断
	{
		if (i % 2 == 0)//偶数放右边
		{
			right++;
			temp[right] = tem[i];
		}
		else//奇数放左边
		{
			left--;
			temp[left] = tem[i];
		}
	}

	for (int i = 0; i < last - 1; i++)//输出最后一行
		cout << temp[i].name << " ";
	cout << temp[last - 1].name << endl;

	for (int m = 1; m < k; m++)//输出之后的k-1行
	{
		pos = row / 2;//中间位置
		left = right = pos;
		temp[pos] = tem[i++];//最高的人在中间
		for (int j = 1; j < row; j++, i++)//按照先左后右的顺序依次放每一个人，用奇偶判断
		{
			if (j % 2 == 0)//偶数放右边
			{
				right++;
				temp[right] = tem[i];
			}
			else//奇数放左边
			{
				left--;
				temp[left] = tem[i];
			}
		}
		for (int z = 0; z < row-1; z++)//输出
			cout << temp[z].name << " ";
		cout << temp[row - 1].name << endl;
	}

	return 0;
}