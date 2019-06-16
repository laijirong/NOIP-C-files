#include <cstdio>
#include <algorithm>
using namespace std;
int n, da[2020], f[2020], ans;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &da[i]);
        f[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
            if (da[i] >= da[j])
                f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i]);
    }
    printf("%d", ans);
    return 0;
}