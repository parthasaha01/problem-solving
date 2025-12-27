#include<bits/stdc++.h>
using namespace std;
#define mx 110
int arr[mx][mx],lrr[mx][mx],rlr[mx][mx],udc[mx][mx],duc[mx][mx],ans[mx][mx],bb[mx][mx];

int main()
{
    int n,m;
    //scanf("%d%d",&n,&m);

    cin>>n>>m;
    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char c;
            cin>>c;
            if(c=='.')
                arr[i][j]=0;
            else
            {
                arr[i][j]=1;
                cnt++;
            }
        }
        // getchar();
    }

//    if(cnt==0)
//    {
//        for(int i=1; i<=n; i++)
//        {
//            for(int j=1; j<=m; j++)
//            {
//                printf(".");
//            }
//            printf("\n");
//        }
//        return 0;
//    }

//    for(int i=1; i<=m; i++)
//    {
//        udc[0][i]=0;
//        duc[n+1][i]=0;
//    }
//    for(int i=1; i<=n; i++)
//    {
//        lrr[i][0]=0;
//        rlr[i][m+1]=0;
//    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            lrr[i][j]=lrr[i][j-1]+arr[i][j];
            //udc[i][j]=udc[i-1][j]+arr[i][j];

            if(arr[i][j]==0)
            {
                lrr[i][j]=0;
                //udc[i][j]=0;
            }
        }
    }

    for(int j=1; j<=m; j++)
    {
        for(int i=1; i<=n; i++)
        {
            udc[i][j]=udc[i-1][j]+arr[i][j];
            //udc[i][j]=udc[i-1][j]+arr[i][j];

            if(arr[i][j]==0)
            {
                udc[i][j]=0;
                //udc[i][j]=0;
            }
        }
    }


    for(int i=1; i<=n; i++)
    {
        for(int j=m; j>=1; j--)
        {
            rlr[i][j]=rlr[i][j+1]+arr[i][j];
            ///duc[i][j]=duc[i+1][j]+arr[i][j];
            if(arr[i][j]==0)
            {
                rlr[i][j]=0;
                //duc[i][j]=0;
            }
        }
    }

    for(int j=1; j<=m; j++)
    {
        for(int i=n; i>=1; i--)
        {
            //rlr[i][j]=rlr[i][j+1]+arr[i][j];
            duc[i][j]=duc[i+1][j]+arr[i][j];
            if(arr[i][j]==0)
            {
                //rlr[i][j]=0;
                duc[i][j]=0;
            }
        }
    }

   // int mxx = 0;
    for(int i=1; i<=n; i++)
    {
        //int tt=0;
        for(int j=1; j<=m; j++)
        {
            int a,b,c,d;
            a = lrr[i][j];
            b = udc[i][j];
            c = rlr[i][j];
            d = duc[i][j];
            ans[i][j] = min(a,min(b,min(c,d)));

        }
        //mxx = max(tt,mxx);
    }

    int mxx = 0;
    while(1)
    {
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                bb[i][j] = ans[i][j];
            }
        }

        for(int i=1; i<=n; i++){
            int tt=0;
            for(int j=1; j<=m; j++){
                if(ans[i][j]==0)continue;
                if(ans[i][j]==1)continue;
                int a,b,c,d;
                a = ans[i-1][j];
                b = ans[i][j-1];
                c = ans[i][j+1];
                d = ans[i+1][j];
                ans[i][j] = min(a,min(b,min(c,d)))+1;
                mxx = max(ans[i][j],mxx);
                //if(ans[i][j]<10) tt+=2;
               // else tt+=3;
            }
            //mxx = max(tt,mxx);
        }

//        for(int i=1; i<=n; i++){
//            for(int j=1; j<=n; j++){
//                printf("%d ",ans[i][j]);
//            }
//        }

        int flag = 1;

        for(int i=1; i<=n && flag; i++){
            for(int j=1; j<=m && flag; j++){
                if(bb[i][j] != ans[i][j]){
                    flag = 0;
                    break;
                }
            }
        }

        if(flag)break;
    }

    if(mxx<10)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(ans[i][j]==0)
                {
                    printf("..");
                }
                else
                    printf(".%d",ans[i][j]);
            }
            cout<<endl;
        }
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(ans[i][j]==0)
                {
                    printf("...");
                }
                else if(ans[i][j]<10)
                {
                    printf("..%d",ans[i][j]);
                }
                else if(ans[i][j]<100)
                {
                    printf(".%d",ans[i][j]);
                }
                else
                {
                    printf("%d",ans[i][j]);
                }
            }
            cout<<endl;
        }
    }

//    for(int i=1; i<=n; i++)
//    {
//        int tt=0;
//        for(int j=1; j<=m; j++)
//        {
//            if(ans[i][j]==0)
//            {
//                tt+=2;
//                printf("..");
//            }
//            else if(ans[i][j]<10)
//            {
//                tt+=2;
//                printf(".%d",ans[i][j]);
//            }
//            else if(ans[i][j]<100)
//            {
//                tt+=3;
//                printf(".%d",ans[i][j]);
//            }
//            else
//            {
//                tt+=3;
//                printf("%d",ans[i][j]);
//            }
//        }
//        if(tt<mxx)
//        {
//            for(int j=tt;j<mxx;j++)
//                printf(".");
//        }
//        cout<<endl;
//    }
    //cout<<mxx<<endl;

//    if(mxx<10)
//    {
//        for(int i=1; i<=n; i++)
//        {
//            for(int j=1; j<=m; j++)
//            {
//                if(ans[i][j]==0)
//                {
//                    printf("..");
//                }
//                else
//                    printf(".%d",ans[i][j]);
//            }
//            cout<<endl;
//        }
//    }
//    else
//    {
//    for(int i=1; i<=n; i++)
//    {
//        int tt=0;
//        for(int j=1; j<=m; j++)
//        {
//            if(ans[i][j]==0)
//            {
//                tt+=2;
//                printf("..");
//            }
//            else if(ans[i][j]<10)
//            {
//                tt+=2;
//                printf(".%d",ans[i][j]);
//            }
//            else if(ans[i][j]<100)
//            {
//                tt+=3;
//                printf(".%d",ans[i][j]);
//            }
//            else
//            {
//                tt+=3;
//                printf("%d",ans[i][j]);
//            }
//        }
//        if(tt<mxx)
//        {
//            for(int j=tt;j<mxx;j++)
//                printf(".");
//        }
//        cout<<endl;
//    }
    // }

    return 0;
}

/*
20 21
TTTTTTTTTTTTTTTTTTTTT
..TTTTTTTTTT.........
TTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTT
.....TTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTT..........
TTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTT
.TTTTTTTTTTTTTTTTTTTT
.TTTTTTTTTTTTTTTTTTTT
.TTTTTTTTTTTTTTTTTTTT
.T.TT.TT.T.T.TTTTTTTT


*/
