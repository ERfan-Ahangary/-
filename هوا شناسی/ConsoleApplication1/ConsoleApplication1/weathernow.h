#pragma once
#include<iostream>
#include"observer.h"
class weathernow:public observer
{
private:
	int m_temp;
	int m_wind;
	int m_humidity;
public:
	int tempnow() {
		return m_temp;
	}
	int humiditynow() {
		return m_humidity;
	}
	int windnow() {
		return m_wind;
	}
	void printAllData() {
		std::cout << "temp now:" << m_temp<<std::endl;
		std::cout << "humidity now:" << m_humidity <<std:: endl;
		std::cout << "wind now:" << m_wind;
	}
private:
	void onchanged(int temp, float humidity, float wind)override{
		m_temp = temp;
		m_wind = wind;
		m_humidity = humidity;
	}
};

