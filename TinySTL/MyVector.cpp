#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;


template<typename T>
class MyVector {

private:
	T* elements;		//指向动态数组的指针
	size_t capacity;	//数组最大的容量
	size_t size;		//数组当前元素的个数

	void reserve(size_t newCapacity) {
		T* newElements = new T[newCapacity];
		std::copy(elements, elements + size, newElements);
		capacity = newCapacity;
		delete[] elements;
		elements = newElements;
	}

public:
	//构造函数：初始化 Vector 实例
	MyVector() :elements(nullptr), capacity(0), size(0) {

	}

	//析构函数：清理资源，确保无内存泄露
	~MyVector() {
		if (elements != nullptr) {
			delete[] elements;
		}
	}

	//拷贝构造函数
	MyVector(const MyVector& other) :capacity(other.capacity), size(other.size) {
		elements = new T[capacity];
		//数据拷贝
		std::copy(other.elements, other.elements + size, elements);
	}

	//重置运算符=，拷贝赋值
	MyVector& operator=(const MyVector& other) {
		if (this != &other) {
			delete[] elements;
			capacity = other.capacity;
			size = other.size;
			elements = new T[capacity];
			std::copy(other.elements, other.elements + size, elements);
		}
		return *this;
	}

	//重载[]
	T& operator[](int index) {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of range");
		}
		return elements[index];
	}

	const T& operator[](int index) const {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of range");
		}
		return elements[index];
	}

	//添加元素到末尾：允许在 Vector 的末尾添加新元素
	void push_back(const T& element) {
		if (size == capacity) {
			if (capacity == 0) {
				reserve(1);
			}
			else {
				reserve(capacity * 2);
			}
		}
		elements[size++] = element;
	}

	//删除数组末尾元素：移除 Vector 末尾的元素
	void pop_back() {
		if (size > 0) {
			size--;
		}
	}

	//获取元素个数：返回 Vector 当前包含的元素数量
	size_t getSize() const {
		return size;
	}

	//获取数组最大容量
	size_t getCapacity() const {
		return capacity;
	}

	//访问指定索引处的元素：通过索引访问特定位置的元素
	T get(int index) {
		if (0 <= index && index < size) {
			return elements[index];
		}
		else {
			throw std::out_of_range("Index out of range");
		}
	}

	//在指定位置插入元素：在 Vector 的特定位置插入一个新元素
	void insert(int index, T element) {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of range");
		}
		if (size == capacity) {
			reserve(capacity == 0 ? 1 : capacity * 2);
		}
		for (size_t i = size; i > index; --i) {
			elements[i] = elements[i - 1];
		}
		elements[index] = element;
		++size;
	}

	//清空数组：删除 Vector 中的所有元素，重置其状态
	void clear() {
		size = 0;
	}

	// 使用迭代器遍历数组的开始位置
	T* begin() {
		return elements;
	}

	// 使用迭代器遍历数组的结束位置
	T* end() {
		return elements + size;
	}

	const T* begin() const {
		return elements;
	}

	const T* end() const {
		return elements + size;
	}

	void print() {
		for (int i = 0; i < size; ++i) {
			cout << elements[i];
			if (i != size - 1) {
				cout << " ";
			}
		}
	}

};