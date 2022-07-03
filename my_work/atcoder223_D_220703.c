#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int heap[10], hpc;

void heapify(int s){
	int ns, ms, t;
	while (s < hpc){
		ms = s;
		ns = s * 2 + 1;
		if (ns >= hpc)
			break;
		if (heap[ms] > heap[ns])
			ms = ns;
		ns = s * 2 + 2;
		if (ns < hpc && heap[ms] > heap[ns])
			ms = ns;
		if (ms == s)
			break;
		t = heap[ms];
		heap[ms] = heap[s];
		heap[s] = t;
		s = ms;
	}
}

void adjust(){
	int s = hpc - 1, p, t;
	while (s){
		p = (s - 1) / 2;
		if (heap[p] <= heap[s])
			break;
		t = heap[p];
		heap[p] = heap[s];
		heap[s] = t;
		s = p;
	}
}

int nc[10];
int nei[10];
int rs[10];

struct{
	int back, next;
} pool[10];

int main(){
	int n=4, m=3;
	int aa[3]={2,3,2};
	int bb[3]={1,4,4};
	int k, a, b, c, j;
	
	for (int i = 1; i <= n; i++){
		nc[i] = 0;
		nei[i] = -1;
	}

	c = 0;
	for (int i = 0; i < m; i++){
		a = aa[i];
		b = bb[i];
		pool[c].back = b;
		pool[c].next = nei[a];
		nei[a] = c++;
		nc[b]++;
	}

	hpc = 0;
	for (int i = 1; i <= n; i++)
		if (nc[i] == 0)
			heap[hpc++] = i;
	
	for (int i = hpc - 1; i >= 0; i--)
		heapify(i);

	k = 0;
	while (hpc){
		a = heap[0];
		hpc--;
		heap[0] = heap[hpc];
		heapify(0);
		rs[k++] = a;
		j = nei[a];
		while (j != -1){
			b = pool[j].back;
			j = pool[j].next;
			nc[b]--;
			if (nc[b])
				continue;
			heap[hpc++] = b;
			adjust();
		}
	}

	if (k < n)
		printf("-1\n");
	else{
		for (int i = 0; i < n; i++)
			printf("%d ", rs[i]);
		printf("\n");
	}

	return 0;
}
