//////////////////////////
//      _        ____   //
//  U  /"\  u U /"___|  //
//   \/ _ \/  \| | u    //
//   / ___ \   | |/__   //
//  /_/   \_\   \____|  //
//   \\    >>  _// \\   //
//  (__)  (__)(__)(__)  //
//  Compro by NULL_CT©  //
//////////////////////////
// STL libs
#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
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
#include <thread>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define REP(I, LIM) for (int I = 0; I < (LIM); I++)
#define ALL(LIST) (LIST.begin()), (LIST.end())

using namespace std;

typedef long long ll;

const int MOD = pow(10,9)+7;

vector<long> divisor(long &_n) {
  vector<long> head, tail;
  for (long i = 1; i * i <= _n; i++) {
    if (_n % i == 0) {
      head.push_back(i);
      if (i * i != _n) tail.push_back(_n / i);
    }
  }
  head.insert(head.end(), tail.rbegin(), tail.rend());
  return head;
}

long kadanes(vector<long> &_ls) {
  long highestMax = 0, currentMax = 0, length = _ls.size();
  for (long i = 0; i < length; i++) {
    currentMax = max(_ls[i], currentMax + _ls[i]);
    highestMax = max(highestMax, currentMax);
  }
  return highestMax;
}

struct init {
  init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // cout<<fixed<<setprecision(20);
  }
} init;

/*----------------------------*/

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> sums(n);
  REP(i,n){ cin>>a[i]; }

  ll ans = 0;

  for (int i = a.size()-1; i != 0; i--){
    if(i == a.size()-1){
      sums[i] = a[i];
    }else{
      sums[i] = (a[i] + sums[i + 1])%MOD;
    }
  }

  for (int i = 0; i < a.size() - 1;i++){
    ans += (a[i] * sums[i + 1]) % MOD;
    ans %= MOD;
  }

  cout << ans << "\n";

  ;
}

