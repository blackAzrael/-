#include"pch.h"
#include <iostream>
using namespace std;

TEST(leecode,717)
{
	std::vector<bool> bits = { 1,1,1,1,1,0 };

	for (int i = 0; i < bits.size(); i++)
	{
		if (bits[i] == 1)
		{
			i++;
			if (i == bits.size() - 1)
			{
				// return false;
				std::cout << false << std::endl;
				return;
			}
		}
	}
	cout << true << endl;
}
TEST(leecode,67)
{
	string a = "111111111";
	string b = "1111101111";
	int diff = 0;
	string temp;
	if (a.size()>b.size())
	{
		diff = a.size() - b.size();
		for (int i = 0; i < diff; ++i)
		{
			temp += "0";
		}
		b = temp + b;
	}
	else
	{
		diff = b.size() - a.size();
		for (int i = 0; i < diff; ++i)
		{
			temp += "0";
		}
		a = temp + a;
	}
	for (int i = a.size()-1; i >=0; --i)
	{
		a[i] = a[i] + b[i] - '0';
		
	}
	cout << a << endl;
	int len = a.size();
	int i = len - 1;
	while (len)
	{
		if (i > 0)
		{
			if (a[i] == '2')
			{
				a[i] = '0';
				a[i - 1] = a[i - 1] + 1;
				continue;
			}
			if (a[i] == '3')
			{
				a[i] = '1';
				a[i - 1] = a[i - 1] + 1;
			}
			
		}
		else
		{
			if (a[i] == '2')
			{
				a[i] = '0';
				a="1"+a;
			}
			if (a[i] == '3')
			{
				a[i] = '1';
				a = "1" + a;
			}
		}
		
		
		len--;
		i--;
	}
	cout << a << endl;
	
}