#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;


template<typename T>
class MyVector {

private:
	T* elements;		//ָ��̬�����ָ��
	size_t capacity;	//������������
	size_t size;		//���鵱ǰԪ�صĸ���

	void reserve(size_t newCapacity) {
		T* newElements = new T[newCapacity];
		std::copy(elements, elements + size, newElements);
		capacity = newCapacity;
		delete[] elements;
		elements = newElements;
	}

public:
	//���캯������ʼ�� Vector ʵ��
	MyVector() :elements(nullptr), capacity(0), size(0) {

	}

	//����������������Դ��ȷ�����ڴ�й¶
	~MyVector() {
		if (elements != nullptr) {
			delete[] elements;
		}
	}

	//�������캯��
	MyVector(const MyVector& other) :capacity(other.capacity), size(other.size) {
		elements = new T[capacity];
		//���ݿ���
		std::copy(other.elements, other.elements + size, elements);
	}

	//���������=��������ֵ
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

	//����[]
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

	//���Ԫ�ص�ĩβ�������� Vector ��ĩβ�����Ԫ��
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

	//ɾ������ĩβԪ�أ��Ƴ� Vector ĩβ��Ԫ��
	void pop_back() {
		if (size > 0) {
			size--;
		}
	}

	//��ȡԪ�ظ��������� Vector ��ǰ������Ԫ������
	size_t getSize() const {
		return size;
	}

	//��ȡ�����������
	size_t getCapacity() const {
		return capacity;
	}

	//����ָ����������Ԫ�أ�ͨ�����������ض�λ�õ�Ԫ��
	T get(int index) {
		if (0 <= index && index < size) {
			return elements[index];
		}
		else {
			throw std::out_of_range("Index out of range");
		}
	}

	//��ָ��λ�ò���Ԫ�أ��� Vector ���ض�λ�ò���һ����Ԫ��
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

	//������飺ɾ�� Vector �е�����Ԫ�أ�������״̬
	void clear() {
		size = 0;
	}

	// ʹ�õ�������������Ŀ�ʼλ��
	T* begin() {
		return elements;
	}

	// ʹ�õ�������������Ľ���λ��
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