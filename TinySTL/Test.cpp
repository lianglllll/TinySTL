#include "MyVector.cpp"
#include<iostream>
using namespace std;


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



int main(){
	TestVector();
}




