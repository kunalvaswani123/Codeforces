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
 	string s;
 	cin>>s;
 	ll i;
 	stack<char> as;
 	ll n=s.size();
 	ll c=1;
 	for(i=0;i<n;i++)
 	{
 		if(!as.empty()&&as.top()==s[i])
 		{
 			as.pop();
 			c=1-c;
 		}
 		else
 			as.push(s[i]);
 	}   
 	if(c==1)
 		cout<<"NO"<<endl;
 	else
 		cout<<"YES"<<endl;
	return 0;
}