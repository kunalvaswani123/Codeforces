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
 	string s;
 	while(t--)
 	{
	 	ll lc=0,uc=0,dig=0;
 		ll i,j,k;
 		cin>>s;
 		ll length=s.length();
 		for(i=0;i<length;i++)
 		{
	 		if(islower(s[i]))
	 			lc=1;
 			if(isupper(s[i]))
 				uc=1;
 			if(isdigit(s[i]))
 				dig=1;
 		}
 		if(lc==1&&uc==0&&dig==0)
 		{
 			s[1]='A';
 			s[2]='1';
 		}
 		else if(uc==1&&lc==0&&dig==0)
 		{
 			s[1]='a';
 			s[2]='1';
 		}
 		else if(dig==1&&uc==0&&lc==0)
 		{
 			s[1]='A';
 			s[2]='a';
 		}
 		else if(lc==1&&dig==1&&uc==1)
 		{
 			cout<<s<<endl;
 			continue;
 		}
 		else
 		{
			ll count=0;
			lc=0,uc=0,dig=0;;
			for(i=0;i<length;i++)
	 		{
		 		if(islower(s[i]))
		 		{
		 			if(lc!=1)
			 			count++;
		 			lc=1;
		 		}
	 			if(isupper(s[i]))
	 			{
	 				if(uc!=1)
			 			count++;
	 				uc=1;
	 			}
	 			if(isdigit(s[i]))
	 			{
	 				if(dig!=1)
			 			count++;
	 				dig=1;
	 			}
	 			if(count==2)
	 			{
	 				if(dig!=1)
	 				{
	 					if(i!=length-1)
		 					s[i+1]='1';
	 					else
	 						s[i-1]='1';
	 				}
	 				if(lc!=1)
	 				{
	 					if(i!=length-1)
		 					s[i+1]='a';
	 					else
	 						s[i-1]='a';
	 				}
	 				if(uc!=1)
	 				{
	 					if(i!=length-1)
		 					s[i+1]='A';
	 					else
	 						s[i-1]='A';
	 				}
	 				break;
	 			}
	 		}
 		}
 		cout<<s<<endl;
 	}   
	return 0;
}