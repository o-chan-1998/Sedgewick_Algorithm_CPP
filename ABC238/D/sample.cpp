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

map<pair<ll,ll>, bool> mp;

bool f(ll a, ll s){
    // sは単調減少なので、0になったら関数終了
    if(!s){
        return a==0;
    }
    auto p = make_pair(a, s);
    if(mp.count(p)){
        return mp[p];
    }

    rep(x,2){
        rep(y,2){
            // xとyの論理積がaの一桁目と一致していない場合はスキップ。
            if((x&y)!=(a&1)){
                continue;
            }
            if(s-x-y<0){
                continue;
            }
            // 一桁目が0でない場合はスキップ
            if((s-x-y)%2!=0){
                continue;
            }
            // aの一桁目とs-x-yの一桁目のいちの位を削除
            if(f(a>>1, (s-x-y)>>1)){
                return mp[p] = true;
            }
        }
    }

    // returnするときに値をメモする
    return mp[p] = false;
}

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int t;
    cin >> t;
    rep(ti, t){
        ll a, s;
        cin >> a >> s;
        mp = map<pair<ll,ll>, bool>();
        if(f(a,s)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    return EXIT_SUCCESS;
}