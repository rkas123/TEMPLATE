#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vpll; 

#define inl(x) ll x;cin>>x
#define in(x) int x;cin>>x
#define mk(t,a,n) t*a = new t[n]
#define inp(a,n) for(int i = 0;i<n;i++)cin>>a[i]
#define sea(a,n,v) for(int i = 0;i<n;i++)a[i] = v
#define pb push_back
#define F first
#define S second
#define LEFT 2*I+1
#define RIGHT 2*I+2
#define endl "\n"
#define mii map<int,int>
#define mll map<ll,ll>
#define ub upper_bound
#define lb lower_bound
#define um unordered_map
#define lop(i,n) for(ll i=0;i<n;i++)
#define lop1(i,n) for(ll i=1;i<=n;i++)
#define lopr(i,n) for(ll i=n-1;i>=0;i--)
#define test() int t;cin>>t;while(t--)
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int mod = 1e9+7,MAX = 1e6+5;
const ll inf = 1e18+5;
const double pi = 3.14159265358979323846;

using namespace std;

ll power(ll x,ll y)
{
    ll temp=1ll;

    while(y)
    {
        if(y&1) temp=(temp*x);
	//temp%=MOD;
        x=(x*x);
        y=y>>1;
    }
    return temp;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //#ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    //#endif

    test()
    {
        
    }
    return 0;	
}
