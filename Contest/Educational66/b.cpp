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
 	ll n;
 	cin >> n;
 	stack<ll>as;
 	ll sum = 1;
 	ll ans = 0;
	string s;
	ll x;
 	ll ch = pow(2,32) - 1;
    ll f = 0;
    ll p = 0;
    stack<ll>ne;
 	while(n--)
 	{
 		cin >> s;
 		if(s == "add")
        {
            if(f == 1)
                continue;
            if(p == 1)
                f = 1;
            else
     			ans += sum;
        }
 		else if(s == "for")
 		{
 			cin >> x;
            if(f == 1)
                continue;
            if(sum * x > ch)
            {
                if(p == 0)
                {
                    p = 1;
                    sum *= x;
                    as.push(x);
                }
                else
                    ne.push(x);
            }
            else
            {
                sum *= x;
     			as.push(x);
            }
 		}
 		else
 		{	
            if(f == 1)
                continue;
            if(p == 1)
            {
                if(sz(ne) == 0)
                {
                    p = 0;
                    sum /= as.top();
                    as.pop();    
                }
                else
                    ne.pop();
            }
            else
            {
       			sum /= as.top();
     			as.pop();
            }
 		}
        if(ans > ch)
            f = 1;
    }
 	if(f == 1)
 		cout << "OVERFLOW!!!" << endl;
 	else
	 	cout << ans << endl;
    return 0;
}