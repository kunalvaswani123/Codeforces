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
char ans[1000];
ll arr[1000];
ll countarr[1000];
vector<ll>pos;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
    	cin>>arr[i];
    	countarr[arr[i]]++;
    }
    for(i=0;i<n;i++)
    {
    	if(countarr[arr[i]]==1)
    		pos.pb(i);
    }
    for(i=0;i<n;i++)
    {
    	ans[i]='A';
    }
    if(pos.size()%2==1)
    {
    	ll flag=0;
    	for(i=0;i<n;i++)
    	{
    		if(countarr[arr[i]]>2)
    		{
    			flag=1;
    			cout<<"YES"<<endl;
    			ans[i]='B';
    		
	    		for(ll j=0;j<pos.size();j++)
			    {
			    	if(j%2==1)
				    	ans[pos[j]]='B';
				    else
				    	ans[pos[j]]='A';
			    }
			    for(ll j=0;j<n;j++)
			   		cout<<ans[j];
			    cout<<endl;
    			break;
    		}
    	}
    	if(flag==0)
    		cout<<"NO"<<endl;
    	return 0;
    }
    cout<<"YES"<<endl;
    for(i=0;i<pos.size();i++)
    {
    	if(i%2==1)
	    	ans[pos[i]]='A';
	    else
	    	ans[pos[i]]='B';
    }
    for(i=0;i<n;i++)
   		cout<<ans[i];
    cout<<endl;
	return 0;
}