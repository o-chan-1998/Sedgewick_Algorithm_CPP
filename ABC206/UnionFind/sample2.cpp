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
using vvll = vv<ll>;

bool CheckFunc(ll, ll);
ll N;
vvll CL(200001, vll(200001));

int main()
{
    ll Q;
    cin >> N >> Q;

    vll A(Q), B(Q), P(Q);

    rep(i, Q)
    {
        cin >> P[i] >> A[i] >> B[i];
    }

    rep(i,N+1){
        rep(j,N+1){
            CL[i][j]=-1;
        }
    }
    rep(i, Q)
    {
        if (P[i])
        {   
            bool ans = false;
            rep(j,N){
                if(CheckFunc(A[i],B[i])){
                    ans = true;
                }
            }
        }
        else
        {
            CL[A[i]][B[i]]=1;
            CL[B[i]][A[i]]=1;
        }
    }

    return EXIT_SUCCESS;
}

bool CheckFunc(ll from, ll to){
    rep(i,N){
        if(CL[from][i]==-1){
            return false;
        }else{
            if(i==to){
                return true;
                break;
            }
            CheckFunc(i, to);
        }
    }
    return false;
}