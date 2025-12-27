#include<bits/stdc++.h>
using namespace std;
string ss[550];
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        for(int i=0; i<n; i++){
            cin >> ss[i];
        }

        int sx = 0;
        bool flag = true;
        int px,py;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(ss[i][j]=='X'){
                    sx++;
                    if(flag){
                        px = i;
                        py = j;
                        flag = false;
                    }
                }
            }
        }

        int cy=0;
        for(int j=py; j<m; j++){
            if(ss[px][j]=='X'){
                cy++;
            }
            else{
                break;
            }
        }

        int cx=0;
        for(int i=px; i<n; i++){
            if(ss[i][py]=='X'){
                cx++;
            }
            else{
                break;
            }
        }

        int ex = px + cx - 1;
        int ey = py + cy - 1;

        int cnt = 0;

        bool valid = true;
        for(int i=px; i<=ex; i++){
            for(int j=py; j<=ey; j++){
                if(ss[i][j]=='X'){
                    cnt++;
                }
                else{
                    valid = false;
                }
            }
        }
        //printf("sx=%d cnt=%d\n",sx,cnt);
        //printf("px=%d py=%d\n",px,py);
        //printf("ex=%d ey=%d\n",ex,ey);
        if(sx==cnt&&valid==true){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
