#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); i++)

void Main() {
  int n;
  cin >> n;
  int m = (n + 1) / 2;
  vector<int> rem(n + 1, -1);
  bool ok = 1;
  rep(i, 1, n + m) {
    int x;
    cin >> x;
    if (x < 1 || x > n) {
      ok = 0;
    } else {
      rem[x]++;
    }
  }
  rep(i, 1, n) {
    if (rem[i] < 0) ok = 0;
  }
  int sum = 0;
  rep(d, 0, m - 1) {
    sum += rem[m - d];
    if (d) sum += rem[m + d];
    if (sum < d + 1) ok = 0;
  }
  if (!ok) {
    cout << -1 << "\n";
    return;
  }

  set<int> alive, zero;
  rep(i, 1, n) {
    alive.insert(i);
    if (!rem[i]) zero.insert(i);
  }
  int p = m;
  vector<pair<int, int>> del;
  rep(step, 0, m - 1) {
    if (!alive.count(p) || rem[p] <= 0) {
      ok = 0;
      break;
    }
    rem[p]--;
    if (!rem[p]) zero.insert(p);
    if (step == m - 1) {
      if (alive.size() != 1) ok = 0;
      break;
    }
    if (rem[p] > 0) {
      auto itl = zero.lower_bound(p);
      auto itr = zero.upper_bound(p);
      if (itl == zero.begin() || itr == zero.end()) {
        ok = 0;
        break;
      }
      int l = *prev(itl), r = *itr;
      alive.erase(l);
      alive.erase(r);
      zero.erase(l);
      zero.erase(r);
      del.push_back({l, r});
    } else {
      auto it = alive.find(p);
      auto pre = it, suf = next(it);
      bool has_pre = it != alive.begin();
      if (has_pre) --pre;
      if (has_pre && rem[*pre] > 0) {
        auto itr = zero.upper_bound(p);
        if (itr == zero.end()) {
          ok = 0;
          break;
        }
        int np = *pre, r = *itr;
        alive.erase(p);
        alive.erase(r);
        zero.erase(p);
        zero.erase(r);
        del.push_back({p, r});
        p = np;
      } else {
        if (suf == alive.end() || rem[*suf] <= 0) {
          ok = 0;
          break;
        }
        auto itl = zero.lower_bound(p);
        if (itl == zero.begin()) {
          ok = 0;
          break;
        }
        int l = *prev(itl), np = *suf;
        alive.erase(l);
        alive.erase(p);
        zero.erase(l);
        zero.erase(p);
        del.push_back({l, p});
        p = np;
      }
    }
  }
  if (!ok) {
    cout << -1 << "\n";
    return;
  }
  vector<int> ans = {p};
  reverse(del.begin(), del.end());
  for (auto [x, y] : del) {
    ans.push_back(x);
    ans.push_back(y);
  }
  rep(i, 0, n - 1) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--) Main();
  return 0;
}
