#include<bits/stdc++.h>
using namespace std;
#define maxx 1000001
bool self_num[maxx+100];
void generator()
{
    for(int i=1; i<maxx; i++){
        int sum=i;
        int n=i;

        while(n!=0){
            sum += (n%10);
            n /= 10;
        }

        self_num[sum]=false;
    }
}
int main()
{
    long int i,p;
    memset(self_num, true, sizeof(self_num));
    generator();

    for(int i=1; i<maxx; i++){
        if(self_num[i]==true){
            printf("%d\n",i);
        }
    }

    return 0;
}
