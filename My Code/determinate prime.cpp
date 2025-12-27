#include<bits/stdc++.h>
using namespace std;
int ara[35005];
vector <int> prime, det[500];

void sieve()
{
    int i, j, k, l;
    for(i = 3; i <= 190; i += 2){
        if(ara[i] == 0){
            for(j = i * i; j <= 35000; j += (i + i)){
                ara[j] = 1;
            }
        }
    }
    for(i = 3; i <= 34500; i += 2){
        if(ara[i] == 0)
            prime.push_back(i);
    }
    k = 0;
    for(i = 0; prime[i] <= 34000; i++){
        if((prime[i + 1] - prime[i]) == (prime[i + 2] - prime[i + 1])){
                l = 2;
            det[k].push_back(prime[i]);
            det[k].push_back(prime[i + 1]);
            det[k].push_back(prime[i + 2]);
            j = 3;
            while((prime[i + j] - prime[i + j -1]) == (prime[i + 1] - prime[i])){
                det[k].push_back(prime[i +j]);
                l++;
                j++;
            }
            i += l;
            k++;
        }
    }
   /* for(i = 0; i < k; i++){
        for(j = 0; j < det[i].size(); j++){
            printf("%d ",det[i][j]);
        }
        printf("\n");
    }*/
}
int main()
{
    sieve();
    int i, j, up, down, l;
    while(scanf("%d %d",&up, &down) == 2){
            if(up == 0 && down == 0)
            break;
        if(down > up)
            swap(up, down);

        for(j = 0; j < 166; j++){
                l = det[j].size() - 1;
            if(det[j][0] >= down && det[j][l] <= up){
                printf("%d",det[j][0]);
                for(i = 1; i <= l; i++)
                    printf(" %d",det[j][i]);

                printf("\n");
            }
        }
    }
    return 0;
}
