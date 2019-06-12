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
const ll L=1e3+5;
pll arr1[L];
pll arr2[L];
int main()
{
	ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
 	ll i,j,n;
 	cin>>n;
 	ll x,y;
 	for(i=1;i<=n;i++)
 	{
 		cin>>x>>y;
 		arr1[i].fi=x,arr1[i].se=y;
 	}
 	for(i=1;i<=n;i++)
 	{
 		cin>>x>>y;
 		arr2[i].fi=x,arr2[i].se=y;
 	}
 	ll flag;
 	ll tx,ty;
 	for(i=1;i<=n;i++)
 	{
	 	set<pll>as;
 		flag=0;
 		for(j=2;j<=n;j++)
 			as.insert(mp(arr1[j].fi,arr1[j].se));
 		tx=arr2[i].fi+arr1[1].fi;
 		ty=arr2[i].se+arr1[1].se;
 		for(j=1;j<=n;j++)
 		{
			if(i!=j)
			{
	 			pll tempv;
	 			tempv.fi=tx-arr2[j].fi;
	 			tempv.se=ty-arr2[j].se;
	 			set<pll> :: iterator lowx=as.find(tempv);
	 			if(lowx!=as.end())
	 				as.erase(lowx);
	 			else	 			
	 			{
	 				flag=1;
	 				break;
	 			}
			}
 		}
 		if(flag==0)
 			break;
 	}
 	cout<<tx<<' '<<ty<<endl;
	return 0;
}