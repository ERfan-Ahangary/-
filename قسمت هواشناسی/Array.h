#pragma once
#include "IArray.h"
#include <exception>
template<typename T>
class Array : public IArray<T>
{
public:

	Array() {
		m_data = nullptr;
		m_size = 0;
		m_capacity = 0;
	};
	Array(size_t size) {
		{
			m_data = new float[size];
			m_size = 0;
			m_capacity = size;
		}
	};
	~Array() {
		if (m_data != nullptr) {
			delete[] m_data;
			m_data = nullptr;
		}
	};

public:

	void insert(size_t index, T value) override {
		{
			validateIndex(index, true);
			if (m_size == m_capacity) {

				T* newdata = new T[m_capacity + 1];
				for (size_t i = 0; i < m_size; ++i) {
					if (i < index)
						newdata[i] = m_data[i];
					else
						newdata[i + 1] = m_data[i];
				}
				newdata[index] = value;

				if (m_data != nullptr) {
					delete[] m_data;
					m_data = nullptr;
				}
				m_data = newdata;
				m_capacity++;
			}
			else {
				T save1 = 0;
				T save2 = 0;
				for (size_t i = 0; i < m_size; ++i) {
					if (i == index)
					{
						save1 = m_data[i];
						save2 = m_data[i + 1];
						m_data[i + 1] = save1;
					}
					else if (i > index)
					{
						save1 = save2;
						save2 = m_data[i + 1];
						m_data[i + 1] = save1;
					}
				}
				m_data[index] = value;
			}



			m_size++;

		}
	};
	T remove(size_t index) override {
		T save = m_data[index];
		for (size_t i = 0; i < m_size - 1; i++)
		{
			if (i >= index)
			{
				m_data[i] = m_data[i + 1];
			}
		}
		m_size--;
		return save;
	};
	T at(size_t index) override {
		validateIndex(index);
		return m_data[index];
	};
	long long find(T value) override {
		for (size_t i = 0; i < m_size; i++) {
			if (m_data[i] == value)
			{
				return i;
			}
		}
		return -1;
	};
	size_t size() override {
		return m_size;
	};

private:
	void validateIndex(size_t index, bool insertCall = false) {

		if ((insertCall && index > m_size) || index > m_size) {
			throw std::exception("Invalid Index");
		}
	};

private:

	T* m_data;
	size_t m_size;
	size_t m_capacity;

};

