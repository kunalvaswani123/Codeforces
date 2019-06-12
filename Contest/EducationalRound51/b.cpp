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
 	ll l,r,i;
 	cin>>l>>r;   
 	for(i=l;i<r;i+=2)
 	{
 		if(__gcd(i,i+1)!=1)
 		{
 			cout<<"NO"<<endl;
 			return 0;
 		}
 	}
 	cout<<"YES"<<endl;
 	for(i=l;i<r;i+=2)
 	{
 		cout<<i<<' '<<i+1<<endl;
 	}
	return 0;
}