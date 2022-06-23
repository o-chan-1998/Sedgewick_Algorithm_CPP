#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
  string s="XX...X.X.X.";
  int k=2;
  int n = s.size();
  vector<int> a(n);
  rep(i,n) a[i] = s[i]=='.';

  int ans = 0;
  int r = 0, sum = 0;
  rep(l,n) {
	// sum+a[r]:.をXに書き換えて良い最大数の右端の場所
    while (r < n && sum+a[r] <= k) {
      sum += a[r];
      ++r;
    }
    ans = max(ans, r-l);
    sum -= a[l];
  }

  cout << ans << endl;
  return 0;
}