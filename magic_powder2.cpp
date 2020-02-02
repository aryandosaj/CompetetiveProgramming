#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
struct dt
{
    ll a;
    ll b;
    ll m;
    ll i;
};
bool compare(dt a, dt b)
{
    return a.m < b.m;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n, k;
    cin >> n >> k;
    // ll arr[n];
    // ll brr[n];
    dt store[n];
    ll mmm = 100000000000000;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> store[i].a;
        store[i].i = i;
        sum += store[i].a;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> store[i].b;
        store[i].m = store[i].b / store[i].a;
        mmm = min(mmm, store[i].m);
    }
    for (int i = 0; i < n; i++)
    {
        store[i].b -= mmm * store[i].a;
        store[i].m -= mmm;
    }
    sort(store, store + n, compare);
    ll mul = 0;
    ll temp;
    for (int i = 1; i < n; i++)
    {
        // cout<<store[i-1].m;
        mul += store[i - 1].a;
        temp = k - (store[i].m - store[i - 1].m) * mul+store[i].b;
        if (temp >= 0)
        {
            mmm += (store[i].m - store[i - 1].m);
            // cout<<mmm<<k;
            k = temp;
        }
        else
        {
            mmm += k / mul;
            k=0;
            break;
        }
    }
    if (k > 0)
        mmm += k / sum;
    cout << mmm;
}