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
const ll L=1e5+5;
ll arr[L];
ll cnt[L];
ll cnt2[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,j,n,m;
 	cin>>n>>m;
 	for(i=0;i<m;i++)
 		cin>>arr[i];
 	vector<int>ans;
 	ll cts=1;
 	for(i=0;i<m;i++)
 	{
		cnt[arr[i]]++;
 		cnt2[cnt[arr[i]]]++;
 		if(cnt2[cts]==n)
 		{
 			ans.pb(1);
 			cts++;
 		}
 		else
 			ans.pb(0);
 	}
 	for(i=0;i<ans.size();i++)
 		cout<<ans[i];
 	cout<<endl;
	return 0;
}