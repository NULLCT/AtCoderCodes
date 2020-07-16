/*------------------------------------------------,
|  __                                       __    |
| |  |--.-----.---.-.----.----.-----.-----.|  |_  |
| |  _  |  -__|  _  |  __|  __|  -__|  _  ||   _| |
| |_____|_____|___._|____|____|_____|   __||____| |
|                                   |__|          |
`------------------------------------------------*/
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdint>
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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define MOD 10000007
#define REP(i, lower, upper) for (long long i = lower; i < upper; i++)
#define ALL(ls) ls.begin(), ls.end()
typedef long long ll;
using namespace std;

int gcd(int a, int b) {
  if (a % b == 0) {
    return (b);
  } else {
    return (gcd(b, a % b));
  }
}
int lcm(int a, int b) { return a * b / gcd(a, b); }
vector<long long> divisor(long long n) {// if 2,it's prime
  vector<long long> ret;
  for(long long i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  return (ret);
}

void execute(){

  int h;
  int w;
  int k;
  cin >> h >> w >> k;
  char mark[h][w];
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> mark[i][j];
    }
  }
  int ans = 0;
  for (int bith = 0; bith < (1 << h); bith++)
  {
    for (int bitw = 0; bitw < (1 << w); bitw++)
    {
      int black = 0;
      for (int i = 0; i < h; i++)
      {
        for (int j = 0; j < w; j++)
        {
          if (!(bith & (1 << i)) && !(bitw & (1 << j)))
          {
            if (mark[i][j] == '#')
              black++;
          }
        }
      }
      if (black == k)
        ans++;
    }
  }
  cout << ans << endl;
}
int main() {

  cin.tie(0);
  ios::sync_with_stdio(0);
  //cout<<fixed<<setprecision(20);

  execute();

  return 0;
}

