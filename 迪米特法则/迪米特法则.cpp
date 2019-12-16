// 迪米特法则.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;



class C {
public:
	string name;
	C(string name) {
		this->name = name;
	}
	~C() = default;
	void work() const
	{
		cout << (name + "把这件事做好了");
	}
};

class B {
private: string name;
public:
	B(string name) {
		this->name = name;
	}
	~B() = default;

	C getC(string name) {
		return C(name);
	}

	void work() {
		C c = getC("王五");
		c.work();
	}
};

class A
{
public:
	string name;

};

int main()
{
    std::cout << "Hello World!\n";
}

