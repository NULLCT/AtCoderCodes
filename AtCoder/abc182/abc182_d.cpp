//////////////////////////
//      _        ____   //
//  U  /"\  u U /"___|  //
//   \/ _ \/  \| | u    //
//   / ___ \   | |/__   //
//  /_/   \_\   \____|  //
//   \\    >>  _// \\   //
//  (__)  (__)(__)(__)  //
//  Compro by NULLCT   //
//////////////////////////
// STL libs
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

// Boost
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/range/irange.hpp>

#define ALL(LIST) (LIST.begin()), (LIST.end())

using namespace std;
using boost::irange;
using boost::multiprecision::cpp_int;

constexpr long MOD = 1000000007;

class UnionFind {
public:
  vector<long> par;

  UnionFind(const long _n) : par(_n, -1) {}
  long root(const long _n) {
    if (par[_n] < 0)
      return _n;
    else
      return par[_n] = root(par[_n]);
  }
  bool unite(const long _main, const long _sub) {
    long mainroot = root(_main);
    long subroot = root(_sub);
    if (mainroot == subroot)
      return false;
    par[mainroot] += par[subroot];
    par[subroot] = mainroot;
    return true;
  }
  bool isSame(const long _x,const long _y) { return root(_x) == root(_y); }
  long size(const long _n) { return -par[root(_n)]; }
};

vector<long> divisor(const long _n) {
  vector<long> head, tail;
  for (long i = 1; i * i <= _n; i++) {
    if (_n % i == 0) {
      head.push_back(i);
      if (i * i != _n)
        tail.push_back(_n / i);
    }
  }
  head.insert(head.end(), tail.rbegin(), tail.rend());
  return head;
}

long kadanes(vector<long>::iterator _begin,const vector<long>::iterator _end) {
  long highestMax = 0, currentMax = 0;
  for (;_begin < _end;_begin++) {
    currentMax = max(*_begin, currentMax + *_begin);
    highestMax = max(highestMax, currentMax);
  }
  return highestMax;
}

void execution();

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  execution();
  return 0;
}

#define int long
//--------------------------------------------------------------
inline void execution() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin>>i;

  cpp_int sum=0; //a[0 .. i] の合計値
  cpp_int pos=0; //現在位置
  cpp_int maxiinsum = 0; // sumの中で最も絶対値が大きくなる瞬間の値
  cpp_int ans=0; //答え
  for (int i = 0; i < n; i++) {
    sum += a[i]; //合計更新
    maxiinsum = max(maxiinsum,sum);
    ans=max(ans,maxiinsum+pos);
    pos += sum; //場所更新
  }
  cout<<ans<<"\n";
}

