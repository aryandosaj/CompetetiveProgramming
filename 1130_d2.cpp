#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
long n, m;
long c[5002];
long s[5002];
long dist(long a, long b)
{
    if (b >= a)
        return b - a;
    else
        return n - (a - b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    long nm = 0;
    for (long i = 1; i <= 5001; i++)
        c[i] = MAX;
    for (long i = 0; i < m; i++)
    {
        long a, b;
        cin >> a >> b;
        s[a]++;
        if (dist(a, b) < c[a])
            c[a] = dist(a, b);
    }
    for (long i = 1; i <= 5001; i++)
        if(c[i]==MAX)c[i]=0;

    for(long i=1;i<=n;i++)
    {
        long ans=0;
        for(long j=1;j<=n;j++)
        {
            ans = max(ans,dist(i,j)+c[j]+(s[j]-1)*n);
        }
        cout<<ans<<" ";
    }
}