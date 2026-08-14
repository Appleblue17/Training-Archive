#include <bits/stdc++.h>
using namespace std;

#define SZ(s) int(s.size())

using LD = long double;
using LL = long long;

struct Point {
  LD x = 0, y = 0;

  Point operator+(const Point& b) const { return {x + b.x, y + b.y}; }
  Point operator-(const Point& b) const { return {x - b.x, y - b.y}; }
  Point operator*(LD k) const { return {x * k, y * k}; }
};

LD cross(Point a, Point b) {
  return a.x * b.y - a.y * b.x;
}

struct Line {
  Point p, v;

  LD side(Point q) const {
    q = q - p;
    return v.x * q.x + v.y * q.y;
  }
};

void uniq(vector<Point>& p) {
  vector<Point> q;
  q.reserve(p.size());
  for (Point x : p) {
    if (q.empty() || x.x != q.back().x || x.y != q.back().y) {
      q.push_back(x);
    }
  }
  if (SZ(q) > 1 && q.front().x == q.back().x &&
      q.front().y == q.back().y) {
    q.pop_back();
  }
  p.swap(q);
}

vector<Point> clip(const vector<Point>& p, const Line& l) {
  vector<Point> ret;
  if (p.empty()) return ret;
  ret.reserve(p.size() + 1);
  for (int i = 0; i < SZ(p); ++i) {
    Point a = p[i], b = p[(i + 1) % SZ(p)];
    LD da = l.side(a), db = l.side(b);
    bool ia = da >= 0, ib = db >= 0;
    if (ia) ret.push_back(a);
    if (ia != ib) {
      LD t = da / (da - db);
      t = max<LD>(0, min<LD>(1, t));
      ret.push_back(a + (b - a) * t);
    }
  }
  uniq(ret);
  return ret;
}

LD area2(const vector<Point>& p) {
  if (SZ(p) < 3) return 0;
  Point o = p[0];
  LD s = 0, c = 0;
  for (int i = 1; i + 1 < SZ(p); ++i) {
    LD v = cross(p[i] - o, p[i + 1] - o);
    LD t = s + v;
    if (fabsl(s) >= fabsl(v)) {
      c += (s - t) + v;
    } else {
      c += (v - t) + s;
    }
    s = t;
  }
  return s + c;
}

struct Qry {
  int s, k;
};

void Main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<Point> poly(m);
  LD lx = numeric_limits<LD>::infinity();
  LD rx = -numeric_limits<LD>::infinity();
  LD ly = numeric_limits<LD>::infinity();
  LD ry = -numeric_limits<LD>::infinity();
  for (Point& p : poly) {
    cin >> p.x >> p.y;
    lx = min(lx, p.x);
    rx = max(rx, p.x);
    ly = min(ly, p.y);
    ry = max(ry, p.y);
  }

  struct Raw {
    Point a, b;
    int w;
  };
  vector<Raw> raw(n);
  for (auto& h : raw) {
    cin >> h.a.x >> h.a.y >> h.b.x >> h.b.y >> h.w;
  }

  vector<Qry> qry(q);
  vector<vector<int>> at(n + 1);
  for (int i = 0; i < q; ++i) {
    cin >> qry[i].s >> qry[i].k;
    if (qry[i].k <= __builtin_popcount(unsigned(qry[i].s))) {
      at[qry[i].k].push_back(i);
    }
  }

  Point o{(lx + rx) / 2, (ly + ry) / 2};
  LD d = max(rx - lx, ry - ly);
  auto norm = [&](Point p) { return (p - o) * (1 / d); };
  for (Point& p : poly) p = norm(p);

  vector<Line> hp(n);
  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    Point a = norm(raw[i].a), b = norm(raw[i].b);
    Point v = b - a;
    LD len = hypotl(v.x, v.y);
    hp[i] = Line{a, {-v.y / len, v.x / len}};
    w[i] = raw[i].w;
  }

  if (area2(poly) < 0) reverse(poly.begin(), poly.end());

  int N = 1 << n;
  vector<LD> ar(N);
  LD d2 = d * d;
  auto dfs = [&](auto&& go, int p, int s,
                 const vector<Point>& a) -> void {
    ar[s] = fabsl(area2(a)) / 2 * d2;
    for (int i = p; i < n; ++i) {
      vector<Point> b = clip(a, hp[i]);
      if (SZ(b) < 3) continue;
      go(go, i + 1, s | (1 << i), b);
    }
  };
  dfs(dfs, 0, 0, poly);

  vector<int> mn(N);
  mn[0] = numeric_limits<int>::max();
  for (int s = 1; s < N; ++s) {
    int i = __builtin_ctz(unsigned(s));
    mn[s] = min(mn[s ^ (1 << i)], w[i]);
  }

  LL C[19][19] = {};
  for (int i = 0; i <= n; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }

  vector<LD> ans(q), f(N);
  for (int k = 1; k <= n; ++k) {
    if (at[k].empty()) continue;
    fill(f.begin(), f.end(), 0);
    for (int s = 1; s < N; ++s) {
      int c = __builtin_popcount(unsigned(s));
      if (c < k) continue;
      LD v = ar[s] * mn[s] * C[c - 1][k - 1];
      f[s] = ((c - k) & 1) ? -v : v;
    }
    for (int i = 0; i < n; ++i) {
      for (int s = 0; s < N; ++s) {
        if (s >> i & 1) {
          f[s] += f[s ^ (1 << i)];
        }
      }
    }
    for (int id : at[k]) ans[id] = f[qry[id].s];
  }

  cout << fixed << setprecision(18);
  for (LD x : ans) {
    if (fabsl(x) < 1e-15L) x = 0;
    cout << x << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) Main();
  return 0;
}
