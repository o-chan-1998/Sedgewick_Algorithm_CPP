#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mycmpi(const void *a, const void *b) { return *(const int *)a - *(const int *)b; }
#define sorti(x, n) qsort(x, n, sizeof(x[0]), mycmpi);

int dp[5][5];
typedef struct{
	int x, y;
} QNode;

QNode q1[300 * 300];
QNode q2[300 * 300];
QNode qt[300 * 300];

int as[5]={2,3,2};
int bs[5]={1,4,3};

// N 種類の弁当が、それぞれ 1 個ずつ売られています。
// i=1,2,…,N について、i 種類目の弁当には A i 個のたこ焼きと B i 個のたい焼きが入っています。

// 高橋君は、 X 個以上のたこ焼きと Y 個以上のたい焼きを食べたいです。
// 高橋君がいくつかの弁当を選んで買うことで、 X 個以上のたこ焼きと Y 個以上のたい焼きを手に入れることが可能かどうか判定して下さい。
// また、可能な場合はそのために高橋君が購入しなければならない弁当の個数の最小値を求めて下さい。

// 各種類の弁当は 1 個しか売られていないため、同じ種類の弁当を 2 個以上購入することは出来ないことに注意して下さい。

int main(){
	int n=3;
	int x=5, y=6;
	int k, c1, c2, i1, i2;
	int a, b, nd;

	for (int i = 0; i <= x; i++)
		for (int j = 0; j <= y; j++)
			dp[i][j] = -1;

	c1 = 1;
	q1[0].x = 0;
	q1[0].y = 0;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++){
		c2 = 0;
		for (int j = 0; j < c1; j++){
			a = q1[j].x;
			b = q1[j].y;
			nd = dp[a][b] + 1;
			a += as[i];
			b += bs[i];
			if (a >= x)
				a = x;
			if (b >= y)
				b = y;
			if (dp[a][b] == -1)	{
				q2[c2].x = a;
				q2[c2].y = b;
				c2++;
				dp[a][b] = nd;
			}
			if (dp[a][b] > nd)
				dp[a][b] = nd;
		}
		q1[c1].x = -1;
		q2[c2].x = -1;
		i1 = i2 = k = 0;
		while (1){
			if (i1 == c1 && i2 == c2)
				break;
			if (q1[i1].x > q2[i2].x || (q1[i1].x == q2[i2].x && q1[i1].y > q2[i2].y))
				qt[k++] = q1[i1++];
			else
				qt[k++] = q2[i2++];
		}
		c1 = k;
		for (int j = 0; j < k; j++)
			q1[j] = qt[j];
	}

	printf("%d\n", dp[x][y]);
	return 0;
}
