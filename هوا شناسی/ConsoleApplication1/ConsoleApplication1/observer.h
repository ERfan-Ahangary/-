#pragma once
class observer {
public:
	virtual void onchanged(int temp,float humidity,float wind)=0;
};