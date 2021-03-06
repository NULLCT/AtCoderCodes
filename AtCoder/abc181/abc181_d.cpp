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
#ifdef DEBUG
#define cerr cout
#endif

using namespace std;
using boost::irange;
using boost::multiprecision::cpp_int;

constexpr long MOD = 1000000007;

class UnionFind {
public:
  vector<long> par;

  UnionFind(long _n) : par(_n, -1) {}
  long root(long _n) {
    if (par[_n] < 0)
      return _n;
    else
      return par[_n] = root(par[_n]);
  }
  bool unite(long _main, long _sub) {
    long mainroot = root(_main);
    long subroot = root(_sub);
    if (mainroot == subroot)
      return false;
    par[mainroot] += par[subroot];
    par[subroot] = mainroot;
    return true;
  }
  bool isSame(long _x, long _y) { return root(_x) == root(_y); }
  long size(long _n) { return -par[root(_n)]; }
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

long kadanes(const vector<long> &_n) {
  long highestMax = 0, currentMax = 0, length = _n.size();
  for (long i = 0; i < length; i++) {
    currentMax = max(_n[i], currentMax + _n[i]);
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
  string str;
  cin>>str;

  if (str.size() < 3) {
    if(str.size() == 2){
      if (((str[1] - '0') * 10 + (str[0] - '0')) % 8 == 0 or ((str[0] - '0') * 10 + (str[1] - '0')) % 8 == 0) {
        cout<<"Yes\n";
        return;
      }
    } else {
      if (str == "8") {
        cout<<"Yes\n";
        return;
      }
    }
    cout<<"No\n";
    return;
  }

  vector<int> cnts(10,0);

  for (int i : str) {
    cnts[i-'0']++;
  }

  for (int i = 0; i < 1000; i += 8) {
    string s=to_string(i);
    if (s.size() == 1)
      s="0"+s;
    if (s.size() == 2)
      s="0"+s;

    vector<int> cntnum(10,0);

    for (int i = 0; i < 3; i++) {
      cntnum[s[i]-'0']++;
    }

    bool tr=false;
    for (int i = 0; i < 10; i++) {
      if (cnts[i] < cntnum[i])
        tr=true;
    }

    if (!tr) {
      cout<<"Yes\n";
      return;
    }
  }
  cout<<"No\n";
}

