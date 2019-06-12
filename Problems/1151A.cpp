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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	string s;
 	cin >> n >> s;
 	ll ans = INT_MAX;
 	ll tans,c1,c2,c3,c4;
 	ll a = 'A' - 'A';
 	ll c = 'C' - 'A';
 	ll t = 'T' - 'A';
 	ll g = 'G' - 'A';
 	for(i=0;i<n-3;i++)
 	{
 		tans = 0;
 		c1 = s[i] - 'A';
 		tans += min(c1,26-c1);
 		c2 = s[i+1] - 'A';
 		if(c2 < c)
 			tans += min(c-c2,26+c2-c);
 		else
	 		tans += min(c2-c,26-c2+c);
 		c3 = s[i+2] - 'A';
 		if(c3 < t)
	 		tans += min(t-c3,26+c3-t);
 		else
 			tans += min(c3-t,26-c3+t);
 		c4 = s[i+3] - 'A';
 		if(c4 < g)
	 		tans += min(g-c4,26+c4-g);
 		else
 			tans += min(c4-g,26-c4+g);
 		ans=min(tans,ans);
 	}
 	cout << ans << endl;
	return 0;
}