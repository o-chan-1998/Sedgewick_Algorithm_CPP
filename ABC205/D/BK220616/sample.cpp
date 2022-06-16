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

using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define rep1(i, N) for (int i = 1; i <= N; i++)
#define drep(i, N) for (int i = N - 1; i >= 0; i--)
#define srep(i, S, T) for (int i = S; i < T; i++)
#define rng(a) a.begin(), a.end()
#define MAX 210

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

int main(){
    int n, q;
    cin >> n >> q;

    vll a(n+2),b(n+2);

    rep1(i,n){
        cin >> a[i];
    }
    a[n+1]=LLONG_MAX;
    rep1(i,n){
        b[i] = a[i]-a[i-1]-1+b[i-1];
    }
    b[n+1]=LLONG_MAX;

    rep(i,q){
        int k;
        int point=0;
        cin >> k; 
        rep1(j,n+1){
            if(k<=b[j]){
                point = j;
                break;
            }
        }
        cout << a[point-1]+k-b[point-1] << " ";
    }

    cout << endl;

    return EXIT_SUCCESS;
}

// 【入力】
// 4 3
// 3 5 6 7
// 2
// 5
// 3
// [1],[2],3,[4],5,6,7,[8],[9]
// 【出力】
// 2
// 9
// 4