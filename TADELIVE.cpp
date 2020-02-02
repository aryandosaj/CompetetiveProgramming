#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
int n, x, y;
int A[100005];
int B[100005];
pair<int, pair<int, int>> C[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
        C[i].second.first = i;
        C[i].second.second = A[i] >= B[i] ;
        C[i].first = abs(A[i]- B[i]);
    }
    sort(C, C + n);
    reverse(C,C+n);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int ind = C[i].second.first;
        if(C[i].second.second)
        {
            if(x>0){ans+=A[ind];x--;}else ans+=B[ind];
        }
        else
        {
            if(y>0){ans+=B[ind];y--;}else ans+=A[ind];
        }
        
    }
    cout << ans;
}