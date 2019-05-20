#include "Vector.h"

#include <iostream>
#include <chrono>

#include <vector>

using namespace std;
using namespace std::chrono;

int main()
{
	unsigned int sz = 10000000; // 100000, 1000000, 10000000, 100000000
	//auto start1 = high_resolution_clock::now();
	int kiekis = 0;
	std::vector<int> v1;
	for (int i = 1; i <= sz; ++i)
	{
		if (v1.size() == v1.capacity())
			kiekis++;
		v1.push_back(i);
	}
	/*auto end1 = high_resolution_clock::now();
	duration<double> diff1 = end1 - start1;*/
	cout << "std::vector" << kiekis << "s.\n";

	Vector<int> v2;
	kiekis = 0;
	//auto start2 = high_resolution_clock::now();
	for (int i = 1; i <= sz; ++i)
	{
		if (v2.size() == v2.capacity())
			kiekis++;
		v2.push_back(i);
	}
	/*auto end2 = high_resolution_clock::now();
	duration<double> diff2 = end2 - start2;*/
	cout << "Vecotr" << kiekis << "s.\n";
}