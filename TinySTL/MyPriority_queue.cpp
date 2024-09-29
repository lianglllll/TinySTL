#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;


template<typename T,typename Container = std::vector<T>>
class MyPriority_queue {

private:
	Container data;

	//��ĳ�㿪ʼ���µ�����
	void heapifyDown(int curIndex) {
		int heapSize = data.size();
		int tmpNode = data[curIndex];
		for (int i = curIndex * 2 + 1; i < heapSize; i = i * 2 + 1) {
			if (i < heapSize - 1 && data[i] < data[i + 1]) {
				i++;
			}
			//��������
			if (data[curIndex] > data[i]) {
				break;
			}
			else {
				data[curIndex] = data[i];
				curIndex = i;
			}
		}
		data[curIndex] = tmpNode;
	}

	//�����ĵ㿪ʼ���ϵ�����
	void heapifyUp() {
		int curIndex = data.size()-1;
		while (curIndex > 0) {
			int parentIndex = (curIndex - 1) / 2;
			if (data[curIndex] > data[parentIndex]) {
				std::swap(data[curIndex], data[parentIndex]);
				curIndex = parentIndex;
			}
			else {
				break;
			}
		}
	}



public:
	MyPriority_queue(){}
	MyPriority_queue(const Container& c) :data(c) {
		//�ײ�����ת��Ϊ��(�ѵĹ���)
		int size = data.size();
		for (int i = (size / 2) - 1; i >= 0; --i) {
			heapifyDown(i);
		}
	}

	void push(const T& value) {
		data.push_back(value);
		heapifyUp();
	}

	void pop() {
		if (!empty()) {
			std::swap(data[0], data[data.size() - 1]);
			data.pop_back();
			heapifyDown(0);
		}
		else {
			throw std::runtime_error("Priority queue is empty");
		}
	}

	T& top() {
		if (!empty()) {
			return data[0];
		}
		else {
			throw std::runtime_error("Priority queue is empty");
		}
	}

	bool empty() const {
		return data.empty();
	}

	size_t size() const {
		return data.size();
	}

};
