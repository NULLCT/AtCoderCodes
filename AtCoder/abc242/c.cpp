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

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define int long long
#define double long double
#define ALL(var) ((var).begin()), ((var).end())
#ifdef DEBUG
#define D(var) cerr << "(\e[34m" << #var << "\e[0m \e[2m@" << __LINE__ << "\e[0m): \e[36m\e[1m" << var << "\e[0m" << endl;
#else
#define D(var) ;
#endif

using namespace std;

template <class T>
ostream &operator<<(ostream &_ostr, const vector<T> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const deque<T> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const list<T> &_v);
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const pair<T, Y> &_v);
template <class... Ts>
ostream &operator<<(ostream &_ostr, const tuple<Ts...> &t);
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const map<T, Y> &_v);
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const multimap<T, Y> &_v);
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const unordered_map<T, Y> &_v);
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const unordered_multimap<T, Y> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const set<T> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const multiset<T> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const unordered_set<T> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const unordered_multiset<T> &_v);

template <class T>
void orange(ostream &_ostr, const T &_v) {
  if (_v.size() == 0)
    return;
  _ostr << *_v.begin();
  for (auto itr = next(_v.begin()); itr != _v.end(); itr++)
    _ostr << " " << *itr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const vector<T> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const deque<T> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const list<T> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const pair<T, Y> &_v) {
  _ostr << _v.first << " " << _v.second;
  return _ostr;
}
template <class... Ts>
ostream &operator<<(ostream &_ostr, const tuple<Ts...> &_v) {
  bool first = true;
  apply([&_ostr, &first](auto &&...args) {
    auto print = [&](auto &&val) {
      if (!first)
        _ostr << " ";
      (_ostr << val);
      first = false;
    };
    (print(args), ...);
  },
        _v);
  return _ostr;
}
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const map<T, Y> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const multimap<T, Y> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const unordered_map<T, Y> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const set<T> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const multiset<T> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const unordered_set<T> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const unordered_multiset<T> &_v) {
  orange(_ostr, _v);
  return _ostr;
}

template <class T, size_t S>
istream &operator>>(istream &_istr, array<T, S> &_v);
template <class T>
istream &operator>>(istream &_istr, vector<T> &_v);
template <class T>
istream &operator>>(istream &_istr, deque<T> &_v);
template <class T, class Y>
istream &operator>>(istream &_istr, pair<T, Y> &_v);

template <class T, size_t S>
istream &operator>>(istream &_istr, array<T, S> &_v) {
  for (auto &i : _v)
    _istr >> i;
  return _istr;
}
template <class T>
istream &operator>>(istream &_istr, vector<T> &_v) {
  for (auto &i : _v)
    _istr >> i;
  return _istr;
}
template <class T>
istream &operator>>(istream &_istr, deque<T> &_v) {
  for (auto &i : _v)
    _istr >> i;
  return _istr;
}
template <class T, class Y>
istream &operator>>(istream &_istr, pair<T, Y> &_v) {
  _istr >> _v.first >> _v.second;
  return _istr;
}

template <int mod>
class ModInt {
public:
  int n;
  constexpr ModInt(const int x = 0) noexcept : n(x % mod) {}
  constexpr ModInt operator+(const ModInt rhs) const noexcept {
    return ModInt(*this) += rhs;
  }
  constexpr ModInt operator-(const ModInt rhs) const noexcept {
    return ModInt(*this) -= rhs;
  }
  constexpr ModInt operator*(const ModInt rhs) const noexcept {
    return ModInt(*this) *= rhs;
  }
  constexpr ModInt operator/(const ModInt rhs) const noexcept {
    return ModInt(*this) /= rhs;
  }
  constexpr ModInt &operator+=(const ModInt rhs) noexcept {
    n += rhs.n;
    if (n >= mod)
      n -= mod;
    return *this;
  }
  constexpr ModInt &operator-=(const ModInt rhs) noexcept {
    if (n < rhs.n)
      n += mod;
    n -= rhs.n;
    return *this;
  }
  constexpr ModInt &operator*=(const ModInt rhs) noexcept {
    n = n * rhs.n % mod;
    return *this;
  }
  constexpr ModInt &operator/=(ModInt rhs) noexcept {
    int exp = mod - 2;
    while (exp) {
      if (exp % 2)
        *this *= rhs;
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
  template <int T>
  friend ostream &operator<<(ostream &_ostr, const ModInt<T> &_v) {
    _ostr << _v.n;
    return _ostr;
  }
};

int modpow(int a, int n, int mod) {
  int res = 1;
  while (n > 0) {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

template <class T>
class SegmentTree {
public:
  int sz;
  vector<T> seg;
  const function<T(T, T)> f;
  const T M1;
  SegmentTree(int n, const function<T(T, T)> f, const T &M1) : f(f), M1(M1) {
    sz = 1;
    while (sz < n)
      sz <<= 1;
    seg.assign(2 * sz, M1);
  }
  void set(int k, const T &x) {
    seg[k + sz] = x;
  }
  void build() {
    for (int k = sz - 1; k > 0; k--)
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
  }
  void update(int k, const T &x) {
    k += sz;
    seg[k] = x;
    while (k >>= 1)
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
  }
  // O(log n)
  T query(int a, int b) {
    T L = M1, R = M1;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1)
        L = f(L, seg[a++]);
      if (b & 1)
        R = f(seg[--b], R);
    }
    return f(L, R);
  }
  T operator[](const int &k) const {
    return seg[k + sz];
  }
  template <class C>
  int find_subtree(int a, const C &check, T &M, bool type) {
    while (a < sz) {
      T nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if (check(nxt))
        a = 2 * a + type;
      else
        M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }
  template <class C>
  int find_first(int a, const C &check) {
    T L = M1;
    if (a <= 0) {
      if (check(f(L, seg[1])))
        return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) {
        T nxt = f(L, seg[a]);
        if (check(nxt))
          return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }
  template <class C>
  int find_last(int b, const C &check) {
    T R = M1;
    if (b >= sz) {
      if (check(f(seg[1], R)))
        return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for (b += sz; a < b; a >>= 1, b >>= 1) {
      if (b & 1) {
        T nxt = f(seg[--b], R);
        if (check(nxt))
          return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

struct SuccinctIndexableDictionary {
  size_t length, blocks;
  vector<unsigned> bit, sum;
  SuccinctIndexableDictionary() = default;
  SuccinctIndexableDictionary(size_t length) : length(length), blocks((length + 31) >> 5) {
    bit.assign(blocks, 0U);
    sum.assign(blocks, 0U);
  }
  void set(int k) {
    bit[k >> 5] |= 1U << (k & 31);
  }
  void build() {
    sum[0] = 0U;
    for (int i = 1; i < blocks; i++)
      sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);
  }
  bool operator[](int k) {
    return (bool((bit[k >> 5] >> (k & 31)) & 1));
  }
  int rank(int k) {
    return (sum[k >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));
  }
  int rank(bool val, int k) {
    return (val ? rank(k) : k - rank(k));
  }
};

template <class T, int MAXLOG>
struct WaveletMatrix {
  size_t length;
  SuccinctIndexableDictionary matrix[MAXLOG];
  int mid[MAXLOG];
  WaveletMatrix() = default;
  WaveletMatrix(vector<T> v) : length(v.size()) {
    vector<T> l(length), r(length);
    for (int level = MAXLOG - 1; level >= 0; level--) {
      matrix[level] = SuccinctIndexableDictionary(length + 1);
      int left = 0, right = 0;
      for (int i = 0; i < length; i++) {
        if (((v[i] >> level) & 1)) {
          matrix[level].set(i);
          r[right++] = v[i];
        } else
          l[left++] = v[i];
      }
      mid[level] = left;
      matrix[level].build();
      v.swap(l);
      for (int i = 0; i < right; i++)
        v[left + i] = r[i];
    }
  }
  pair<int, int> succ(bool f, int l, int r, int level) {
    return {matrix[level].rank(f, l) + mid[level] * f, matrix[level].rank(f, r) + mid[level] * f};
  }
  T access(int k) {
    T ret = 0;
    for (int level = MAXLOG - 1; level >= 0; level--) {
      bool f = matrix[level][k];
      if (f)
        ret |= T(1) << level;
      k = matrix[level].rank(f, k) + mid[level] * f;
    }
    return ret;
  }
  T operator[](const int &k) {
    return access(k);
  }
  int rank(const T &x, int r) {
    int l = 0;
    for (int level = MAXLOG - 1; level >= 0; level--)
      tie(l, r) = succ((x >> level) & 1, l, r, level);
    return r - l;
  }
  T kth_smallest(int l, int r, int k) {
    assert(0 <= k && k < r - l);
    T ret = 0;
    for (int level = MAXLOG - 1; level >= 0; level--) {
      int cnt = matrix[level].rank(false, r) - matrix[level].rank(false, l);
      bool f = cnt <= k;
      if (f) {
        ret |= T(1) << level;
        k -= cnt;
      }
      tie(l, r) = succ(f, l, r, level);
    }
    return ret;
  }
  T kth_largest(int l, int r, int k) {
    return kth_smallest(l, r, r - l - k - 1);
  }
  int range_freq(int l, int r, T upper) {
    int ret = 0;
    for (int level = MAXLOG - 1; level >= 0; level--) {
      bool f = ((upper >> level) & 1);
      if (f)
        ret += matrix[level].rank(false, r) - matrix[level].rank(false, l);
      tie(l, r) = succ(f, l, r, level);
    }
    return ret;
  }
  int range_freq(int l, int r, T lower, T upper) {
    return range_freq(l, r, upper) - range_freq(l, r, lower);
  }
  T prev_value(int l, int r, T upper) {
    int cnt = range_freq(l, r, upper);
    return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);
  }
  T next_value(int l, int r, T lower) {
    int cnt = range_freq(l, r, lower);
    return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);
  }
};

template <typename T, int MAXLOG>
struct CompressedWaveletMatrix {
  WaveletMatrix<int, MAXLOG> mat;
  vector<T> ys;
  CompressedWaveletMatrix(const vector<T> &v) : ys(v) {
    sort(begin(ys), end(ys));
    ys.erase(unique(begin(ys), end(ys)), end(ys));
    vector<int> t(v.size());
    for (int i = 0; i < v.size(); i++)
      t[i] = get(v[i]);
    mat = WaveletMatrix<int, MAXLOG>(t);
  }
  inline int get(const T &x) {
    return lower_bound(begin(ys), end(ys), x) - begin(ys);
  }
  T access(int k) {
    return ys[mat.access(k)];
  }
  T operator[](const int &k) {
    return access(k);
  }
  int rank(const T &x, int r) {
    auto pos = get(x);
    if (pos == ys.size() || ys[pos] != x)
      return 0;
    return mat.rank(pos, r);
  }
  T kth_smallest(int l, int r, int k) {
    return ys[mat.kth_smallest(l, r, k)];
  }
  T kth_largest(int l, int r, int k) {
    return ys[mat.kth_largest(l, r, k)];
  }
  int range_freq(int l, int r, T upper) {
    return mat.range_freq(l, r, get(upper));
  }
  int range_freq(int l, int r, T lower, T upper) {
    return mat.range_freq(l, r, get(lower), get(upper));
  }
  T prev_value(int l, int r, T upper) {
    auto ret = mat.prev_value(l, r, get(upper));
    return ret == -1 ? T(-1) : ys[ret];
  }
  T next_value(int l, int r, T lower) {
    auto ret = mat.next_value(l, r, get(lower));
    return ret == -1 ? T(-1) : ys[ret];
  }
};

class UnionFind {
public:
  int n;
  vector<int> par;
  UnionFind(int _n) : n(_n), par(_n, -1) {}
  // O(α(n))
  bool merge(int a, int b) {
    a = root(a), b = root(b);
    if (a == b)
      return false;
    if (par[a] > par[b])
      swap(a, b);
    par[a] += par[b];
    par[b] = a;
    return true;
  }
  // O(α(n))
  bool isSame(int a, int b) {
    return root(a) == root(b);
  }
  int root(int a) {
    if (par[a] < 0)
      return a;
    return par[a] = root(par[a]);
  }
  int size(int a) {
    return -par[root(a)];
  }
  vector<vector<int>> groups() {
    vector<int> leader_buf(n), group_size(n);
    for (int i = 0; i < n; i++) {
      leader_buf[i] = root(i);
      group_size[leader_buf[i]]++;
    }
    vector<vector<int>> result(n);
    for (int i = 0; i < n; i++)
      result[i].reserve(group_size[i]);
    for (int i = 0; i < n; i++)
      result[leader_buf[i]].push_back(i);
    result.erase(remove_if(result.begin(), result.end(), [&](const vector<int> &v) { return v.empty(); }), result.end());
    return result;
  }
};

class DirectedGraph {
public:
  struct Edge {
    int to, cost;
  };
  int n;
  vector<vector<Edge>> g;

  DirectedGraph(int _n) : g(_n) {
    n = _n;
  }
  void add(int s, int t, int cost) {
    Edge e;
    e.to = t, e.cost = cost;
    g[s].push_back(e);
  }
  // O(V^3)
  vector<vector<int>> warshallfloyd() {
    vector<vector<int>> d(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++)
      d[i][i] = 0;
    for (int i = 0; i < n; i++)
      for (Edge &j : g[i])
        d[i][j.to] = min(d[i][j.to], j.cost);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
    return d;
  }
  // O(E+VlogV)
  vector<int> dijkstra(int s) {
    vector<int> d(n, INT_MAX);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push(make_pair(0, s));
    while (!que.empty()) {
      pair<int, int> p = que.top();
      que.pop();
      int v = p.second;
      if (d[v] < p.first)
        continue;
      for (auto e : g[v]) {
        if (d[e.to] > d[v] + e.cost) {
          d[e.to] = d[v] + e.cost;
          que.push(make_pair(d[e.to], e.to));
        }
      }
    }
    return d;
  }
  // O(V*E)
  vector<int> bellmanford(int s) {
    vector<int> d(n, INT_MAX);
    d[s] = 0;
    for (int _ = 0; _ < n; _++) {
      bool upd = false;
      for (int u = 0; u < n; u++)
        if (d[u] < INT_MAX)
          for (const auto &e : g[u]) {
            int v = e.to;
            if (d[v] > d[u] + e.cost)
              d[v] = d[u] + e.cost, upd = true;
          }
      if (!upd)
        return d;
    }
    queue<int> Q;
    for (int u = 0; u < n; u++)
      if (d[u] < INT_MAX)
        Q.emplace(u);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      for (const auto &e : g[u]) {
        int v = e.to;
        if (d[v] > INT_MIN && (d[u] == INT_MIN || d[v] > d[u] + e.cost))
          d[v] = INT_MIN, Q.emplace(v);
      }
    }
    return d;
  }
};

class UndirectedGraph {
public:
  int n;
  vector<tuple<int, int, int>> g;
  UndirectedGraph(int _n) {
    n = _n;
  }
  void add(int u, int v, int c) {
    g.push_back({u, v, c});
  }
  // O(ElogV)
  vector<vector<int>> kruskal() {
    UnionFind uf(n);
    vector<vector<int>> res(n);
    sort(g.begin(), g.end(), [](auto &l, auto &r) { return get<2>(l) < get<2>(r); });
    D(g);
    for (auto &[a, b, cost] : g) {
      if (uf.merge(a, b)) {
        res[a].push_back(b);
        res[b].push_back(a);
      }
    }
    return res;
  }
};

class Range {
  struct Cnt {
    int n;
    int add = 1;
    int operator*() { return n; }
    bool operator!=(const Cnt &_n) { return n < _n.n; }
    void operator++() { n += add; }
  };
  Cnt st, ed;

public:
  Range(const int &_ed) : st({0}), ed({_ed}) {}
  Range(const int &_st, const int &_ed) : st({_st}), ed({_ed}) {}
  Range(const int &_st, const int &_ed, const int &_add) : st({_st, _add}), ed({_ed, _add}) {}
  Cnt &begin() { return st; }
  Cnt &end() { return ed; }
};

template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

void _matchPair(int n, vector<vector<pair<int, int>>> &res, vector<pair<int, int>> r, set<int> trs) {
  if (trs.size() == 0) {
    res.push_back(r);
    return;
  }
  int mem1 = *trs.begin();
  trs.erase(trs.begin());
  for (auto &i : trs) {
    {
      auto t = trs;
      t.erase(i);
      r.push_back({mem1, i});
      _matchPair(n, res, r, t);
      r.pop_back();
    }
  }
}

vector<vector<pair<int, int>>> matchPair(int n) {
  set<int> trs;
  for (int i : Range(n))
    trs.insert(i);
  vector<pair<int, int>> r;
  vector<vector<pair<int, int>>> res;
  _matchPair(n, res, r, trs);
  return res;
}

vector<int> divisor(const int _n) {
  vector<int> head, tail;
  for (int i = 1; i * i <= _n; i++) {
    if (_n % i == 0) {
      head.push_back(i);
      if (i * i != _n)
        tail.push_back(_n / i);
    }
  }
  head.insert(head.end(), tail.rbegin(), tail.rend());
  return head;
}

vector<pair<int, int>> primeFactorize(int n) {
  vector<pair<int, int>> res;
  for (int a = 2; a * a <= n; ++a) {
    if (n % a != 0)
      continue;
    int ex = 0;
    while (n % a == 0) {
      ++ex;
      n /= a;
    }
    res.push_back({a, ex});
  }
  if (n != 1)
    res.push_back({n, 1});
  return res;
}

int dichotomy(int ng, int ok, function<bool(int)> discriminant) {
  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;
    (discriminant(mid) ? ok : ng) = mid;
  }
  return ok;
}

template <class T>
pair<T, T> getLiner(pair<T, T> p0, pair<T, T> p1) {
  T a = (p0.second - p1.second) / (p0.first - p1.first);
  T b = p0.second - (p0.first * a);
  return make_pair(a, b);
}

template <class T>
vector<vector<T>> turnR(const vector<vector<T>> &s) {
  vector<vector<T>> res(s[0].size(), vector<T>(s.size()));
  for (int y = 0; y < s.size(); y++)
    for (int x = 0; x < s[0].size(); x++)
      res[x][s.size() - y - 1] = s[y][x];
  return res;
}

template <class T>
vector<vector<T>> turnL(const vector<vector<T>> &s) {
  vector<vector<T>> res(s[0].size(), vector<T>(s.size()));
  for (int y = 0; y < s.size(); y++)
    for (int x = 0; x < s[0].size(); x++)
      res[s[0].size() - x - 1][y] = s[y][x];
  return res;
}

void execution();

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(16);
  execution();
}

void execution() {
  int n;
  cin >> n;
  vector<vector<ModInt<998244353>>> dp(n, vector<ModInt<998244353>>(9));
  for (int i : Range(9))
    dp[0][i] = 1;

  auto cal = [&dp](int n, int j) {
    ModInt<998244353> res = 0;
    if (j == 0) {
      res += dp[n - 1][j + 1];
      res += dp[n - 1][j];
    } else if (j == 8) {
      res += dp[n - 1][j - 1];
      res += dp[n - 1][j];
    } else {
      res += dp[n - 1][j - 1];
      res += dp[n - 1][j];
      res += dp[n - 1][j + 1];
    }
    dp[n][j] = res;
  };

  ModInt<998244353> ans = 0;

  for (int i : Range(1, n)) {
    for (int j : Range(9)) {
      cal(i, j);
    }
  }

  cout<< accumulate(ALL(dp[n-1]),ModInt<998244353>())<<"\n";
}

