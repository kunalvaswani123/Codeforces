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
ll c[L];
ll arr[L];
set<ll>as[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n,k;
 	cin >> n >> k;
 	for(i=0;i<k;i++)
 	{
 		cin >> arr[i];
 		c[arr[i]] = 1;
 		as[arr[i]].insert(i);
 	}
 	ll p,ans = 0;
 	for(i=1;i<=n;i++)
 	{
 		if(c[i] == 0)
 		{
 			if(i == 1 || i == n)
 				ans -= 1;
 			ans += 3;
 		}
 		else
 		{
 			p = *as[i].begin();
 			if(i!=n)
 			{
 				if(as[i+1].upper_bound(p) == as[i+1].end())
 					ans += 1;
 			}
 			if(i!=1)
 			{
 				if(as[i-1].upper_bound(p) == as[i-1].end())
 					ans += 1;	
 			}	
 		}
 	}
 	cout << ans << endl;
	return 0;
}