#include <bits/stdc++.h>
using namespace std;

struct Info {
  bool has[3] = {};
  bool p10 = 0, p20 = 0, p21 = 0, p210 = 0;
};

Info mergeInfo(const Info& x, const Info& y) {
  Info z;
  for (int v = 0; v < 3; v++) z.has[v] = x.has[v] || y.has[v];
  z.p10 = x.p10 || y.p10 || (x.has[1] && y.has[0]);
  z.p20 = x.p20 || y.p20 || (x.has[2] && y.has[0]);
  z.p21 = x.p21 || y.p21 || (x.has[2] && y.has[1]);
  z.p210 = x.p210 || y.p210
           || (x.has[2] && y.p10)
           || (x.p21 && y.has[0]);
  return z;
}

Info single(int value) {
  Info ret;
  ret.has[value] = 1;
  return ret;
}

struct SegTree {
  int n;
  vector<Info> t;

  SegTree(const vector<int>& a) : n(int(a.size())), t(4 * n) {
    build(1, 0, n, a);
  }

  void build(int p, int l, int r, const vector<int>& a) {
    if (r - l == 1) {
      t[p] = single(a[l]);
      return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m, a);
    build(2 * p + 1, m, r, a);
    t[p] = mergeInfo(t[2 * p], t[2 * p + 1]);
  }

  void modify(int x, int value) { modify(1, 0, n, x, value); }

  void modify(int p, int l, int r, int x, int value) {
    if (r - l == 1) {
      t[p] = single(value);
      return;
    }
    int m = (l + r) / 2;
    if (x < m) modify(2 * p, l, m, x, value);
    else modify(2 * p + 1, m, r, x, value);
    t[p] = mergeInfo(t[2 * p], t[2 * p + 1]);
  }

  Info query(int ql, int qr) const {
    return query(1, 0, n, ql, qr);
  }

  Info query(int p, int l, int r, int ql, int qr) const {
    if (ql <= l && r <= qr) return t[p];
    int m = (l + r) / 2;
    if (qr <= m) return query(2 * p, l, m, ql, qr);
    if (m <= ql) return query(2 * p + 1, m, r, ql, qr);
    return mergeInfo(query(2 * p, l, m, ql, qr),
                     query(2 * p + 1, m, r, ql, qr));
  }
};

void Main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  SegTree seg(a);
  while (q--) {
    int type, x, y;
    cin >> type >> x >> y;
    if (type == 1) {
      seg.modify(x - 1, y);
    } else {
      Info ret = seg.query(x - 1, y);
      if (ret.p210) cout << 2 << "\n";
      else if (ret.p10 || ret.p20 || ret.p21) cout << 1 << "\n";
      else cout << 0 << "\n";
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) Main();
  return 0;
}
