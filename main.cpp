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
	Vector<y_gor_iok> a;

	y_gor_iok yg(15, 12);
	a.push_back(yg);

	a.emplace_back(20, 20);

	cout << a.size() << endl << a.capacity()<<endl;

	a[0].print();
	a[1].print();

}