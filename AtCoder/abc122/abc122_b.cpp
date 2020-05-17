#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;

  string T = "ACGT";
  int ans = 0;

  for (int i = 0; i < str.size(); i++) {
    int num = 0;
    for (int j = i; j < str.size(); j++) {
      bool ok = false;
      for (int k = 0; k < T.size(); k++) {
        if (str[j] == T[k]) {
          num++;
          ok = true;
        }
      }
      if (ok == false) {
        break;
      }
    }
    ans = max(ans, num);
  }
  cout << ans << endl;
}

