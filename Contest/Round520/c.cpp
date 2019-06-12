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
const ll L=1e6;
ll arr[L];
pair<ll,ll >parr[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n,q,i;
 	cin>>n;
 	cin>>q;
 	string s;
 	cin>>s;
 	ll on=0;
 	ll ze=0;
 	for(i=0;i<n;i++)
 	{
 		ll val=s[i]-'0';
 		if(val==1)
 			on++;
 		else
 			ze++;
 		parr[i]=mp(on,ze);
 	}
 	while(q--)
 	{
 		ll l,r;
 		cin>>l>>r;
 		l--;r--;
 		ll ones,zeroes;
 		if(l==0)
 		{
 			 ones=parr[r].fi;
 			 zeroes=parr[r].se;
	
 		}
 		else
 		{
 			 ones=parr[r].fi-parr[l-1].fi;
 			 zeroes=parr[r].se-parr[l-1].se;
 		}
 		ll temp=power(2,ones,mod);
 		ll temp2=power(2,zeroes,mod);
 		
 		ll ans=temp-1+mod+((((temp-1+mod)%mod)*((temp2-1+mod)%mod))%mod);
 		cout<<ans%mod<<endl;	
 	}   
	return 0;
}