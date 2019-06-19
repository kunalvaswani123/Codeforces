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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll x,y,z;
 	cin >> x >> y >> z;
 	ll ans = 0;
 	ans += (x / z);
 	ans += (y / z);
 	x = x%z;
 	y = y%z;
 	ll temp = (x + y) / z;
 	ans += ((x+y) / z);
 	ll t2 = min(temp*z - x,temp*z -y);
 	if(t2 < 0)
 		t2 = 0;
 	cout << ans << ' ' << t2 << endl;   
	return 0;
}