#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int size { 10 }, min_n { -100 }, max_n { 100 };

void fillArray(int ar[], int size = ::size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		ar[i] = ::min_n + rand() % (::max_n - ::min_n);
}

void printArray(int ar[], int size = ::size) {
	for (int i = 0; i < size; i++)
		cout << ar[i] << " ";
	cout << endl;
}

void linearSearchArray(int ar[], int key, int size = ::size) {
	bool found { 0 };
	for (int i = 0; i < size; i++)
		if (ar[i] == key) {
			cout << "Key " << key << " found in position " << i << endl;
			found = 1;
		}
	if (!found)
		cout << "Key " << key << " not found!";
}

void swap(int ar[], int i1, int i2) {
	int t { 0 };
	t = ar[i1];
	ar[i1] = ar[i2];
	ar[i2] = t;
}

void bubbleSortArray(int ar[], int size = ::size) {
	bool sorted { 0 };
	while (!sorted) {
		sorted = 1;
		for (int i = 1; i < size; i++) {
			if (ar[i - 1] > ar[i]) {
				swap(ar, i - 1, i);
				sorted = 0;
			}
		}
	}
}

void binarySearchArray(int ar[], int key, int size = ::size) {
	bool found { 0 };
	bubbleSortArray(ar, size);
	int mid { size / 2 }, div { 2 };
	while (!found) {
		if (ar[mid] == key) {
			cout << "Key " << key << " found in position " << mid << endl;
			found = 1;
		} else if (ar[mid > key]) {
			div *= 2;
			mid -= size / div;
		} else if (ar[mid < key]) {
			div *= 2;
			mid += size / div;
		}
		if (size / div == 0 && !found) {
			cout << "Key " << key << " not found!";
			return;
		}
	}
}

int main() {
	int array[::size] { };
	fillArray(array);
	int command { 0 }, key { 0 };
	do {
		cout << "Array is:" << endl;
		printArray(array);
		cout << "Enter command:" << endl;
		cout << "1. Linear search for key" << endl;
		cout << "2. Binary search for key (will autosort array)" << endl;
		cout << "0. Exit" << endl;
		cin >> command;
		switch (command) {
		case 1:
			cout << "Enter key: ";
			cin >> key;
			linearSearchArray(array, key);
			break;
		case 2:
			cout << "Enter key: ";
			cin >> key;
			binarySearchArray(array, key);
			break;
		case 0:
			return 0;
		default:
			cout << "Wrong command!" << endl;
		}
	} while (command);

	return 0;
}
