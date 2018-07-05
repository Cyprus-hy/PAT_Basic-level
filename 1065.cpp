#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	map<int, int> tem;//两个数据分别对应着伴侣的编号
	map<int, int> peo;//关键字为伴侣，值为1代表参加了这次聚会
	int n, m;
	vector<int> s;//单身狗

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		tem[a] = b;//a的伴侣是b，b的伴侣是a
		tem[b] = a;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int c;
		cin >> c;
		peo[c]++;//代表c参加了这次聚会
	}

	for (auto i = peo.begin(); i != peo.end(); i++)//循环遍历
	{
		if (!tem[i->first])//没有伴侣
			s.push_back(i->first);
		else if(!peo[tem[i->first]])//有伴侣但是没有来
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