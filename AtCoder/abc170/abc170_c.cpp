/*------------------------------------------------,
|  __                                       __    |
| |  |--.-----.---.-.----.----.-----.-----.|  |_  |
| |  _  |  -__|  _  |  __|  __|  -__|  _  ||   _| |
| |_____|_____|___._|____|____|_____|   __||____| |
|                                   |__|          |
`------------------------------------------------*/
#include<algorithm>
#include<array>
#include<bitset>
#include<cmath>
#include<complex>
#include<cstdint>
#include<deque>
#include<functional>
#include<iomanip>
#include<ios>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
typedef long long ll; using namespace std;
#define INF 2147483647
#define MOD 10000007
#define REP(counter, limit) for (long long counter = 0; counter < limit; counter++)
int gcd(int a, int b) { if (a % b == 0) { return(b); } else { return(gcd(b, a % b)); } }
int lcm(int a, int b) { return a * b / gcd(a, b); }
bool primenum(int a) { if (a == 1) { return false; }if (a == 2) { return true; }if (a % 2 == 0) { return false; }for (int i = 3; i < sqrt(a) + 1; i += 2) { if (a != i) { if (a % i == 0) { return false; } } }return true; }
struct setupios{setupios(){cin.tie(0);ios::sync_with_stdio(0); /*cout<<fixed<<setprecision(20);*/};}setupios;
int main() {

  int x,n;
  cin>>x>>n;
  vector<int> p(n);
  REP(i,n)cin>>p[i];

  int ans=MOD;
  for(int i=-1;i<102;i++){
    bool tr=false;
    REP(j,p.size()){
      if(i==p[j]){
        tr=true;
        break;
      }
    }
    if(!tr){
      if(abs(ans-x) > abs(x-i)){
        ans=i;
      }
    }
  }
  cout<<ans<<endl;

}

