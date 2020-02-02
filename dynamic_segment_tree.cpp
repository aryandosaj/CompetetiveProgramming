//dynamic Segment Tree
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
struct segtree
{
    segtree *left;
    segtree *right;
    ll val;
    ll ripe;
    segtree(segtree *l, segtree *r, ll v, ll ri) { left = l, right = r, val = v, ripe = ri; }
};
void update(segtree *root, ll l, ll r, ll ql, ll qr)
{
    if(root->ripe)return;
    if (r < ql || l > qr)
        return;
    if (l >= ql && r <= qr)
    {
        root->val = r - l + 1;
        root->ripe=1;
        return;
    }
    if (root->right == NULL)
        root->right = new segtree(NULL, NULL, 0, 0);
    if (root->left == NULL)
        root->left = new segtree(NULL, NULL, 0, 0);
    ll mid = (l + r) / 2;
    update(root->left, l, mid, ql, qr);
    update(root->right, mid + 1, r, ql, qr);
    root->val = root->left->val + root->right->val;
    return;
}
ll query(segtree *root, ll l, ll r, ll ql, ll qr)
{
    
    if (r < ql || l > qr)
        return 0;
    if (l >= ql && r <= qr)
    {
        return root->val;
    }
    if(root->ripe)
    {
        if(l<=ql && r>=qr )return (qr-ql+1);
        if(l<=ql && r<=qr )return r-ql+1;
        if(r>=qr && l>=ql) return qr-l+1; 
    }
    
    ll ans = 0;
    ll mid = (l + r) / 2;
    if (root->left)
        ans += query(root->left, l, mid, ql, qr);
    if (root->right)
        ans += query(root->right, mid + 1, r, ql, qr);
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    segtree *root = new segtree(NULL, NULL, 0, 0);
    ll c = 0;
    ll m;
    cin >> m;
    ll l = 1, r = 1000000010;
    while (m--)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        x += c, y += c;
        if (t == 1)
        {
            c = query(root, l, r, x, y);
            cout << c << "\n";
        }
        else
        {
            update(root, l, r, x, y);
            // cout << root->val << "\n";
        }
    }
}