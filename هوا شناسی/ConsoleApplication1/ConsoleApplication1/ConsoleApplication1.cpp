
#include <iostream>
#include"WeatherData.h"
#include"IArray.h"
#include"Array.h"
#include"weathernow.h"
#include"observer.h"
#include"weatherforecast.h"
#include"maxmintemp.h"
using namespace std;
int main()
{
	weathernow* now=new weathernow();
	//---------------------------------
	maxmintemp* maxmin = new maxmintemp();
	//---------------------------------
	weatherforecast* forecast = new weatherforecast();
	//---------------------------------
	WeatherData weather;
	weather.insertObserver(now);
	weather.insertObserver(maxmin);
	weather.insertObserver(forecast);
	weather.updateData(1, 20, 15);
	weather.updateData(2, 20, 15);
	weather.updateData(12, 20, 15);
	cout <<endl << "weather now:" << endl;
	now->printAllData();
	cout << endl << "--------------------" << endl << "maxmin:" << endl;
	maxmin->printAllData();
	cout << endl << "--------------------" << endl << "forecast:" << endl;
	forecast->ForecastTemp();
	cout << endl << "----------------------------";
	weather.deleteobserver(now);
	//-----------------------------------
	
}
