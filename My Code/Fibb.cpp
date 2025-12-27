#include<bits/stdc++.h>
using namespace std;

int get_nth_fibonacci(int n) {
    if(n<2) return 1;

    return get_nth_fibonacci(n-1) + get_nth_fibonacci(n-2);
}

int main(){
    int n;
    cin>>n;

    int ans = get_nth_fibonacci(n);

    printf("%d", ans);

    return 0;
}
