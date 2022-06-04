#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>
#include <iomanip>
#include <queue>
#include <map>
#include <climits>
#include <bitset>
#include <numeric> // iota関数

using namespace std;

#define rep(i, H) for (int i = 0; i < H; i++)
#define rep1(i, H) for (int i = 1; i <= H; i++)
#define drep(i, H) for (int i = H - 1; i >= 0; i--)
#define drep1(i, H) for (int i = H; i >= 1; i--)
#define srep(i, S, T) for (int i = S; i < T; i++)
#define rng(a) a.begin(), a.end()

template <typename T>
using vc = vector<T>;
template <typename T>
using vv = vc<vc<T>>;
template <typename T>
using vvv = vv<vc<T>>;
using vi = vc<int>;
using vvi = vv<int>;
using vvvi = vvv<int>;
using vl = vc<long>;
using vvl = vv<long>;
using ll = long long;
using vll = vc<ll>;
using vvll = vv<ll>;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(m);
	vector<vector<int>> pos(n);
	rep(i, m)
	{
		int k;
		cin >> k;
		a[i] = vector<int>(k);
		rep(j, k) {
			cin >> a[i][j];
		}
		rep(j, k)
		{
			a[i][j]--;
			pos[a[i][j]].push_back(i);
		}
	}
	vector<int> cnt(n);
	queue<int> q;
	rep(i, m)
	{
		int t = a[i].back();
		cnt[t]++;
	}
	rep(i, n) {	// 同じ色は2つであると問題文で保証されている
		if (cnt[i] == 2) {
			q.push(i);
		}
	}
	int take = 0;
	while (q.size())
	{
		int x = q.front();
		q.pop();
		take++;
		rep(i, 2)
		{
			int p = pos[x][i];
			a[p].pop_back();
			if (a[p].size())
			{
				int t = a[p].back();
				cnt[t]++;
				if (cnt[t] == 2)
					q.push(t);
			}
		}
	}
	if (take == n)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return EXIT_SUCCESS;
}