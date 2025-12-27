#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int a = 0;
    int b = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='o')a++;
        else b++;
    }

    if(a==0){
      printf("YES\n");
    }
    else if(b%a==0){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

    //main();

    return 0;
}
