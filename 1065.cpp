#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	map<int, int> tem;//�������ݷֱ��Ӧ�Ű��µı��
	map<int, int> peo;//�ؼ���Ϊ���£�ֵΪ1����μ�����ξۻ�
	int n, m;
	vector<int> s;//����

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		tem[a] = b;//a�İ�����b��b�İ�����a
		tem[b] = a;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int c;
		cin >> c;
		peo[c]++;//����c�μ�����ξۻ�
	}

	for (auto i = peo.begin(); i != peo.end(); i++)//ѭ������
	{
		if (!tem[i->first])//û�а���
			s.push_back(i->first);
		else if(!peo[tem[i->first]])//�а��µ���û����
			s.push_back(i->first);
	}

	sort(s.begin(), s.end());

	cout << s.size() << endl;
	for (int i = 0; i < s.size(); i++)
	{
		if (i)
			cout << " ";
		printf("%05d", s[i]);
	}

	return 0;
}