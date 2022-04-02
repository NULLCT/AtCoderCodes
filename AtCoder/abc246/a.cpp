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
  short a,b,c, d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  cout<<(a^c^e)<<" "<<(b^d^f)<<"\n";
}

