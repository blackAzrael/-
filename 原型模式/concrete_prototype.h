#pragma once
#include "prototype.h"
#include <iostream>
#include <string>

using namespace std;

// 孙悟空
class SunWuKong : public Monkey
{
public:
	SunWuKong(string name) { m_strName = name; }
	~SunWuKong() = default;

	// 拷贝构造函数
	SunWuKong(const SunWuKong& other)
	{
		m_strName = other.m_strName;
	}
	Monkey* Clone() override
	{
		// 调用拷贝构造函数
		return new SunWuKong(*this);
	}
	void Play() override
	{
		cout << m_strName << " play Golden-Hoop-Stick" << endl;
	}
	void Play1(string game) override
	{
		cout << m_strName << game << endl;
	}


private:
	string m_strName;
};