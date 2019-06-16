#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;

struct Node {
	int ord;
	char s[20];
} data[N];

int main() {
	freopen("toy.in", "r", stdin);
	freopen("toy.out", "w", stdout);
	int n, m, turn;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &turn);
		scanf("%s", &data[i].s[1]);// 外面是-, 里面是+ 
		if (turn) data[i].ord = -1;
		else data[i].ord = 1;
	}
	int way, step, now = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &way, &step);// 右边是+左边是- 
		if (way) way = 1;
		else way = -1; 
		int to = way * data[now].ord * step;
		now = (now + n + to) % n;
	}
	printf("%s", &data[now].s[1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
