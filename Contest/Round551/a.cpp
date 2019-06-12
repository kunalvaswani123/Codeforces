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
ll ceil(ll a, ll b)
{
	if(a%b==0)
		return a/b;
	return a/b + 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,n,t;
    cin >> n >> t;
    ll ans = INT_MAX;
    ll s,d;
    ll ind;
    for(i=0;i<n;i++)
    {
    	cin >> s >> d;
    	if(s >= t)
    	{
    		if(s<ans)
    			ans = s, ind = i+1;
    	}
    	else
    	{
    		ll temp = ceil(t - s, d);
    		temp = s + temp * d;
    		if(temp < ans)
    			ans = temp, ind = i+1;
    	}
    }
    cout << ind << endl;
	return 0;
}