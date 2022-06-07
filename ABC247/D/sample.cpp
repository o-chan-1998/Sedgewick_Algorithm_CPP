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

	int q;
	cin >> q;

	deque<pair<ll,ll>> deq;

	rep(i,q){
		ll t, x, c;
		cin >> t;
		if(t==1){
			cin >> x >> c;
			deq.push_back({x,c});
		}else{
			cin >> c;
			ll sum=0;
			while(c){
				pair<ll,ll> data =deq.front();
				deq.pop_front();
				sum += data.first*min(c,data.second);
				if(data.second > c){
					deq.push_front({data.first,data.second-c});
				}
				c -= min(c,data.second);
			}
			cout << sum << endl;
		}
	}

    return EXIT_SUCCESS;
}