#include<bits/stdc++.h>

using namespace std;
int ar,s=5;


#define ll unsigned long long int

ll mod=1000000007;
struct st
{
    ll  arr[6][6];
};

st sq(st a,st b)
{
    st rs;
    for(int i=0; i<s; i++)
        for(int j=0; j<s; j++)
            rs.arr[i][j]=0;

    for(int i=0; i<s; i++)
        for(int j=0; j<s; j++)
            for(int k=0; k<s; k++)
            {
                rs.arr[i][j]+=(a.arr[i][k]*b.arr[k][j]);
                rs.arr[i][j]%=mod;
            }
    return rs;
}
st fastexpo(st base,ll m)
{
    st ans;
    for(int i=0; i<s; i++)
        for(int j=0; j<s; j++)
            ans.arr[i][j]=0;
    for(int i=0; i<s; i++)
        ans.arr[i][i]=1;
    //      cout<<m<<endl;
    while(m)
    {
        if(m&1)
        {
            ans=sq(ans,base);

        }
        base=sq(base,base);
        m>>=1;
    }
    return ans;

}

int main()
{
    ll q,n;
    ll po;
    st base;
    int test ;
    int cas=0;
    //scanf("%d",&test);

    while(cin>>n)
    {
        ll ans1=0,ans2=0;
        ll quer[105];
        ll p,q,po,a0,b0,ax,bx,ay,by;
        scanf("%llu%llu%llu",&a0,&ax,&ay);
        scanf("%llu%llu%llu",&b0,&bx,&by);

        ll a[3],b[3],aod[3];
        a[0]=a0;

        b[0]=b0;

        aod[0]=(a[0]*b[0])%mod;

        st base;

        for(int i=0;i<s;i++)
            for(int j=0;j<s;j++)
            base.arr[i][j]=0;

        base.arr[0][0] = base.arr[4][4] = 1;
    base.arr[1][0] = base.arr[1][1] = (ax * bx) % mod;
    base.arr[2][0] = base.arr[2][1] = (ax * by) % mod;
    base.arr[3][0] = base.arr[3][1] = (ay * bx) % mod;
    base.arr[4][0] = base.arr[4][1] = (ay * by) % mod;
    base.arr[2][2] = ax;
    base.arr[4][2] = ay;
    base.arr[3][3] = bx;
    base.arr[4][3] = by;

       /*  for(int i=0;i<s;i++)
              {
                  for(int j=0;j<s;j++)
                cout<<base.arr[i][j]<<" ";
                  cout<<endl;
              }
*/
        //cout<<po<<"what "<<endl;
        // printf("Case %d:\n",++cas);
    //    printf("Case %d: ",++cas);
    if(n == 0) {
            ans1=0;
    }
        else if(n==1)
        {
            //    cout<<"not do"<<endl;

            ans1=aod[0];
        }
        else
        {
            //cout<<" get expo"<<endl;



            st res=fastexpo(base,n-1);
            /* for(int i=0;i<s;i++)
              {
                  for(int j=0;j<s;j++)
                cout<<res.arr[i][j]<<" ";
                  cout<<endl;
              }*/
            //cout<<endl<<res.arr[0][3]*c<<endl;
           ans1=((res.arr[0][0]*aod[0])%mod+(res.arr[1][0]*aod[0])%mod+(res.arr[2][0]*a[0])%mod+(res.arr[3][0]*b[0])%mod+(res.arr[4][0]%mod))%mod;
            //ans2=((res.arr[3][0]*f2)%mod+(res.arr[3][1]*f1)%mod+(res.arr[3][2]*f0)%mod+(res.arr[3][3]*g2)%mod+(res.arr[3][4]*g1)%mod+(res.arr[3][5]*g0)%mod)%mod;
        }

        printf("%llu\n",ans1);
    }
}


