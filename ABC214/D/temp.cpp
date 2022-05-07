#include <bits/stdc++.h>
using namespace std;

#define rep(i, H) for (int i = 0; i < H; i++)
#define rep1(i, H) for (int i = 1; i <= H; i++)

const long long inf = 1e18;
const int maxn = 2e5 + 10;

struct edge
{
	int u, v;
	long long w;
} e[maxn];
bool operator<(const edge x, const edge y) {
	return x.w < y.w; 
}

long long ans = 0;
int fa[maxn], sz[maxn];

int my_find(int x) { 
	return fa[x] == x ? x : fa[x] = my_find(fa[x]); 
}

void my_merge(int x, int y, long long w)
{
	int fx = my_find(x);
	int fy = my_find(y);

	ans += w * sz[fx] * sz[fy];
	
	if (sz[fx] > sz[fy])
		swap(fx, fy);
	
	fa[fx] = fy;
	sz[fy] += sz[fx];
}

int main()
{
	int n;
	cin >> n;

	int u, v, w;
	rep1(i,n-1)
	{
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}

	sort(e + 1, e + n);

	rep1(i,n){
		fa[i] = i;
		sz[i] = 1;
	}

	rep1(i,n-1){
		my_merge(e[i].u, e[i].v, e[i].w);
	}

	cout << ans;

	return 0;
}
