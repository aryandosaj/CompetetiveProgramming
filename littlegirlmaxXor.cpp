#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll a,b;
    cin>>a>>b;
    ll arr[66];
    ll brr[66];
    for(int i = 0; i < 66; i++)
    {
        arr[i]=0;
        brr[i]=0;
    }
    
    ll j=0;
    while(a>0)
    {
        arr[j]=a%2;
        a/=2;
        j++;
    }
    j=0;
    while(b>0)
    {
        brr[j]=b%2;
        b/=2;
        j++;
    }
    for(ll i=65;i>=0;i--)
    {
        if(arr[i]!=brr[i])
        {
            cout<<(ll)(2*pow(2,i)-1);
            return 0;
        }
    }
    cout<<'0';

}