/* ( ε:)( ε:)(:ε )(:ε ) */
/* ( ε:)Give me AC(:ε ) */
/* ( ε:)( ε:)(:ε )(:ε ) */
#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdlib>
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

#define REP(count_ver, lower, upper) for (long long count_ver = lower; count_ver < upper; count_ver++)

typedef long long ll;
using namespace std;
const int MOD=10000007;

int gcd(int a, int b) {
  if (a % b == 0) return (b);
  else            return (gcd(b, a % b));
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

vector<long long> divisor(long long n) {
  vector<long long> ret;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n) ret.push_back(n / i);
    }
  }
  return (ret);
}

//--------------------------------

void execute(){
  int n;
  cin>>n;
  int ac=0,wa=0,tle=0,re=0;
  REP(i,0,n){
    string s;
    cin>>s;
    if(s=="AC"){
      ac++;
    }
    if(s=="WA"){
      wa++;
    }
    if(s=="TLE"){
      tle++;
    }
    if(s=="RE"){
      re++;
    }
  }
  cout<<"AC x "<<ac<<endl;
  cout<<"WA x "<<wa<<endl;
  cout<<"TLE x "<<tle<<endl;
  cout<<"RE x "<<re<<endl;
}

//--------------------------------

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  //cout<<fixed<<setprecision(20);

  execute();

  return (0);
}

