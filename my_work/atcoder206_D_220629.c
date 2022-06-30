#include <stdio.h>
#include <string.h>

#define N	20
#define A	20

int ds[A + 1];

int find(int i) {
	return ds[i] < 0 ? i : (ds[i] = find(ds[i]));
}

int join(int i, int j) {
	i = find(i);
	j = find(j);
	if (i == j)
		return 0;
	if (ds[i] > ds[j])
		ds[i] = j;
	else {
		if (ds[i] == ds[j])
			ds[i]--;
		ds[j] = i;
	}
	return 1;
}

int main() {
	// 	N項からなる正整数列A=(A1,A2,…AN)が与えられます。
	// 以下の操作を0回以上何度でも行える時、操作を最小何回行えば、Aを回文にすることができますか？
	// ・ある正整数の組(x,y)を選ぶ。
	//   その後、現在Aに含まれるxをすべてyに置き換える。
	// なお、この問題では、全ての整数i(1≤i≤N)について、Ai=AN+1−iが成り立つとき、またその時に限って、Aが回文であると言います。

	int n = 8;
	static int aa[]={1,5,3,2,5,2,3,1};

	memset(ds, -1, sizeof ds);

	int ans;
	ans = 0;

	for (int i = 0, j = n - 1; i < j; i++, j--)
		// join関数はUnionFind処理
		// join(aa[0], aa[7]), join(aa[1], aa[6]), join(aa[2], aa[5]), join(aa[3], aa[4])
		if (join(aa[i], aa[j]))
			ans++;

	printf("%d\n", ans);
	return 0;
}