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
const ll L = 1e5 + 5;
ll a[2 * L];
ll b[2 * L];
ld d[2 * L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i, n;
 	cin >> n;
 	for(i = 0; i < n; i++)
 		cin >> a[i];

 	for(i = 0; i < n; i++)
 		cin >> b[i];

 	for(i = 0; i < n; i++)
 	{
 		if(a[i] == 0 && b[i] == 0)
 			d[i] = -1e12;
 		else if(a[i] == 0)
 			d[i] = 1e12;
 		else if(b[i] == 0)
 			d[i] = 0;
 		else
 			d[i] = -b[i] / a[i];
 	}
 	sort(d, d + n);
 	d[n] = 1e12 + 5;
 	ll st = 0;
 	ll count = 0;
 	ll ans = 0;
 	if(d[0] == -1e12)
 		st++;
 	else
 		count = 1;
 	for(i = 1; i < n + 1; i++)
 	{
 		if(d[i] == 0)
 			st++,i++;
 		else if(d[i] == d[i - 1])
 			count++;
 		else
 			count = 1, ans = max(count, ans);
 	}
 	ans += st;
 	if(ans == 1)

	return 0;
}