#include<bits/stdc++.h>
using namespace std;
char s[100005];
int vp[105],vn[105];
int main()
{
    char ch;
    int k,neg,pos,qm;
    k=neg=pos=qm=0;
    int n;

    while(cin>>ch)
    {
        if(ch=='=')
        {
            cin >> n;
            break;
        }
        else if(ch=='-')
        {
            neg++;
            s[k++]=ch;
        }
        else if(ch=='+')
        {
            s[k++]=ch;
        }
        else if(ch=='?')
        {
            qm++;
            //s[k++]=ch;
        }
    }

    pos=qm-neg;

    //cout << "pos=" << pos << " neg=" << neg << endl;

    int maxx=pos*n-neg;
    int minn=max(pos-neg*n,0);

    if(qm==1)
    {
        printf("Possible\n");
        printf("%d = %d\n",n,n);
    }
    else if(n>=minn && n<=maxx)
    {
        for(int i=0; i<pos; i++){
            vp[i]=1;
        }
        for(int i=0; i<neg; i++){
            vn[i]=1;
        }

        int val=pos-neg;

        if(val>n)
        {
            int need=val-n;
            for(int i=0; i<neg && need>0; i++)
            {
                int kom=min(n-1,need);
                vn[i]+=kom;
                need-=kom;
            }
        }
        else if(val<n)
        {
            int need=n-val;
            for(int i=0; i<pos && need>0; i++)
            {
                int kom=min(n-1,need);
                vp[i]+=kom;
                need-=kom;
            }
        }

        printf("Possible\n");

        int x=0,y=0;

        printf("%d",vp[x++]);

        for(int i=0; i<k; i++)
        {
            if(s[i]=='+')
            {
                printf(" + %d",vp[x++]);
            }
            else
            {
                printf(" - %d",vn[y++]);
            }
        }

        printf(" = %d\n",n);
    }
    else
    {
        printf("Impossible\n");
    }

    return 0;
}

/*
? + ? - ? + ? + ? = 42
? - ? = 1
? = 1000000
? + ? + ? - ? + ? - ? + ? - ? + ? + ? = 2
? - ? = 12
? - ? = 3
? + ? + ? + ? = 7
? + ? + ? + ? = 3
? - ? + ? - ? + ? - ? = 10
? - ? + ? - ? + ? - ? = 1
? - ? + ? - ? + ? - ? = 2

*/
