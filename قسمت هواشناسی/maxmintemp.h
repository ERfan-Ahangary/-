#pragma once
#include<iostream>
#include<vector>
#include"observer.h"
using namespace std;
class maxmintemp:public observer
{
private:
	vector<int> templist;
public:
	int maxTemp() {
		int save = templist[0];
		for (size_t i = 0; i < templist.size(); i++)
		{
			if (templist[i] > save)
			{
				save = templist[i];
			}
		}
		return save;
	}
	int minTemp() {
		int save=templist[0];
		for (size_t i = 0; i <templist.size(); i++)
		{
			if (templist[i]<save)
			{
				save = templist[i];
			}
		}
		return save;
	}
	void printAllData() {
		int max = maxTemp();
		int min = minTemp();
		std::cout << "max temp:" << max<<std::endl;
		std::cout << "min temp:" << min;
	}
private:
	void onchanged(int temp, float humidity, float wind)override {
		templist.push_back(temp);
	}
};

