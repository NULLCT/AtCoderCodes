///////////////////////////////////////////////////
/* __                                       __   */
/*|  |--.-----.---.-.----.----.-----.-----.|  |_ */
/*|  _  |  -__|  _  |  __|  __|  -__|  _  ||   _|*/
/*|_____|_____|___._|____|____|_____|   __||____|*/
/*                                  |__|         */
///////////////////////////////////////////////////
#include<algorithm>
#include<bitset>
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
typedef long long lint; using namespace std;
#define rep(counter, limit) for (int counter = 0; counter < limit; counter++)
#define INF 1000000000000
#define MOD 10000007
int gcd(int a, int b) { if (a % b == 0) { return(b); } else { return(gcd(b, a % b)); } }
int lcm(int a, int b) { return a * b / gcd(a, b); }
bool primenum(int a) { if (a == 1) { return false; }if (a == 2) { return true; }if (a % 2 == 0) { return false; }for (int i = 3; i < sqrt(a) + 1; i += 2) { if (a != i) { if (a % i == 0) { return false; } } }return true; }
struct setupios{setupios(){cin.tie(0);ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);};}setupios;
int main() {

  int n,m,c;
  cin>>n>>m>>c;
  vector<int> b(m);
  vector<vector<int> > a(n,vector<int>(m));
  rep(i,m)cin>>b[i];
  rep(q,n)rep(i,m)cin>>a[q][i];
  int ans=0;

  rep(q,n){
    int sum=0;
    rep(i,m){
      sum+=(b[i]*a[q][i]);
    }
    sum+=c;
    if(sum > 0){
      ans++;
    }
  }
  cout<<ans<<endl;

}

