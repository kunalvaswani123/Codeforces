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
 	ll i,j,n;
 	cin>>n;
 	multiset<pair<ll,string> >s;
	vector<string>as;
	string te;
 	for(i=0;i<(2*n-2);i++)
 	{
 		cin>>te;
 		as.pb(te);
 		s.insert(mp(te.size(),te));
 	}
 	multiset<pair<ll,string> >::iterator it;
 	char out[n+1];
 	for(it=s.begin();it!=s.end();it++)
	{
		string ne=(*it).se;
		if(ne.size()==1)
		{
			out[0]=ne[0];
			it++;
			ne=(*it).se;
			out[n-1]=ne[0];
		}
		else
		{
			ll f=0;
			for(i=0;i<ne.size()-1;i++)
			{
				if(ne[i]!=out[i])
					f=1;
			}
			if(f==0)
			{
				for(i=0;i<ne.size();i++)
					out[i]=ne[i];
				it++;
				ne=(*it).se;
				ll c=0;
				for(i=n-ne.size();i<n;i++)
					out[i]=ne[c++];
			}
			else
			{
				ll c=0;
				for(i=n-ne.size();i<n;i++)
					out[i]=ne[c++];
				it++;
				ne=(*it).se;
				for(i=0;i<ne.size();i++)
					out[i]=ne[i];
			}
		}
	}
	map<string,ll>st;
	for(i=0;i<(2*n-2);i++)
	{
		ll f=0;
		for(j=0;j<as[i].size();j++)
		{
			if(as[i][j]!=out[j])
				f=1;
		}
		if(f==0&&st[as[i]]==0)
		{
			cout<<'P';
			st[as[i]]=1;
		}
		else
			cout<<'S';
	}
	cout<<endl;
	return 0;
}