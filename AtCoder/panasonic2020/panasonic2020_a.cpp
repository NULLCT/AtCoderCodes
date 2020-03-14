///////////////////////////////////////////
//root@NULLCT$(☝ ՞ਊ ՞)☝  << "Be accept!!"//
///////////////////////////////////////////
//#define BOOST
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>    // bitset
#include <cctype>    // isupper, islower, isdigit, toupper, tolower
#include <cstdint>   // int66_t, int*_t
#include <cstdio>    // printf
#include <deque>     // deque
#include <iomanip>   //setfill(char)
#include <ios>       //left,right
#include <iostream>  // cout, endl, cin
#include <map>       // map
#include <queue>     // queue, priority_queue
#include <set>       // set
#include <stack>     // stack
#include <string>    // string, to_string, stoi
#include <tuple>     // tuple, make_tuple
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <utility>       // pair, make_pair
#include <vector>        // vector
#ifdef BOOST
#include <boost/multiprecision/cpp_int.hpp> // cpp_int
using namespace boost::multiprecision;
#endif
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;
using namespace std;
int setup(void) { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0; }
int lenght(char* str) { int i = 0; while (str[i])i++; return i; }
int gcd(int a, int b) { if (a % b == 0) { return(b); } else { return(gcd(b, a % b)); } }
int lcm(int a, int b) { return a * b / gcd(a, b); }
int iinput(void) { int a = 0; cin >> a; return a; }
int dinput(void) { double a = 0; cin >> a; return a; }
string sinput(void) { string a = ""; cin >> a; return a; }
int kuriup(double a) { int b = int(a); if (a != b) { return b + 1; } else { return b; } }
int kuridown(double a) { int b = int(a); return b; }
int run(void);
int main() { setup(); run(); return 0; }
/////////////////////////////////////////////////////////////////////////////////////////
int run(void) {

  int list[32]= {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  int a=iinput();
  cout<<list[a-1]<<endl;

  return 0;
}

