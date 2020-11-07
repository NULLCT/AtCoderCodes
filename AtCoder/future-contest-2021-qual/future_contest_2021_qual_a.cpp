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
  vector<vector<int>> dise(20,vector<int>(20,0));
  vector<pair<int,int>> list(101);
  list[0]=make_pair(0, 0);
  for (int i = 1; i < 101; i++) {
    cin>>list[i].second>>list[i].first;
  }

  for (int i = 1; i < 101; i++) {

    if (i == 99) {
      //98 (99 100)
      if (abs(list[98].first - list[99].first) +
              abs(list[98].second - list[99].second) +
              abs(list[99].first - list[100].first) +
              abs(list[99].second - list[100].second) >
          abs(list[98].first - list[100].first) +
              abs(list[98].second - list[100].second) +
              abs(list[100].first - list[99].first) +
              abs(list[100].second - list[99].second) + 5) {
        swap(list[99],list[100]);
        //X
        if (list[i-1].first > list[i].first) {
          for (int j = 0; j < list[i-1].first - list[i].first; j++) {
            cout<<"L";
          }
        } else if (list[i-1].first < list[i].first) {
          for (int j = 0; j < list[i].first - list[i-1].first; j++) {
            cout<<"R";
          }
        }
        //Y
        if (list[i-1].second > list[i].second) {
          for (int j = 0; j < list[i-1].second - list[i].second; j++) {
            cout<<"U";
          }
        } else if (list[i-1].second < list[i].second) {
          for (int j = 0; j < list[i].second - list[i-1].second; j++) {
            cout<<"D";
          }
        }
        cout<<"I";
        i++;
        int type=-1;
        //2
        if (list[i-1].first > list[i].first) {
          for (int j = 0; j < list[i-1].first - list[i].first; j++) {
            if (j + 1 == list[i - 1].first - list[i].first) {
              type=0;
              break;
            }
            cout<<"L";
          }
        } else if (list[i-1].first < list[i].first) {
          for (int j = 0; j < list[i].first - list[i-1].first; j++) {
            if (j + 1 == list[i - 1].first - list[i].first) {
              type = 1;
              break;
            }
            cout<<"R";
          }
        }

        //Y
        if (list[i-1].second > list[i].second) {
          for (int j = 0; j < list[i-1].second - list[i].second; j++) {
            if (type == -1 and j + 1 == list[i - 1].second - list[i].second) {
              type = 2;
              break;
            }
            cout<<"U";
          }
        } else if (list[i-1].second < list[i].second) {
          for (int j = 0; j < list[i].second - list[i-1].second; j++) {
            if (type == -1 and j + 1 == list[i - 1].second - list[i].second) {
              type = 3;
              break;
            }
            cout<<"D";
          }
        }
        if (type == 0) {//L
          cout<<"OLIRI";
        }
        if (type == 1) {//R
          cout<<"ORILI";
        }
        if (type == 2) {//U
          cout<<"OUIDI";
        }
        if (type == 3) {//D
          cout<<"ODIUI";
        }
        return;
      }
    }

//-----------------------------------------------------------------------------

    //X
    if (list[i-1].first > list[i].first) {
      for (int j = 0; j < list[i-1].first - list[i].first; j++) {
        cout<<"L";
      }
    } else if (list[i-1].first < list[i].first) {
      for (int j = 0; j < list[i].first - list[i-1].first; j++) {
        cout<<"R";
      }
    }
    //Y
    if (list[i-1].second > list[i].second) {
      for (int j = 0; j < list[i-1].second - list[i].second; j++) {
        cout<<"U";
      }
    } else if (list[i-1].second < list[i].second) {
      for (int j = 0; j < list[i].second - list[i-1].second; j++) {
        cout<<"D";
      }
    }
    cout<<"I";
  }
}

