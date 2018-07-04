#include<iostream>
#include<string>
#include<vector>
//注意scanf读入字符的问题！！！在利用scanf读入字符型变量时，它是没有默认的分隔符的，也就是说scanf会把
//空格一起读入。比如说我们要读入a c时，应该这么写scanf("%c %c",&a,&b),而不是用循环两次读入，因为这样
//第二次读入的是空格，而不是c
using namespace std;

typedef struct Mystruct
{
	int score;//满分
	int opt;//选项个数
	int right;//正确选项个数
	int ans;//答案
}Que;


int main()
{
	int n, m;
	cin >> n >> m;
	vector<Que> tem;
	//哈希映射，对应五个选项，比如说a就是00001，b就是00010，c就是00100等等
	int hash[5] = { 1,2,4,8,16 };
	//每道题每个选项的错误次数，注意错误既包括漏选也包括错选
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
			//构造答案对应的整数，比如说正确答案是ac，则其为5，二进制数就是00101
			q.ans += hash[c-'a'];
		}
		tem.push_back(q);
	}

	for (int i = 0; i < n; i++)
	{
		double sum = 0;//总分
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
				answer += hash[cc-'a'];//考生该题的答案
			}
			cin >> c2;
			//将正确答案与考生答案做异或运算，如果正确则异或结果为0，错选或漏选结果就是1
			int el = answer ^ tem[j].ans;
			if (!el)
				sum += tem[j].score;
			else
			{
				//将正确答案与考生答案做或运算，如果结果是正确答案，则说明考生漏选了
				if ((answer | tem[j].ans) == tem[j].ans)
					sum += tem[j].score*0.5;
				//错误选项既包括漏选也包括错选
				for (int k = 0; k < 5; k++)
				{
					//将异或结果与每一个选项做与运算，结果为1则说明该选项错选或漏选
					if (el&hash[k])
						wa[j][k]++;
				}
			}
		}
		printf("%.1f\n", sum);
	}

	int max = 0;
	for (int i = 0; i < m; i++)//找到最大值
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
		for (int i = 0; i < m; i++)//输出题号与选项
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