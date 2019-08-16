#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265359
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
ll power(ll x,ll y,ll p) 
{ 
    ll res=1;  
    x=x%p;
    while (y > 0) 
    { 
        if(y&1) 
            res=(res*x)%p; 
        y=y>>1;
        x=(x*x)%p;   
    } 
    return res; 
}
const ll L = 1e5 + 5;
ll arr[L];
ll tree[4 * L];
void make(ll l, ll r, ll i)
{
	if(l == r)
	{
		tree[i] = arr[l];
		return;
	}
	ll mid = (l + r) >> 1;
	make(l, mid, 2 * i + 1);
	make(mid + 1, r, 2 * i + 2);
	tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}
ll query(ll l, ll r, ll s, ll e, ll i)
{
	if(s <= l && r <= e)
		return tree[i];
	if(r < s || e < l)
		return INT_MAX;
	else
	{
		ll mid = (l + r) >> 1;
		ll a = query(l, mid, s, e, 2 * i + 1);
		ll b = query(mid + 1, r, s, e, 2 * i + 2);
		return min(a, b);
	}
}
void update(ll l, ll r, ll i, ll id, ll val)
{
	if(l == r)
	{
		arr[id] = val;
		tree[i] = val;
		return;
	}
	ll mid = (l + r) >> 1;
	if(id <= mid)
		update(l, mid, 2 * i + 1, id, val);
	else
		update(mid + 1, r, 2 * i + 2, id, val);
	tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n,q;
 	cin >> n >> q;
 	for(i=0;i<n;i++)
 		cin >> arr[i];
 	make(0,n-1,0);
 	char c;
 	ll a,b;
 	while(q--)
 	{
 		cin >> c;
 		if(c == 'q')
 		{
 			cin >> a >> b;
 			a--, b--;
 			cout << query(0,n-1,a,b,0) << endl;
 		}
 		else
 		{
 			cin >> a >> b;
 			a--;
 			update(0,n-1,0,a,b);
 		}
 	}
	return 0;
}