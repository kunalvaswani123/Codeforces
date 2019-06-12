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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	cin >> n;
 	string s;
 	cin >> s;
 	vector<ll>ans;
 	ll s1 = 0, s2 = 0;
 	for(i=0;i<n;i++)
 	{
 		if(s[i] == '(')
 		{
 			s1 = 1 - s1;
 			ans.pb(s1);
 		}
 		else
 		{
 			s2 = 1 - s2;
 			ans.pb(s2);
 		}
 	}
 	for(i=0;i<n;i++)
 		cout << ans[i];
 	cout << endl;
	return 0;
}