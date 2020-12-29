//      _        ____   //
//  U  /"\  u U /"___|  //
//   \/ _ \/  \| | u    //
//   / ___ \   | |/__   //
//  /_/   \_\   \____|  //
//   \\    >>  _// \\   //
//  (__)  (__)(__)(__)  //
//  Compro by NULLCT   //

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")

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
#include <list>
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

#define int int64_t
#ifdef DEBUG
#define PRINTVAR(var) cout << #var << ": " << var << endl;
#define PRINTARR(var)                    \
  cout << #var << ":\n";                 \
  for (const auto &printarrvar : var)    \
    cout << "  " << printarrvar << "\n"; \
  cout << flush;
#define PRINTBOX(var)                    \
  cout << #var << ":\n  ";                 \
  for (const auto &wrap : var) {         \
    for (const auto &printarrvar : wrap) \
      cout << printarrvar << " ";        \
    cout << "\n  ";                        \
  }                                      \
  cout << endl;
#else
  #define PRINTVAR(var) ;
  #define PRINTARR(var) ;
  #define PRINTBOX(var) ;
#endif

using namespace std;

template <int MOD> class ModNum {
public:
  int num;

  constexpr ModNum(int v = 0) noexcept : num(v % MOD) {
    if (num < 0)
      num += MOD;
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
    if (num >= MOD)
      num -= MOD;
    return *this;
  }
  constexpr ModNum &operator-=(const ModNum &r) noexcept {
    num -= r.num;
    if (num < 0)
      num += MOD;
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
    if (num < 0)
      num += MOD;
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
    if (n == 0)
      return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1)
      t = t * a;
    return t;
  }
};

class UnionFind {
public:
  int n;
  vector<int> par;

  UnionFind() : n(0) {}
  UnionFind(int _n) : n(_n), par(_n, -1) {}
  int merge(int a, int b) {
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
    int x = root(a), y = root(b);
    if (x == y)
      return x;
    if (-par[x] < -par[y])
      swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return x;
  }
  bool isSame(int a, int b) {
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
    return root(a) == root(b);
  }
  int root(int a) {
    assert(0 <= a && a < n);
    if (par[a] < 0)
      return a;
    return par[a] = root(par[a]);
  }
  int size(int a) {
    assert(0 <= a && a < n);
    return -par[root(a)];
  }
  vector<vector<int>> groups() {
    vector<int> leader_buf(n), group_size(n);
    for (int i = 0; i < n; i++) {
      leader_buf[i] = root(i);
      group_size[leader_buf[i]]++;
    }
    vector<vector<int>> result(n);
    for (int i = 0; i < n; i++)
      result[i].reserve(group_size[i]);
    for (int i = 0; i < n; i++)
      result[leader_buf[i]].push_back(i);
    result.erase(remove_if(result.begin(), result.end(), [&](const vector<int> &v) { return v.empty(); }), result.end());
    return result;
  }
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

int kadanes(vector<int>::iterator _begin, const vector<int>::iterator _end) {
  int highestMax = 0, currentMax = 0;
  for (; _begin < _end; _begin++) {
    currentMax = max(*_begin, currentMax + *_begin);
    highestMax = max(highestMax, currentMax);
  }
  return highestMax;
}

int dichotomy(int ng,int ok,function<bool(int)> discriminant){
  while(ok - ng > 1){
    int mid = (ng + ok) / 2;
    (discriminant(mid) ? ok : ng) = mid;
  }
  return ok;
}

void execution();

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  execution();
  return 0;
}

#define REP(var, lim) for (int var = 0; var < lim; var++)
#define FOR(var, begin, end) for (int var = begin; var < end; var++)
#define ALL(var) var.begin(), var.end()
#define LEN(var) static_cast<long long>(var.size())
//--------------------------------------------------------------
enum fieldstatus{
  //for field
  NONE=0,
  BLOK=2,

  //for tate and yoko
  LIGH=3,
  DARK=4
};
inline void execution() {
  int h,w,n,m;cin>>h>>w>>n>>m;
  vector<vector<int>> field(h,vector<int>(w,NONE));
  vector<pair<int,int>> light(n);

  for(auto &i:light){
    int a,b;cin>>a>>b;
    i = {a-1,b-1};
  }
  while(m--){
    int c,d;cin>>c>>d;
    field[c-1][d-1]=BLOK;
  }

  PRINTBOX(field);

  vector<vector<int>> yoko(h,vector<int>(w,DARK));
  for(auto i:light){
    if(yoko[i.first][i.second] == DARK){
      for(int j=i.second;j<w;j++){
        if(field[i.first][j] == BLOK){
          break;
        }
        yoko[i.first][j] = LIGH;
      }
      for(int j=i.second;j>=0;j--){
        if(field[i.first][j] == BLOK){
          break;
        }
        yoko[i.first][j] = LIGH;
      }
    }
  }

  vector<vector<int>> tate(h,vector<int>(w,DARK));
  for(auto i:light){
    if(tate[i.first][i.second] == DARK){
      for(int j=i.first;j<h;j++){
        if(field[j][i.second] == BLOK)
          break;
        tate[j][i.second] = LIGH;
      }
      for(int j=i.first;j>=0;j--){
        if(field[j][i.second] == BLOK)
          break;
        tate[j][i.second] = LIGH;
      }
    }
  }

  PRINTBOX(yoko);
  PRINTBOX(tate);

  int ans=0;
  for(int i=0;i<h;i++) for(int j=0;j<w;j++){
    if(yoko[i][j] == LIGH or tate[i][j] == LIGH){
      ans++;
    }
  }
  cout<<ans<<"\n";
}

