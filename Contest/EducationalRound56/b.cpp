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
 	ll t;
 	cin>>t;
 	while(t--)
 	{
 		string s;
 		cin>>s;
 		set<char>as;
 		ll i;
 		for(i=0;i<s.size();i++)
 			as.insert(s[i]);
 		if(as.size()==1)
 		{
 			cout<<-1<<endl;
 			continue;
 		}
 		else
 		{
 			char te=s[0];
 			for(i=0;i<s.size();i++)
 			{
 				if(s[i]!=te)
 					break;
 			}
 			char temp=s[i];
 			s[i]=s[s.size()-1];
 			s[s.size()-1]=temp;
 		}
 		cout<<s<<endl;
 	}   
	return 0;
}