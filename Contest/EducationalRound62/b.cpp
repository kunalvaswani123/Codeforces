#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define american_pie 3.1415926535
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
 	ll t;
 	cin >> t;
 	while(t--)
 	{
 		ll i, n;
 		cin >> n;
 		string s;
 		cin >> s;
 		if(s[0] == '<' && s[n-1] == '>')
 		{
 			for(i=0;i<=n-1;i++)
 			{
 				if(s[i]=='>')
 					break;
 			}
 			ll a1 = i;
 			ll a2 = 0;
 			for(i=n-1;i>=0;i--)
 			{
 				if(s[i]=='<')
 					break;
 				else
	 				a2++;
 			}
 			cout << min(a1, a2) << endl;
 		}
 		else
 			cout << 0 << endl;
 	}   
	return 0;
}