// 模板方法模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "CaffeineBeverage.h"
int main()
{
	Tea* tea = new Tea();
	Coffee* coffee = new Coffee();

	std::cout << "\nMaking tea...\n";
	tea->prepareRecipe();

	std::cout << "\nMaking coffee...\n";
	coffee->prepareRecipe();

	delete tea;
	delete coffee;

}


