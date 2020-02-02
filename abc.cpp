#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)cout<<"3\n";
        else if(n==2)cout<<"4\n";
        else if(n==3)cout<<"5\n";
        else if(n==4)cout<<"6\n";
        else if(n==5)cout<<"7\n";
        else if(n%2==1)cout<<"8\n";
        else cout<<"8\n";
    
    }
}