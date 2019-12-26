// 原型模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "prototype.h"
#include "concrete_prototype.h"
#include "Resume.h"
using namespace std;

int main()
{

	Resume* resume = new  Resume("resume");

	resume->sex = "男";
	resume->age = "23";
	resume->time_area = "2019-2020";
	resume->company = "g";
	resume->set_work("2010", "3333");
	resume->work_experince.work_time = "2010";
	resume->work_experince.work_addr = "333";

	Resume* resume2 = resume->clone();
	resume2->name = "resume2";
	// resume2->work_experince_p->work_time = "20177";
	// resume2->work_experince_p->work_addr = "444";
	// resume2->set_work("201022", "333322");

	Resume* resume3 = resume2->clone();
	resume3->name = "resume3";
	// resume3->work_experince_p->work_time = "20177999";
	// resume3->work_experince_p->work_addr = "555";
	resume3->set_work("201033", "333336666652223");
	// resume3->name = "4444";

	

	resume2->age = "34";
	resume2->time_area = "2020-2026";

	resume->display();
	
	resume2->display();
	
	resume3->display();
	cout << &resume->work_experince_p->work_time << endl;
	cout << &resume2->work_experince_p->work_time << endl;
	// cout << &resume3->work_experince << endl;

	
	delete resume;



	return 0;
}


