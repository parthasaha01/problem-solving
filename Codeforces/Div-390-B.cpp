#include<bits/stdc++.h>
using namespace std;
string s[5];
bool check(string tp)
{
    if(tp=="x.x") return true;
    if(tp==".xx") return true;
    if(tp=="xx.") return true;
    if(tp=="xxx") return true;

    return false;
}
bool clac(int a,int b,int c,int d, int e, int f)
{
    string tp;

    tp  = s[a][b];
    tp += s[c][d];
    tp += s[e][f];

    if(check(tp)) return true;
    else return false;
}
int main()
{
    while(cin>>s[0])
    {
        cin>>s[1];
        cin>>s[2];
        cin>>s[3];

        //1
        if(clac(0,0,0,1,0,2)){
            printf("YES\n"); continue;
        }

        if(clac(0,0,1,0,2,0)){
            printf("YES\n"); continue;
        }

        if(clac(0,0,1,1,2,2)){
            printf("YES\n"); continue;
        }

        //2
        if(clac(0,1,0,2,0,3)){
            printf("YES\n"); continue;
        }

        if(clac(0,1,1,1,2,1)){
            printf("YES\n"); continue;
        }

        if(clac(0,1,1,2,2,3)){
            printf("YES\n"); continue;
        }

        //3
        if(clac(0,2,1,1,2,0)){
            printf("YES\n"); continue;
        }

        if(clac(0,2,1,2,2,2)){
            printf("YES\n"); continue;
        }

        //4
        if(clac(0,3,1,2,2,1)){
            printf("YES\n"); continue;
        }

        if(clac(0,3,1,3,2,3)){
            printf("YES\n"); continue;
        }

        //5
        if(clac(1,0,1,1,1,2)){
            printf("YES\n"); continue;
        }

        if(clac(1,0,2,0,3,0)){
            printf("YES\n"); continue;
        }

        if(clac(1,0,2,1,3,2)){
            printf("YES\n"); continue;
        }

        //6
        if(clac(1,1,1,2,1,3)){
            printf("YES\n"); continue;
        }

        if(clac(1,1,2,1,3,1)){
            printf("YES\n"); continue;
        }

        if(clac(1,1,2,2,3,3)){
            printf("YES\n"); continue;
        }

        //7
        if(clac(1,2,2,1,3,0)){
            printf("YES\n"); continue;
        }

        if(clac(1,2,2,2,3,2)){
            printf("YES\n"); continue;
        }

        //8
        if(clac(1,3,2,2,3,1)){
            printf("YES\n"); continue;
        }

        if(clac(1,3,2,3,3,3)){
            printf("YES\n"); continue;
        }

        //9
        if(clac(2,0,2,1,2,2)){
            printf("YES\n"); continue;
        }

        //10
        if(clac(2,1,2,2,2,3)){
            printf("YES\n"); continue;
        }

        //13
        if(clac(3,0,3,1,3,2)){
            printf("YES\n"); continue;
        }

        //14
        if(clac(3,1,3,2,3,3)){
            printf("YES\n"); continue;
        }

        printf("NO\n");

    }

    return 0;
}
