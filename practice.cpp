#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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

struct trie
{
    map<char,trie> next;
    bool end_of_word;
};

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    string s;
    cin>>s;
    trie nll;
    nll.end_of_word=false;
    int n=s.length();
    int i=0;
    trie* p_temp;
    trie temp;
    p_temp = &nll;
    while(1)
    {
        temp = *p_temp;
        if((temp.next.count(s[i])))
        {
            if(i==n-1)
            {
                temp.end_of_word=true;
                break;
            }
        }
        else
        {
            trie ne;
            ne.end_of_word=false;
            temp.next[s[i]]=ne;
            

        }
        *p_temp = temp;
        p_temp = &(temp.next[s[i]]);
        i++;
    }
    cout<<"here";
    temp = nll;
    i=0;
    while(temp.end_of_word!=true)
    {
        if(temp.next.count(s[i]))
        {
            cout<<s[i]<<"\n";
            temp = temp.next[s[i]];
            i++;
        }
        else
        break;
    }
    
}