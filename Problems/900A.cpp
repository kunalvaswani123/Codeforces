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
 	ll x,y,n,i;
 	cin>>n;
 	ll c1=0,c2=0;
 	for(i=0;i<n;i++)
 	{
 		cin>>x>>y;
 		if(x<0)
 			c1++;
 		else
 			c2++;
 	}
 	if(c1==1||c1==0||c2==1||c2==0)
 		cout<<"YES"<<endl;
 	else
 		cout<<"NO"<<endl;   
	return 0;
}