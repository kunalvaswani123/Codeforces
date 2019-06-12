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
const ll L = 2e5 + 5;
ll arr[L];
ll size[L];
vector<ll>ad[L];
ll root(ll i)
{
    while(arr[i] != i)
    {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}
ll union1(ll i, ll j)
{
    ll ri = root(i);
    ll rj = root(j);
    if(size[ri] <= size[rj])
    {
        arr[ri] = rj;
        size[rj] += size[ri];
    	ad[rj].pb(ri);
    }
    else
    {
        arr[rj] = ri;
        size[ri] += size[rj];   
    	ad[ri].pb(rj);
    }
}
ll find(ll i, ll j)
{
    if(root(i) == root(j))
        return true;
    return false;
}
void rec(ll ind)
{
	ll i;
	cout << ind << ' ';
	for(i=0;i<sz(ad[ind]);i++)
	{
		ll v = ad[ind][i];
		if(sz(ad[v]) != 0)
			rec(v);
		else
			cout << v << ' ';
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,n;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        arr[i] = i;
        size[i] = 1;
    }
    ll x,y;
    for(i=0;i<n-1;i++)
    {
    	cin >> x >> y;
    	union1(x,y);
    }
    ll st;
    for(i=1;i<=n;i++)
    	if(arr[i] == i)
    		st = i;
    rec(st);
    cout << '\n';
	return 0;
}