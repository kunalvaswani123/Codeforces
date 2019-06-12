#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
const ll L = 150000 + 10;
ll arr[L];
ll check[L];
vector<ll>G[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i, n;
 	ll x, y;
 	cin >> n;
 	for(i=0;i<n-1;i++)
 	{
 		cin >> x >> y;
 		if(check[x] == 0 && check[y] == 0)
 		{
	 		G[x].pb(y);
	 		check[x] = x;
	 		check[y] = x;
 		}
 		else if(check[x] != 0 && check[y] == 0)
 		{
 			G[check[x]].pb(y)
 			check[y] = check[x];
 		}
 		else if(check[x] == 0 && check[y] != 0)
 		{
 			G[check[y]].pb(x)
 			check[x] = check[y];
 		}
 		else
 		{
 			G[min(check[x],check[y])].pb(max(check[x],check[y]));
 		}
 	}
	return 0;
}