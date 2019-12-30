////////////////////////////////////////////////////////////////
//
//    (☝ ՞ਊ ՞)☝ << Be accept!!
//
//    C++ format for competitive professional V1.0
//
//    GCC is recommendation.
//
////////////////////////////////////////////////////////////////

#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<time.h>
#include<random>
#include<thread>
#include<boost/multiprecision/cpp_int.hpp>

#define rp(n) for(int i = 0;i < n;i++)
#define Be return
#define accept 0;

using ll = long long;
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

int inline setup(void) {//set
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}
int lenght(char* str){//getcharlengh
	int i = 0;
	while (str[i]) {
		i++;
	}
	return i;
}
int main(int argc, const char* argv[]) {
	setup();
	ll a, b, k;
	cin >> a >> b >> k;
	if (a >= k) {
		a -= k;
	}
	else {
		k -= a;
		a = 0;
		if (b > k) {
			b -= k;
		}
		else {
			b = 0;
		}
	}
	cout << a << "\n" << b << "\n";
	Be accept
}

