#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {

	int list[4];
	for (int i = 0; i != 4; i++)cin >> list[i];

	sort(list, list + 4);

	if (list[0] == 1) {
		if (list[1] == 4) {
			if (list[2] == 7) {
				if (list[3] == 9) {
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}

	cout << "NO" << endl;
	
	return 0;
}

