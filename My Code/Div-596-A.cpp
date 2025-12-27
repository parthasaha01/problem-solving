#include<bits/stdc++.h>
using namespace std;
set< pair<int,int> > ss;
int first_digit(int n){
    while (n >= 10)
        n /= 10;
    return n;
}
int main()
{
    int da, db;
    for(int i=1; i<1000000000; i++){
        int ma = first_digit(i);
        int mb = first_digit(i+1);
        pair<int,int> pp = make_pair(ma,mb);
        if(ss.find(pp) == ss.end()){
            printf("%d %d, %d %d\n",ma, mb, i, i+1);
            ss.insert(pp);
        }
    }

    return 0;
}

