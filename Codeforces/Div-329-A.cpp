#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[1005];
long int freq[105][30];
int flag[30];
int main()
{
    long int N,i,j,k,maxx,cnt,res,a,b;
    int w;
    bool ok;

    scanf("%ld",&N);
    memset(freq,0,sizeof(freq));

    for(k=0; k<N; k++)
    {
        scanf("%s",&s);
        //printf("%s\n",s);
        int len=strlen(s);
        cnt=0;
        ok=true;
        memset(flag,0,sizeof(flag));
        for(i=0; i<len; i++)
        {

            w=s[i];
            w=w-97;
            //printf("%d ",w);
            if(flag[w]==0)
            {
                ++cnt;
                flag[w]=1;
                if(cnt>2)
                {
                    ok=false;
                    break;
                }
                if(cnt==1)
                {
                    a=w;
                    b=w;
                }
                else
                {
                    b=w;
                }

            }
            //flag[w]+=1;

        }
        //printf("\n");
        if(ok==true)
        {

            if(a==b)
            {
                freq[a][b]+=len;
                /*for(i=0; i<26; i++)
                {
                    //freq[i][a]+=flag[a];
                    freq[i][a]+=len;
                }*/
            }
            else
            {
                if(b<a){
                    int temp=a;
                    a=b;
                    b=temp;
                }
                //freq[a][b]+=flag[a]+flag[b];
                freq[a][b]+=len;
            }

            //printf("freq[%ld:%ld]=%ld\n",a,b,freq[a][b]);
        }
    }
    /*for(i=0; i<26; i++)
        printf("%ld ",freq[i]);
    printf("\n");*/
    //sort(freq,freq+26);
    /*for(i=0; i<26; i++)
        printf("%ld ",freq[i]);
    printf("\n");*/
    maxx=0;

    for(i=0; i<26; i++)
    {
        for(j=i; j<26; j++)
        {
            //printf("%ld ",freq[i][j]);

            if(i!=j)
            {
                if(maxx<freq[i][j]+freq[i][i]+freq[j][j])
                    maxx=freq[i][j]+freq[i][i]+freq[j][j];
            }
            else
            {
                if(maxx<freq[i][j])
                    maxx=freq[i][j];

            }
        }
        //printf("\n");
    }

    //maxx=freq[24]+freq[25];

    printf("%ld\n",maxx);

    return 0;
}
