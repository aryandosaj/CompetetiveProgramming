#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
bool isprime(ll n)
{ll flag=0;ll root = sqrt(n);
for(ll i=2;i<=root;i++)
{
if(n%i==0)
{
flag=1;return 0;}
}
return 1;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    cout<<isprime(13)<<" "<<isprime(15);
    
}
