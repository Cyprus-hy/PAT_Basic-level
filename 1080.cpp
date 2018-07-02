#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

typedef struct Mystruct
{
	string name;
	int p;//平时编程成绩
	int mid;//期中
	int final;//期末
	int res;//总评成绩
}Stu;

bool cmp(Stu s1, Stu s2)//按总评成绩排序，并列按学号递增排
{
	if (s1.res > s2.res)
		return true;
	else if (s1.res == s2.res&&s1.name < s2.name)
		return true;
	else
		return false;
}

int main()
{
	int p, m, n;
	cin >> p >> m >> n;
	map<string, int> gp;//平时编程成绩
	map<string, int> gm;//期中
	map<string, int> gf;//期末
	vector<Stu> temp;//合格的学生

	for (int i = 0; i < p; i++)
	{
		string ID;
		int a;
		cin >> ID>>a ;
		if(a>=200)//只处理平时成绩大于等于200的
			gp[ID] = a;
	}

	for (int i = 0; i < m; i++)
	{
		string ID;
		int a;
		cin >> ID>>a ;
		gm[ID] = a;
	}

	for (int i = 0; i < n; i++)
	{
		string ID;
		int a;
		cin >> ID>>a;
		gf[ID] = a;
	}

	for (map<string,int>::iterator i = gp.begin(); i != gp.end(); i++)//遍历平时编程成绩的map
	{
		int g = gf[i->first];
		if (gm[i->first] > gf[i->first])//期中大于期末
			g = int (gm[i->first] * 0.4 + 0.6*gf[i->first] + 0.5);

		if (g >= 60)//合格的条件
		{
			Stu s = {i->first,i->second,-1,gf[i->first],g};

			if (gm[i->first])//期中成绩可能不存在
				s.mid = gm[i->first];

			temp.push_back(s);
		}
	}

	sort(temp.begin(), temp.end(), cmp);//排序

	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i].name << " ";
		printf("%d %d %d %d\n", temp[i].p, temp[i].mid, temp[i].final, temp[i].res);
	}
	return 0;
}