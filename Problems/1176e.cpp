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
vector<ll> ad[L];
bool vis[L];
vector<ll>l[2];
void dfs(ll ind, ll la)
{
	vis[ind] = true;
	ll i;
	l[la].pb(ind);
	for(i=0;i<sz(ad[ind]);i++)
	{
		if(!vis[ad[ind][i]])
			dfs(ad[ind][i],1-la);
	}
}	
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,t,n,m;
 	cin >> t;
 	while(t--)
 	{
 		l[0].clear();
 		l[1].clear();
 		cin >> n >> m;
 		for(i=1;i<=n;i++)
 		{
 			vis[i] = false;
 			ad[i].clear();
 		}
 		ll a,b;
 		for(i=1;i<=m;i++)
 		{
 			cin >> a >> b;
 			ad[a].pb(b);
 			ad[b].pb(a);
 		}
 		dfs(1,0);
 		cout << min(sz(l[0]), sz(l[1])) << endl;
 		if(sz(l[0]) < sz(l[1]))
 			for(i=0;i<sz(l[0]);i++)
 				cout << l[0][i] << ' ';
 		else
 			for(i=0;i<sz(l[1]);i++)
 				cout << l[1][i] << ' ';
 		cout << endl;
 	}
	return 0;
}