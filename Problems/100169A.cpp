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
const ll L = 4e4 + 5;
vector<pair<pll,ll> >ad[L];
ll vis[L];
ll dist[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n,m,p;
 	char te;
 	cin >> n >> m >> p;   
	ll a,b,w;
	while(m--)
	{
		cin >> a >> b >> w >> te;
		if(a != b)
		{
			ll x;
			if(te == 'I')
				x = 1;
			else
				x = 2;
			ad[a].pb(mp(mp(b,w),x));
			ad[b].pb(mp(mp(a,w),x));
		}
	}
	ll s,d;
	while(p--)
	{
		cin >> s >> d;
		pqq<pair<ll,pll>,vector<pair<ll,pll> >,greater<pair<ll,pll> > >as;
		as.push(mp(0,mp(0,s)));
		for(i=0;i<n;i++)
		{
			vis[i] = 0;
			dist[i] = 1e18;
		}
		dist[s] = 0;
		while(!as.empty())
		{
			ll v = as.top().se.se;
			ll sc = as.top().se.fi;
			as.pop();
			if(!vis[v])
			{
				vis[v] = 1;
				dist[v] = sc;
				for(i=0;i<sz(ad[v]);i++)	
				{
					if(!vis[ad[v][i].fi.fi])
						as.push(mp(ad[v][i].se, mp(sc + ad[v][i].fi.se, ad[v][i].fi.fi)));
				}
			}
		}
		if(dist[d] == 1e18)
			cout << "IMPOSSIBLE" << endl;
		else
		{
			ll ou = 0;
			ll in = 0;
			ll st = d;
			while(st != s)
			{
				for(i=0;i<sz(ad[st]);i++)
				{
					if(dist[ad[st][i].fi.fi] + ad[st][i].fi.se == dist[st])
					{
						if(ad[st][i].se == 2)
							ou += ad[st][i].fi.se;
						else
							in += ad[st][i].fi.se;
						st = ad[st][i].fi.fi;
						break;
					}
				}
			}
			cout << ou << ' ' << in << endl;
		}
	}
	return 0;
}