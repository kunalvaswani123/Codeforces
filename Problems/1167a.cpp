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
 	ll i,t,n;
 	string s;
 	cin >> t;
 	while(t--)
 	{
 		cin >> n >> s;
 		for(i=0;i<n;i++)
 		{
 			if(s[i] == '8')
 				break;
 		}
 		if(n-i < 11)
 			cout << "NO" << endl;
 		else
 			cout << "YES" << endl;	
 	}   
	return 0;
}