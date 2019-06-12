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
ll ans[2*L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n,m,d,i,j,te;
 	cin>>n>>m>>d;
 	set<pll>s;
 	for(i=0;i<n;i++)
 	{
 		cin>>te;
 		s.insert(mp(te,i));
 	}
 	ll st=1;
 	set<pll>::iterator it=s.begin();
 	pll check;
 	while(it!=s.end())
 	{
 		check=*it;
 		ans[check.se]=st;
 		while(s.lower_bound(mp(check.fi+d+1,0))!=s.end())
 		{
 			pll temp=*s.lower_bound(mp(check.fi+d+1,0));
 			ans[temp.se]=st;
 			s.erase(s.lower_bound(mp(check.fi+d+1,0)));
 			check=temp;
 		}
 		st++;
 		it++;
 	}
 	cout<<st-1<<endl;
 	for(i=0;i<n;i++)
 		cout<<ans[i]<<' ';
 	cout<<endl;
	return 0;
}