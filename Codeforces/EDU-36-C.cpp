#include<bits/stdc++.h>
using namespace std;
#define ll long long
int fa[15],fb[15];
int main()
{
    ll a,b;
    cin>>a>>b;

    string sa,sb;

    memset(fa,0,sizeof(fa));
    memset(fb,0,sizeof(fb));

    ll x=a;
    while(x!=0)
    {
        ll r = x%10LL;
        sa += (r+'0');
        x /= 10;
        fa[r]++;
    }
    reverse(sa.begin(),sa.end());

    x = b;
    while(x!=0)
    {
        ll r = x%10LL;
        sb += (r+'0');
        x /= 10;
        fb[r]++;
    }
    reverse(sb.begin(),sb.end());

    int la = sa.size();
    int lb = sb.size();

    //cout << sa << " " << la << endl;
    //cout << sb << " " << lb << endl;

    if(lb>la){
        sort(sa.begin(),sa.end());
        reverse(sa.begin(),sa.end());
        cout << sa << endl;
        return 0;
    }

    int soman = 1;
    int choto = 0;

    string ans;

    for(int i=0; i<lb; i++)
    {
        int d = sb[i]-'0';

        if(soman==1)
        {
            if(fa[d]>0)
            {
                fa[d]--;
                ans += d+'0';
            }
            else
            {
                bool flag = false;

                for(int k=d-1; k>=0; k--)
                {
                    if(fa[k]>0)
                    {
                        flag = true;
                        soman = 0;
                        choto = 1;
                        fa[k]--;
                        ans += k+'0';
                        break;
                    }
                }

                if(flag==false)
                {
                    int id = sb[i-1]-'0';
                    fa[id]++;
                    for(int k=id-1; k>=0; k--)
                    {
                        if(fa[k]>0)
                        {
                            flag = true;
                            soman = 0;
                            choto = 1;
                            fa[k]--;
                            ans[i-1] = k+'0';
                            break;
                        }
                    }
                    i--;
                }
            }
        }
        else
        {
            for(int k=9; k>=0; k--)
            {
                while(fa[k]>0)
                {
                    ans += k+'0';
                    fa[k]--;
                }
            }
            break;
        }
    }

    cout << ans << endl;

    //main();

    return 0;

}
