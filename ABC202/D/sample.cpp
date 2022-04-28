#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
#include <queue>
#include <map>

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

ll C[61][61];   // パスカルの三角形


int main()
{
    int A, B;
    ll K;

    cin >> A >> B >> K;
    string ans; // K番目の文字列

    C[0][0]=1;
    rep(i,60){
        rep(j,i+1){
            C[i+1][j]+=C[i][j]; // パスカルの三角形イメージ
            C[i+1][j+1]+=C[i][j];   // パスカルの三角形イメージ
        }
    }

    while(A+B>0){
        ll x=0;   // Aから始まる文字列
        if(A>=1){
            x=C[A+B-1][A-1];
        }
        if(K<=x){
            ans += 'a';
            A--;
        }else{
            ans += 'b';
            B--;
            K -= x; // KのインデックスをX(Aの数分減らす)
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

