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
const ll L = 1e6 + 5;
ll arr[L];
ll size[L];
ll root(ll i)
{
    while(arr[i] != i)
    {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}
void union1(ll i, ll j)
{
    ll ri = root(i);
    ll rj = root(j);
    if(size[ri] <= size[rj])
    {
        arr[ri] = rj;
        size[rj] += size[ri];
    }
    else
    {
        arr[rj] = ri;
        size[ri] += size[rj];   
    }
}
ll find(ll i, ll j)
{
    if(root(i) == root(j))
        return true;
    return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,n,m,k;
    cin >> n >> m >> k;
    for(i=1;i<=n;i++)
    {
        arr[i] = i;
        size[i] = 1;
    }
    vector<pair<ll,pll> > edgs;
    ll a,b,c;
    while(m--)
    {
        cin >> a >> b >> c;
        edgs.pb(mp(c,mp(a,b)));
    }
    sort(all(edgs));
    c = 0;
    vector<ll>ch;
    for(i=0;i<sz(edgs);i++)
    {
        ll v1 = edgs[i].se.fi;
        ll v2 = edgs[i].se.se;
        if(!find(v1,v2))
        {
            ch.pb(edgs[i].fi);
            c += edgs[i].fi;
            union1(v1,v2);
        }
    }
    ll ans = 0;
    for(i=sz(ch)-1;i>=0;i--)
    {
        if(c <= k)
            break;
        c -= ch[i];
        c += 1;
        ans++;
    }
    ll f = 0;
    ll st = root(1);
    for(i=2;i<=n;i++)
    {
        if(root(i)!=st)
        {
            f = 1;
            break;
        }
    }
    if(c <= k && f == 0)
        cout << ans << endl;
	else
        cout << -1 << endl;
    return 0;
}