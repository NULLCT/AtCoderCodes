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
#define rep(counter, limit) for (int counter = 0; counter < (limit); counter++)
#define INF 1000000000000
#define MOD 10000007
int gcd(int a, int b) { if (a % b == 0) { return(b); } else { return(gcd(b, a % b)); } }
int lcm(int a, int b) { return a * b / gcd(a, b); }
bool primenum(int a) { if (a == 1) { return false; }if (a == 2) { return true; }if (a % 2 == 0) { return false; }for (int i = 3; i < sqrt(a) + 1; i += 2) { if (a != i) { if (a % i == 0) { return false; } } }return true; }
struct setupios{setupios(){cin.tie(0);ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);};}setupios;
int main() {

  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(n);
  rep(i,n){
    if(s[i] == 'R') a[i] = 0;
    if(s[i] == 'G') a[i] = 1;
    if(s[i] == 'B') a[i] = 2;
  }
  vector<int> cnt(3);
  rep(i,n) cnt[a[i]]++;
  lint ans = 1;
  rep(i,3) ans *= cnt[i];
  rep(j,n)rep(i,j){
    int k = j + (j - i);
    if(k < n){
      if(a[i] == a[j]) continue;
      if(a[i] == a[k]) continue;
      if(a[j] == a[k]) continue;
      ans--;
    }
  }
  cout << ans << endl;
  return 0;

}

