#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
	int N;
	cin >> N;
	vector<int> a(N);

	rep(i, N) {
		cin >> a[i];
	}

	vector<int> cnt(200);
	// 入力値a[0]～a[199]の値を200で割った余りの数の分布を作る
	rep(i, N) {
		cnt[a[i] % 200]++;
	}

	ll ans = 0;
	// 余りが同じものを2つ選ぶ組み合わせ数を計算
	rep(i, 200){
		ans += (ll)cnt[i] * (cnt[i] - 1) / 2;
	} 

	// 組み合わせパターンを出力する！
	cout << ans << endl;
	return 0;
}