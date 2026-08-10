#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int N = 2e5 + 5;
int n, m, q, len, cnt, kmp[N], ql[N], qr[N], sum[N];
string s;
ull B, pw[N], h[N];
ll f[N], g[N], ans[N];
pair<ull, int> a[N];
vector<vector<int>> res[N];
vector<pair<vector<int> *, int>> upd[N];
vector<int> qry[N];
ll c2(int x) {
  return x * (x - 1ll) / 2;
}
ull get_hash(int l, int r) {
  return h[r] - h[l - 1] * pw[r - l + 1];
}
struct DS {
  int b, msk, len, f[N + (1 << 9) + 5], g[(N >> 9) + 5];
  void init() {
    b = roundl(log2l(sqrtl(n)));
    msk = (1 << b) - 1;
    len = n >> b;
    fill(f + 1, f + ((len + 1) << b) + 1, 0), fill(g, g + len + 1, 0);
  }
  void add(int x) {
    f[x]++, g[x >> b]++;
  }
  int qry(int x) {
    int res = 0;
    for (; x & msk; x++) res += f[x];
    for (x >>= b; x <= len; x++) res += g[x];
    return res;
  }
} ds;
void work() {
  cin >> n >> m >> q >> s;
  if (m == 1) {
    ll out = 0;
    for (int i = 1; i <= q; i++) {
      int l, r;
      cin >> l >> r;
      out ^= i * c2(r - l + 1);
    }
    cout << out << '\n';
    return;
  }
  s = ' ' + s;
  for (int i = 1; i <= n; i++) h[i] = h[i - 1] * B + s[i];
  for (int i = 0; i <= n + 1; i++) res[i].clear(), f[i] = g[i] = 0; 
  cnt = n;
  for (int i = 1; i <= n; i++) a[i].second = i;
  for (len = 1; len <= n; len++) {
    for (int i = 1; i <= cnt; i++) a[i].first = get_hash(a[i].second, a[i].second + len - 1);
    sort(a + 1, a + cnt + 1);
    int ncnt = 0;
    for (int l = 1, r; l <= cnt; l = r + 1) {
      for (r = l; r + 1 <= cnt && a[l].first == a[r + 1].first; r++);
      if (l == r) continue;
      kmp[1] = 0;
      int p = 0, delta = a[l].second - 1;
      for (int i = 2; i <= len; i++) {
        while (p && s[delta + i] != s[delta + p + 1]) p = kmp[p];
        if (s[delta + i] == s[delta + p + 1]) p++;
        kmp[i] = p;
      }
      if (!kmp[len]) {
        res[len].emplace_back(r - l + 1);
        for (int i = l; i <= r; i++) {
          res[len].back()[i - l] = a[i].second;
        }
        f[len] += n + q;
        g[len] += c2(r - l + 1);
      }
      for (int i = l; i <= r; i++) {
        if (a[i].second + len <= n) a[++ncnt].second = a[i].second;
      }
    }
    cnt = ncnt;
    if (!cnt) break;
  }
  len = min(len, n);
  for (int i = 1; i <= len; i++) f[i] += f[i - 1];
  for (int i = len; i >= 1; i--) g[i] += g[i + 1];
  pair<ll, int> best = {(ll)1e18, -1};
  for (int i = 0; i <= len; i++) best = min(best, {f[i] + g[i + 1], i});
  // cerr << '!' << best.first + q * (ll)sqrtl(n) << '\n';
  for (int i = 1; i <= n; i++) upd[i].clear(), qry[i].clear();
  fill(ans + 1, ans + q + 1, 0);
  for (int i = 1; i <= q; i++) {
    cin >> ql[i] >> qr[i];
    qry[qr[i]].push_back(i);
  }
  for (int i = 1; i <= best.second; i++) for (auto &cur : res[i]) {
    fill(sum + 1, sum + n + 1, 0);
    for (int j : cur) sum[j]++;
    for (int j = 1; j <= n; j++) sum[j] += sum[j - 1];
    for (int j = 1; j <= q; j++) {
      int r = qr[j] - i + 1;
      if (ql[j] <= r) ans[j] += c2(sum[r] - sum[ql[j] - 1]);
    }
  }
  for (int i = best.second + 1; i <= len; i++) for (auto &cur : res[i]) {
    for (int j = 1; j < cur.size(); j++) upd[cur[j] + i - 1].emplace_back(&cur, j);
  }
  ds.init();
  for (int i = 1; i <= n; i++) {
    for (auto [ptr, p] : upd[i]) {
      auto &cur = *ptr;
      for (int j = 0; j < p; j++) ds.add(cur[j]);
    }
    for (int id : qry[i]) ans[id] += ds.qry(ql[id]);
  }
  ll out = 0;
  for (int i = 1; i <= q; i++) out ^= i * ans[i];
  cout << out << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
  B = rng() | 1;
  pw[0] = 1;
  for (int i = 1; i < N; i++) pw[i] = pw[i - 1] * B;
  int t;
  cin >> t;
  while (t--) work();
}