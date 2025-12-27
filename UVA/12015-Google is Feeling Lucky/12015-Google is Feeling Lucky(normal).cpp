#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int rels[10], T, i, Max, test=1;
    char A[100], B[100], C[100], D[100], E[100], F[100], G[100], H[100], I[100], J[100];

    scanf("%d", &T);

    while(T--)
    {
        scanf("%s %d", A, &rels[0]);
        scanf("%s %d", B, &rels[1]);
        scanf("%s %d", C, &rels[2]);
        scanf("%s %d", D, &rels[3]);
        scanf("%s %d", E, &rels[4]);
        scanf("%s %d", F, &rels[5]);
        scanf("%s %d", G, &rels[6]);
        scanf("%s %d", H, &rels[7]);
        scanf("%s %d", I, &rels[8]);
        scanf("%s %d", J, &rels[9]);

        Max=0;

        for(i=0; i<10; i++)
        {
            if(rels[i] > Max)
                Max=rels[i];
        }

        printf("Case #%d:\n", test++);

        for(i=0; i<10; i++)
        {
            if(Max == rels[i])
            {
                switch(i)
                {
                    case 0:
                        puts(A);
                        break;
                    case 1:
                        puts(B);
                        break;
                    case 2:
                        puts(C);
                        break;
                    case 3:
                        puts(D);
                        break;
                    case 4:
                        puts(E);
                        break;
                    case 5:
                        puts(F);
                        break;
                    case 6:
                        puts(G);
                        break;
                    case 7:
                        puts(H);
                        break;
                    case 8:
                        puts(I);
                        break;
                    case 9:
                        puts(J);
                        break;
                }
            }
        }
    }

    return 0;
}
