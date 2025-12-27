#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;

    int n = s.size();

    int flag = 1;
    for(int i=0; i<n; i++){
        if(s[i]!='A' && s[i]!='!'){
            flag = 0;
            break;
        }
    }

    if(!flag){
        printf("No panic\n");
        return 0;
    }

    if(s[0]!='A' || s[n-1]!='!'){
        printf("No panic\n");
        return 0;
    }

    int k=0;
    for(int i=0; i<n; i++){
        if(s[i]!='A'){
            k = i;
            break;
        }
    }

    for(int i=k; i<n; i++){
        if(s[i]!='!'){
            //printf(" %d %c\n",i, s[i]);
            flag = 0;
            break;
        }
    }

    if(!flag){
        //cout << "partha" << endl;
        printf("No panic\n");
        return 0;
    }

    printf("Panic!\n");

    return 0;

}
