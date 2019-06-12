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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll x,y,z,a,b,c1;
 	cin >> x >> y >> z >> a >> b >> c1;
 	ll ta = a,tb = b,tc = c1;
	ll c = a+b+c1;
	if(ta>=x)
		ta-=x,c-=x;
	else
	{
		cout << "NO" << endl;
		return 0;;
	}
	if((ta+tb)>=y)
		c-=y;
	else
	{
		cout << "NO" << endl;
		return 0;;
	}
	if(c>=z)
		cout << "YES" << endl;
	else
	{
		cout << "NO" << endl;
		return 0;;
	}
	return 0;
}