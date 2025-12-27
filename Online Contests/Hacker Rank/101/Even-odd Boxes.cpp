#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll a[mx+5],s[mx+5],b[mx+5];
int main()
{
    //freopen("b.txt","r",stdin);
    //freopen("bb.txt","w",stdout);

    //freopen("c.txt","r",stdin);
    //freopen("cc.txt","w",stdout);

    ll tt; scanf("%lld",&tt);

    for(ll ks=1; ks<=tt; ks++)
    {
        ll n; scanf("%lld",&n);
        ll sum=0;

        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        ll g=0;
        for(int i=1; i<=n; i++){
            if(i%2==1)g+=2;
            else g+=1;
        }

        if((sum%2)!=(g%2) || sum<g)
        {
            printf("-1\n");
            continue;
        }

        ll ans=0,kk=0,one=0;

        for(ll i=1; i<=n; i++)
        {
            if((i%2)==1 && a[i]==1)
            {
                kk++;
                b[kk]=i;
                one++;
            }
        }

        ll k=0;



        for(int i=1; i<=n; i++)
        {
            if(kk==0)break;

            if((i%2)==1)//must be even
            {
                if((a[i]%2)==1)
                {
                    if(a[i]!=1){
                        a[i]--;
                        kk--;
                        k++;
                        a[b[k]]++;
                    }
                }
            }
            else //must be odd
            {
                if(a[i]%2==0){
                    a[i]--;
                    kk--;
                    k++;
                    a[b[k]]++;
                }
            }
        }

        //printf("partha\n");

        for(int i=1; i<=n; i++)
        {
            if(kk==0)break;

            //printf("i=%d kk=%d\n",i,kk);

            if((i%2)==1)//must be even
            {
                //cout << "i=" << i << " a[i]=" << a[i] << endl;
               if(a[i]!=1)
               {
                    ll d = (a[i]-2);
                    while(d>0)
                    {
                        if(kk==0)break;
                        kk--;
                        a[i]--;
                        d--;
                        k++;
                        a[b[k]]++;
                    }
               }
            }
            else //must be odd
            {
               ll d = (a[i]-1);
               while(d>0)
               {
                   //cout << "i=" << i << " a[i]=" << a[i] << endl;
                   if(kk==0)break;
                   kk--;
                   a[i]--;
                   d--;
                   k++;
                   a[b[k]]++;
               }
            }
        }

        //printf("partha\n");
        ans = 0;
        ll hate=0;
        for(ll i=1; i<=n; i++)
        {
            ll r = a[i]%2;

            if((i%2)==r)
            {
                if(hate>0){
                    hate--;
                }
                else{
                    ans++;
                    hate++;
                }
            }
        }

        ans += one;

        printf("%lld\n",ans);
    }
    return 0;
}

