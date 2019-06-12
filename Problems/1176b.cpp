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
 	ll i,n,t,x;
 	cin >> t;
 	while(t--)
 	{
 		cin >> n;
 		ll t3 = 0;
 		ll t2 = 0;
 		ll t1 = 0;
		ll ans = 0;
 		for(i=0;i<n;i++)
 		{
 			cin >> x;
 			if(x % 3 == 0)
 				t3++;
 			else if(x % 3 == 1)
 				t1++;
 			else
 				t2++;
 		}
		ans += min(t2,t1);
		t2 -= ans;
		t1 -= ans;
		ans += t3;
		if(t2 > 0)
			ans += t2 / 3;
		if(t1 > 0)
			ans += t1 / 3;
		cout << ans << endl;
 	}
	return 0;
}