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
const ll L=1e2+5;
ll arr[L];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,j,n;
    cin>>n;
    string s;
    cin>>s;
    for(i=0;i<n;i++)
        arr[i]=s[i]-'0';
    for(i=0;i<n-1;i++)
    {
        ll f=0;
        ll sum1=0;
        for(j=0;j<=i;j++)
            sum1+=arr[j];
        ll tempsum=0,tempv=i+1;
        ll d=1;
        while(tempv<n)
        {
            tempsum+=arr[tempv];
            if(tempsum==sum1)
            {
                tempsum=0;
                d++;
            }
            else if(tempsum>sum1)
            {   
                f=1;
                break;
            }
            tempv++;
        }
        if(f==0&&tempsum==0&&d>1)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}