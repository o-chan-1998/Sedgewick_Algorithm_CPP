#include <stdio.h>
#include <math.h>

#define EPS 1e-7

int eq(double a, double b) {
	return fabs(a - b) < EPS;
}

int is_int(double x) {
	return eq(x, round(x));
}

typedef struct pt {
	double x;
	double y;
} pt;

// 座標間の距離を計算する
double dist(pt a, pt b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) - (a.y - b.y));
}

pt add(pt a, pt b) {
	pt res;
	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return res;
}

pt sub(pt a, pt b) {
	pt res;
	res.x = a.x - b.x;
	res.y = a.y - b.y;
	return res;
}


int N;

#define OFFSET 16
char exists[32][32];

int main(void) {
	// 	要素数が共にNであるような二次元平面上の点の集合S={(a1,b1),(a2,b2),…,(aN,bN)}とT={(c1,d1),(c2,d2),…,(cN,dN)}が与えられます。
	// Sに対して以下の操作を0回以上任意の順に好きなだけ繰り返すことで、SとTを一致させられるかを判定してください。
	// ・実数p(0<p<360)を定め、Sに含まれる全ての点を、原点を中心に時計回りにp度回転させる。
	// ・実数q,rを定める。
	// Sに含まれる全ての点を、x軸方向にq,y軸方向にr移動させる。
	// q,rの値域に制約はなく、特に正/負/零のいずれになってもよい。
	// 解説とは特に関係なく、コードの詳細を知りたい版
	// 【※】2022年6月30日時点、まだ未完了【※】
	N = 6;

	pt S[]={{10,5},{-9,3},{1,-5},{-6,-5},{6,9},{-9,0}};
	pt T[]={{-7,-10},{-10,-5},{5,4},{9,0},{0,-10},{-10,-2}};
	for (int i = 0; i < N; i++) {
		exists[(int)S[i].y + OFFSET][(int)S[i].x + OFFSET] = 1;
	}

	if (N == 1) {
		puts("Yes");
		return 0;
	}

	pt v01_s;
	double a01_s;
	v01_s = sub(S[1], S[0]);
	a01_s = atan2(v01_s.y, v01_s.x);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				pt v01_t = sub(T[j], T[i]);
				double a01_t = atan2(v01_t.y, v01_t.x);
				double a_diff = a01_s - a01_t;
				double sin_d = sin(a_diff), cos_d = cos(a_diff);
				int yes = 1;
				for (int k = 0; k < N; k++) {
					pt p = sub(T[k], T[i]);
					pt p2, p3;
					p2.x = p.x * cos_d - p.y * sin_d;
					p2.y = p.x * sin_d + p.y * cos_d;
					p3 = add(p2, S[0]);
					if (!is_int(p3.x) || !is_int(p3.y) || !exists[(int)round(p3.y) + OFFSET][(int)round(p3.x) + OFFSET]) {
						yes = 0;
						break;
					}
				}
				if (yes) {
					puts("Yes");
					return 0;
				}
			}
		}
	}
	puts("No");
	return 0;
}
