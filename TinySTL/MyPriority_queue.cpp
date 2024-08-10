#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>

template<typename T,typename Container = std::vector<T>>
class MyPriority_queue {

private:
	Container data;

	//从某点开始向下调整堆
	void heapifyDown(int curIndex) {
		int heapSize = data.size();
		int tmpNode = data[curIndex];
		for (int i = curIndex * 2 + 1; i < heapSize; i = i * 2 + 1) {
			if (i < heapSize - 1 && data[i] < data[i + 1]) {
				i++;
			}
			//调整结束
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

	//从最后的点开始向上调整堆
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
		//底层容器转化为堆(堆的构建)
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

int main() {
	// 使用 std::vector 作为底层容器
	MyPriority_queue<int, std::vector<int>> myPriorityQueue;
	
	std::string line;
	while (true) {
		std::getline(std::cin, line);
		std::istringstream iss(line);
		std::string command;
		iss >> command;

		int element;

		if (command == "push") {
			iss >> element;
			myPriorityQueue.push(element);
		}

		if (command == "pop") {
			try {
				myPriorityQueue.pop();
			}
			catch (const std::runtime_error& e) {
				// 不做任何处理
				continue;
			}
		}

		if (command == "top") {
			try {
				std::cout << myPriorityQueue.top() << std::endl;
			}
			catch (const std::runtime_error& e) {
				std::cout << "null" << std::endl;
			}
		}

		if (command == "size") {
			std::cout << myPriorityQueue.size() << std::endl;
		}

		if (command == "empty") {
			std::cout << (myPriorityQueue.empty() ? "true" : "false") << std::endl;
		}
		
		if (command == "quit") {
			break;
		}

	}
	return 0;
}