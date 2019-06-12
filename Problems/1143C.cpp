#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define pival 3.1415926535
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
const ll L = 1e5 + 5;
vector<ll>ad[L];
ll c[L];
set<ll>vals;
set<ll> :: iterator it;
void dfs(ll ind)
{
	ll i;
	ll f = 0;
	for(i=0;i<ad[ind].size();i++)
	{
		if(c[ad[ind][i]] == 0)
			f = 1;
		dfs(ad[ind][i]);
	}
	if(f == 0 && c[ind] == 1)
		vals.insert(ind);
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n,p,c1;
 	cin >> n;
 	ll root;
 	for(i=1;i<=n;i++)
 	{
 		cin >> p >> c1;
 		if(p == -1)
 			root = i;
 		else
 			ad[p].pb(i);
		c[i] = c1;
 	}
 	dfs(root);
 	if(vals.size() == 0)
 		cout << -1 << endl;
 	else
 	{
	 	for(it=vals.begin();it!=vals.end();it++)
	 		cout << *it << ' ';
	 	cout << endl;
 	}
	return 0;
}