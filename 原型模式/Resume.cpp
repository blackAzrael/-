#include "Resume.h"
#include <utility>





Resume::Resume(string name)
{
	this->name = std::move(name);
	cout << "执行构造函数" << endl;
	work_experince_p = new WorkExperince;
}

// Resume::~Resume()= default;

Resume* Resume::clone()
{
	return new Resume(*this);
}

void Resume::display() const
{

	cout << "姓名 " << name << endl;
	cout << "性别 " << sex << endl;
	cout << "年龄 " << age << endl;
	cout << "地点 " << time_area << endl;
	cout << "公司 " << company << endl;
	cout << "work_time_p " << work_experince_p->work_time << endl;
	cout << "work_addr_p " << work_experince_p->work_addr << endl;
	cout << "work_time " << work_experince.work_time << endl;
	cout << "work_addr " << work_experince.work_addr<< endl;
	cout << endl;
}

void Resume::set_work(string time,string addr) 
{
	work_experince.work_addr = addr;
	work_experince.work_time = time;
	work_experince_p->work_addr = std::move(addr);
	work_experince_p->work_time = std::move(time);

}

// void Resume::set_persion_info(string sex, string age)
// {
// 	this->sex = std::move(sex);
// 	this->age = std::move(age);
// }
//
// void Resume::set_work_experence(string time_area, string company)
// {
// }
