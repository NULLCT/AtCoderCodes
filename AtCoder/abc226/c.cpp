#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define int long long

using namespace std;

struct tk{
  int t,k;
  vector<int> a;
};
vector<tk> a;
vector<bool> trs;

int dfs(int n){
  int sum = a[n].t;
  for(auto &i:a[n].a){
    if(not trs[i-1]){
      sum += dfs(i-1);
    }
  }
  trs[n] = true;

  return sum;
}

signed main() {
  int n;cin>>n;

  a.resize(n);
  trs.resize(n,false); // true -> syuutoku

  for(int i=0;i<n;i++){
    int t,k;cin>>t>>k;
    a[i].t = t;
    a[i].k = k;
    a[i].a.resize(k);
    for(auto &i:a[i].a){
      cin>>i;
    }
  }

  cout<<dfs(n-1)<<"\n";
}

