#pragma once
#include"observer.h"
#include"weathernow.h"
#include"maxmintemp.h"
#include"weatherforecast.h"
#include"observerlist.h"
class WeatherData
{
private:
	observerlist list;
public:
	WeatherData() {}
	void insertObserver(observer* newobserver) {
		list.insertnode(newobserver);
	}
	void deleteobserver(observer* dobserver) {
		list.deletenode(dobserver);
	}
	void updateData(int temp, float humidity, float wind) {
		list.navigation(temp, humidity, wind);
	}
};

