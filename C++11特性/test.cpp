#include "pch.h"
#include <iostream>
using namespace std;


TEST(TestCaseName, TestName)
{
	EXPECT_EQ(1, 1);

}

class report
{
private:
	std::string str;
public:
	report(const std::string s) : str(s)
	{
		std::cout << "Object created.\n";
	}

	~report()
	{
		std::cout << "Object deleted.\n";
	}

	void comment() const
	{
		std::cout << str << "\n";
	}
};


TEST(����ָ��, auto_ptr)
{
	auto_ptr<string> ps(new string("aaaaa"));
	cout << ps.get()->c_str() << endl;
}

TEST(����ָ��, ����ָ��)
{
	{
		std::auto_ptr<report> ps(new report("using auto ptr"));
		ps->comment();
	}

	{
		std::shared_ptr<report> ps(new report("using shared ptr"));
		ps->comment();
	}

	{
		std::unique_ptr<report> ps(new report("using unique ptr"));
		ps->comment();
	}
}

TEST(����ָ��, auto_ptr����)
{
	auto_ptr<string> films[5] =
	{
		auto_ptr<string>(new string("Fowl Balls")),
		auto_ptr<string>(new string("Duck Walks")),
		auto_ptr<string>(new string("Chicken Runs")),
		auto_ptr<string>(new string("Turkey Errors")),
		auto_ptr<string>(new string("Goose Eggs"))
	};
	auto_ptr<string> pwin;
	pwin = films[2]; // films[2] loses ownership. ������Ȩ��films[2]ת�ø�pwin����ʱfilms[2]�������ø��ַ����Ӷ���ɿ�ָ��

	// unique_ptr<string> pwin;
	// pwin = films[2];

	cout << "The nominees for best avian baseballl film are\n";
	for (int i = 0; i < 5; ++i)
		cout << *films[i] << endl;
	cout << "The winner is " << *pwin << endl;
	cin.get();
}


unique_ptr<string> demo(const char* s)
{
	unique_ptr<string> temp(new string(s));
	return temp;
}

TEST(����ָ��, auto_ptr����1)
{
	// unique_ptr<string> p3(new string("auto"));   //#4
	// unique_ptr<string> p4;                       //#5
	// 	p4 = p3;

	unique_ptr<string> ps;
	ps = demo("Uniquely special");

	cout << ps->c_str() << endl;
}

TEST(����ָ��, shared_ptr)
{
	shared_ptr<string> sp1(new string("1111"));
	shared_ptr<string> sp2 = make_shared<string>("22222");
}

void fun(int i)
{
	cout << i << endl;
}

TEST(ѭ������, ����for)
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	for_each(v.begin(), v.end(), fun);
	for_each(v.begin(), v.end(), [](int i)-> void { cout << i << " "; });


}

TEST(��������, 1)
{
	int a;
	int b = 7;
	int c = 4;
	auto my_lambda_func = [b, c](int x, int y)->int
	{
		cout << b << endl;
		int z = x + y; return z;
	};
	cout << my_lambda_func(1, 3) << endl;

}