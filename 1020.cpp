#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//注意属性全用double
typedef struct Mystruct//月饼
{
	double num;//总库存
	double sale;//总售价
	double price;//单价
}mooncake;

bool compare(mooncake a,mooncake b)
{
	if (a.price >= b.price)
		return true;
	else
		return false;
}

int main()
{
	vector<mooncake> cake;

	int n,need,storage=0;
	cin >> n>>need;

	for (int i = 0; i < n; i++)//总库存
	{
		mooncake mc;
		double tem;
		cin >> tem;
		mc.num = tem;
		mc.price=0;
		mc.sale = 0;
		cake.push_back(mc);
		storage += tem;
	}

	for (int i = 0; i < n; i++)//总价
	{
		double tem;
		cin >> tem;
		double d = tem/ cake[i].num;
		cake[i].sale = tem;
		cake[i].price = d;
	}

	//按月饼单价排序
	sort(cake.begin(), cake.end(),compare);
	double sum = 0;
	int pos = 0;

	do
	{
		if (need <= cake[pos].num)//当前月饼总量大于等于市场需求量
		{
			sum += need * cake[pos].price;
			need = 0;
			storage -= need;
		}

		//当前月饼总量小于市场需求量
		else
		{
			sum += cake[pos].sale;
			need -= cake[pos].num;
			storage -= cake[pos].num;
		}
		pos++;
	} while (need>0&&storage>0);//注意总库存小于总需求量的情况

	printf("%.2f\n", sum);
	return 0;
}