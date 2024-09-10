#include "MyVector.cpp"
#include "MyList.cpp"
#include "MyPriority_queue.cpp"
#include "MyDeque.cpp"



void TestVector() {

	MyVector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	cout <<"元素个数：" << v1.getSize() << endl;
	cout <<"容量大小：" << v1.getCapacity() << endl;
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


int main(){
	//TestVector();
	//TestList();
	//TestPriority_queue();
	TestDeque();
}
