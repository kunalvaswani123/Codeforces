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
    ll n,a,b,c;
    cin>>n;
    a=n/3;
    if(n%3==0)
    {
    	if(a%3==0)
	    	cout<<a-2<<' '<<a+1<<' '<<a+1<<endl;
    	else
	    	cout<<a<<' '<<a<<' '<<a<<endl;
    }
    else
    {
    	c=n-2*a;
    	if(c%3==0)
	    	cout<<a+1<<' '<<a+1<<' '<<c-2<<endl;
	    else if(a%3==0)
	    	cout<<a-2<<' '<<a-2<<' '<<c+4<<endl;
	    else
	    	cout<<a<<' '<<a<<' '<<c<<endl;
    }
	return 0;
}