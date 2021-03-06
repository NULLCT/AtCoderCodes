//      _        ____   //
//  U  /"\  u U /"___|  //
//   \/ _ \/  \| | u    //
//   / ___ \   | |/__   //
//  /_/   \_\   \____|  //
//   \\    >>  _// \\   //
//  (__)  (__)(__)(__)  //
//  Compro by NULLCT   //

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cinttypes>
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
#include <ostream>
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

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/range/irange.hpp>

#define int int64_t

using namespace std;
using boost::irange;
using boost::multiprecision::cpp_int;

template <int MOD> class ModNum {
public:
  int num;

  constexpr ModNum(int v = 0) noexcept : num(v % MOD) {
    if (num < 0) num += MOD;
  }
  constexpr int getmod() { return MOD; }
  constexpr ModNum operator-() const noexcept { return num ? MOD - num : 0; }
  constexpr ModNum operator+(const ModNum &r) const noexcept {
    return ModNum(*this) += r;
  }
  constexpr ModNum operator-(const ModNum &r) const noexcept {
    return ModNum(*this) -= r;
  }
  constexpr ModNum operator*(const ModNum &r) const noexcept {
    return ModNum(*this) *= r;
  }
  constexpr ModNum operator/(const ModNum &r) const noexcept {
    return ModNum(*this) /= r;
  }
  constexpr ModNum &operator+=(const ModNum &r) noexcept {
    num += r.num;
    if (num >= MOD) num -= MOD;
    return *this;
  }
  constexpr ModNum &operator-=(const ModNum &r) noexcept {
    num -= r.num;
    if (num < 0) num += MOD;
    return *this;
  }
  constexpr ModNum &operator*=(const ModNum &r) noexcept {
    num = num * r.num % MOD;
    return *this;
  }
  constexpr ModNum &operator/=(const ModNum &r) noexcept {
    int a = r.num, b = MOD, u = 1, v = 0;
    while (b) {
      int t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    num = num * u % MOD;
    if (num < 0) num += MOD;
    return *this;
  }
  constexpr bool operator==(const ModNum &r) const noexcept {
    return this->num == r.num;
  }
  constexpr bool operator!=(const ModNum &r) const noexcept {
    return this->num != r.val;
  }
  friend constexpr ostream &operator<<(ostream &os, const ModNum<MOD> &x) noexcept {
    return os << x.num;
  }
  friend constexpr ModNum<MOD> modpow(const ModNum<MOD> &a, int n) noexcept {
    if (n == 0) return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
  }
};

class UnionFind {
public:
  vector<int> par;

  UnionFind(const int _n) : par(_n, -1) {}
  int root(const int _n) {
    if (par[_n] < 0)
      return _n;
    else
      return par[_n] = root(par[_n]);
  }
  bool unite(const int _main, const int _sub) {
    int mainroot = root(_main);
    int subroot = root(_sub);
    if (mainroot == subroot)
      return false;
    par[mainroot] += par[subroot];
    par[subroot] = mainroot;
    return true;
  }
  bool isSame(const int _x,const int _y) { return root(_x) == root(_y); }
  int size(const int _n) { return -par[root(_n)]; }
};

vector<int> divisor(const int _n) {
  vector<int> head, tail;
  for (int i = 1; i * i <= _n; i++) {
    if (_n % i == 0) {
      head.push_back(i);
      if (i * i != _n)
        tail.push_back(_n / i);
    }
  }
  head.insert(head.end(), tail.rbegin(), tail.rend());
  return head;
}

int kadanes(vector<int>::iterator _begin,const vector<int>::iterator _end) {
  int highestMax = 0, currentMax = 0;
  for (;_begin < _end;_begin++) {
    currentMax = max(*_begin, currentMax + *_begin);
    highestMax = max(highestMax, currentMax);
  }
  return highestMax;
}

void execution();

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  execution();
  return 0;
}

//--------------------------------------------------------------
double dp[101][101][101];
double func(int a,int b,int c){
  if(dp[a][b][c])
    return dp[a][b][c];

  if(a == 100 or b == 100 or c == 100)
    return 0;

  double ans = 0;

  ans+=(func(a+1,b,c)+1)*a/(a+b+c);
  ans+=(func(a,b+1,c)+1)*b/(a+b+c);
  ans+=(func(a,b,c+1)+1)*c/(a+b+c);
  
  dp[a][b][c]=ans;
  return ans;
}
inline void execution() {
  int a,b,c;
  cin>>a>>b>>c;

  cout<<func(a,b,c)<<"\n";
}

