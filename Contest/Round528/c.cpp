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
ll dp[1001][1001];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	set<pll>ps;
 	ll x=3;
 	while(x--)
 	{
 		ll temp1,temp2;
 		cin>>temp1;
 		cin>>temp2;
 		ps.insert(mp(temp2,temp1));
 	}
 	set<pll>::iterator it;
 	it=ps.begin();
 	ll x1,x2,y1,y2,x3,y3;
 	x1=(*it).se;
 	y1=(*it).fi;
	it++;
	x2=(*it).se;
	y2=(*it).fi;
	it++;
 	x3=(*it).se;
 	y3=(*it).fi;
 	ll i,j,end;
 	for(i=y1;i<=y2;i++)
 		dp[x1][i]=1;
 	i=min(x1,x2);
 	end=max(x1,x2);
 	for(;i<=end;i++)
 		dp[i][y2]=1;
 	for(i=y2;i<=y3;i++)
 		dp[x3][i]=1;
 	i=min(x2,x3);
 	end=max(x2,x3);
 	for(;i<=end;i++)
 		dp[i][y2]=1;
 	vector<pll>ans;
 	for(i=0;i<=1000;i++)
 	{
 		for(j=0;j<=1000;j++)
 		{
 			if(dp[i][j]==1)
	 			ans.pb(mp(i,j));
 		}
 	}
 	cout<<ans.size()<<endl;
 	for(i=0;i<ans.size();i++)
 	{
 		cout<<ans[i].fi<<' '<<ans[i].se<<endl;
 	}
	return 0;
}