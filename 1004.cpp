#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef struct Mystruct
{
	string name;//姓名
	string num;//学号
	int goal;//分数
}Stu;

int main()
{
	int i_num;
	cin >> i_num;//学生人数
	Stu s,s_tem[1000];
	for (int i = 0; i < i_num; i++)
		cin >> s_tem[i].name >> s_tem[i].num >> s_tem[i].goal;
	for(int i=0;i<i_num-1;i++)//冒泡排序，升序
		for (int j = 0; j < i_num - i-1; j++)//注意j要小于i_num - i-1，因为下面是j和j+1比较
		{
			if (s_tem[j].goal > s_tem[j + 1].goal)
			{
				s = s_tem[j];
				s_tem[j] = s_tem[j + 1];
				s_tem[j + 1] = s;
			}
		}
	cout << s_tem[i_num - 1].name << " " << s_tem[i_num - 1].num << endl;
	cout << s_tem[0].name << " " << s_tem[0].num << endl;
	return 0;
}