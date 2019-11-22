#pragma once
#include "prototype.h"
#include <iostream>
#include <string>

using namespace std;

// �����
class SunWuKong : public Monkey
{
public:
	SunWuKong(string name) { m_strName = name; }
	~SunWuKong() = default;

	// �������캯��
	SunWuKong(const SunWuKong& other)
	{
		m_strName = other.m_strName;
	}
	Monkey* Clone() override
	{
		// ���ÿ������캯��
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