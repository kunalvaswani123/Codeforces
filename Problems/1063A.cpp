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
 	ll i,n;
 	cin>>n;
 	string s;
 	cin>>s;
 	map<char,ll>vals;
 	for(i=0;i<n;i++)
 	{
 		if(vals.find(s[i])!=vals.end())
 			vals[s[i]]++;
 		else
 			vals[s[i]]=1;
 	}   
 	map<char,ll> :: iterator it;
 	string out="";
 	for(it=vals.begin();it!=vals.end();it++)
 	{
 		for(i=0;i<it->se;i++)
 			out+=it->fi;
 	}
 	cout<<out<<endl;
	return 0;
}