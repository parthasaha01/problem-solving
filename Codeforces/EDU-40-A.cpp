#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    string s;
    cin>>s;

    int k=0;

    for(int i=0; i<n-1;)
    {
        if(s[i]!=s[i+1]){
            k++;
            i++;
            i++;
        }
        else{
            i++;
        }
    }

    cout << n-k << endl;

    //main();

    return 0;
}
