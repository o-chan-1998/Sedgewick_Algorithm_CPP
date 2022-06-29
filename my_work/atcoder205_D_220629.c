#include <stdio.h>
#include <stdlib.h>

int asc(const void *x, const void *y) {
   long a = *(const long*)x, b = *(const long*)y;
   return a < b ? -1 : a > b;
}

int  my_binary_search(int l, int h, long k, long *c){
	int t;

	while (h > l+1) {
		t = (l+h)/2;
		if (k > c[t])
			l = t;
		else
			h = t;
	}

	return l;
}

int main(){

	// 	長さ N の正整数列 A=(A 1​ ,A 2​ ,…,A N​ ) と Q 個のクエリが与えられます。
	// i(1≤i≤Q) 番目のクエリでは、正整数 K i​  が与えられるので、
	// A 1​ ,A 2​ ,…,A N​  のいずれとも異なる正整数のうち、
	// 小さい方から数えて K i​  番目のものを求めてください。
	int n=4,q=3;

	long a[]={3,5,6,7};
	long kk[]={2,5,3};
	long c[10],ans;
	
	qsort(a,n,sizeof(long),asc);

	c[0]=a[0]-1;
	for (int i=1;i<n;i++)
		// 配列aの補間累積和
		// c[1] = a[1]-a[0]-1+c[0]
		// c[2] = a[2]-a[1]-1+c[1]
		// c[3] = a[3]-a[2]-1+c[2]
		// c[4] = a[4]-a[3]-1+c[3]
		c[i]=a[i]-a[i-1]-1+c[i-1];
	
	for (int i=0;i<q;i++) {
		long k = kk[i];

		// クエリの値が補間累積和の冒頭
		if (k<=c[0]) {
			printf("%ld\n",k);
			continue;
		}
		// クエリの値が補間累積和の配列外
		if (k>c[n-1]){
			// a[3]+k-c[3]
			printf("%ld\n",a[n-1]+k-c[n-1]);
		}else {
			// 二分探索
			long key = my_binary_search(0, n-1, k, c);
			printf("%ld\n",a[key]+k-c[key]);
		}
	}
	return 0;
}