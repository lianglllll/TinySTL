#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class MyList {

public:
	template<typename L>
	friend std::ostream& operator<<(std::ostream& os, const MyList<L>& pt);

private:

	struct Node {
		T data;
		Node* pre;
		Node* next;
		Node(const T& value,Node* preNode = nullptr,Node* nextNode = nullptr):data(value),pre(preNode),next(nextNode){}
	};

	Node* head;
	Node* tail;
	size_t size;

public:

	MyList():head(nullptr), tail(nullptr),size(0){}


	~MyList() {
		clear();
	}


	void push_back(const T& value) {
		
		//create a new node
		Node* newNode = new Node(value,tail,nullptr);

		//link with list
		if (tail) {
			tail->next = newNode;
		}
		else {
			head = newNode;
		}

		//update infomation
		tail = newNode;
		++size;
	}


	void push_front(const T& value) {

		Node* newNode = new Node(value,nullptr,head);
		if (head) {
			head->pre = newNode;
		}
		else {
			tail = newNode;
		}
		head = newNode;
		++size;
	}


	void pop_back() {

		if (size <= 0) {
			return;
		}

		Node* newTailNode = tail->pre;
		delete tail;
		tail = newTailNode;
		
		if (tail) {
			tail->next = nullptr;
		}
		else {
			head = nullptr;
		}

		--size;
	}

	void pop_front() {

		if (size <= 0) {
			return;
		}

		Node* newHeadNode = head->next;
		delete head;
		head = newHeadNode;
		if (head) {
			head->pre = nullptr;
		}
		else {
			tail = nullptr;
		}

		--size;

	}


	void clear() {

		Node* cur;
		while (head)
		{
			cur = head;
			head = head->next;
			delete cur;
		}
		
		tail = nullptr;
		size = 0;
	}


	void removeByValue(const T& value) {
		
		Node* cur = head;
		while (cur && cur->data != value) {
			cur = cur->next;
		}
		
		if (cur == nullptr) {
			return;
		}

		if (cur != head && cur != tail) {
			cur->pre->next = cur->next;
			cur->next->pre = cur->pre;
		}
		else if (cur == head && cur == tail) {
			head = nullptr;
			tail = nullptr;
		}
		else if (cur == head) {
			head = cur->next;
			head->pre = nullptr;
		}
		else if (cur == tail) {
			tail = cur->pre;
			tail->next = nullptr;
		}

		delete cur;
		cur = nullptr;
		--size;
	}


	T& getNodeByValue(const T& value) {
		Node* cur = head;
		while (cur != nullptr && cur->data != value) {
			cur = cur->next;
		}
		return cur;
	}


	const T& operator[](int index) {
		if (index < 0 || index >= size) {
			throw std::out_of_range("index out of range");
		}

		Node* cur = head;
		for (size_t i = 0; i < index; ++i) {
			cur = cur->next;
		}
		return cur->data;
	}


	size_t getSize() {
		return size;
	}


	bool empty() {
		return size <= 0;
	}


	Node* begin() {
		return head;
	}
	

	Node* end() {
		return nullptr;
	}


	const Node* begin() const {
		return head;
	}


	const Node* end() const {
		return nullptr;
	}

	void print() const {
		for (Node* cur = head; cur; cur = cur->next) {
			cout << cur->data << " ";
		}
		cout << endl;
	}

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const MyList<T>& pt) {

	for (typename MyList<T>::Node* current = pt.head; current; current = current->next) {
		os << " " << current->data;
	}

	os << endl;
	return os;
}
