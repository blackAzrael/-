#pragma once
// ºï×Ó

class Monkey
{
public:
	Monkey() = default;
	virtual ~Monkey() = default;
	virtual Monkey* Clone() = 0;  // ¿ËÂ¡
	virtual void Play() = 0;  // ÍæË£
	virtual void Play1(std::string game) = 0;  // ÍæË£
};