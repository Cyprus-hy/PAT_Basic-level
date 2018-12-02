#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//ע������ȫ��double
typedef struct Mystruct//�±�
{
	double num;//�ܿ��
	double sale;//���ۼ�
	double price;//����
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

	for (int i = 0; i < n; i++)//�ܿ��
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

	for (int i = 0; i < n; i++)//�ܼ�
	{
		double tem;
		cin >> tem;
		double d = tem/ cake[i].num;
		cake[i].sale = tem;
		cake[i].price = d;
	}

	//���±���������
	sort(cake.begin(), cake.end(),compare);
	double sum = 0;
	int pos = 0;

	do
	{
		if (need <= cake[pos].num)//��ǰ�±��������ڵ����г�������
		{
			sum += need * cake[pos].price;
			need = 0;
			storage -= need;
		}

		//��ǰ�±�����С���г�������
		else
		{
			sum += cake[pos].sale;
			need -= cake[pos].num;
			storage -= cake[pos].num;
		}
		pos++;
	} while (need>0&&storage>0);//ע���ܿ��С���������������

	printf("%.2f\n", sum);
	return 0;
}