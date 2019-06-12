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
 	ll i,n,t;
 	string s;
 	cin >> t;
 	while(t--)
 	{
 		cin >> s;
 		map<char,ll>m;
 		n = sz(s);
 		sort(all(s));
 		s += '1';
 		char c = s[0];
 		ll co = 1;
 		string temp = "";
 		temp += c;
 		for(i=1;i<n+1;i++)
 		{
 			if(s[i] == c)
 				co++;
 			else
 			{
 				m[c] = co;
 				c = s[i];
 				if(i != n)
 					temp += c;
 				co = 1;
 			}
 		}
 		string ans = "";
 		if(sz(temp) == 1)
 		{
 			cout << s.substr(0,n) << endl;
 			continue;
 		}
 		if(sz(temp) == 3)
 		{
 			ll cf = 0;
 			do{
	 			ll f1 = 0;
 				for(i=1;i<sz(temp);i++)
		 		{
		 			if(abs(temp[i]-temp[i-1]) == 1)
		 			{
		 				f1 = 1;
		 				break;
		 			}
		 		}
		 		if(f1 == 0)
		 		{
		 			cf = 1;
		 			ans = temp;
		 			break;
		 		}
 			}while(next_permutation(all(temp)));
 			if(cf == 0)
 			{
 				cout << "No answer" << endl;
 				continue;
 			}
 		}
 		else
 		{
	 		ll f = 0;
	 		string s1 = "", s2 = "";
	 		for(i=0;i<sz(temp)/2;i++)
	 			s1 += temp[i], s2 += temp[sz(temp)-i-1];
	 		if(sz(temp)%2!=0)
	 			s2 += temp[i];
	 		reverse(all(s2));
	 		for(i=0;i<sz(s2);i++)
	 		{
	 			ans += s2[i];
	 			if(i != sz(s1))
		 			ans += s1[i];
	 		}
	 		for(i=1;i<sz(ans);i++)
	 		{
	 			if(abs(ans[i]-ans[i-1]) == 1)
	 			{
	 				f = 1;
	 				break;
	 			}
	 		}
	 		if(f == 1)
	 		{
	 			cout << "No answer" << endl;
	 			continue;
	 		}
 		}
 		ll j;
 		for(i=0;i<sz(ans);i++)
 		{
 			for(j=0;j<m[ans[i]];j++)
 				cout << ans[i];
 		}
 		cout << endl;
 	}   	
	return 0;
}