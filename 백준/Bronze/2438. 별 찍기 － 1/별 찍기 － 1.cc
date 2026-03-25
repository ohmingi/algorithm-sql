#include <iostream>

using namespace std;

int main() {
	
	int i;
	
	cin >> i;
	int c = i;

	for (i; i > 0; i--) {
		
		for (int star{c}; star >= i; star--) {
			cout << "*";
		}
		cout << "\n";
	}
}