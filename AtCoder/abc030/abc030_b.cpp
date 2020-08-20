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
      if (i * i != _n)
        tail.push_back(_n / i);
    }
  }
  head.insert(head.end(), tail.rbegin(), tail.rend());
  return head;
}

long kadanes(vector<long> &_ls) {
  long highestmax=0,currentmax=0,length=_ls.size();
  for(long i=0;i<length;i++){
    currentmax=max(_ls[i],currentmax+_ls[i]);
    highestmax=max(highestmax,currentmax);
  }
  return highestmax;
}

struct init {
  init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    //cout<<fixed<<setprecision(20);
  }
} init;

/*----------------------------*/

int main() {
  double h,m;
  cin>>h>>m;

  if(12 <= h)h-=12;
  h=h*30+(m/2);
  m*=6;

  double ans=0;
  ans=fabs(h-m);
  if(h < m)
    h+=360;
  else
    m+=360;
  ans=min(ans,fabs(h-m));
  cout<<ans<<"\n";
}

