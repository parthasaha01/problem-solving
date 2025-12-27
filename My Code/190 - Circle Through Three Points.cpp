#include<bits/stdc++.h>
using namespace std;
int INF = 1000000000;
double EPS = 0.0000000001;
vector<double>a[3];
vector< double > ans;
int gauss ()
{
    int n = (int) 3;
    int m = (int) 3;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}
int main()
{
    double x[5],y[5];
    int ks=0;
    while(cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2])
    {
        //if(ks)printf("\n");
        //ks++;

        for(int i=0; i<3; i++){
            a[i].push_back(x[i]);
            a[i].push_back(y[i]);
            a[i].push_back(-1.0);
            a[i].push_back(-((x[i]*x[i])+(y[i]*y[i])));
        }

//        for(int i=0; i<3; i++){
//            for(int j=0; j<a[i].size(); j++){
//                cout << a[i][j] << " ";
//            }
//            cout << endl;
//        }

        int xxx = gauss();

        double c,d,e;
        c = ans[0];
        d = ans[1];
        e = ans[2];
        //cout << c << " " << d << " " << e << endl;
        double g,f,b;
        g = c/2.0;
        f = d/2.0;
        b = (-1.0)*e;
        //cout << g << " " << f << " " << b << endl;

        double h,k,r;
        h = (-1.0)*g;
        k = (-1.0)*f;
        r = sqrt((g*g)+(f*f)-b);
        //cout << h << " " << k << " " << r << endl;

        if(h<0.0){
            h = (-1.0)*h;
            printf("(x + %.3f)^2 + ",h);
        }
        else{
            printf("(x - %.3f)^2 + ",h);
        }
        if(k<0.0){
            k = (-1.0)*k;
            printf("(y + %.3f)^2",k);
        }
        else{
            printf("(y - %.3f)^2",k);
        }
        printf(" = %.3f^2\n",r);

        printf("x^2 + y^2");
        if(c<0.0){
            c = (-1.0)*c;
            printf(" - %.3fx",c);
        }
        else{
            printf(" + %.3fx",c);
        }
        if(d<0.0){
            d = (-1.0)*d;
            printf(" - %.3fy",d);
        }
        else{
            printf(" + %.3fy",d);
        }
        if(e<0.0){
            e = (-1.0)*e;
            printf(" + %.3f = 0\n",e);
        }
        else{
            printf(" - %.3f = 0\n",e);
        }

        printf("\n");
        a[0].clear();
        a[1].clear();
        a[2].clear();
        ans.clear();

    }

    return 0;
}
