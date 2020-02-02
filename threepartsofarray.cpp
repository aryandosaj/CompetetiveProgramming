#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll i = 0, j = n - 1;
    ll s1 = 0, s3 = 0;
    ll ans = 0;
    while (i <= j)
    {
        // cout<<s1<<" "<<s3;
        if (s1 == s3)
        {
            ans = s1;
            s1 += arr[i++];
            // s3 += arr[j--];
            continue;
        }
        if (s1 > s3)
        {
            s3 += arr[j--];
            continue;
        }
        if (s3 > s1)
        {
            s1 += arr[i++];
            continue;
        }
    }
    if (s1 == s3)
            ans=s1;
    cout<<ans;
}