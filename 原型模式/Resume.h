#pragma once
#include <iostream>
using namespace std;


//����������
class WorkExperince
{
public:
	WorkExperince()
	{
		cout << "WorkExperince ������" << endl;
	}
	~WorkExperince()
	{
		cout << "WorkExperince ������" << endl;
	}

public:
	string work_time;
	string work_addr;
};

//������
class Resume
{
public:
	Resume(string name);
	~Resume()
	{
		cout << "Resume ������" << this->name<< endl;
		delete work_experince_p;
	}
	 Resume(const Resume& res): work_experince_p(res.work_experince_p)
	 {
	 	cout << "���ÿ������캯��" << endl;
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
	//���ù�������
	// void set_persion_info(string sex, string age);
	// void set_work_experence(string time_area, string company);
	Resume* clone();
	void  display() const;
	void  set_work(string time,string addr) ;

};

