#include<iostream>
#include<vector>

using namespace std;

typedef struct Mystruct
{
	char a;//�׵�
	char b;//�ҵ�
}Game;

int main()
{
	//��¼��ʤƽ���Ĵ�������ʤʱ��ÿ�����ƵĴ�������ʤʱ��ÿ�����ƵĴ���
	int i_num, max1=0,max2=0,count1 = 0, count2 = 0, count3 = 0, win1[3] = { 0 }, win2[3] = { 0 };
	char c[3] = { 'B','C','J' };//���ݼ�¼�ļ���ʤʱ���ִ����������ƶ�Ӧ���±��������
	cin >> i_num;
	vector <Game> v;//��vector�洢
	for (int i = 0; i < i_num; i++)
	{
		Game g;
		cin >> g.a >> g.b;
		v.push_back(g);
	}
	for (int i = 0; i < i_num; i++)
	{
		if (v[i].a == 'B'&&v[i].b == 'C')
		{
			count1++;
			win1[0]++;//��ʤ�Ҵ�ʱ���ֵ��ǲ�
		}
		else if (v[i].a == 'C'&&v[i].b == 'J')
		{
			count1++;
			win1[1]++;//��ʤ�Ҵ�ʱ���ֵ��Ǵ���
		}
		else if (v[i].a == 'J'&&v[i].b == 'B')
		{
			count1++;
			win1[2]++;//��ʤ�Ҵ�ʱ���ֵ��Ǽ���
		}
		else if (v[i].a == v[i].b)
		{
			count2++;//ƽ��
		}
		else if (v[i].b == 'B'&&v[i].a == 'C')
		{
			count3++;
			win2[0]++;//��ʤ�Ҵ�ʱ���ֵ��ǲ�
		}
		else if (v[i].b == 'C'&&v[i].a == 'J')
		{
			count3++;
			win2[1]++;//��ʤ�Ҵ�ʱ���ֵ��Ǵ���
		}
		else if (v[i].b == 'J'&&v[i].a == 'B')
		{
			count3++;
			win2[2]++;//��ʤ�Ҵ�ʱ���ֵ��Ǽ���
		}
	}
	for (int i = 1; i < 3; i++)
	{
		if (win1[i] > win1[max1])
			max1 = i;//�����������ƶ�Ӧ���±�
	}
	for (int i = 1; i < 3; i++)
	{
		if (win2[i] > win2[max2])
			max2 = i;
	}
	cout << count1 << " " << count2 << " " << count3 << endl;
	cout << count3 << " " << count2 << " " << count1 << endl;
	cout << c[max1] << " " << c[max2] << endl;
	return 0;
}