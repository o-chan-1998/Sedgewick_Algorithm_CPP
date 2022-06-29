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
#include <complex>

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
using C = complex<double>;

void output(int s) {
  vector<int> a;
  int i = 1;
  while (s) {
    if (s&1) 
		a.push_back(i);
    ++i;
    s >>= 1;
  }
  cout << a.size();
  for (int x : a) 
  	cout << " " << x;
  cout << endl;
}

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// N 個の正整数からなる数列 A=(A_1,A_2,…,A_N) が与えられます。 
	// 以下の条件を全て満たす 2 つの数列 B=(B 1 ,B 2 ,…,B x ), C=(C 1 ,C 2 ,…,C y ) が存在するか判定し、存在する場合はひとつ出力してください。
	// ・1≤ x,y≤N
	// ・1≤B 1 <B 2 <⋯<B x ≤N
	// ・1≤C 1 <C 2 <⋯<C y ≤N
	// ・B と C は、異なる数列である。
	//   x≠y のとき、または、ある整数 i (1≤ i≤ min(x,y)) が存在して B i≠C i  であるとき、B と C は異なるものとする。
	// ・A_(B_1)+A_(B_2)+⋯+A_(B_x)を 200 で割った余りと A C 1  +A C 2  +⋯+A C y   を 200 で割った余りが等しい。
	int n=5;
	vector<int> a{180,186,189,191,218};
	n = min(n,8);
	vector<int> st(200);
	for (int s = 1; s < (1<<n); ++s) {
		int x = 0;
		rep(i,n) 
			if (s>>i&1) 
				x = (x+a[i])%200;
		if (st[x] == 0) 
			st[x] = s;
		else {
			cout << "Yes" << endl;
			output(s);
			output(st[x]);
			return 0;
		}
	}
	cout << "No" << endl;

    return EXIT_SUCCESS;
}
