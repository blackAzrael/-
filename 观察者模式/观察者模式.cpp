// 观察者模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include "WeatherData.hpp"
#include "CurrentConditionsDisplay.hpp"

using namespace std;
void WeatherStationWithFunctions()
{
	auto w = std::make_shared<WeatherData>();
	CurrentConditionsDisplay* currentDisplay = new CurrentConditionsDisplay(w);
	currentDisplay->registerObserver();
	CurrentConditionsDisplay2* currentDisplay2 = new CurrentConditionsDisplay2(w);
	currentDisplay2->registerObserver();

	// 只要主题的值改变了，就会通知观察者即CurrentConditionsDisplay，然后观察者打印出来
	w->setMeasurements(80, 65, 30.4f);
	w->setMeasurements(82, 70, 29.2f);
	w->setMeasurements(78, 90, 29.2f);
	delete currentDisplay;
}

int main()
{
	WeatherStationWithFunctions();
}