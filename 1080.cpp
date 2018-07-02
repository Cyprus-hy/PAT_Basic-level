#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

typedef struct Mystruct
{
	string name;
	int p;//ƽʱ��̳ɼ�
	int mid;//����
	int final;//��ĩ
	int res;//�����ɼ�
}Stu;

bool cmp(Stu s1, Stu s2)//�������ɼ����򣬲��а�ѧ�ŵ�����
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
	map<string, int> gp;//ƽʱ��̳ɼ�
	map<string, int> gm;//����
	map<string, int> gf;//��ĩ
	vector<Stu> temp;//�ϸ��ѧ��

	for (int i = 0; i < p; i++)
	{
		string ID;
		int a;
		cin >> ID>>a ;
		if(a>=200)//ֻ����ƽʱ�ɼ����ڵ���200��
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

	for (map<string,int>::iterator i = gp.begin(); i != gp.end(); i++)//����ƽʱ��̳ɼ���map
	{
		int g = gf[i->first];
		if (gm[i->first] > gf[i->first])//���д�����ĩ
			g = int (gm[i->first] * 0.4 + 0.6*gf[i->first] + 0.5);

		if (g >= 60)//�ϸ������
		{
			Stu s = {i->first,i->second,-1,gf[i->first],g};

			if (gm[i->first])//���гɼ����ܲ�����
				s.mid = gm[i->first];

			temp.push_back(s);
		}
	}

	sort(temp.begin(), temp.end(), cmp);//����

	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i].name << " ";
		printf("%d %d %d %d\n", temp[i].p, temp[i].mid, temp[i].final, temp[i].res);
	}
	return 0;
}