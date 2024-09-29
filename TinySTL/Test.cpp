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


int main() {
	//TestRedBlackTree();
	//TestSet();
	//Testunordered_set();
	TestMultiSet();
}