#pragma once 
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MyDeque {
private:
	T* elements;
	size_t capacity;
	size_t frontIndex;	//��һ��Ԫ�ص�λ��
	size_t backIndex;	//���һ��Ԫ�ص���һ��λ��
	size_t size;

public:
	MyDeque() :elements(nullptr), capacity(0), frontIndex(0), backIndex(0), size(0) {}
	~MyDeque() {
		clear();
		if (elements != nullptr) {
			delete[] elements;
		}
	}

	void push_front(const T& value) {
		
		//��Ҫ����
		if (size == capacity) {
			resize();
		}

		//���¼���ǰ����
		frontIndex = (frontIndex - 1 + capacity) % capacity;

		//����
		elements[frontIndex] = value;

		//����
		++size;
	}

	void push_back(const T& value) {

		//��Ҫ����
		if (size == capacity) {
			resize();
		}

		backIndex = (backIndex + 1) % capacity;
		elements[backIndex] = value;
		++size;
	
	}

	void pop_front() {
		
		if (size <= 0) {
			throw std::out_of_range("Deque is empty");
		}

		frontIndex = (frontIndex + 1) % capacity;
		--size;
	
	}

	void pop_back() {

		if (size <= 0) {
			throw std::out_of_range("Deque is empty");
		}

		backIndex = (backIndex - 1 + capacity) % capacity;
		--size;

	}

	T& operator[](int index) {
		if (index < 0 || index >= size) {
			throw std::out_of_range("index out of range");
		}
		return elements[(frontIndex + index) % capacity];
	}

	T& front() {
		if (!empty()) {
			return elements[frontIndex];
		}
	}

	T& back() {
		if (!empty()) {
			return elements[backIndex];
		}
	}

	size_t getSize() {
		return size;
	}

	bool empty() {
		return size == 0;
	}

	void clear() {
		while (size > 0) {
			pop_front();
		}
	}

	void printElements() const {
		size_t index = frontIndex;
		for (size_t i = 0; i < size; ++i) {
			cout << elements[index] << " ";
			index = (index + 1) % capacity;
		}
		cout << endl;
	}

private:

	void resize() {
		//�����¿ռ�
		size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
		T* newElements = new T[newCapacity];
		//����Ԫ�ص��¿ռ�
		size_t index = frontIndex;
		for (size_t i = 0; i < size; ++i) {
			newElements[i] = elements[index];
			index = (index + 1) % capacity;
		}
		//�ͷžɿռ�
		delete[] elements;
		//����������Ϣ
		elements = newElements;
		capacity = newCapacity;
		frontIndex = 0;
		backIndex = size-1;

	}
};