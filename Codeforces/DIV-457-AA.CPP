#define MX 1000000
#define mod (ll) 1000000007

int n,m,k;
ll N,M,K;

int main()
{

    int t,tc=1;
    int x,h;
	sf1(x);
	sf2(h,m);
	for(int i=0;;i++){
		int H=h,M=m;
		int y=x*i;
		M-=y;
		if(M<0){
			M+=60;
			H--;
		}
		if(H<0){
			H+=(24);
		}
		// cout<<H<<" "<<M<<endl;
		if(M%10==7 || M/10==7){
			pfi(i);
			return 0;
		}
		if(H%10==7 || H/10==7){
			pfi(i);
			return 0;
		}

	}


	return 0;
}
