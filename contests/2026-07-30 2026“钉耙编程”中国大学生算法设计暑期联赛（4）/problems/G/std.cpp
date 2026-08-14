#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); i++)
using LL = long long;

void Main() {
  int n, d;
  if (!(cin >> n >> d)) return;
  string a;
  cin >> a;
  int q = gcd(n, 2 * d);
  vector<vector<int>> cnt(q, vector<int>(26, 0));
  vector<int> sz(q, 0);
  rep(i, 0, n - 1) {
    cnt[i % q][a[i] - 'a']++;
    sz[i % q]++;
  }
  vector<bool> vis(q, 0);
  LL ans = 0;
  rep(r, 0, q - 1) {
    if (vis[r]) continue;
    int other = (q - 1 - r + q) % q;
    vis[r] = vis[other] = 1;
    int tot = sz[r];
    if (other != r) tot += sz[other];
    int mx = 0;
    rep(c, 0, 25) {
      int cur = cnt[r][c];
      if (other != r) cur += cnt[other][c];
      mx = max(mx, cur);
    }
    ans += tot - mx;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--) Main();
  return 0;
}
