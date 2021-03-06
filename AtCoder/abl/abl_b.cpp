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
#include <boost/algorithm/minmax.hpp>
#include <boost/algorithm/minmax_element.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/range/irange.hpp>

#define ALL(LIST) (LIST.begin()), (LIST.end())

using namespace std;
using boost::irange;
using boost::multiprecision::cpp_int;

constexpr int64_t MOD = 1000000007;

class UnionFind {
public:
  vector<int> par;

  UnionFind(int N) : par(N) {
    for (int i = 0; i < N; i++)
      par[i] = i;
  }
  int root(int x) {
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }
  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry)
      return;
    par[rx] = ry;
  }
  bool isSame(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

vector<int64_t> divisor(const int64_t &_n) {
  vector<int64_t> head, tail;
  for (int64_t i = 1; i * i <= _n; i++) {
    if (_n % i == 0) {
      head.push_back(i);
      if (i * i != _n)
        tail.push_back(_n / i);
    }
  }
  head.insert(head.end(), tail.rbegin(), tail.rend());
  return head;
}

int64_t kadanes(const vector<int64_t> &_ls) {
  int64_t highestMax = 0, currentMax = 0, length = _ls.size();
  for (int64_t i = 0; i < length; i++) {
    currentMax = max(_ls[i], currentMax + _ls[i]);
    highestMax = max(highestMax, currentMax);
  }
  return highestMax;
}

void execution();

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  // cout<<fixed<<setprecision(20);

  execution();
  return 0;
}

//--------------------------------------------------------------
void execution() {
  int64_t a,b,c,d;
  cin>>a>>b>>c>>d;
  int64_t under = max(a,c);
  int64_t upper = min(b,d);
  if(under > upper){
    cout<<"No\n";
  }else{
    cout<<"Yes\n";
  }
}

