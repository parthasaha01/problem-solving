#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int fr[10],ans[10],fa[10],fb[10];
int main()
{
    int n;

    while(cin>>n)
    {
        memset(fr,0,sizeof(fr));
        memset(fa,0,sizeof(fa));
        memset(fb,0,sizeof(fb));

        for(int i=1; i<=n; i++){
            cin>>a[i];
            fr[a[i]]++;
            fa[a[i]]++;
        }
        for(int i=1; i<=n; i++){
            cin>>b[i];
            fr[b[i]]++;
            fb[b[i]]++;
        }

        int flag = true;

        for(int i=1; i<=5; i++){
            if(fr[i]%2==1){
                flag = false;
                break;
            }
            else{
                ans[i]=fr[i]/2;
            }
        }

        if(!flag){
            printf("-1\n");
            continue;
        }

        int minn1=0;
        for(int i=1; i<=5; i++){
            minn1 += abs(ans[i]-fa[i]);
        }
        int minn2=0;
        for(int i=1; i<=5; i++){
            minn2 += abs(ans[i]-fb[i]);
        }

        int minn = min(minn1,minn2)/2;

        printf("%d\n",minn);
    }

    return 0;
}
