#include<bits/stdc++.h>
using namespace std;
struct data
{
    long int x;
    data(long int a)
    {
        x=a;
    }

    bool operator < (const data& s) const{
        return s.x < x;
    }

};
priority_queue<data>pq;
long int a[5005];
int main()
{
    int n;

    while(cin >> n && n)
    {
        for(int i=0; i<n; i++){
            cin >> a[i];
            pq.push(data(a[i]));
        }

        long int sum,total;
        data u(0),v(0);
        sum = 0;
        total=0;
        for(int i=1; i<n; i++)
        {
            u=pq.top();
            pq.pop();
            v=pq.top();
            pq.pop();
            sum = u.x+v.x;
            total+=sum;
            pq.push(data(sum));
        }
        pq.pop();
        cout << total << endl;
    }

    return 0;
}
