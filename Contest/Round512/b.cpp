#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
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
 	ll n,d;
 	cin>>n>>d;
 	ll m;
 	cin>>m;
 	while(m--)
 	{
 		ll x,y;
 		ll f1=0;
 		ll f2=0;
 		cin>>x>>y;
 		ll a=x+y;
 		ll b=y-x;
 		if(a>=d&&a<=(2*n-d))
 			f1=1;
 		if(b<=d&&b>=-d)
 			f2=1;
 		if(f1==1&&f2==1)
 			cout<<"YES"<<endl;
 		else
 			cout<<"NO"<<endl;
 	}   
	return 0;
}