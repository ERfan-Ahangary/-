#pragma once
#include"observer.h"
#include"weathernow.h"
#include"maxmintemp.h"
#include"weatherforecast.h"
#include<exception>
#include "Array.h"
#include "IArray.h"
class observerlist
{
private:
	IArray<observer*>* list = new Array<observer*>;
public:
	void insertnode(observer*& newnode) {
		list->insert(list->size(),newnode);
	}
	void deletenode(observer*& deletenode) {
		int index = list->find(deletenode);
		if (index==-1)
		{
			throw std::exception("Invalid node");
		}
		list->remove(index);
		delete deletenode;
	}
	void navigation(int temp, float humidity, float wind){
		for (size_t i = 0; i < list->size(); i++)
		{
			list->at(i)->onchanged(temp, humidity, wind);
		}
	}
};

