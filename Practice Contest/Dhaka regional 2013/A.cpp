#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d", &n)==1)
    {
        if(n==0) break;
        int vol = 0, hh = 0;
        for(int i=0; i<n; i++) {
            int l, w, h; scanf("%d %d %d", &l, &w, &h);
            if(h>hh) {
                vol = l*w*h;
                hh = h;
            }
            else if(hh==h) {
                int t = l*w*h;
                vol = max(vol, t);
            }
        }

        printf("%d\n", vol);
    }

    return 0;
}
