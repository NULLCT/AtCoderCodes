#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  pair<int,int> a,b,c;
  cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
  cout<<(a.first^b.first^c.first)<<" "<<(a.second^b.second^c.second)<<"\n";
}

