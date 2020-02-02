#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
ll arr[20][20];
ll n, m, k;
ll ans = 0;
void traverse(ll i1, ll j1, ll xr)
{
    xr=xr^arr[i1][j1];
    if ((i1 == n - 1) && (j1 == m - 1) && (xr == k))
    {
        ans++;
        return;
    }
    if(i1<n-1)
    traverse(i1+1,j1,(xr));
    if(j1<m-1)
    traverse(i1,j1+1,(xr));

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    cin >> n >> m >> k;

    for (ll i = 0; i < n; i++)
    {

        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    traverse(0,0,0);
    cout<<ans;
}