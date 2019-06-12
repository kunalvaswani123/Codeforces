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
 	ll n,m,k;
 	cin>>n>>m>>k;
 	ll ch=n*m;
 	if((2*ch)%k!=0)
 	{
 		cout<<"NO"<<endl;
 		return 0;
 	}
 	cout<<"YES"<<endl;
 	cout<<0<<' '<<0<<endl;
 	if((2*n)%k==0)
 	{
 		ll te=(2*n)/k;
 		cout<<te<<' '<<0<<endl;
 		cout<<0<<' '<<m<<endl;
 	}
 	else if((2*m)%k==0)
 	{
 		ll te=(2*m)/k;
 		cout<<0<<' '<<te<<endl;
 		cout<<n<<' '<<0<<endl;
 	}
 	else if((2*ch)%k==0)
 	{
 		ll te=(2*ch)/k;
 		cout<<0<<' '<<te<<endl;
 		cout<<1<<' '<<0<<endl;
 	}   
	return 0;
}