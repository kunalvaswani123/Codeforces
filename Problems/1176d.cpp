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
const ll L = 2750140;
ll s[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,j,n;
 	cin >> n;
 	ll c = 0;
 	for(i=2;i<=L;i++)
 	{
 		if(s[i] == 0)
 		{
	 		s[i] = ++c;
	 		for(j=i*2;j<=L;j+=i)
	 			s[j] = -1;
 		}
 	}
 	ll x;
 	multiset<ll,greater<ll> >as;
 	multiset<ll,greater<ll> >::iterator it;
 	for(i=0;i<2*n;i++)
 		cin >> x, as.insert(x);
 	vector<ll>ans;	
 	it = as.begin();
 	while(sz(ans)!=n)
 	{
 		if(s[*it] != -1)
 		{
 			ans.pb(s[*it]);	
 			as.erase(as.find(s[*it]));
 		}
 		else
 		{
 			ll req;
			ans.pb(*it);
 			for(j=2;j*j<=*it;j++)
 			{
 				if(*it % j==0)
 				{
 					req = *it/j;
 					break;
 				}
 			}
 			as.erase(as.find(req));
 		}
 		it++;
 	}
 	for(i=0;i<n;i++)
 		cout << ans[i] << ' ';
 	cout << endl;
	return 0;
}