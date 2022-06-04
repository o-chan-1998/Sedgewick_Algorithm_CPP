#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <bitset>
#include <numeric> // iota関数
#include <fstream>

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
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vvi to(n);
	rep(i,m){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		to[a].push_back(b);
	}

	int ans=0;
	rep(sv,n){
		queue<int> q;
		vi used(n);
		used[sv] = 1;
		ans++;
		q.push(sv);
		while(q.size()){
			int v = q.front();
			q.pop();
			for(int u:to[v]){
				if(used[u]){
					continue;
				}
				ans++;
				used[u]=1;
				q.push(u);
			}
		}
	}

	cout << ans << endl;

    return EXIT_SUCCESS;
}