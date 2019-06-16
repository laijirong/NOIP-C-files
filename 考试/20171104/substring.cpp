#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = 1005;
const int M = 205;
const int MOD = 1000000007;
ll f[2][M][M][2]; int n, m, q;
char s1[N], s2[N];
int main() {
	freopen( "substring.in", "r", stdin );
	freopen( "substring.out", "w", stdout );
	scanf( "%d%d%d", &n, &m, &q );
	scanf( "%s%s", s1+1, s2+1 );
	f[0][0][0][0] = 1;
	for( int i = 1; i <= n; i ++ ) {
		int p = i&1, pp = p^1;
		memset(f[p],0,sizeof(f[p]));
		for( int j = 0; j <= m; j ++ ) {
			for( int k = 0; k <= j && k <= q; k ++ ) {
				f[p][j][k][0] = f[pp][j][k][0] + f[pp][j][k][1];
				f[p][j][k][0] %= MOD;
				if(j && s1[i]==s2[j]) {
					f[p][j][k][1] = f[pp][j-1][k][1];
					if(k) f[p][j][k][1] += f[pp][j-1][k-1][0]+f[pp][j-1][k-1][1];
					f[p][j][k][1] %= MOD;
				}
			}
		}
	}
	printf( "%d", (f[n&1][m][q][0]+f[n&1][m][q][1])%MOD );
	
	fclose( stdin );
	fclose( stdout );
	return 0;
}
