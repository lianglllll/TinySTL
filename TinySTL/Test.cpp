#pragma once 
#include "MyVector.cpp"
#include "MyList.cpp"
#include "MyPriority_queue.cpp"
#include "MyDeque.cpp"
#include "MyHashTable.cpp"
#include "MyRedBlackTree.cpp"
#include "MySet.cpp"
#include "Myunordered_set.cpp"
#include "MyMultiSet.cpp"
#include "MyMap.cpp"
#include "Myunordered_map.cpp"
#include "MyMultiMap.cpp"
#include "MyStack.cpp"
#include "MyQueue.cpp"


void TestVector() {

	MyVector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	cout << "Ԫ�ظ�����" << v1.getSize() << endl;
	cout << "������С��" << v1.getCapacity() << endl;
	v1.print();
	cout << endl << endl;

	cout << "v1.pop_back()" << endl;
	v1.pop_back();
	cout << "Ԫ�ظ�����" << v1.getSize() << endl;
	cout << "������С��" << v1.getCapacity() << endl;
	v1.print();
	cout << endl << endl;

	cout << "v1[0] = 100" << endl;
	v1[0] = 100;
	v1.print();
	cout << endl << endl;

	cout << "v1.get(1)" << endl;
	cout << v1.get(1) << endl;
	v1.print();
	cout << endl << endl;

	cout << "v1.insert(2, 25)" << endl;
	v1.insert(2, 25);
	cout << "Ԫ�ظ�����" << v1.getSize() << endl;
	cout << "������С��" << v1.getCapacity() << endl;
	v1.print();
	cout << endl << endl;

	cout << "v2 = v1;" << endl;
	MyVector<int> v2;
	v2 = v1;
	v2.print();
	v2[1] = 200;
	cout << endl << endl;

	cout << "v3(v2)" << endl;
	MyVector<int> v3(v2);
	v3.print();
	cout << endl << endl;

	cout << "v3.clear()" << endl;
	v3.clear();
	cout << "Ԫ�ظ�����" << v3.getSize() << endl;
	cout << "������С��" << v3.getCapacity() << endl;
	cout << endl << endl;

	cout << "foreach v1" << endl;
	for (auto item : v1) {
		cout << item << " ";
	}
	cout << endl << endl;



}

void TestList() {
	// ����һ�� List ����
	MyList<int> myList;

	int N;
	std::cin >> N;
	// ���߻س�
	getchar();
	std::string line;
	// ��������
	for (int i = 0; i < N; i++) {
		std::getline(std::cin, line);
		std::istringstream iss(line);
		std::string command;
		iss >> command;
		int value;

		try
		{
			if (command == "push_back") {
				iss >> value;
				myList.push_back(value);
			}

			if (command == "push_front") {
				iss >> value;
				myList.push_front(value);
			}

			if (command == "pop_back") {
				myList.pop_back();
			}

			if (command == "pop_front") {
				myList.pop_front();
			}

			if (command == "remove") {
				iss >> value;
				myList.removeByValue(value);
			}

			if (command == "clear") {
				myList.clear();
			}

			if (command == "size") {
				std::cout << myList.getSize() << std::endl;
			}

			if (command == "get") {
				iss >> value;
				std::cout << myList[value] << std::endl;
			}

			if (command == "print") {
				if (myList.getSize() == 0) {
					std::cout << "empty" << std::endl;
				}
				else {
					myList.print();
				}
			}
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}

}

void TestPriority_queue() {
	// ʹ�� std::vector ��Ϊ�ײ�����
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
				// �����κδ���
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
}

void TestDeque() {
	// ����һ�� Deque ����
	MyDeque<int> myDeque;

	int N;
	std::cin >> N;
	// ���߻س�
	getchar();
	std::string line;

	// ��������
	for (int i = 0; i < N; i++) {

		try
		{
			std::getline(std::cin, line);
			std::istringstream iss(line);
			std::string command;
			iss >> command;
			int value;

			if (command == "push_back") {
				iss >> value;
				myDeque.push_back(value);
			}

			if (command == "push_front") {
				iss >> value;
				myDeque.push_front(value);
			}

			if (command == "pop_back") {

				myDeque.pop_back();
			}

			if (command == "pop_front") {

				myDeque.pop_front();
			}

			if (command == "clear") {
				myDeque.clear();
			}

			if (command == "size") {
				std::cout << myDeque.getSize() << std::endl;
			}

			if (command == "get") {
				iss >> value;
				std::cout << myDeque[value] << std::endl;
			}

			if (command == "print") {
				if (myDeque.getSize() == 0) {
					std::cout << "empty" << std::endl;
				}
				else {
					myDeque.printElements();
				}
			}
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}


	}

}

void TestHashTable() {
	// ����һ����ϣ��ʵ��
	MyHashTable<int, int> hashTable;

	int N;
	std::cin >> N;
	getchar();

	std::string line;
	for (int i = 0; i < N; i++) {
		std::getline(std::cin, line);
		std::istringstream iss(line);
		std::string command;
		iss >> command;

		int key;
		int value;

		if (command == "insert") {
			iss >> key >> value;
			hashTable.insert(key, value);
		}

		if (command == "erase") {
			if (hashTable.size() == 0) {
				continue;
			}
			iss >> key;
			hashTable.erase(key);
		}

		if (command == "find") {
			if (hashTable.size() == 0) {
				std::cout << "not exist" << std::endl;
				continue;
			}
			iss >> key;
			int* res = hashTable.find(key);
			if (res != nullptr) {
				std::cout << *res << std::endl;
			}
			else {
				std::cout << "not exist" << std::endl;
			}
		}

		if (command == "print") {
			if (hashTable.size() == 0) {
				std::cout << "empty" << std::endl;
			}
			else {
				hashTable.print();
			}
		}

		if (command == "size") {
			std::cout << hashTable.size() << std::endl;
		}

		if (command == "clear") {
			hashTable.clear();
		}
	}
}

void TestRedBlackTree() {
	// ���������ʵ��
	MyRedBlackTree<int, int> rbTree;

	int N;
	std::cin >> N;
	getchar();

	std::string line;
	for (int i = 0; i < N; i++)
	{
		std::getline(std::cin, line);
		std::istringstream iss(line);
		std::string command;
		iss >> command;

		int key;
		int value;

		if (command == "insert")
		{
			iss >> key >> value;
			rbTree.Insert(key, value);
		}

		if (command == "size")
		{
			std::cout << rbTree.GetSize() << std::endl;
		}

		if (command == "at")
		{
			iss >> key;
			int* res = rbTree.At(key);
			if (res == nullptr)
			{
				std::cout << "not exist" << std::endl;
			}
			else
			{
				std::cout << *res << std::endl;
			}
		}

		if (command == "remove")
		{
			iss >> key;
			rbTree.Remove(key);
		}

		if (command == "print")
		{
			if (rbTree.Empty())
			{
				std::cout << "empty" << std::endl;
			}
			else
			{
				rbTree.print();
			}
		}
	}
}

void TestSet() {
	MySet<int> mySet;

	// ����Ԫ��
	mySet.Insert(10);
	mySet.Insert(20);
	mySet.Insert(20);
	mySet.Insert(30);

	// ��ӡ���ϴ�С
	std::cout << "��ǰ���ϵĴ�С: " << mySet.Size() << std::endl;

	// ��鼯���Ƿ�����ض�Ԫ��
	int keyToCheck = 20;
	std::cout << "�����Ƿ����Ԫ��" << keyToCheck << ": "
		<< (mySet.Contains(keyToCheck) ? "��" : "��") << std::endl;

	// ɾ��Ԫ��
	int keyToDelete = 20;
	mySet.Erase(keyToDelete);
	std::cout << "ɾ��Ԫ��" << keyToDelete
		<< "�󣬵�ǰ���ϵĴ�С: " << mySet.Size() << std::endl;

	// �ٴμ�鼯���Ƿ������ɾ����Ԫ��
	std::cout << "ɾ��Ԫ��" << keyToDelete << "�󣬼����Ƿ����Ԫ��"
		<< keyToDelete << ": " << (mySet.Contains(keyToCheck) ? "��" : "��")
		<< std::endl;

	// ��鼯���Ƿ�Ϊ��
	std::cout << "�����Ƿ�Ϊ��: " << (mySet.Empty() ? "��" : "��") << std::endl;

}

void Testunordered_set() {
	// ����һ���������͵� Unordered_set ����
	Myunordered_set<int> intSet;

	// ����һЩ����
	intSet.Insert(1);
	intSet.Insert(2);
	intSet.Insert(2);
	intSet.Insert(3);

	// ��鼯���Ƿ�Ϊ��
	std::cout << "�����Ƿ�Ϊ��? " << (intSet.Empty() ? "��" : "��") << std::endl;

	// ��鼯�ϵĴ�С
	std::cout << "���ϵĴ�С: " << intSet.Size() << std::endl;

	// ����һ��Ԫ��
	std::cout << "2 �Ƿ��ڼ�����? " << (intSet.Contains(2) ? "��" : "��")
		<< std::endl;

	// ɾ��һ��Ԫ��
	intSet.Erase(2);
	std::cout << "ɾ�� 2 ��2 �Ƿ��ڼ�����? " << (intSet.Contains(2) ? "��" : "��")
		<< std::endl;

	// ��ռ���
	intSet.Clear();
	std::cout << "��պ󼯺��Ƿ�Ϊ��? " << (intSet.Empty() ? "��" : "��")
		<< std::endl;

	// ����һ���ַ������͵� Unordered_set ����
	Myunordered_set<std::string> stringSet;

	// ����һЩ�ַ���
	stringSet.Insert("apple");
	stringSet.Insert("banana");
	stringSet.Insert("banana");
	stringSet.Insert("cherry");

	// ����һ���ַ���
	std::cout << "'banana' �Ƿ��ڼ�����? "
		<< (stringSet.Contains("banana") ? "��" : "��") << std::endl;

	// ɾ��һ���ַ���
	stringSet.Erase("banana");
	std::cout << "ɾ�� 'banana' ��'banana' �Ƿ��ڼ�����? "
		<< (stringSet.Contains("banana") ? "��" : "��") << std::endl;

	return ;
}

void TestMultiSet() {
	MyMultiSet<int> mySet; // Create an Unordered_set for integers

	// Insert some elements
	mySet.Insert(1);
	mySet.Insert(2);
	mySet.Insert(2);
	mySet.Insert(3);

	// Check if elements are in the set
	std::cout << "Does the set contain 1? " << (mySet.Count(1) > 0 ? "Yes" : "No")
		<< std::endl;
	std::cout << "Does the set contain 4? " << (mySet.Count(4) > 0 ? "Yes" : "No")
		<< std::endl;

	// Print the size of the set
	std::cout << "The set size is: " << mySet.Size() << std::endl;

	// Remove an element
	mySet.Erase(2);
	std::cout << "After erasing 2, does the set contain 2? "
		<< (mySet.Count(2) > 0 ? "Yes" : "No") << std::endl;
	std::cout << "The set size is now: " << mySet.Size() << std::endl;

	// Clear the set
	mySet.Clear();
	std::cout << "After clearing, is the set empty? "
		<< (mySet.Empty() ? "Yes" : "No") << std::endl;

	return;
}

void TestMap() {
	MyMap<int, std::string> map;

	// �����ֵ��
	map.Insert(1, "Apple");
	map.Insert(2, "Banana");
	map.Insert(3, "Cherry");

	// ��ӡ��С
	std::cout << "��ǰMap�Ĵ�С: " << map.Size() << std::endl;

	// ����Ԫ��
	try {
		std::cout << "��1��Ӧ��ֵ: " << map.At(1) << std::endl;
		std::cout << "��2��Ӧ��ֵ: " << map.At(2) << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "����: " << e.what() << std::endl;
	}

	// ����Ƿ����ĳ����
	int keyToCheck = 3;
	std::cout << "Map�Ƿ������" << keyToCheck << ": "
		<< (map.Contains(keyToCheck) ? "��" : "��") << std::endl;

	// ʹ��[]��������ʻ򴴽�Ԫ��
	std::cout << "��4��Ӧ��ֵ���ڴ�֮ǰ�����ڣ�����������: " << map[4]
		<< std::endl;

	// ɾ��Ԫ��
	int keyToDelete = 2;
	std::cout << "ɾ����" << keyToDelete << std::endl;
	map.Erase(keyToDelete);

	// �ٴδ�ӡ��С
	std::cout << "ɾ����" << keyToDelete << "�󣬵�ǰMap�Ĵ�С: " << map.Size()
		<< std::endl;

	// ʹ��[]�����ΪԪ�ظ�ֵ
	map[4] = "Pear";
	std::cout << "��4��Ӧ��ֵ: " << map[4] << '\n';
	return ;
}

void TestUnordered_map() {
	// ����һ�� Unordered_map������ֵ���� std::string ����
	Myunordered_map<std::string, std::string> map;

	// ����һЩ��ֵ��
	map.Insert("apple", "ƻ��");
	map.Insert("banana", "�㽶");
	map.Insert("cherry", "ӣ��");

	// ���ӳ���Ƿ�Ϊ��
	std::cout << "ӳ���Ƿ�Ϊ��? " << (map.Empty() ? "��" : "��") << std::endl;

	// ��ȡӳ��Ĵ�С
	std::cout << "ӳ��Ĵ�С: " << map.Size() << std::endl;

	// ����Ԫ��
	std::cout << "apple ��Ӧ��������: " << map["apple"] << std::endl;

	// �޸�Ԫ��
	map["apple"] = "��ƻ��";
	std::cout << "�޸ĺ� apple ��Ӧ��������: " << map["apple"] << std::endl;

	// ʹ�� [] �����������µļ�ֵ��
	map["orange"] = "����";
	std::cout << "orange ��Ӧ��������: " << map["orange"] << std::endl;

	// ����Ԫ��
	std::cout << "cherry �Ƿ���ӳ����? " << (map.Contains("cherry") ? "��" : "��")
		<< std::endl;

	// ɾ��Ԫ��
	map.Erase("banana");
	std::cout << "ɾ�� banana ��banana �Ƿ���ӳ����? "
		<< (map.Contains("banana") ? "��" : "��") << std::endl;

	// ���ӳ��
	map.Clear();
	std::cout << "��պ�ӳ���Ƿ�Ϊ��? " << (map.Empty() ? "��" : "��")
		<< std::endl;

	return ;
}

void TestMultimap() {
	// ����һ��MultiMapʵ��������������std::string��ֵ��������int
	MyMultiMap<std::string, int> myMultiMap;

	// ����һЩ��ֵ��
	myMultiMap.Insert("apple", 10);
	myMultiMap.Insert("banana", 20);
	myMultiMap.Insert("apple", 30); // "apple"�����ж��ֵ

	// ��ȡ����ӡ��"apple"������ֵ
	auto appleValues = myMultiMap.At("apple");
	if (appleValues) {
		std::cout << "Values for 'apple':";
		for (const auto& val : *appleValues) {
			std::cout << val << ", ";
		}
		std::cout << '\n';
	}

	// ��MultiMap���Ƴ���"banana"������ֵ
	myMultiMap.Erase("banana");

	// ��MultiMap���Ƴ���"apple"��ֵ30
	myMultiMap.Erase("apple", 30);

	// ���MultiMap�Ƿ�Ϊ��
	if (!myMultiMap.Empty()) {
		std::cout << "The MultiMap is not empty, it has " << myMultiMap.Size()
			<< " elements." << std::endl;
	}

	return ;
}

void TestStack() {
	// ʹ�� std::deque ��Ϊ�ײ�������ʾ��
	MyStack<int, MyDeque<int>> stack;

	int N;
	std::cin >> N;
	getchar();

	std::string line;
	for (int i = 0; i < N; i++) {
		std::getline(std::cin, line);
		std::istringstream iss(line);
		std::string command;
		iss >> command;
		int element;
		if (command == "push") {
			iss >> element;
 			stack.push(element);
		}
		if (command == "pop") {
			try {
				stack.pop();
			}
			catch (const std::runtime_error& e) {
				// �����κδ���
				continue;
			}
		}
		if (command == "top") {
			try {
				std::cout << stack.top() << std::endl;
			}
			catch (const std::runtime_error& e) {
				std::cout << "null" << std::endl;
			}
		}
		if (command == "size") {
			std::cout << stack.size() << std::endl;
		}
		if (command == "empty") {
			std::cout << (stack.empty() ? "true" : "false") << std::endl;
		}
	}
	return ;
}

void TestQueue() {
	// ʹ�� std::deque ��Ϊ�ײ�������ʾ��
	MyQueue<int, MyDeque<int>> myQueue;

	int N;
	std::cin >> N;
	getchar();
	std::string line;

	for (int i = 0; i < N; i++) {
		std::getline(std::cin, line);
		std::istringstream iss(line);
		std::string command;
		iss >> command;

		int element;

		if (command == "push") {
			iss >> element;
			myQueue.push(element);
		}

		if (command == "pop") {
			try {
				myQueue.pop();
			}
			catch (const std::runtime_error& e) {
				// �����κδ���
				continue;
			}
		}

		if (command == "front") {
			try {
				std::cout << myQueue.front() << std::endl;
			}
			catch (const std::runtime_error& e) {
				std::cout << "null" << std::endl;
			}
		}

		if (command == "back") {
			try {
				std::cout << myQueue.back() << std::endl;
			}
			catch (const std::runtime_error& e) {
				std::cout << "null" << std::endl;
			}
		}

		if (command == "size") {
			std::cout << myQueue.size() << std::endl;
		}

		if (command == "empty") {
			std::cout << (myQueue.empty() ? "true" : "false") << std::endl;
		}
	}
	return;
}

int main() {
	//TestRedBlackTree();
	//TestSet();
	//Testunordered_set();
	//TestMultiSet();
	//TestMap();
	//TestUnordered_map();
	//TestMultimap();
	//TestStack();
	TestQueue();
}