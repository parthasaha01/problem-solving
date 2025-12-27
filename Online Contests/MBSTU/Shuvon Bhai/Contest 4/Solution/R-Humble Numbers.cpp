#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define Max 5842
long humble[5845];
long Minimum(long minara[])
{
    long Min=minara[0];

    for(int i=1; i<4; i++)
    {
        if(minara[i]<Min)
            Min=minara[i];
    }

    return Min;
}
void HumbleNumber()
{
    int i,i2=1,i3=1,i5=1,i7=1;
    long minara[4]={2,3,5,7};

    humble[1]=1;

    for(i=2; i<=Max; i++)
    {
        humble[i] = Minimum(minara);

        if(humble[i]==minara[0])
        {
            i2++;
            minara[0]=2*humble[i2];
        }
        if(humble[i]==minara[1])
        {
            i3++;
            minara[1]=3*humble[i3];
        }
        if(humble[i]==minara[2])
        {
            i5++;
            minara[2]=5*humble[i5];
        }
        if(humble[i]==minara[3])
        {
            i7++;
            minara[3]=7*humble[i7];
        }
     }
}

int main()
{
    HumbleNumber();

    int N,rem,i;
    string str[] = {"th","st","nd","rd"};

    while(cin >> N && N)
    {
        rem=N%10;

        if((N/10)%10==1)
            i=0;
        else if(rem==1)
            i=1;
        else if(rem==2)
            i=2;
        else if(rem==3)
            i=3;
        else
            i=0;

        cout << "The " << N << str[i] << " humble number is " << humble[N] << "." << endl;
    }

    return 0;
}
