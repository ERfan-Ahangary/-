#pragma once
#include<iostream>
#include"observer.h"
using namespace std;
class weatherforecast:public observer
{
private:
	int m_temp;
	int m_humidity;
	int m_wind;
public:
	int ForecastTemp() {
		int save;
		if (m_humidity>5)
		{
			save = m_temp + 5;
			cout << "Because the humidity is more than 5 the temp increses 5degree";
		}
		else
		{
			cout << "Because the humidity is less than 5 the temp remains contant";
			save = m_temp;
		}
		if (m_wind>10)
		{
			save -= 6;
			cout <<endl<< "Because the wind is more than 10 the temp decreases 6degree";
		}
		else
		{
			cout << endl<< "Because the wind is less than 10 the temp remains contant";
		}
		cout << endl <<"temp forecast:"<< save;
		return save;
	}
private:
	void onchanged(int temp, float humidity, float wind)override {
		m_temp = temp;
		m_wind = wind;
		m_humidity = humidity;
	}
};

