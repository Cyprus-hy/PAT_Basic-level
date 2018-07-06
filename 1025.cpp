#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

typedef struct Mystruct
{
	int address;//物理地址
	int data;//数据
	int next;//下一个元素的地址
}List;


int main()
{
	int first,n, k,m=0,sum=0;
	cin >> first >> n >> k;
	//数组下标就是节点的地址
	List temp[100005];
	int count = n / k;
	List l;
	vector<vector<List>> v(count+1);//二维vector存储链表节点

	for (int i = 0; i < n; i++)
	{
		List t;
		scanf("%d %d %d", &t.address, &t.data, &t.next);
		temp[t.address] = t;
	}

	//每k个节点存储在v的一行中
	for (int i = 0; i < count; i++)
	{
		for (; m <(i+1)*k; m++)
		{
			//可能有不在链表上的节点
			if (first == -1)
				break;
	
			l = temp[first];
			v[i].push_back(l);
			first = l.next;
			sum++;
		}

		if (first == -1)
			break;
	}
	//剩下的不足k个节点也放进v中
	for (; m < n; m++)
	{
		if (first == -1)
			break;
		
		l = temp[first];
		v[count].push_back(l);
		first = l.next;
		sum++;
	}

	count = sum / k;//sum是实际的节点个数

	//sum刚好能整除k,特别注意输入的首地址是-1的情况，此时无输出，不然最后一个测试点过不了
	if (sum%k == 0&&sum)
	{
		for (int i = 0; i < count; i++)
		{
			//逆序输出
			for (int j = k - 1; j >= 0; j--)
			{
				//输出的next值是前一个节点的地址
				if(j)
					printf("%05d %d %05d\n", v[i][j].address, v[i][j].data, v[i][j - 1].address);
				else
				{
					//如果是每一行的第一个元素，它的next值是下一行最后一个元素的地址
					if(i!=count-1)
						printf("%05d %d %05d\n", v[i][0].address, v[i][0].data, v[i + 1][k - 1].address);
					//如果是最后一行的第一个元素，它的next值是-1
					else
						printf("%05d %d -1\n", v[count-1][0].address, v[count-1][0].data);
				}
					
			}
				
		}
	}
	//sum不能整除k
	else if(sum%k != 0 && sum)
	{
		for (int i = 0; i < count; i++)
		{
			//逆序输出
			for (int j = k - 1; j >= 0; j--)
			{
				//输出的next值是前一个节点的地址
				if (j)
					printf("%05d %d %05d\n", v[i][j].address, v[i][j].data, v[i][j - 1].address);
				else
				{
					//如果是每一行的第一个元素，它的next值是下一行最后一个元素的地址
					if(i!=count-1)
						printf("%05d %d %05d\n", v[i][0].address, v[i][0].data, v[i + 1][k - 1].address);
					//如果是倒数第二行的第一个元素，它的next值是最后一行的第一个元素
					else
						printf("%05d %d %05d\n", v[i][0].address, v[i][0].data, v[i + 1][0].address);
				}
						
			}

		}
		//顺序输出最后的不足k个的元素
		for(int i=0;i<v[count].size()-1;i++)
			printf("%05d %d %05d\n", v[count][i].address, v[count][i].data, v[count][i+1].address);
		//最后一个元素next值为-1
		printf("%05d %d -1\n", v[count][v[count].size() - 1].address, v[count][v[count].size() - 1].data);
	}

	return 0;
}
