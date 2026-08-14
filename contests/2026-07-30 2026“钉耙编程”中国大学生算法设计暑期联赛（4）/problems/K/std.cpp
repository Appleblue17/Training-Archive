#include <bits/stdc++.h>
using namespace std;

#define ALL(s) s.begin(), s.end()
#define SZ(s) int(s.size())
#define pb push_back

using LL = long long;

void Main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  int cnt = 0;
  for (int& x : a) cin >> x, cnt += x;
  for (int i = 1, u, v; i < n; i++) cin >> u >> v;
  while (q--) {
    int r;
    cin >> r;
    cout << (a[r - 1] ? 0 : cnt + 1) << "\n";
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--) Main();
  return 0;
}
