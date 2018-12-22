#include<iostream>
#include<algorithm>
using namespace std;
int main(void) {
	
	long long n, a[99999], b = 0, an = 0;
	cin >> n;
	for (int i = 0; i != n; i++)cin >> a[i];

	for (;;) {
		for (int i = 0; i != n; i++) {
			if (a[i] % 2 == 1) {
				b = 1;
				break;
			}
			else {
				a[i] /= 2;
			}
		}
		if (b == 1) {
			break;
		}
		else {
			an++;
		}
	}
	cout << an << endl;

	return 0;
}
