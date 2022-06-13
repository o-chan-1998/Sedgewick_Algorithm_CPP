#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
#include <queue>
#include <map>
#include <fstream>

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
  // ファイル出力
  const char *fileName = "trace.txt";
  ofstream ofs(fileName);
  if (!ofs)
  {
    cout << "ファイルが開けませんでした。" << endl;
    cin.get();
    return 0;
  }

    int A, B;
    ll K;

    cin >> A >> B >> K;
    string ans; // K番目の文字列

    C[0][0]=1;
    rep(i,10){
        rep(j,i+1){
            C[i+1][j]+=C[i][j]; // パスカルの三角形イメージ
            C[i+1][j+1]+=C[i][j];   // パスカルの三角形イメージ
        }
    }
    rep(i,10){
ofs << "C[" << i << "]: " << " ";
        rep(j,10){
ofs << C[i][j] << " ";
        }
ofs << endl;        
    }

ofs << "    while(A+B(" << A+B << ")>0){" << endl;
    while(A+B>0){
        ll x=0;   // Aから始まる文字列
ofs << "        if(A(" << A << ")>=1){" << endl;
        if(A>=1){
            x=C[A+B-1][A-1];
ofs << "            x(" << x << ")=C[A+B-1(" << A+B-1 << ")][A-1(" << A-1 << ")](" << C[A+B-1][A-1] << ");" << endl;
        }
ofs << "        if(K(" << K << ")<=x(" << x << ")){" << endl;
        if(K<=x){
            ans += 'a';
ofs << "            ans(" << ans << ") += 'a';" << endl;
ofs << "            A(" << A << ")--;" << endl;
            A--;
        }else{
ofs << "        }else{" << endl;
            ans += 'b';
ofs << "            ans(" << ans << ") += 'b';" << endl;
            B--;
ofs << "            B(" << B << ")--;" << endl;
ofs << "            K(" << K << ") -= x(" << x << ");" << endl;
            K -= x; // KのインデックスをX(Aの数分減らす)
        }
    }

    cout << ans << endl;

  ofs.close();
    return EXIT_SUCCESS;
}

