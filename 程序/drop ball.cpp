#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int D,I;
	for(int i=0;i<n;i++){
		scanf("%d%d",&D,&I);
			int k=1;
			for(int j=0;j<D-1;j++){
				if(I%2){
					k=k*2;
					I=(I+1)/2;
				}
				else{
					k=k*2+1;
					I/=2;
				}
			}
			printf("%d\n",k);
		} 
	return 0;
} 
