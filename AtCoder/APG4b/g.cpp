#include<iostream>
using namespace std;
int main(void) {

	int a[5];
	for (int i = 0; i != 5; i++)cin >> a[i];
	for (int i = 0; i != 4; i++) {
		if (a[i] == a[i + 1]) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

	return 0;
}
