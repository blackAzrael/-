#pragma once
// ����

class Monkey
{
public:
	Monkey() = default;
	virtual ~Monkey() = default;
	virtual Monkey* Clone() = 0;  // ��¡
	virtual void Play() = 0;  // ��ˣ
	virtual void Play1(std::string game) = 0;  // ��ˣ
};