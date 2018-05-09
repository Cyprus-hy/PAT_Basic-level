#include<iostream>
#include<vector>

using namespace std;

typedef struct Mystruct
{
	char a;//甲的
	char b;//乙的
}Game;

int main()
{
	//记录甲胜平负的次数、甲胜时出每种手势的次数、乙胜时出每种手势的次数
	int i_num, max1=0,max2=0,count1 = 0, count2 = 0, count3 = 0, win1[3] = { 0 }, win2[3] = { 0 };
	char c[3] = { 'B','C','J' };//根据记录的甲乙胜时出现次数最多的手势对应的下标输出手势
	cin >> i_num;
	vector <Game> v;//用vector存储
	for (int i = 0; i < i_num; i++)
	{
		Game g;
		cin >> g.a >> g.b;
		v.push_back(g);
	}
	for (int i = 0; i < i_num; i++)
	{
		if (v[i].a == 'B'&&v[i].b == 'C')
		{
			count1++;
			win1[0]++;//甲胜且此时出现的是布
		}
		else if (v[i].a == 'C'&&v[i].b == 'J')
		{
			count1++;
			win1[1]++;//甲胜且此时出现的是锤子
		}
		else if (v[i].a == 'J'&&v[i].b == 'B')
		{
			count1++;
			win1[2]++;//甲胜且此时出现的是剪刀
		}
		else if (v[i].a == v[i].b)
		{
			count2++;//平局
		}
		else if (v[i].b == 'B'&&v[i].a == 'C')
		{
			count3++;
			win2[0]++;//乙胜且此时出现的是布
		}
		else if (v[i].b == 'C'&&v[i].a == 'J')
		{
			count3++;
			win2[1]++;//乙胜且此时出现的是锤子
		}
		else if (v[i].b == 'J'&&v[i].a == 'B')
		{
			count3++;
			win2[2]++;//乙胜且此时出现的是剪刀
		}
	}
	for (int i = 1; i < 3; i++)
	{
		if (win1[i] > win1[max1])
			max1 = i;//次数最多的手势对应的下标
	}
	for (int i = 1; i < 3; i++)
	{
		if (win2[i] > win2[max2])
			max2 = i;
	}
	cout << count1 << " " << count2 << " " << count3 << endl;
	cout << count3 << " " << count2 << " " << count1 << endl;
	cout << c[max1] << " " << c[max2] << endl;
	return 0;
}