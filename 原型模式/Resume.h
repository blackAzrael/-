#pragma once
#include <iostream>
using namespace std;


//工作经历类
class WorkExperince
{
public:
	WorkExperince()
	{
		cout << "WorkExperince 被构造" << endl;
	}
	~WorkExperince()
	{
		cout << "WorkExperince 被析构" << endl;
	}

public:
	string work_time;
	string work_addr;
};

//简历类
class Resume
{
public:
	Resume(string name);
	~Resume()
	{
		cout << "Resume 被析构" << this->name<< endl;
		delete work_experince_p;
	}
	 Resume(const Resume& res): work_experince_p(res.work_experince_p)
	 {
	 	cout << "调用拷贝构造函数" << endl;
	 	 //res.work_experince = new WorkExperince();
	 	
	 }

public:
	WorkExperince* work_experince_p;

	WorkExperince work_experince;
	string name;
	string sex;
	string age;
	string time_area;
	string company;
	
public:
	//设置工作经历
	// void set_persion_info(string sex, string age);
	// void set_work_experence(string time_area, string company);
	Resume* clone();
	void  display() const;
	void  set_work(string time,string addr) ;

};

