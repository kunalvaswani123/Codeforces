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
vector<pll>ad[L];
ll vis[L];
ll dist[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n,m;
 	cin >> n >> m;   
	for(i=2;i<=n;i++)
		dist[i] = 1e18;
	ll a,b,w;
	while(m--)
	{
		cin >> a >> b >> w;
		if(a != b)
		{
			ad[a].pb(mp(b,w));
			ad[b].pb(mp(a,w));
		}
	}
	pqq<pll,vector<pll>,greater<pll> >as;
	as.push(mp(0,1));
	while(!as.empty())
	{
		ll v = as.top().se;
		ll sc = as.top().fi;
		as.pop();
		if(!vis[v])
		{
			vis[v] = 1;
			dist[v] = sc;
			for(i=0;i<sz(ad[v]);i++)
			{
				if(!vis[ad[v][i].fi])
					as.push(mp(sc + ad[v][i].se, ad[v][i].fi));
			}
		}
	}
	if(dist[n] == 1e18)
		cout << -1 << endl;
	else
	{
		vector<ll>ans;
		ll st = n;
		while(st != 1)
		{
			ans.pb(st);
			for(i=0;i<sz(ad[st]);i++)
			{
				if(dist[ad[st][i].fi] + ad[st][i].se == dist[st])
				{
					st = ad[st][i].fi;
					break;
				}
			}
		}
		ans.pb(1);
		reverse(all(ans));
		for(i=0;i<sz(ans);i++)
			cout << ans[i] << ' ';
		cout << endl;
	}
	return 0;
}