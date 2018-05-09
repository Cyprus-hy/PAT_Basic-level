#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct Mystruct
{
	int ID;
	int de;
	int cai;
	int sum;
}Stu;

bool cmp(Stu s1, Stu s2)//表函数
{
	if (s1.sum > s2.sum)
		return true;
	else if (s1.sum == s2.sum&&s1.de > s2.de)
		return true;
	else if (s1.sum == s2.sum&&s1.de == s2.de&&s1.ID < s2.ID)
		return true;
	else
		return false;
}

int main()
{
	vector<Stu> tem, v1, v2, v3, v4;//用STL容器向量中自带的排序算法
	int n, l, h,count=0,count1=0,count2=0,count3=0,count4=0;
	cin >> n >> l >> h;
	for (int i = 0; i < n; i++)
	{
		Stu s;
		cin >> s.ID >> s.de >> s.cai;
		s.sum = s.cai + s.de;
		tem.push_back(s);//存入向量中
	}
	for (int j = 0; j < n; j++)
	{
		if (tem[j].cai >= l && tem[j].de >= l)//具有录取资格
		{
			count++;//具有录取资格的人数
			if (tem[j].cai >= h && tem[j].de >= h)//德才兼尽
			{
				v1.push_back(tem[j]);
				count1++;//该批次的人数
			}
			else if (tem[j].de >= h && tem[j].cai < h)//第二批录取
			{
				v2.push_back(tem[j]);
				count2++;
			}
			else if (tem[j].cai <= tem[j].de&&tem[j].de < h)//第三批录取
			{
				v3.push_back(tem[j]);
				count3++;
			}
			else//第四批录取
			{
				v4.push_back(tem[j]);
				count4++;
			}
		}
	}
	sort(v1.begin(),v1.end(),cmp);//学会用向量自带的排序函数
	sort(v2.begin(), v2.end(), cmp);
	sort(v3.begin(), v3.end(), cmp);
	sort(v4.begin(), v4.end(), cmp);
	cout << count << endl;
	for (int i = 0; i < count1; i++)//输出，printf比cout快
		printf("%d %d %d\n", v1[i].ID, v1[i].de, v1[i].cai);
	for (int i = 0; i < count2; i++)
		printf("%d %d %d\n", v2[i].ID, v2[i].de, v2[i].cai);
	for (int i = 0; i < count3; i++)
		printf("%d %d %d\n", v3[i].ID, v3[i].de, v3[i].cai);
	for (int i = 0; i < count4; i++)
		printf("%d %d %d\n", v4[i].ID, v4[i].de, v4[i].cai);
	return 0;
}