#include<bits/stdc++.h>
using namespace std;
int n,a[25],b[25],fr[25];
int main()
{
    string s;
    while(cin>>s)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(fr,0,sizeof(fr));
        n = s.size();
        for(int i=0; i<n; i++){
            a[i]=s[i]-'0';
        }

        int flag = 1;

        for(int i=0; i<n && flag; i++)
        {
            int d = a[i];

            if(fr[d]<2)
            {
                b[i]=a[i];
                fr[d]++;
            }
            else
            {
                d--;
                int j;
                int choto = 0;

                for(j=i; j>=0; j--)
                {
                    while(d>=0)
                    {
                        if(fr[d]<2)
                        {
                            if(j<i)fr[b[j]]--;
                            choto=1;
                            b[j]=d;
                            if(j==0 && d==0){
                                //fr[b[j]]--;
                                //printf("partha\n");
                            }
                            else{

                                fr[d]++;
                            }
                            break;
                        }
                        d--;
                    }

                    if(choto==1)
                    {
                        for(int k=j+1; k<n; k++)
                        {
                            int d = 9;
                            while(d>=0)
                            {
                                if(fr[d]<2)
                                {
                                    b[k]=d;
                                    fr[d]++;
                                    break;
                                }
                                d--;
                            }
                        }

                        flag = 0;
                        break;

                    }
                    else
                    {
                        if(j<i)
                        {
                            fr[b[j]]--;
                            d = b[j-1]-1;
                        }
                        else
                        {
                            d = b[j-1]-1;
                            if(d<0)fr[0]--;
                        }
                    }
                }
            }
        }

        string ans;
        bool start = false;
        for(int i=0; i<n; i++){
            if(b[i]==0 && start==false){
                //
            }
            else{
                start = true;
                ans+=b[i]+'0';
            }
        }

        cout << ans << endl;
    }

    return 0;
}
