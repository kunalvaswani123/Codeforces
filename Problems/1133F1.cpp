#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define american_pie 3.1415926535
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define qq queue
#define pqq priority_queue
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
const ll L = 3 * (1e5);
vector<pll> ed;
vector<ll> ad[L];
bool visited[L];
void bfs(ll ind)
{
	deque<ll> q;
	visited[ind] = true;
	q.push_front(ind);
	while(!q.empty())
	{
		ll p = q.front();
		q.pop_front();
		ll i;
		for(i = 0; i < ad[p].size(); i++)
		{
			if(!visited[ad[p][i]])
			{
				ed.pb(mp(p, ad[p][i]));
				visited[ad[p][i]] = true;
				q.push_back(ad[p][i]);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i, n, m, u, v;
 	cin >> n >> m;
 	ll ans = 0;
 	ll val = 0;
 	for(i = 0; i < m; i++)
 	{
 		cin >> u >> v;
 		ad[u].pb(v);
 		ad[v].pb(u);
 		if(ad[u].size() > ans)
 			ans = ad[u].size(), val = u;
 		if(ad[v].size() > ans)
 			ans = ad[v].size(), val = v;
 	}
 	bfs(val);
 	for(i = 0; i < ed.size(); i++)
 		cout << ed[i].fi << ' ' << ed[i].se << endl;
	return 0;
}