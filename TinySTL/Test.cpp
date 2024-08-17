#include "MyVector.cpp"
#include<iostream>
using namespace std;


void TestVector() {

	MyVector<int> v1;
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);

	cout << v1.getSize() << endl;
}


void TestPriority_queue() {

}


int main(){
	TestVector();
}




