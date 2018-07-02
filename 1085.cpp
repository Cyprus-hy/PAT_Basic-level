#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
//ѧ����STL����map
using namespace std;

typedef struct Mystruct
{
	string school;//ѧУ
	int gra;//��Ȩ�ɼ�
	int num;//��������
}PAT;

bool cmp(PAT p1, PAT p2)//ѧУ�Ӹߵ��͵�����
{
	if (p1.gra > p2.gra)
		return true;
	else if (p1.gra == p2.gra&&p1.num < p2.num)//�ɼ���ͬ�Ƚ�����
		return true;
	else if (p1.gra == p2.gra&&p1.num == p2.num&&p1.school < p2.school)//�ɼ���������ͬ�Ƚ�ѧУ�ֵ���
		return true;
	else
		return false;
}


int main()
{
	int n,rank=1;
	cin >> n;
	vector<PAT> tem;
	//map��Ҫ������������һ�������ǹؼ��֣��ڶ����ǹؼ�����Ӧ��ֵ��sum�洢��ѧУ�ĳɼ�
	map<string, double> sum;
	//num�洢��ѧУ��ѧ������
	map<string, int> num;

	for (int i = 0; i < n; i++)
	{
		string ID,sch;
		int grade;
		cin>>ID;
		scanf("%d", &grade);//��ʡʱ��
		cin >> sch;

		for (int j = 0; j < sch.length(); j++)
			sch[j] = tolower(sch[j]);//tolower����д��ĸת����Сд

		//sum��ֵΪ0
		if (ID[0] == 'T')//��Ȩ�ɼ�
			sum[sch] += grade * 1.5;
		else if (ID[0] == 'A')
			sum[sch] += grade;
		else
			sum[sch] += grade / 1.5;

		//num��ֵΪ0
		num[sch]++;//ѧ��������1
	}

	//ע��iҪ��auto���ͣ�����������i != sum.end()������С��
	for (auto i = sum.begin(); i != sum.end(); i++)
	{
		PAT p;
		//map�������ؼ��ֱַ���i->first��i->second�����еڶ����ؼ��������鷽ʽȡ��Ҳ����
		p.school = i->first;
		p.gra = sum[i->first];
		p.num = num[i->first];
		tem.push_back(p);
	}
	sort(tem.begin(), tem.end(), cmp);//����

	printf("%d\n",tem.size());
	cout << "1 " << tem[0].school << " " << tem[0].gra << " " << tem[0].num << endl;
	for (int i = 1; i < tem.size(); i++)
	{
		//�������ڲ��е������������ѧУ��ǰһ��ѧУ�ɼ���ͬ�����У����������䣬��������Ϊ�������±��1
		if (tem[i].gra != tem[i - 1].gra)
			rank = i + 1;
		cout << rank << " " << tem[i].school << " " << tem[i].gra << " " << tem[i].num << endl;
	}

	return 0;
}