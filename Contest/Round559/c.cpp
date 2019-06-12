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
ll bo[L];
ll gi[L];
ll bg[L];
pqq <ll> val;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,b,g;
 	cin >> b >> g;
 	ll ans = 0;
 	ll x = -1e18, y = 1e18;
 	for(i=0;i<b;i++)
 	{
 		bg[i] = 1;
 		cin >> bo[i];
 		arr[i] = g - 1;
 		ans += bo[i];
 		x = max(bo[i],x);
 	}
 	for(i=0;i<g;i++)
 	{
 		cin >> gi[i];
 		ans += gi[i];
 		val.push(gi[i]);
 		y = min(gi[i],y);
 	}
 	if(y < x)
 	{
 		cout << -1 << endl;
 		return 0;
 	}
 	sort(bo,bo+b);
 	i = b-1;
 	while(!val.empty() && i >= 0)
 	{
 		if(val.top() >= bo[i])
 		{
	 		if(arr[i] == 0)
	 		{
	 			if(bo[i] == val.top())
	 			{
	 				ans -= bo[i];
	 				val.pop();
	 			}
	 			i--;
	 			continue;
	 		}
	 		arr[i]--;
	 		val.pop();
 		}
 		else
 			i--;
 	}
 	for(i=0;i<b;i++)
 		ans += arr[i] * bo[i];
	cout << ans << endl;
	return 0;
}