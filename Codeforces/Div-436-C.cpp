#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b,f,k;
    cin>>a>>b>>f>>k;

    ll cnt=0;
    ll pos=0;
    ll tank = b;
    ll flag=1;
    ll ra,rb;
    ra = a+(a-f);
    rb = a+f;

    for(ll i=1; i<=k; i++)
    {
        if(pos==0)
        {
            if(tank<f)
            {
                flag=-1;
                break;
            }
        }
        else
        {
            if(tank<(a-f))
            {
                flag=-1;
                break;
            }
        }

        if(i<k)
        {
            if(pos==0)
            {
                if(tank<ra)
                {
                    cnt++;
                    tank=b-(a-f);
                    if(tank<0)
                    {
                        flag=-1;
                        break;
                    }
                }
                else
                {
                    tank = tank-a;
                    if(tank<0)
                    {
                        flag=-1;
                        break;
                    }
                }
            }
            else
            {
                if(tank<rb)
                {
                    cnt++;
                    tank=b-f;
                    if(tank<0)
                    {
                        flag=-1;
                        break;
                    }
                }
                else
                {
                    tank=tank-a;
                    if(tank<0)
                    {
                        flag=-1;
                        break;
                    }
                }
            }
        }
        else
        {
            if(tank<a)
            {

                if(pos==0)
                {
                    if(tank<f || b<(a-f))
                    {
                        flag=-1;
                        break;
                    }
                    else
                    {
                        cnt++;
                    }
                }
                else
                {
                    if(tank<(a-f) || b<f)
                    {
                        flag=-1;
                        break;
                    }
                    else
                    {
                        cnt++;
                    }
                }

            }
        }

        pos = 1-pos;
    }

    if(flag==-1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%I64d\n",cnt);
    }

    return 0;
}
