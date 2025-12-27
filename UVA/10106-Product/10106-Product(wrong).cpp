#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    long int L1, L2, L, i, j, k, p, carry, flag, x, y, q, cary, m, z, r, s, t, u;
    char res[1000000], a[500], b[500], num[1000], sum[1000], product[1000], last[500];

    while(gets(a))
    {
        gets(b);

        if((!strcmp(a, "0")) || (!strcmp(b, "0")))
        {
            printf("0\n");
            continue;
        }

        L1= strlen(a);
        L2= strlen(b);

        z=r=0;

        if(L1 >= L2)
        {
            for(j=L2-1; j>=0; j--)
            {
                carry=k=0;

                for(i=L1-1; i >=0; i--)
                {
                    p = carry + ((a[i]-'0')*(b[j]-'0'));
                    res[k++] = (p%10)+'0';
                    carry = p/10;
                }
                if(carry>0)
                {
                    res[k++]=carry+'0';
                }
                res[k]='\0';
                //puts(res);
                if(z)
                {
                    cary=m=0;
                    y=1;
                    for(x=0; x<k && y<L; x++)
                    {
                        q = cary+ (res[x]-'0')+(sum[y++]-'0');
                        num[m++] = (q%10)+'0';
                        cary = q/10;
                    }
                    if(x<k)
                    {
                        while(x<k)
                        {
                            q = cary+(res[x++]-'0');
                            num[m++]=(q%10)+'0';
                            cary = q/10;
                        }

                        if(cary > 0)
                            num[m++] = cary +'0';
                    }
                    num[m]='\0';
                    strcpy(sum, num);
                }
                else
                    strcpy(sum, res);

                z=1;
                L=strlen(sum);

                last[r++]=sum[0];

               // puts(sum);
                //printf("\n");
            }

            last[r]='\0';

            for(s=0, t=L-1; s<L-1; s++)
            {
                product[s] = sum[t--];
            }
            for(u=0, t=r-1; u<r; u++)
            {
                product[s++] = last[t--];
            }

            product[s]='\0';

            puts(product);
        }
        else
        {
            for(j=L1-1; j>=0; j--)
            {
                carry=k=0;

                for(i=L2-1; i >=0; i--)
                {
                    p = carry + ((b[i]-'0')*(a[j]-'0'));
                    res[k++] = (p%10)+'0';
                    carry = p/10;
                }
                if(carry>0)
                {
                    res[k++]=carry+'0';
                }
                res[k]='\0';
                puts(res);
                if(z)
                {
                    cary=m=0;
                    y=1;
                    for(x=0; x<k && y<L; x++)
                    {
                        q = cary+ (res[x]-'0')+(sum[y++]-'0');
                        num[m++] = (q%10)+'0';
                        cary = q/10;
                    }
                    if(x<k)
                    {
                        while(x<k)
                        {
                            q = cary+(res[x++]-'0');
                            num[m++]=(q%10)+'0';
                            cary = q/10;
                        }
                    }
                    num[m]='\0';
                    strcpy(sum, num);
                }
                else
                    strcpy(sum, res);

                z=1;
                L=strlen(sum);

                last[r++]=sum[0];

                //puts(sum);
                //printf("\n");
            }

            last[r]='\0';

            for(s=0, t=L-1; s<L-1; s++)
            {
                product[s] = sum[t--];
            }
            for(u=0, t=r-1; u<r; u++)
            {
                product[s++] = last[t--];
            }

            product[s]='\0';

            puts(product);
        }

    }

    return 0;
}
