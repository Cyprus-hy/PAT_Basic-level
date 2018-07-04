#include<iostream>
#include<string>
#include<vector>
//ע��scanf�����ַ������⣡����������scanf�����ַ��ͱ���ʱ������û��Ĭ�ϵķָ����ģ�Ҳ����˵scanf���
//�ո�һ����롣����˵����Ҫ����a cʱ��Ӧ����ôдscanf("%c %c",&a,&b),��������ѭ�����ζ��룬��Ϊ����
//�ڶ��ζ�����ǿո񣬶�����c
using namespace std;

typedef struct Mystruct
{
	int score;//����
	int opt;//ѡ�����
	int right;//��ȷѡ�����
	int ans;//��
}Que;


int main()
{
	int n, m;
	cin >> n >> m;
	vector<Que> tem;
	//��ϣӳ�䣬��Ӧ���ѡ�����˵a����00001��b����00010��c����00100�ȵ�
	int hash[5] = { 1,2,4,8,16 };
	//ÿ����ÿ��ѡ��Ĵ��������ע�����Ȱ���©ѡҲ������ѡ
	int wa[100][5] = { 0 };
	char c;

	for (int i = 0; i < m; i++)
	{
		Que q;
		cin >> q.score >> q.opt >> q.right;
		q.ans = 0;
		for (int j = 0; j < q.right; j++)
		{
			cin >> c;
			//����𰸶�Ӧ������������˵��ȷ����ac������Ϊ5��������������00101
			q.ans += hash[c-'a'];
		}
		tem.push_back(q);
	}

	for (int i = 0; i < n; i++)
	{
		double sum = 0;//�ܷ�
		for (int j = 0; j < m; j++)
		{
			char c1, c2;
			int a;
			cin >> c1 >> a;
			int answer=0;
			for (int k = 0; k < a; k++)
			{
				char cc;
				cin >> cc;
				answer += hash[cc-'a'];//��������Ĵ�
			}
			cin >> c2;
			//����ȷ���뿼������������㣬�����ȷ�������Ϊ0����ѡ��©ѡ�������1
			int el = answer ^ tem[j].ans;
			if (!el)
				sum += tem[j].score;
			else
			{
				//����ȷ���뿼�����������㣬����������ȷ�𰸣���˵������©ѡ��
				if ((answer | tem[j].ans) == tem[j].ans)
					sum += tem[j].score*0.5;
				//����ѡ��Ȱ���©ѡҲ������ѡ
				for (int k = 0; k < 5; k++)
				{
					//���������ÿһ��ѡ���������㣬���Ϊ1��˵����ѡ���ѡ��©ѡ
					if (el&hash[k])
						wa[j][k]++;
				}
			}
		}
		printf("%.1f\n", sum);
	}

	int max = 0;
	for (int i = 0; i < m; i++)//�ҵ����ֵ
	{
		for (int j = 0; j < 5; j++)
		{
			if (wa[i][j] > max)
				max = wa[i][j];
		}
	}

	if (max == 0)
		cout << "Too simple\n";
	else
	{
		for (int i = 0; i < m; i++)//��������ѡ��
		{
			for (int j = 0; j < 5; j++)
			{
				if (wa[i][j] == max)
					printf("%d %d-%c\n", max, i + 1, 'a' + j);
			}
		}
	}
	
	return 0;
}