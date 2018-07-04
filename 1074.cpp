#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string s, a, b,res;
	cin >> s >> a >> b;

	reverse(a.begin(), a.end());//��������������Ʊ�ת
	reverse(b.begin(), b.end());
	reverse(s.begin(), s.end());
	//���������������Ȳ��ȵ��������0���в���
	if (a.length() < b.length())
		a.append(b.length() - a.length(), '0');
	else
		b.append(a.length() - b.length(), '0');
	
	int len = (a.length() > b.length()) ? a.length() : b.length();
	//carryΪ���ƣ�sumΪÿһλ�Ľ��
	int carry = 0,sum=0,i=0;

	for (; i < len; i++)
	{
		if (s[i] == '0')//���࣬0����ʮ����
		{
			sum = (a[i] - '0' + b[i] - '0' + carry) % 10;
			carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
		}

		else
		{
			sum = (a[i] - '0' + b[i] - '0' + carry) % (s[i] - '0');
			carry = (a[i] - '0' + b[i] - '0' + carry) / (s[i] - '0');
		}
		
		res += sum + '0';
	}

	while(carry)//���λ�Ľ�λ��һ��Ҫ�ǵô���
	{
		if (s[i]!='0')
		{
			sum = carry % (s[i] - '0');
			carry = carry / (s[i] - '0');
		}
		
		else
		{
			sum = carry % 10;
			carry = carry / 10;
		}

		i++;
		res += sum + '0';
	}

	reverse(res.begin(), res.end());//�������ת

	int k = 0;
	//����֮ǰ�����˲�0�������ǰ��λ������0�����ⲿ��0�������
	while (res[k] == '0'&&k<res.size())
		k++;
	//���ܳ��ֺ�Ϊ0���������Ҫ�����������Ȼ���һ�����Ե������
	if (k == res.size())
		cout << "0";
	else
	{
		for (; k < res.size(); k++)
			cout << res[k];
	}

	cout << endl;
	return 0;
}
