#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
#include <queue>
#include <map>

using namespace std;

#define rep(i,N) for (int i = 0; i < N; i++)
#define rep1(i,N) for(int i = 1; i <= N; i++)
#define drep(i,N) for(int i = N-1; i >= 0; i--)
#define srep(i,S,T) for (int i = S; i < T; i++)
#define rng(a) a.begin(),a.end()
#define MAX 210

template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
using vi = vc<int>; using vvi = vv<int>;
using vl = vc<long>; using vvl = vv<long>;
using ll = long long;

bool judge(int X);

int main(){

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	bool judge=false;

	if((x1+2)==x2 && (y1+1)==y2){
		judge=true;
	}else if((x1+2)==x2 && (y1-1)==y2){
		judge=true;
	}else if((x1+1)==x2 && (y1+2)==y2){
		judge=true;
	}else if((x1+1)==x2 && (y1-2)==y2){
		judge=true;
	}else if((x1-1)==x2 && (y1+2)==y2){
		judge=true;
	}else if((x1-1)==x2 && (y1-2)==y2){
		judge=true;
	}else if((x1-2)==x2 && (y1+1)==y2){
		judge=true;
	}else if((x1-2)==x2 && (y1-1)==y2){
		judge=true;
	}

	if(judge)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return EXIT_SUCCESS;
}

