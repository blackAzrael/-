#pragma once
#include <iostream>
using namespace std;
class CaffeineBeverage
{
public:
	virtual ~CaffeineBeverage() {}

	//准备配方
	void prepareRecipe() {
		boilWater();
		brew();
		pourInCup();
		if (customerWantsCondiments())
			addCondiments();
	}
	//酿造
	virtual void brew() = 0;
	//添加调料
	virtual void addCondiments() = 0;

	void boilWater() {
		std::cout << "Boiling water\n";
	}

	void pourInCup() {
		std::cout << "Pouring into cup\n";
	}

	virtual bool customerWantsCondiments() {
		cout << "是否加糖" << endl;
		return true;
	}
	
};

class Coffee : public CaffeineBeverage {
public:
	~Coffee() {}

	void brew() {
		std::cout << "Dripping Coffee through filter\n";
	}

	void addCondiments() override
	{
		std::cout << "Adding Sugar and Milk\n";
	}

	bool customerWantsCondiments() override
	{
		char c;
		std::cout << "Do you want to add condiments?\n";
		std::cin >> c;

		if (c == 'y')
			return true;
		else
			return false;
	}


};

class Tea : public CaffeineBeverage {
public:
	~Tea() {}

	void brew() {
		std::cout << "Steeping the tea\n";
	}

	void addCondiments() override
	{
		std::cout << "Adding Lemon\n";
	}

	bool customerWantsCondiments() override
	{
		char c;
		std::cout << "Do you want to add condiments?\n";
		std::cin >> c;
	
		if (c == 'y')
			return true;
		else
			return false;
	}


};
