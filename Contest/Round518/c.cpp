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
 map<ll,vector< pair<ll,ll> > >mpz;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,i,j,x,y;
    cin >> n >> m;
    ll i1=1,j1=1,i2=1,j2=2;
    for(i=0;i<m;i++)
    {
    	cin >> x >> y;
    	mpz[x].pb(mp(i1,j1));
    	mpz[y].pb(mp(i2,j2));
    	i1++;
    	i2++;
    	j1+=2;
    	j2+=2;
	}

	for(i=1;i<=n;i++)
	{
		printf("%lld\n",mpz[i].size());
		for(j=0;j<mpz[i].size();j++)
			printf("%lld %lld\n",mpz[i][j].first,mpz[i][j].second);
	}

	return 0;
}