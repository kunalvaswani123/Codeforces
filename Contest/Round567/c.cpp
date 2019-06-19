#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265359
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
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
char arr[1005][1005];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,j,n,m;
 	cin >> n >> m;
 	string s;
 	for(i=0;i<n;i++)
 	{
 		cin >> s;
 		for(j=0;j<m;j++)
 			arr[i][j] = s[j];
 	}
 	set<pair<pair<pll,ll>,pair<pll,ll> > >pv;
 	ll ans = 0;	
 	for(j=0;j<m;j++)
 	{
	 	set<pair<pair<pll,ll>,pair<pll,ll> > >v;
	 	set<pair<pair<pll,ll>,pair<pll,ll> > > :: iterator it;
	 	vector<pair<char,pll> >v2;
	 	char temp;
	 	ll c = 0;
	 	ll ind = 0;
	 	for(i=0;i<n+1;i++)
	 	{
	 		if(i == 0)
	 		{
	 			temp = arr[i][j];
	 			c=1;
	 			ind = 0;
	 		}
	 		else if(i == n || arr[i][j] != arr[i-1][j])
	 		{
	 			v2.pb(mp(temp,mp(c,ind)));
	 			temp = arr[i][j];
	 			c=1;
	 			ind = i;
	 		}
	 		else
	 			c++;
	 	}
	 	for(i=0;i<=sz(v2)-3;i++)
	 	{
	 		if(v2[i].se.fi < v2[i+1].se.fi)
	 			continue;
	 		if(v2[i+2].se.fi < v2[i+1].se.fi)
	 			continue;
	 		ll ch = v2[i+1].se.fi;
	 		pair<pll,ll> temp;
	 		pair<pll,ll> temp2;
	 		ll len = v2[i+1].se.fi;
	 		temp.fi.fi = v2[i+1].se.se - len;
	 		temp.fi.se = len;
	 		temp.se = 1;
	 		temp2.fi.fi = v2[i].fi;
	 		temp2.fi.se = v2[i+1].fi;
	 		temp2.se = v2[i+2].fi;
	 		v.insert(mp(temp,temp2));
	 	}
	 	set<pair<pair<pll,ll> ,pair<pll,ll> > >newv;
	 	if(j == 0)
	 	{
	 		pv = v;
	 		ans += sz(v);
	 	}
	 	else
	 	{
	 		for(it=v.begin();it!=v.end();it++)
	 		{
 				pair<pair<pll,ll> ,pair<pll,ll> >  sat = *it;
 				pair<pair<pll,ll> ,pair<pll,ll> >  sa1 = *it;
	 			sa1.fi.se = -1;
 				pair<pair<pll,ll> ,pair<pll,ll> >  sa2 = *pv.lower_bound(sa1);
	 			ll tc = sa2.fi.se;
	 			sa2.fi.se = sat.fi.se;
	 			if(sa2 == sat)
	 			{
	 				ans += (tc + 1);
	 				sa2.fi.se = tc + 1;
	 				newv.insert(sa2);
	 			}
	 			else
	 			{
	 				newv.insert(*it);
	 				ans += 1;
	 			}
	 		}
	 		pv = newv;
	 	}
 	}
 	cout << ans << endl;
	return 0;
}