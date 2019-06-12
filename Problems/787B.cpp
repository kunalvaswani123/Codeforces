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
 	ll n,m,i,k,p,f;
 	cin>>n>>m;
 	ll ans=0;
 	while(m--)
 	{
 		cin>>k;
 		set<ll>s;
 		f=0;
 		while(k--)
 		{	
 			cin>>p;
 			s.insert(p);
 		}
 		set<ll>::iterator it;
 		for(it=s.begin();it!=s.end();it++)
 		{
 			ll val=-*it;
 			set<ll>::iterator ch=s.lower_bound(val);
 			if(*ch==val)
 				f=1;
 		}
 		if(f==0)
 			ans=1;
 	}
 	if(ans==1)
 		cout<<"YES"<<endl;
 	else
 		cout<<"NO"<<endl;   
	return 0;
}