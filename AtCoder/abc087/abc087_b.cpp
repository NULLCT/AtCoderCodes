/*-----------------------------------------------,
|  __                                       __   |
| |  |--.-----.---.-.----.----.-----.-----.|  |_ |
| |  _  |  -__|  _  |  __|  __|  -__|  _  ||   _||
| |_____|_____|___._|____|____|_____|   __||____||
|                                   |__|         |
`-----------------------------------------------*/
#include<algorithm>
#include<array>
#include<bitset>
#include<cctype>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
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
typedef long long ll; typedef long double ld ;using namespace std;
#define INF 1000000000000
#define MOD 10000007
#define ALL(name) (name).begin(),(name).end()
#define REP(counter, limit) for (long long counter = 0; counter < limit; counter++)
int gcd(int a, int b) { if (a % b == 0) { return(b); } else { return(gcd(b, a % b)); } }
int lcm(int a, int b) { return a * b / gcd(a, b); }
bool primenum(int a) { if (a == 1) { return false; }if (a == 2) { return true; }if (a % 2 == 0) { return false; }for (int i = 3; i < sqrt(a) + 1; i += 2) { if (a != i) { if (a % i == 0) { return false; } } }return true; }
struct setupios{setupios(){ios::sync_with_stdio(0);cin.tie(nullptr); /*cout<<fixed<<setprecision(20);*/};}setupios;
int main() {

  int a,b,c,x;
  int ans=0;
  cin>>a>>b>>c>>x;
  for(int q=0;q<=a;q++){
    for(int w=0;w<=b;w++){
      for(int e=0;e<=c;e++){
        if(q*500+w*100+e*50==x){
          ans++;
        }
      }
    }
  }
  cout<<ans<<endl;
}

