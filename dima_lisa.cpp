#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
bool isprime(ll n)
{
    ll flag = 0;
    ll root = sqrt(n);
    for (ll i = 2; i <= root; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            return 0;
        }
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n;
    cin>>n;
    ll big_prime;
    if(isprime(n))
    {
        cout<<"1\n"<<n;
        return 0;
    }
    for(ll i = 2; i < 300; i++)
    {
        if(isprime(n-i))
        {
            big_prime=n-i;
            break;
        }
    }
    ll rem=n-big_prime;
    ll ans[3];
    ans[0]=big_prime;
    for(int i = rem; i >1; i--)
    {
        if(isprime(i))
        {
            if(((rem-i)==0)||(isprime(rem-i)))
            {
                ans[1]=i;
                ans[2]=rem-i;
            }
       }
    }
    if(ans[2]==0)
    cout<<"2";
    else
    cout<<"3";
    cout<<"\n"<<ans[0]<<" "<<ans[1];
    if(ans[2]!=0)
    cout<<" "<<ans[2];
    
    
}