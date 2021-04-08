#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ulli unsigned ll int
#define all(v)  v.begin(),v.end()
#define ub(v,x)  upper_bound(all(v),x)
#define lb(v,x)  lower_bound(all(v),x)
#define  mmst(A,val)  memset(A,val,sizeof A);
#define  pll pair <ll, ll>
#define  vctr(n) vector<n>
#define  pb push_back
#define  pf push_front
#define  mkpr  make_pair
#define  ff   first
#define  ss  second
#define  srt(V)  sort(V.begin(),V.end());
#define  rsrt(V)  sort(V.rbegin(),V.rend());
#define fast ios_base::sync_with_stdio(0);cin.tie(nullptr);
#define  nl cout<<"\n";  
#define  PI  2*acos(0.0);
#define  INFP ((ll)1<<62)
#define  INFN (0-(ll)1<<62)
#define  fr(i,a,b) for(int i=a;i<=b;i++)
#define  frr(i,a,b) for(int i=a;i>=b;i--)
#define  tst(n)  for(int cs=1;cs<=n;cs++)
#define  pys cout<<"YES\n";
#define  pno cout<<"NO\n";
#define  bug cout<<"bug\n";
#define  pmn cout<<"-1\n";
#define  limit 300001
#define  md 100000007
#define  sq(n)  n*n
#define pcs cout<<"Case "<<cs<<": ";
typedef pair<ll,ll> iPair;

vctr(ll) v;
ll ans,a,b,cnt;
void solve(ll mask,ll pos)
{
   if(pos==cnt)
   {
     if(mask==0)return;
      ll s=1;
      fr(i,0,cnt-1)
      {
        if(mask&(1LL<<i)) s*=v[i];
      }

        ll cnt=b/s-(a-1)/s;
       if(__builtin_popcount(mask)%2)ans-=cnt;
       else ans+=cnt;
     return;
   }

      solve(mask|(1LL<<pos),pos+1);
      solve(mask,pos+1);
}


ll  prime[78500];
bool check[1000002];
ll sieve(ll int n)
{
    ll int z,x=1;
    prime[0]=2;
    check[1]=check[0]=true;
    for(int i=3;i*i<=n;i+=2)
    {
        if(!check[i])
        {
            prime[x]=i;
            x++;
            for(int j=i*i;j<=n;j+=i)check[j]=true;
        }
        z=i;
    }
    for(int j=4;j<=n;j+=2)check[j]=true;

    for(int j=z+1;j<=n;j++)
    {
        if(!check[j])
        {
            prime[x]=j;
            x++;
        }
    }
    return  x;
}

int main()
{
/*     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);*/
     ll np=sieve(1000000);
     //cout<<np<<endl;
     ios_base::sync_with_stdio(0);
     cin.tie(nullptr);
     ll test;
     cin>>test;
     tst(test)
     {
        ll m;
        cin>>a>>b>>m;
        if(a==b)
        {
            if(a==1)cout<<1<<"\n";
            else cout<<"0\n";
            continue;
        }
        ll bb=max(b,a);
        ll aa=min(b,a);
        ll p=bb-aa;
        a=aa;
        b=aa+m;
        mmst(check,false);
        v.clear();
        //cout<<p<<endl;
        for(int i=0;i<np;i++)
        {
            while(p%prime[i]==0)
            {
                check[i]=true;
                p/=prime[i];
            }
        }
        if(p>1)v.pb(p);
        //cout<<v.size()<<endl;

        fr(i,0,np-1)
        {
            if(check[i])v.pb(prime[i]);
        }
        cnt=v.size();
        ans=m+1;
        solve(0,0);
        cout<<ans<<endl;
        
     }  
}
