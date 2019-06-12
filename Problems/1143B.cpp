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
ll prod(ll n)
{
	ll temp = n;
	ll val = 1;
	while(temp > 0)
	{
		val *= (temp % 10);
		temp /= 10;
	}
	return val;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n;
 	cin >> n;
 	ll ans = -1;
 	ll st = 1;
 	while(1)
 	{
		ll check = n - n % st;
 		ll temp;
 		if(st == 1)
 			temp = check;
 		else
 			temp = check - 1;
 		ans = max(ans, prod(temp));
 		st *= 10;
 		if(check == 0)
 			break;
 	}
 	cout << ans << endl;
	return 0;
}