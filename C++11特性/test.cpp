#include "pch.h"
#include <iostream>
#include <functional>
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


TEST(智能指针, auto_ptr)
{
	auto_ptr<string> ps(new string("aaaaa"));
	cout << ps.get()->c_str() << endl;
}

TEST(智能指针, 三个指针)
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

TEST(智能指针, auto_ptr测试)
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
	pwin = films[2]; // films[2] loses ownership. 将所有权从films[2]转让给pwin，此时films[2]不再引用该字符串从而变成空指针

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

TEST(智能指针, auto_ptr测试1)
{
	// unique_ptr<string> p3(new string("auto"));   //#4
	// unique_ptr<string> p4;                       //#5
	// 	p4 = p3;

	unique_ptr<string> ps;
	ps = demo("Uniquely special");

	cout << ps->c_str() << endl;
}

TEST(智能指针, shared_ptr)
{
	shared_ptr<string> sp1(new string("1111"));
	shared_ptr<string> sp2 = make_shared<string>("22222");
}

void fun(int i)
{
	cout << i << endl;
}

TEST(循环测试, 测试for)
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	for_each(v.begin(), v.end(), fun);
	for_each(v.begin(), v.end(), [](int i)-> void { cout << i << " "; });


}

TEST(匿名函数, 1)
{
	int a;
	int b = 7;
	int c = 4;
	auto my_lambda_func = [b, c](int x, int y)->int
	{
		cout << b << endl;
		int z = x + y;
		return z;
	};
	cout << my_lambda_func(1, 3) << endl;

}

TEST(STRING, find)
{
	string path = "/home/ttt";
	int v=  path.find_last_of('a');
	cout << v << endl;;

}

// void f(int i) { std::cout << "1111: " << i << "\n"; }
void f(int& i)
{
	std::cout << "lvalue ref: " << i << "\n";

}
void f(int&& i)
{
	std::cout << "rvalue ref: " << i << "\n";
}
int getValue()
{
	int ii = 10;
	return ii;
}
int getValue(int &t)
{
	int ii = 10;
	return ii;
}
TEST(右值引用,1)
{
	auto i = 77;
	int* i1 = nullptr;
	
	int a[5] = { 1,2,3,4,5 };
	f(i);    // lvalue ref called
	f(99);   // rvalue ref called
	cout << getValue();
	int ccc = getValue(*i1);
	int ccc2 = getValue(i);
	int&& ccc1 = getValue();
	//
	// f(std::move(i));  // 稍后介绍

}


void f1(int i) {
	std::cout << "f is called, i = " << i << ".\n";
}

TEST(回调函数, 基本回调函数)
{
	function<void(int)> callback = std::bind(&f1, std::placeholders::_1);
	callback(1);

}



class A {
private:
	int j;
public:
	A()
	{
		j = 1;
	}
	void f(int i, function<void(int,int)> cbk)
	{
		std::cout << "A::f is called, i = " << i << ", j = " << j << ".\n";

		cbk(i,j);
	}

};

void f2(int i,int j) {
	std::cout << "**************** " << i << ".\n";
}

TEST(回调函数, 回调对象中的函数)
{
	shared_ptr<A> a1 = make_shared<A>();
	function<void(int,int)> f_bck = bind(&f2, placeholders::_1,placeholders::_2);
	// function<void(int, int)> f_bck = f2;
	f_bck(2222, 666);


	A a;
	a.f(111, &f2);

	const function<void(int, function<void(int,int)>)> callback = std::bind(&A::f, &a, placeholders::_1,placeholders::_2);
	
	callback(222,&f2);
	int num = 33;
	int num1 = 34443;

	callback(444, [=](int x, int y)
		{
			cout << "------" << num << endl;
			cout << "------" << num1 << endl;
		});
}

// typedef std::function<void(int, int)> Fun;
class B {
public:
	void call(int a, function<void(int, int)>  f)
	{
		f(a, 2);
	}
};

class Test {
public:
	void callback(int a, int b)
	{
		cout << a << "+" << b << "=" << a + b << endl;
	}

	void bind()
	{
		function<void(int, int)>  fun = std::bind(&Test::callback, this, placeholders::_1, placeholders::_2);
		B b;
		b.call(1, fun);
	
	}

};

TEST(回调函数, 回调对象中的函数1)
{
	// shared_ptr<A> a = make_shared<A>();
	// function<void(int)> f_bck = bind(&f2, placeholders::_1);
	
	// a.f(111, f2);
	// const function<void(int, function<void(int)>)> callback = std::bind(&A::f, &a, placeholders::_1,placeholders::_2);

	
}