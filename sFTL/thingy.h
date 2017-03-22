#pragma once

class Stat()
{
private:
	int8_t value;
	int8_t minValue=0;
	int8_t maxValue=100;

	check()
	{
		if(value>maxValue)	value = maxValue;
		if(value<minValue)	value = minValue;
	};
public:
	Stat(void)=default;
	Stat(int8_t value)
	{
		this->value = value;
	};
	Stat(int8_t value,int8_t minValue,int8_t maxValue)
	{
		this->value = value;
		this->minValue = minValue;
		this->maxValue = maxValue;
	};

	int8_t get()	{	return value;	}
	void set(int8_t value)	{	this->value = value;	}
	void setRange(int8_t minValue,int8_t maxValue)	{	this->minValue = minValue; this->maxValue = maxValue;	check();	}
	void add(int8_t more)	{	this->value += more;	check();	}
};