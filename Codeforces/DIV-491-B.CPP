#include<bits/stdc++.h>
using namespace std;
double a[105];
int main()
{
    //cout << round(4.500001) << endl;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    sort(a,a+n);
    double sum = 0.0;
    double m = n;
    for(int i=0; i<n; i++){
        sum += a[i];
    }

    double avg;
    avg = sum/m;
    avg = round(avg);
    if(avg>4.90){
        cout << 0 << endl;
    }
    else{
        for(int i=0; i<n; i++){
            sum -= a[i];
            sum += 5.00;
            avg = sum/m;
            avg = round(avg);

            if(avg>4.90){
                cout << i+1 << endl;
                break;
            }
        }
    }

    //cout << round(4.49999) << endl;

    //main();
    return 0;
}
