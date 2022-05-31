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

int n, m, u, v;
vector<int> edge[110000];

int memo[110000];
bool done[110000];

// ファイル出力
const char *fileName = "trace.txt";
ofstream ofs(fileName);

int dp(int v){
ofs << "-----/////-----" << endl;
ofs << "int dp(int v(" << v << ")){" << endl << endl;

ofs << "done[] : ";
rep(i, 11){
ofs << done[i] << " ";
}
ofs << endl;
ofs << "memo[] : ";
rep(i, 11){
ofs << memo[i] << " ";
}
ofs << endl;

ofs << "    if(done[v](" << done[v] << "))return memo[v](" << memo[v] << ");" << endl;
    if(done[v])return memo[v];
    int ans = 0;
ofs << "    for(int to: edge[v(" << v << ")]){" << endl;
    for(int to: edge[v]){
ofs << "        ans = max(ans(" << ans << "), dp(to(" << to << ")) + 1);" << endl;
        ans = max(ans, dp(to) + 1);
    }
    done[v] = true;
    memo[v] = ans;

ofs << "*****-----*****" << endl;
ofs << "done[] : ";
rep(i, 11){
ofs << done[i] << " ";
}
ofs << endl;
ofs << "memo[] : ";
rep(i, 11){
ofs << memo[i] << " ";
}
ofs << endl;
ofs << "*****-----*****" << endl;
    return ans;
}

int main(){
  if (!ofs)
  {
    cout << "ファイルが開けませんでした。" << endl;
    cin.get();
    return 0;
  }

    cin >> n >> m;
ofs << "    cin >> n(" << n << ") >> m(" << m << ");" << endl;
    for(int i = 0;i < m;i++){
ofs << "    for(int i = 0;i(" << i << ") < m(" << m << ");i++){" << endl;
        cin >> u >> v;
        edge[u].push_back(v);
ofs << "        cin >> u(" << u << ") >> v(" << v << ");" << endl;
ofs << "        edge[u(" << u << ")].push_back(v(" << u << "));" << endl;
    }
rep(i,7){
ofs << "edge[" << i << "]" << " ";
    for(int j=0; j<edge[i].size(); j++)
        ofs << edge[i][j] << " ";
ofs << endl;
}
ofs << endl;

    int ans = 0;
ofs << "    for(int v = 1;v <= n(" << n << ");v++){" << endl;
    for(int v = 1;v <= n;v++){
        ans = max(ans, dp(v));
ofs << "        ans(" << ans << ") = max(ans(" << ans << "), dp(v(" << v << ")));" << endl;
    }

    cout << ans << endl;

ofs << "===============" << endl;
ofs << "done[] : ";
rep(i, 11){
ofs << done[i] << " ";
}
ofs << endl;
ofs << "memo[] : ";
rep(i, 11){
ofs << memo[i] << " ";
}
ofs << endl;
ofs << "===============" << endl;

  ofs.close();

    return 0;
}