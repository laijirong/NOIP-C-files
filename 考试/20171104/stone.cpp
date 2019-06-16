#include <cstdio>
const int N = 50050;
int l, n, m, a[N];
int check( int x ) {
	int p = 0, ans = 0;
	while (p <= n) {
		int t = p;
		while (t <= n && a[t]-a[p] < x) {
			t++;
		}
		if(t == n+1) break;
		p = t; ans ++;
	}
	if(a[n+1]-a[p]<x) ans --;
	return n-ans;
}
int main() {
	freopen( "stone.in", "r", stdin );
	freopen( "stone.out", "w", stdout );
	
	scanf( "%d%d%d", &l, &n, &m );
	for( int i = 1; i <= n; i ++ ) {
		scanf( "%d", &a[i] );
	}
	a[n+1] = l;
	int l = 0, r = 1000000000;
	while ( l < r ) {
		int mid = (l+r+1)>>1;
		if(check(mid) <= m) l = mid;
		else r = mid-1;
	}
	printf( "%d\n", l );
	
	fclose( stdin );
	fclose( stdout );
	return 0;
}
