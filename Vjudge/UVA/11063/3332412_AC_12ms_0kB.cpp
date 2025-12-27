#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int N,i,j,flag,test=1,sum;

    while(cin >> N)
    {
        int num[N];
        flag=1;

        int check[20005]={0};

        for(i=0; i<N; i++){
            cin >> num[i];
        }

        if(num[0]<=0){
            flag=0;
            goto label;
        }

        for(i=1; i<N; i++){
            if(num[i]<=num[i-1]){
                flag=0;
                goto label;
            }
        }

        for(i=0; i<N; i++){
            for(j=i; j<N; j++){
                sum=num[i]+num[j];

                if(check[sum]==1){
                    flag=0;
                    goto label;
                }
                else
                    check[sum]=1;
            }
        }

        label:
        if(flag)
            cout << "Case #" << test++ << ": It is a B2-Sequence." << endl << endl;
        else
            cout << "Case #" << test++ << ": It is not a B2-Sequence." << endl << endl;
    }

    return 0;
}
