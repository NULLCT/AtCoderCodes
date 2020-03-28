/*///////////////////////////////////////////*/
/*/ root@NULLCT$(´・ω・｀)<<"Be accept!!"  /*/
/*///////////////////////////////////////////*/
#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>
#define rep(counter, limit) for (int counter = 0; counter < limit; counter++)
typedef long long ll; using namespace std;
int gcd(int a, int b) { if (a % b == 0) { return(b); } else { return(gcd(b, a % b)); } }
int lcm(int a, int b) { return a * b / gcd(a, b); }
bool primenum(int a) { if (a == 1) { return false; }if (a == 2) { return true; }if (a % 2 == 0) { return false; }for (int i = 3; i < sqrt(a) + 1; i += 2) { if (a != i) { if (a % i == 0) { return false; } } }return true; }
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int k, n;
  cin >> k >> n;
  vector<int> a(n);
  int maxto = 0;
  int maxnum = 0;
  rep(i, n) {
    cin >> a[i];
  }
  rep(i, n-1) {
    if (maxto < a[i + 1] - a[i]) {
      maxto = a[i + 1] - a[i];
      maxnum = i;
    }
  }
  if (maxto < k - a[n - 1] + a[0]) {
    maxto = k - a[n - 1] + a[0];
    maxnum = n - 1;
  }
  if (maxnum == n - 1) {
    cout << a[n - 1] - a[0] << endl;
    return 0;
  }
  else {
    cout << k - a[maxnum + 1] + a[maxnum] << endl;
  }

  return 0;
}


