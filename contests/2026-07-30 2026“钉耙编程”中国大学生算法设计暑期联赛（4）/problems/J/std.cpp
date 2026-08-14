#include <bits/stdc++.h>
using namespace std;

#define SZ(s) int(s.size())

using ULL = unsigned long long;

const int P = 998244353;

ULL splitmix(ULL x) {
  x += 0x9e3779b97f4a7c15ULL;
  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
  x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
  return x ^ (x >> 31);
}

struct Key {
  ULL x, y;
  bool operator==(const Key& other) const {
    return x == other.x && y == other.y;
  }
};

struct HashTable {
  struct Node {
    Key key;
    int val, next;
  };

  vector<int> head;
  vector<Node> e;
  int mask;

  HashTable(int n = 0) {
    init(n);
  }

  void init(int n) {
    int m = 1;
    while (m < 2 * n + 1) m <<= 1;
    head.assign(m, -1);
    e.clear();
    e.reserve(n);
    mask = m - 1;
  }

  int hash(const Key& key) const {
    ULL y = key.y << 32 | key.y >> 32;
    return int(splitmix(key.x ^ y ^ 0x6a09e667f3bcc909ULL) & ULL(mask));
  }

  int& operator[](const Key& key) {
    int p = hash(key);
    for (int i = head[p]; i != -1; i = e[i].next) {
      if (e[i].key == key) return e[i].val;
    }
    e.push_back({key, 0, head[p]});
    head[p] = SZ(e) - 1;
    return e.back().val;
  }
};

namespace IO {
const int B = 1 << 20;
char buf[B];
int p1, p2;

int gc() {
  if (p1 == p2) {
    p1 = 0;
    p2 = int(fread(buf, 1, B, stdin));
    if (!p2) return EOF;
  }
  return buf[p1++];
}

int read() {
  int c, x = 0;
  do c = gc(); while (c <= ' ' && c != EOF);
  do {
    x = x * 10 + c - '0';
    c = gc();
  } while ('0' <= c && c <= '9');
  return x;
}
}

void Main() {
  int n = IO::read();
  vector<int> cnt(n + 1), last(4 * (n + 1)), f(n + 1);
  vector<ULL> b1(n + 1), b2(n + 1);
  vector<Key> h(n + 1);

  for (int i = 1; i <= n; ++i) {
    b1[i] = splitmix(ULL(i) + 0x243f6a8885a308d3ULL);
    b2[i] = splitmix(ULL(i) + 0x13198a2e03707344ULL);
  }

  HashTable mp(n + 1);
  f[0] = 1;
  mp[h[0]] = 1;
  int lim = 0;

  for (int i = 1; i <= n; ++i) {
    int x = IO::read();
    int old = cnt[x] & 3;
    int nxt = lim;
    if (cnt[x] >= 4) nxt = max(nxt, last[4 * x + old]);
    last[4 * x + old] = i;
    ++cnt[x];
    int now = cnt[x] & 3;

    h[i].x = h[i - 1].x - b1[x] * ULL(old) + b1[x] * ULL(now);
    h[i].y = h[i - 1].y - b2[x] * ULL(old) + b2[x] * ULL(now);

    while (lim < nxt) {
      int& value = mp[h[lim]];
      value -= f[lim];
      if (value < 0) value += P;
      ++lim;
    }

    f[i] = mp[h[i]];
    int& value = mp[h[i]];
    value += f[i];
    if (value >= P) value -= P;
  }

  printf("%d\n", f[n]);
}

int main() {
  int T = IO::read();
  while (T--) Main();
  return 0;
}
