#include <bits/stdc++.h>
using namespace std;
typedef vector<int> V;
const int N = 2005;
int p[N], c[N], n, i, a[N];
V e[N];
V dfs(int x)
{
    V v;
    for (int y : e[x])
    {
        V t = dfs(y);
        v.insert(v.end(), t.begin(), t.end());
    }
    if (c[x] > v.size())
    {
        puts("NO");
        exit(0);
    }
    v.insert(v.begin() + c[x], x);
    return v;
}
int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
        scanf("%d%d", p + i, c + i), e[p[i]].push_back(i);
    V v = dfs(0);
    for (i = 1; i <= n; ++i)
        a[v[i]] = i;
    puts("YES");
    for (i = 1; i <= n; ++i)
        printf("%d%c", a[i], i == n ? '\n' : ' ');
    return 0;
}