#include<bits/stdc++.h>
using namespace std;
int main()
{
    int maxh,maxv,vol,l,w,h,n;

    while(scanf("%d",&n) && n)
    {
        maxh=0;

        for(int i=0; i<n; i++){
            scanf("%d %d %d",&l,&w,&h);

            if(h>=maxh){
                if(h>maxh){
                    maxv=l*w*h;
                    maxh=h;
                }
                else{
                    vol = l*w*h;
                    if(vol>maxv){
                        maxv=vol;
                    }
                }

            }
        }

        printf("%d\n",maxv);
    }

    return 0;
}

