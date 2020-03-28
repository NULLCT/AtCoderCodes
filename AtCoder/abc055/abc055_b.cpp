///////////////////////////////////////////
//root@NULLCT$(☝ ՞ਊ ՞)☝  << "Be accept!!"//
///////////////////////////////////////////
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <iostream>  // cout, endl, cin
#include <map>       // map
#include <queue>     // queue, priority_queue
#include <string>    // string, to_string, stoi
#include <tuple>     // tuple, make_tuple
#include <vector>        // vector
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
using namespace std;
int gcd(int a, int b) { if (a % b == 0) { return(b); } else { return(gcd(b, a % b)); } }
int lcm(int a, int b) { return a * b / gcd(a, b); }
int kuriup(double a) { int b = int(a); if (a != b) { return b + 1; } else { return b; } }
int kuridown(double a) { int b = int(a); return b; }
int main() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  ll a;
  cin>>a;
  ll power=1;
  rep(i,a){
    power=(power*(i+1))%1000000007;
  }

  cout<<power<<endl;

  return 0;
}


