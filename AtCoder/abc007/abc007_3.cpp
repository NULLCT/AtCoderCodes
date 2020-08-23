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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define REP(I, LIM) for (int I = 0; I < (LIM); I++)
#define ALL(LIST) (LIST.begin()), (LIST.end())

using namespace std;

constexpr int MOD = 10000007;

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
  int h, w, bx, by, gx, gy;
  cin >> h >> w >> by >> bx >> gy >> gx;
  char f[w][h];
  vector<vector<int>> n(w, vector<int>(h, 0));
  bx--; by--; gx--; gy--;
  REP(j,h){ REP(i, w) { cin >> f[i][j]; } }

  queue<pair<int, int>> que;
  que.push(make_pair(bx, by));
  f[bx][by] = '@';

  int cnt = 0;

  while(!que.empty()){
    pair<int, int> sv = que.front();
    que.pop();
    if(n[gx][gy] != 0){
      cout << n[gx][gy] << "\n";
      return 0;
    }

    if(f[sv.first+1][sv.second] == '.'){
      que.push(make_pair(sv.first + 1, sv.second));
      f[sv.first+1][sv.second] = '@';
      n[sv.first + 1][sv.second] = n[sv.first][sv.second]+1;
    }
    if(f[sv.first][sv.second+1] == '.'){
      que.push(make_pair(sv.first, sv.second+1));
      f[sv.first][sv.second+1] = '@';
      n[sv.first][sv.second+1] = n[sv.first][sv.second]+1;
    }
    if(f[sv.first-1][sv.second] == '.'){
      que.push(make_pair(sv.first-1, sv.second));
      f[sv.first-1][sv.second] = '@';
      n[sv.first - 1][sv.second] = n[sv.first][sv.second]+1;
    }
    if(f[sv.first][sv.second-1] == '.'){
      que.push(make_pair(sv.first, sv.second-1));
      f[sv.first][sv.second-1] = '@';
      n[sv.first][sv.second-1] = n[sv.first][sv.second]+1;
    }
    cnt++;
  }
}

