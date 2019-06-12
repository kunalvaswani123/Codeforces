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
 	string s;
 	cin>>s;
 	ll i,n=s.size();
 	ll c1=0,c2=1;
 	for(i=0;i<n;i++)
 	{
 		if(s[i]=='0')
 		{
 			cout<<2*c1+1<<' '<<1<<endl;
 			c1=1-c1;
 		}
 		else
 		{
 			cout<<c2<<' '<<2<<endl;
 			c2++;
 			if(c2>4)c2=1;
 		}
 	}
	return 0;
}