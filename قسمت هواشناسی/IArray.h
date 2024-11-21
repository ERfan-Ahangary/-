#pragma once

template<typename T>
class IArray {

public:

	virtual void insert(size_t index, T value) = 0;
	virtual T remove(size_t index) = 0;
	virtual T at(size_t index) = 0;
	virtual long long find(T value) = 0;
	virtual size_t size() = 0;
};