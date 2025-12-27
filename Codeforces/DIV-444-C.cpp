#include<bits/stdc++.h>
using namespace std;
int a[30],b[30];
int check()
{
    int flag = 1;
    for(int k=0; k<6; k++)
    {
        int x = k*4;

        if(b[x+1]==b[x+2] && b[x+2]==b[x+3] && b[x+3]==b[x+4]){

        }
        else{
            return 0;
        }
    }

    return 1;
}
int main()
{
    for(int i=1; i<=24; i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=1; i<=24; i++)b[i]=a[i];

    b[1] = a[24];
    b[3] = a[22];
    b[5] = a[1];
    b[7] = a[3];
    b[9] = a[5];
    b[11] = a[7];
    b[24] = a[9];
    b[22] = a[11];

    if(check()==1){
        printf("YES\n");
        return 0;
    }

    for(int i=1; i<=24; i++)b[i]=a[i];

    b[2] = a[23];
    b[4] = a[21];
    b[6] = a[2];
    b[8] = a[4];
    b[10] = a[6];
    b[12] = a[8];
    b[23] = a[10];
    b[21] = a[12];

    if(check()==1){
        printf("YES\n");
        return 0;
    }

    for(int i=1; i<=24; i++)b[i]=a[i];

    b[22] = a[3];
    b[24] = a[1];
    b[11] = a[22];
    b[9] = a[24];
    b[7] = a[11];
    b[5] = a[9];
    b[3] = a[7];
    b[1] = a[5];

    if(check()==1){
        printf("YES\n");
        return 0;
    }

    for(int i=1; i<=24; i++)b[i]=a[i];

    b[21] = a[4];
    b[23] = a[2];
    b[12] = a[21];
    b[10] = a[23];
    b[8] = a[12];
    b[6] = a[10];
    b[4] = a[8];
    b[2] = a[6];

    if(check()==1){
        printf("YES\n");
        return 0;
    }

    for(int i=1; i<=24; i++)b[i]=a[i];

    b[2] = a[20];
    b[1] = a[18];
    b[13] = a[2];
    b[15] = a[1];
    b[11] = a[13];
    b[12] = a[15];
    b[20] = a[11];
    b[18] = a[12];

    if(check()==1){
        printf("YES\n");
        return 0;
    }

    for(int i=1; i<=24; i++)b[i]=a[i];

    b[4] = a[19];
    b[3] = a[17];
    b[14] = a[4];
    b[16] = a[3];
    b[9] = a[14];
    b[10] = a[16];
    b[19] = a[9];
    b[17] = a[10];

    if(check()==1){
        printf("YES\n");
        return 0;
    }

    for(int i=1; i<=24; i++)b[i]=a[i];

    b[1] = a[15];
    b[2] = a[13];
    b[18] = a[1];
    b[20] = a[2];
    b[12] = a[18];
    b[11] = a[20];
    b[15] = a[12];
    b[13] = a[11];

    if(check()==1){
        printf("YES\n");
        return 0;
    }

    for(int i=1; i<=24; i++)b[i]=a[i];

    b[3] = a[16];
    b[4] = a[14];
    b[17] = a[3];
    b[19] = a[4];
    b[10] = a[17];
    b[9] = a[19];
    b[16] = a[10];
    b[14] = a[9];

    if(check()==1){
        printf("YES\n");
        return 0;
    }

    for(int i=1; i<=24; i++)b[i]=a[i];

    b[6] = a[18];
    b[5] = a[17];
    b[14] = a[6];
    b[13] = a[5];
    b[22] = a[14];
    b[21] = a[13];
    b[18] = a[22];
    b[17] = a[21];

    if(check()==1){
        printf("YES\n");
        return 0;
    }

    for(int i=1; i<=24; i++)b[i]=a[i];

    b[8] = a[20];
    b[7] = a[19];
    b[16] = a[8];
    b[15] = a[7];
    b[24] = a[16];
    b[23] = a[15];
    b[20] = a[24];
    b[19] = a[23];

    if(check()==1){
        printf("YES\n");
        return 0;
    }

    for(int i=1; i<=24; i++)b[i]=a[i];

    b[5] = a[13];
    b[6] = a[14];
    b[17] = a[5];
    b[18] = a[6];
    b[21] = a[17];
    b[22] = a[18];
    b[13] = a[21];
    b[14] = a[22];

    if(check()==1){
        printf("YES\n");
        return 0;
    }

    for(int i=1; i<=24; i++)b[i]=a[i];

    b[7] = a[15];
    b[8] = a[16];
    b[19] = a[7];
    b[20] = a[8];
    b[23] = a[19];
    b[24] = a[20];
    b[15] = a[23];
    b[16] = a[24];

    if(check()==1){
        printf("YES\n");
        return 0;
    }

    printf("NO\n");

    return 0;


}
