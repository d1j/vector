#include "Vector.h"

#include <iostream>

#include <vector>

using namespace std;

class y_gor_iok {
private:
	int a;
	int b;
public:
	y_gor_iok() : a(0), b(0) {}
	y_gor_iok(int a_, int b_) : a(a_), b(b_) {}
	void print() {
		cout << a << " " << b << endl;
	}
};

template <typename T>
void printArr(T arr) {
	for (auto i = 0; i < arr.size(); ++i) {
		std::cout << arr[i] << " ";
	}
	cout << endl;
}


int main() {
	Vector<int> a{1, 2, 3, 4};
	cout<<a.size()<<a.capacity()<<endl;
	cout<<a.data()<<endl;
	printArr(a);
	auto b = a.begin();
	cout<<a.insert(b, 50)<<endl;
	cout<<a.data()<<endl;

	printArr(a);
}