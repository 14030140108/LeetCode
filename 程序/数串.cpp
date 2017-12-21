#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

char *itoa(int num){
	int num1[20];
	int i=0;
	while(num!=0){
		num1[i]=num%10;
		num/=10;
		i++;		
	}
	char *p;
	p=new char[10];
	int k=0;
	for(int j=i-1;j>=0;j--){
		p[k]=num1[j]+'0';
		k++;
	}
	p[k]='\0';
	return p;
}

int main(){
    while(1){
        int n;
        cin>>n;
        int num[n];
        string str[n];
        char *p[n];
        int j=0;
        string str_temp;
        for(int i=0;i<n;i++){
            cin>>num[i];
            p[i]=itoa(num[i]);
        }
        for(int i=0;i<n;i++){
            str[i]="";
        } 
        for(int i=0;i<n;i++){
            str[i]=p[i];
        }
        for(int i=0;i<n;i++){
            for(int j=n-2;j>=i;j--){
                if(strcmp(str[j].c_str(),str[j+1].c_str())==-1){
                    str_temp=str[j];
                    str[j]=str[j+1];
                    str[j+1]=str_temp;
                }
            }
        }
        for(int i=1;i<n;i++){
            str[0]+=str[i];
        }
        cout<<str[0];
    }
}
