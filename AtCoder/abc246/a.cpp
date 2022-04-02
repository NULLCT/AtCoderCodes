/*                 _        ____              */
/*   AC        U  /"\  u U /"___|     AC      */
/*              \/ _ \/  \| | u               */
/*        AC    / ___ \   | |/__    AC        */
/*             /_/   \_\   \____|             */
/* AC           \\    >>  _// \\         AC   */
/*             (__)  (__)(__)(__)             */
/*          github.com/NULLCT/Compro          */
/*            Copyriaht (c) NULLCT            */
/*   Code is written at the bottom function   */

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

void execution();

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  execution();
}

class Scanner {
  vector<char> buffer;
  ssize_t n_written;
  ssize_t n_read;

public:
  Scanner() : buffer(1024 * 1024) { do_read(); }

  int64_t read_int() {
    int64_t ret = 0, sgn = 1;
    int ch = current_char();
    while (isspace(ch)) {
      ch = next_char();
    }
    if (ch == '-') {
      sgn = -1;
      ch = next_char();
    }
    for (; isdigit(ch); ch = next_char())
      ret = (ret * 10) + (ch - '0');
    return sgn * ret;
  }

private:
  void do_read() {
    ssize_t r = read(0, &buffer[0], buffer.size());
    n_written = r;
    n_read = 0;
  }

  inline int next_char() {
    ++n_read;
    if (n_read == n_written) {
      do_read();
    }
    return current_char();
  }

  inline int current_char() {
    return (n_read == n_written) ? EOF : buffer[n_read];
  }
};

void execution() {
  Scanner s;
  pair<int,int> a,b,c;
  a.first=s.read_int();
  a.second=s.read_int();
  b.first=s.read_int();
  b.second=s.read_int();
  c.first=s.read_int();
  c.second=s.read_int();
  cout<<(a.first^b.first^c.first)<<" "<<(a.second^b.second^c.second)<<"\n";
}

