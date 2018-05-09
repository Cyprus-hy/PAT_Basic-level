#include<iostream>

using namespace std;

int main()
{
	int num[2002] = { 0 }, count = 0;
	do
	{
		cin >> num[count];
		count++;
	}while (cin.get() != '\n');//用do while读入会比较好
	if (num[count - 1] == 0)//首先判断最后一位是否为0
	{
		if (count == 2)//零多项式
			cout << "0 0" << endl;
		else
		{
			for (int i = 0; i < count - 4; i += 2)
				cout << num[i] * num[i + 1] << " " << num[i + 1] - 1 << " ";
			cout << num[count - 4] * num[count - 3] << " " << num[count - 3] - 1 << endl;//最后的常数项不输出
		}
	}
	else
	{
		for (int i = 0; i < count-2 ; i += 2)
			cout << num[i] * num[i + 1] << " " << num[i + 1] - 1 << " ";
		cout << num[count - 2] * num[count - 1] << " " << num[count - 1] - 1 << endl;//输出所有项
	}
	return 0;
}