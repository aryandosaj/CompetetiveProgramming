#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
}
class Solution {
public:
    map<ALNode*,ALNode*> mp;
    ALNode* fun(ALNode* head)
    {
        if(head==NULL)return NULL;
        ALNode* a = new  ALNode(0); 
        a->val = head->val;
        a->arbitary = head->arbitary;
        a->next = fun(head->next);
        return a;
    }
    
    ALNode* copyarbitaryList(ALNode* head) {
        ALNode* hea = head;        
        ALNode* root = fun(head);
        ALNode* ret = root;
        while(root!=NULL)
        {
            mp[head] = root;
            head=head->next;
            root=root->next;
        }
        root=ret;
        
        while(root!=NULL)
        {
            root->arbitary = mp[root->arbitary];
            root = root->next;
        }
        
        return ret;
    }
};