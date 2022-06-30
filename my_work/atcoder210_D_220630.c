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

long min(long a,long b){
	return a>b ? b:a;
}

int main(){
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	// ※要確認！！2022年6月30日




	// 高橋王国はH行W列のグリッドで表されます。
	// 北からi行目、西からj列目のマスを(i,j)で表します。
	// このたび、高橋王国の国民から交通の利便性のために鉄道の建設を求める声が多数寄せられ、国王の高橋君は鉄道を建設しなければならなくなりました。
	// 鉄道建設は以下の2つのステップからなります。
	// まず、2つの異なるマスを選び、それぞれに駅を建設する。
	// マス(i,j)に駅を建設するとAi,j円の費用がかかる。
	// その後、建設した2つの駅を結ぶ線路を建設する。
	// 2つの駅がマス(i,j)とマス(i′,j′)にあるとき、これらを結ぶ線路の建設をするとC×(∣i−i′∣+∣j−j′∣)円の費用がかかる。
	// （ここで、∣x∣はxの絶対値を表す。）
	// 高橋君は国民の利便性を上げることよりも、鉄道建設にかかる費用を少なく抑えることを優先したいと考えています。
	// 鉄道建設にかかる費用として考えられる最小値を出力してください。
	int H = 3, W = 4;
	long C=2;
	long A[5][5]={{1,7,7,9},{9,6,3,7},{7,8,6,4}};
	long a[5][5],b[5][5],c[5][5],d[5][5];

	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			a[i][j]=1l<<60;	// 巨大な数字で初期化
			b[i][j]=1l<<60;	// 巨大な数字で初期化
			c[i][j]=1l<<60;	// 巨大な数字で初期化
			d[i][j]=1l<<60;	// 巨大な数字で初期化
		}
	}
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(i>=1){
				// a[1][0]=min(a[1][0], min(a[0][0],A[0][0])+C)
				// a[1][1]=min(a[1][1], min(a[0][1],A[0][1])+C)
				// a[1][2]=min(a[1][2], min(a[0][2],A[0][2])+C)
				// a[1][3]=min(a[1][3], min(a[0][3],A[0][3])+C)
				a[i][j]=min(a[i][j],min(a[i-1][j],A[i-1][j])+C);

				// b[1][3]=min(b[1][3], min(b[0][3],b[0][3])+C)
				// b[1][2]=min(b[1][2], min(b[0][2],b[0][2])+C)
				// b[1][1]=min(b[1][1], min(b[0][1],b[0][1])+C)
				// b[1][0]=min(b[1][0], min(b[0][0],b[0][0])+C)
				b[i][W-1-j]=min(b[i][W-1-j],min(b[i-1][W-1-j],A[i-1][W-1-j])+C);
				
				c[H-1-i][j]=min(c[H-1-i][j],min(c[H-i][j],A[H-i][j])+C);
				d[H-1-i][W-1-j]=min(d[H-1-i][W-1-j],min(d[H-i][W-1-j],A[H-i][W-1-j])+C);
			}
			if(j>=1){
				a[i][j]=min(a[i][j],min(a[i][j-1],A[i][j-1])+C);
				b[i][W-1-j]=min(b[i][W-1-j],min(b[i][W-j],A[i][W-j])+C);
				c[H-1-i][j]=min(c[H-1-i][j],min(c[H-1-i][j-1],A[H-1-i][j-1])+C);
				d[H-1-i][W-1-j]=min(d[H-1-i][W-1-j],min(d[H-1-i][W-j],A[H-1-i][W-j])+C);
			}
		}
	}
	long ans=1l<<60;
	long temp1, temp2;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			temp1 = min(a[i][j],b[i][j]);
			temp2 = min(c[i][j],d[i][j]);
			ans=min(ans,min(temp1, temp2))+A[i][j];
		}
	}
	printf("%ld\n",ans);

    return EXIT_SUCCESS;
}