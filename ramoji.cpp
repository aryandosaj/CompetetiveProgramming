#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    string s;
    cin>>s;
    ll l = s.length();
    ll flag=0;
    for(ll i = 0; i < l; i++)
    {
        if(s[i]=='n')
        continue;
        if((!((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u')))&&(i==l-1))
        {
            // cout<<s[i];
            flag=1;
            break;
        }
        if(!((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u')))
        {
            if(!((s[i+1]=='a')||(s[i+1]=='e')||(s[i+1]=='i')||(s[i+1]=='o')||(s[i+1]=='u')))
            {
            // cout<<s[i];

                flag=1;
                break;
            }
        }

    }
    if(flag==1)
    cout<<"NO";
    else
    cout<<"YES";
    
}