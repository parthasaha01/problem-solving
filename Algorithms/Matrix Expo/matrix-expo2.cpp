#include <bits/stdc++.h>
using namespace std;
long long mod; // যেই ভ্যালুটা দিয়ে মড করব।

class Matrix
{
public:

    int row, col; // Matirx এর row এবং column এর সংখ্যা
    long long valu[5][5]; // Matirx এর ভ্যালু


    void clear()  // Matirx এর সকল ভ্যালু 0 করে দেয়ার জন্য
    {
        memset(valu,0,sizeof(valu));
        row=0;
        col=0;
    }



    void identify(int x) // Identity Matrix বা 1 Matrix বানানোর জন্য।
    {
        clear();
        row=x;
        col=x;

        for(int i=0; i<row; i++)
            valu[i][i]=1; // ডায়াগোনাল সব এলিমেন্ট 1 করে দেয়া হচ্ছে।
    }



    Matrix operator * (Matrix b) // দুইটা  Matrix গুন করে গুনফল Matrix টা রিটার্ন করবে
    {
        int i,j,k;
        Matrix c;

        c.clear();
        c.row=row;
        c.col=b.col;
                               // Complexity d^3. যদিও এইটা বেশি হবে না কারন আমার
                               // Matrix এর সাইজ অনেক ছোট। ২x২ মাত্র।

        for(i=0; i<row; i++)
            for(j=0; j<b.col; j++)
                for(k=0; k<col; k++)
                {
                    c.valu[i][j] = c.valu[i][j] + (valu[i][k])*(b.valu[k][j]);
                    c.valu[i][j] %= mod;
                }
        return c;
    }



    Matrix operator ^ (long long p)   // Fast Exponential for Matrix, Matrix^p রিটার্ন করে।
    {
        Matrix res, x;
        res.identify(row);

        x=*(this);

        while(p)
        {
            if(p & 1) res = res * x;
            x=x*x;
            p>>=1;
        }
        return res;

    }

};

Matrix a, b;

void setMatrixValues() //Base Matrix এবং Matrix A এর ভ্যালু সেট করতেছি।

{
    a.row=2;
    b.row=2;
    a.col=1;
    b.col=2;

    b.valu[0][0]=1;
    b.valu[0][1]=1;
    b.valu[1][0]=1;
    b.valu[1][1]=0;

    a.valu[0][0]=1;
    a.valu[1][0]=1;

}



int main()

{

    Matrix x,y;

    setMatrixValues();

     mod=10000000+7;
     y = b^(10000000000-2); // Base Matrix এর পাওয়ার করতেছি।
     x= y * a;              // Exponent Matrix এর সাথে A Matrix গুন দিলাম।
     printf("%lld\n",x.valu[0][0]); // Printing The Result

    return 0;
}
