#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
//学会用STL容器map
using namespace std;

typedef struct Mystruct
{
	string school;//学校
	int gra;//加权成绩
	int num;//考生人数
}PAT;

bool cmp(PAT p1, PAT p2)//学校从高到低的排序
{
	if (p1.gra > p2.gra)
		return true;
	else if (p1.gra == p2.gra&&p1.num < p2.num)//成绩相同比较人数
		return true;
	else if (p1.gra == p2.gra&&p1.num == p2.num&&p1.school < p2.school)//成绩人数都相同比较学校字典序
		return true;
	else
		return false;
}


int main()
{
	int n,rank=1;
	cin >> n;
	vector<PAT> tem;
	//map需要两个参数，第一个参数是关键字，第二个是关键数对应的值，sum存储该学校的成绩
	map<string, double> sum;
	//num存储该学校的学生人数
	map<string, int> num;

	for (int i = 0; i < n; i++)
	{
		string ID,sch;
		int grade;
		cin>>ID;
		scanf("%d", &grade);//节省时间
		cin >> sch;

		for (int j = 0; j < sch.length(); j++)
			sch[j] = tolower(sch[j]);//tolower将大写字母转化成小写

		//sum初值为0
		if (ID[0] == 'T')//加权成绩
			sum[sch] += grade * 1.5;
		else if (ID[0] == 'A')
			sum[sch] += grade;
		else
			sum[sch] += grade / 1.5;

		//num初值为0
		num[sch]++;//学生人数加1
	}

	//注意i要是auto类型，结束条件是i != sum.end()而不是小于
	for (auto i = sum.begin(); i != sum.end(); i++)
	{
		PAT p;
		//map中两个关键字分别是i->first，i->second，其中第二个关键字用数组方式取出也可以
		p.school = i->first;
		p.gra = sum[i->first];
		p.num = num[i->first];
		tem.push_back(p);
	}
	sort(tem.begin(), tem.end(), cmp);//排序

	printf("%d\n",tem.size());
	cout << "1 " << tem[0].school << " " << tem[0].gra << " " << tem[0].num << endl;
	for (int i = 1; i < tem.size(); i++)
	{
		//排名存在并列的情况，如果这个学校和前一个学校成绩相同（并列）则排名不变，否则排名为其数组下标加1
		if (tem[i].gra != tem[i - 1].gra)
			rank = i + 1;
		cout << rank << " " << tem[i].school << " " << tem[i].gra << " " << tem[i].num << endl;
	}

	return 0;
}