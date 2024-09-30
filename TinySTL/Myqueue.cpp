#pragma once 
#include "MyDeque.cpp"
#include <stdexcept>

template<typename T,typename Contatiner = MyDeque<T>>
class MyQueue
{
private:
	Contatiner data;

public:
	void push(const T& value) {
		data.push_back(value);
	}

	void pop() {
		if (!empty()) {
			data.pop_front();
		}
		else {
			throw std::runtime_error("Queue is empyt");
		}
	}

	T& front() {
		if (!empty()) {
			return data.front();
		}
		else {
			throw std::runtime_error("Queue is empyt");
		}
	}
	
	T& back() {
		if (!empty()) {
			return data.back();
		}
		else {
			throw std::runtime_error("Queue is empyt");
		}
	}

	bool empty() {
		return data.empty();
	}

	size_t size() {
		return data.getSize();
	}

};

