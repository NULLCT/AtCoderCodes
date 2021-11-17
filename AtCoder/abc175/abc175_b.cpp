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
constexpr long INF = LONG_MAX;

vector<long> divisor(long n) {
  vector<long> head, tail;
  for (long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      head.push_back(i);
      if (i * i != n)
        tail.push_back(n / i);
    }
  }
  head.insert(head.end(), tail.rbegin(), tail.rend());
  return (head);
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
  cin>>n;

  vector<long> l(n);
  REP(i,n)cin>>l[i];

  int ans=0;

  for(int i=0;i<n-2;i++){
    for(int j=i+1;j<n-1;j++){
      for(int k=j+1;k<n;k++){
        vector<int> list(3);
        list[0]=l[i];
        list[1]=l[j];
        list[2]=l[k];
        sort(ALL(list));
        if(list[0] != list[1] and list[1] != list[2]){
          if(list[0]+list[1] > list[2]){
            ans++;
          }
        }
      }
    }
  }
  cout<<ans<<endl;
}

