/*------------------------------------------------,
|  __                                       __    |
| |  |--.-----.---.-.----.----.-----.-----.|  |_  |
| |  _  |  -__|  _  |  __|  __|  -__|  _  ||   _| |
| |_____|_____|___._|____|____|_____|   __||____| |
|                                   |__|          |
`------------------------------------------------*/
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdint>
#include <deque>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;
using namespace std;
#define INF 2147483647
#define MOD 10000007
#define REP(count_ver, lower, upper) for (long long count_ver = lower; count_ver < upper; count_ver++)

int gcd(int a, int b) {
  if (a % b == 0) {
    return (b);
  } else {
    return (gcd(b, a % b));
  }
}
int lcm(int a, int b) { return a * b / gcd(a, b); }
bool isPrime(int a) {
  if (a == 1)     return false;
  if (a == 2)     return true;
  if (a % 2 == 0) return false;
  for (int i = 3; i < sqrt(a) + 1; i += 2) if (a != i and a%i==0) return false;
  return true;
}

void execute(){

  int n,k;
  cin>>n>>k;
  vector<int> p(n);
  REP(i,0,n)cin>>p[i];

  sort(p.begin(),p.end());

  int sum=0;
  REP(i,0,k){
    sum+=p[i];
  }
  cout<<sum<<endl;

}
int main() {

  cin.tie(0);
  ios::sync_with_stdio(0);
  //cout<<fixed<<setprecision(20);

  execute();

  return 0;
}

