#pragma once 
#include "MyDeque.cpp"
#include <stdexcept>

template<typename T,typename Container = MyDeque<T>>
class MyStack
{
private:
	Container data;
public:
	void push(const T& value) {
		data.push_back(value);
	}

	void pop() {
		if (!empty()) {
			data.pop_back();
		}
		else {
			throw std::runtime_error("Stack is emtpy");
		}
	}

	T& top() {
		if (!empty()) {
			return data.back();
		}
		else {
			throw std::runtime_error("Stack is emtpy");
		}
	}

	bool empty() {
		return data.empty();
	}

	size_t size() {
		return data.getSize();
	}

private:

};

