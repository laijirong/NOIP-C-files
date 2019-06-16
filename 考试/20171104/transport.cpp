#include <queue>
#include <vector>
#include <cstdio>
const int N = 300005;
struct path{
	int x, w;
	path() {}
	path( int x, int w ): x(x), w(w) {}
	bool operator < ( const path& rhs ) const {
		return w < rhs.w;
	}
};
std::vector <path> g[N];
int n, m, Head[N], To[N<<1], Next[N<<1], Val[N<<1], ecnt, dfn[N], nfd[N], clock;
int fa[N][21], dep[N], dist[N], pdist[N], last[N];
void add( int u, int v, int w ) { Next[++ecnt] = Head[u]; Head[u] = ecnt; To[ecnt] = v; Val[ecnt] = w; }
void dfs( int u ) {
	dep[u] = dep[fa[u][0]]+1;
	for( int i = 1; i < 20; i ++ ) 
		fa[u][i] = fa[fa[u][i-1]][i-1];
	dfn[u] = ++clock; nfd[clock] = u;
	for( int i = Head[u]; i; i = Next[i] ) {
		int v = To[i], w = Val[i]; if(v == fa[u][0]) continue;
		fa[v][0] = u; dist[v] = dist[u] + w; dfs(v);
	}
	last[u] = clock;
}
int lca( int a, int b ) {
	if( dep[a] < dep[b] ) std::swap( a, b );
	for( int i = 19; ~i; i --) if( dep[fa[a][i]] >= dep[b] ) a = fa[a][i];
	if( a == b ) return a;
	for( int i = 19; ~i; i --) if( fa[a][i] != fa[b][i] ) a = fa[a][i], b = fa[b][i];
	return fa[a][0];
}
std::priority_queue<path> Qmid, Qother;
int ans[N]; bool in_mid[N], inqm[N], inqo[N];
void ext( int u ) {
	u = nfd[u];
	int sz = g[u].size();
	for( int i = 0; i < sz; i ++ ) {
		path t = g[u][i]; 
		in_mid[t.x] ^= 1;
		if(in_mid[t.x]) {
			if(!inqm[t.x]) Qmid.push(t), inqm[t.x] = true;
		}
		else {
			if(!inqo[t.x]) Qother.push(t), inqo[t.x] = true;
		}
	}
}
int querymid() {
	while ( !Qmid.empty() ) {
		path t = Qmid.top();
		if(in_mid[t.x]) return t.w;
		else Qmid.pop(), inqm[t.x] = false;
	}
	return 0;
}
int queryother() {
	while ( !Qother.empty() ) {
		path t = Qother.top();
		if(!in_mid[t.x]) return t.w;
		else Qother.pop(), inqo[t.x] = false;
	}
	return 0;
}
void merge( int l, int r ) {
	if(l > r) return;
	int mid = (l+r)>>1;
	int lp = mid, rp = mid-1;
	for(int u = nfd[mid]; u && dfn[u]>=l && last[u]<=r; u = fa[u][0] ) {
		int ll = dfn[u], rr = last[u];
		while ( lp>ll ) ext(--lp);
		while ( rr>rp ) ext(++rp);
		int w = dist[u] - dist[fa[u][0]];
		ans[u] = std::max(querymid()-w, queryother());
	}
	for( int i = lp; i<= rp; i ++) ext(i);
	merge(l,mid-1); merge(mid+1,r);
}
int main() {
	freopen( "transport.in", "r", stdin );
	freopen( "transport.out", "w", stdout );
	
	scanf( "%d%d", &n, &m );
	for ( int i = 1; i < n; i ++ ) {
		int u, v, w; scanf( "%d%d%d", &u, &v, &w );
		add( u, v, w ); add( v, u, w );
	}
	dfs(1);
	for( int i = 0; i < m; i ++ ) {
		int u, v; scanf( "%d%d", &u, &v );
		int c = lca(u,v); pdist[i] = dist[u]-dist[c]+dist[v]-dist[c];
		path t = path( i, pdist[i] );  g[u].push_back( t ); g[v].push_back( t );
		Qother.push(t), inqo[t.x] = true;
	}
	merge(1,n); int Ans = 0x7fffffff;
	for( int i = 1; i <= n; i ++ ) Ans = std::min(Ans,ans[i]);
	printf( "%d\n", Ans );
	
	fclose( stdin );
	fclose( stdout );
	return 0;
}
