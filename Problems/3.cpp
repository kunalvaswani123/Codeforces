#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
vector<pair<ll,ll> >v;
ll count1[10000];
int main()
{
	ll n,m,i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		ll p,c;
		cin>>p>>c;
		v.pb(mp(c,p));
	}
	sort(v.begin(),v.end());
	for(i=0;i<n;i++)
	{
		cout<<v[i].first<<' '<<v[i].second<<endl;
	}
	ll ans=0;
	for(i=0;i<n;i++)
	{
		ll res=0;
		ll maxc=0;
		for(j=0;j<n;j++)
		{
			count1[v[j].second]++;
			if(maxc<count1[v[j].second])
			{
				maxc=count1[v[j].second];
				res=v[j].second;
			}
		}
		cout<<res<<endl;
		if(res==1)
		{
			
			break;
		}
		if(v[i].second!=1)
		{
			v[i].second=1;
			ans+=v[i].first;
		}
		for(j=0;j<n;j++)
			count1[j]=0;
	}
	cout<<ans<<endl;
	return 0;
}