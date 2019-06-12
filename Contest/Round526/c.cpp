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
 	string s;
 	cin>>s;
 	vector<pair<char,ll> >v;
 	ll i;
 	ll len=s.size();
 	ll count=1;
 	for(i=1;i<=len;i++)
 	{
 		if(i!=len&&s[i]==s[i-1])
 			count++;
 		else
 		{
 			v.pb(mp(s[i-1],count));
 			count=1;
 		}
 	}  
 	ll flag=0;
 	ll j;
 	vector<ll>nos;
 	nos.pb(0);
 	for(i=0;i<v.size();i++)
 	{
 		if(v[i].fi=='a')
 		{
 			if(flag==1)
 			{
 				nos.pb(v[i].se);
 				flag=0;
 			}
 			else
 				nos[nos.size()-1]+=v[i].se;
 			for(j=i+1;j<v.size();j++)
 			{
 				if(v[j].fi=='b')
 					flag=1;
 				else if(v[j].fi=='a')
 				{
 					i=j-1;
 					break;
 				}
 			}	
 		}
 	} 	
 	ll ans=0;
 	for(i=0;i<nos.size();i++)
 	{
 		ll newans=(ans*nos[i])%mod;
 		newans=(newans+nos[i])%mod;
 		ans=(newans+ans)%mod;
 	}
 	cout<<ans<<endl;
	return 0;
}