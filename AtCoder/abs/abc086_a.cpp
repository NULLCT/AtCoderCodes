#include<iostream>
#include<string>
using namespace std;
int main(void) {

	int a, b;
	cin >> a >> b;
	int c = a*b;
	if (c % 2 == 1) {
		cout << "Odd" << endl;
	}
	else {
		cout << "Even" << endl;
	}
	return 0;
}
