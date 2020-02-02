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
ll mat[102][102];
ll t1[102][102];
ll t2[102][102];
ll a[102][102];
ll dp[102];
void multiply(ll m)
{
   for (ll i = 0; i < m; i++)
   {
      for (ll j = 0; j < m; j++)
      {
         ll temp = 0;
         for (ll k = 0; k < m; k++)
         {
            temp += (t1[i][k] * t2[k][j]) % MAX;
            temp = temp % MAX;
         }
         a[i][j] = temp;
      }
   }
}
void multiply2(ll m)
{
   for (ll i = 0; i < m; i++)
   {
      for (ll j = 0; j < m; j++)
      {
         ll temp = 0;
         for (ll k = 0; k < m; k++)
         {
            temp += (t1[i][k] * t2[k][j]) % MAX;
            temp = temp % MAX;
         }
         mat[i][j] = temp;
      }
   }
}
void mul(ll m, ll n)
{
   while (n > 0)
   {
      if (n % 2)
      {
         for (ll i = 0; i < 102; i++)
            for (ll j = 0; j < 102; j++)
               t1[i][j] = a[i][j], t2[i][j] = mat[i][j];
         multiply(m);
      }
      n /= 2;
      for (ll i = 0; i < 102; i++)
         for (ll j = 0; j < 102; j++)
            t1[i][j] = mat[i][j], t2[i][j] = mat[i][j];
      multiply2(m);
   }
}
ll val(ll n, ll m)
{
   if (dp[n] != -1)
      return dp[n];
   if (n == 0)
      return 0;
   if (n - m >= 0)
      return dp[n] = (val(n - 1, m) + val(n - m, m)) % MAX;
   else
      return dp[n] = (val(n - 1, m)) % MAX;
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n, m;
   cin >> n >> m;
   mat[0][0] = 1;
   mat[0][m - 1] = 1;
   for (ll i = 0; i < m; i++)
      mat[i + 1][i] = 1;
   for (ll i = 0; i < m; i++)
      a[i][i] = 1;
   mul(m, n - (m - 1));
   for (ll i = 0; i < 102; i++)
      dp[i] = -1;
   dp[0] = 1;
   ll ans = 0;
   for(ll i=0;i<m;i++)
      ans+=val(m-i-1,m)*a[0][i],ans%=MAX;
   cout << ans % MAX ;
}