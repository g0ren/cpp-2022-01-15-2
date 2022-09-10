#include <iostream>
#include <cmath>
using namespace std;

long long pow2(int p) {
	long long r { 1 };
	for (int i = 0; i < p; i++)
		r *= 2;
	return r;
}

long long binaryToDecimal(long long bin) {
	long long dec { 0 };
	int i { 0 };
	while (bin) {
		if (bin % 10) {
			dec += pow2(i);
		}
		bin /= 10;
		i++;
	}
	return dec;
}

int main() {
	long long bin { 0 };
	cout << "Enter binary number" << endl;
	cin >> bin;
	cout << bin << "b is " << binaryToDecimal(bin) << " in decimal";
	return 0;
}
