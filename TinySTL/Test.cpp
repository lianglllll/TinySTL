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

	cout << "元素个数：" << v1.getSize() << endl;
	cout << "容量大小：" << v1.getCapacity() << endl;
	v1.print();
	cout << endl << endl;

	cout << "v1.pop_back()" << endl;
	v1.pop_back();
	cout << "元素个数：" << v1.getSize() << endl;
	cout << "容量大小：" << v1.getCapacity() << endl;
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
	cout << "元素个数：" << v1.getSize() << endl;
	cout << "容量大小：" << v1.getCapacity() << endl;
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
	cout << "元素个数：" << v3.getSize() << endl;
	cout << "容量大小：" << v3.getCapacity() << endl;
	cout << endl << endl;

	cout << "foreach v1" << endl;
	for (auto item : v1) {
		cout << item << " ";
	}
	cout << endl << endl;



}

void TestList() {
	// 创建一个 List 对象
	MyList<int> myList;

	int N;
	std::cin >> N;
	// 读走回车
	getchar();
	std::string line;
	// 接收命令
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
}

void TestDeque() {
	// 创建一个 Deque 对象
	MyDeque<int> myDeque;

	int N;
	std::cin >> N;
	// 读走回车
	getchar();
	std::string line;

	// 接收命令
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
	// 创建一个哈希表实例
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
	// 创建红黑树实例
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

	// 插入元素
	mySet.Insert(10);
	mySet.Insert(20);
	mySet.Insert(20);
	mySet.Insert(30);

	// 打印集合大小
	std::cout << "当前集合的大小: " << mySet.Size() << std::endl;

	// 检查集合是否包含特定元素
	int keyToCheck = 20;
	std::cout << "集合是否包含元素" << keyToCheck << ": "
		<< (mySet.Contains(keyToCheck) ? "是" : "否") << std::endl;

	// 删除元素
	int keyToDelete = 20;
	mySet.Erase(keyToDelete);
	std::cout << "删除元素" << keyToDelete
		<< "后，当前集合的大小: " << mySet.Size() << std::endl;

	// 再次检查集合是否包含已删除的元素
	std::cout << "删除元素" << keyToDelete << "后，集合是否包含元素"
		<< keyToDelete << ": " << (mySet.Contains(keyToCheck) ? "是" : "否")
		<< std::endl;

	// 检查集合是否为空
	std::cout << "集合是否为空: " << (mySet.Empty() ? "是" : "否") << std::endl;

}

void Testunordered_set() {
	// 创建一个整数类型的 Unordered_set 集合
	Myunordered_set<int> intSet;

	// 插入一些数字
	intSet.Insert(1);
	intSet.Insert(2);
	intSet.Insert(2);
	intSet.Insert(3);

	// 检查集合是否为空
	std::cout << "集合是否为空? " << (intSet.Empty() ? "是" : "否") << std::endl;

	// 检查集合的大小
	std::cout << "集合的大小: " << intSet.Size() << std::endl;

	// 查找一个元素
	std::cout << "2 是否在集合中? " << (intSet.Contains(2) ? "是" : "否")
		<< std::endl;

	// 删除一个元素
	intSet.Erase(2);
	std::cout << "删除 2 后，2 是否还在集合中? " << (intSet.Contains(2) ? "是" : "否")
		<< std::endl;

	// 清空集合
	intSet.Clear();
	std::cout << "清空后集合是否为空? " << (intSet.Empty() ? "是" : "否")
		<< std::endl;

	// 创建一个字符串类型的 Unordered_set 集合
	Myunordered_set<std::string> stringSet;

	// 插入一些字符串
	stringSet.Insert("apple");
	stringSet.Insert("banana");
	stringSet.Insert("banana");
	stringSet.Insert("cherry");

	// 查找一个字符串
	std::cout << "'banana' 是否在集合中? "
		<< (stringSet.Contains("banana") ? "是" : "否") << std::endl;

	// 删除一个字符串
	stringSet.Erase("banana");
	std::cout << "删除 'banana' 后，'banana' 是否还在集合中? "
		<< (stringSet.Contains("banana") ? "是" : "否") << std::endl;

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

	// 插入键值对
	map.Insert(1, "Apple");
	map.Insert(2, "Banana");
	map.Insert(3, "Cherry");

	// 打印大小
	std::cout << "当前Map的大小: " << map.Size() << std::endl;

	// 访问元素
	try {
		std::cout << "键1对应的值: " << map.At(1) << std::endl;
		std::cout << "键2对应的值: " << map.At(2) << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "错误: " << e.what() << std::endl;
	}

	// 检查是否包含某个键
	int keyToCheck = 3;
	std::cout << "Map是否包含键" << keyToCheck << ": "
		<< (map.Contains(keyToCheck) ? "是" : "否") << std::endl;

	// 使用[]运算符访问或创建元素
	std::cout << "键4对应的值（在此之前不存在，将被创建）: " << map[4]
		<< std::endl;

	// 删除元素
	int keyToDelete = 2;
	std::cout << "删除键" << keyToDelete << std::endl;
	map.Erase(keyToDelete);

	// 再次打印大小
	std::cout << "删除键" << keyToDelete << "后，当前Map的大小: " << map.Size()
		<< std::endl;

	// 使用[]运算符为元素赋值
	map[4] = "Pear";
	std::cout << "键4对应的值: " << map[4] << '\n';
	return ;
}

void TestUnordered_map() {
	// 创建一个 Unordered_map，键和值都是 std::string 类型
	Myunordered_map<std::string, std::string> map;

	// 插入一些键值对
	map.Insert("apple", "苹果");
	map.Insert("banana", "香蕉");
	map.Insert("cherry", "樱桃");

	// 检查映射是否为空
	std::cout << "映射是否为空? " << (map.Empty() ? "是" : "否") << std::endl;

	// 获取映射的大小
	std::cout << "映射的大小: " << map.Size() << std::endl;

	// 访问元素
	std::cout << "apple 对应的中文是: " << map["apple"] << std::endl;

	// 修改元素
	map["apple"] = "红苹果";
	std::cout << "修改后 apple 对应的中文是: " << map["apple"] << std::endl;

	// 使用 [] 操作符插入新的键值对
	map["orange"] = "橙子";
	std::cout << "orange 对应的中文是: " << map["orange"] << std::endl;

	// 查找元素
	std::cout << "cherry 是否在映射中? " << (map.Contains("cherry") ? "是" : "否")
		<< std::endl;

	// 删除元素
	map.Erase("banana");
	std::cout << "删除 banana 后，banana 是否还在映射中? "
		<< (map.Contains("banana") ? "是" : "否") << std::endl;

	// 清空映射
	map.Clear();
	std::cout << "清空后映射是否为空? " << (map.Empty() ? "是" : "否")
		<< std::endl;

	return ;
}

void TestMultimap() {
	// 创建一个MultiMap实例，键的类型是std::string，值的类型是int
	MyMultiMap<std::string, int> myMultiMap;

	// 插入一些键值对
	myMultiMap.Insert("apple", 10);
	myMultiMap.Insert("banana", 20);
	myMultiMap.Insert("apple", 30); // "apple"可以有多个值

	// 获取并打印键"apple"的所有值
	auto appleValues = myMultiMap.At("apple");
	if (appleValues) {
		std::cout << "Values for 'apple':";
		for (const auto& val : *appleValues) {
			std::cout << val << ", ";
		}
		std::cout << '\n';
	}

	// 从MultiMap中移除键"banana"的所有值
	myMultiMap.Erase("banana");

	// 从MultiMap中移除键"apple"的值30
	myMultiMap.Erase("apple", 30);

	// 检查MultiMap是否为空
	if (!myMultiMap.Empty()) {
		std::cout << "The MultiMap is not empty, it has " << myMultiMap.Size()
			<< " elements." << std::endl;
	}

	return ;
}

void TestStack() {
	// 使用 std::deque 作为底层容器的示例
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
				// 不做任何处理
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
	// 使用 std::deque 作为底层容器的示例
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
				// 不做任何处理
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