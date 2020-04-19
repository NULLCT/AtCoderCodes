#include <algorithm>
#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <iterator>
#include <cctype>
#include <cstdio>
#include <cstring>
#define rep(counter, limit) for (int counter = 0; counter < limit; counter++)
typedef long long ll; using namespace std;const int INF=1001001001;
int gcd(int a, int b) { if (a % b == 0) { return(b); } else { return(gcd(b, a % b)); } }
int lcm(int a, int b) { return a * b / gcd(a, b); }
bool primenum(int a) { if (a == 1) { return false; }if (a == 2) { return true; }if (a % 2 == 0) { return false; }for (int i = 3; i < sqrt(a) + 1; i += 2) { if (a != i) { if (a % i == 0) { return false; } } }return true; }
int main() {

  int n;
  cin>>n;
  vector<int> ans(n,0);
  rep(i,n-1){
    int input;
    cin>>input;
    ans[input-1]++;
  }
  rep(i,n){
    cout<<ans[i]<<endl;
  }



}

