#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin>>n;
	char str[2000];
	FILE *fp=fopen("data.txt","r");
	fgets(str,2000,fp);
	const char *split=" ,.";
	char *p[2000];
	char *str1;
	p[0]=strtok(str,split);
	int i=0;
	while(p[i]!=NULL){
		i++;
		p[i]=strtok(NULL,split);
	}
	for(int j=0;j<n;j++){
		str1=new char[100];
		cin>>str1;
		int count=0;
		for(int k=0;k<i;k++){
			if(!strcmp(str1,p[k])){
				count++;
				cout<<"Î»ÖÃ£º"<<k+1<<endl;
			}
		}
		cout<<"´ÎÊý£º"<<count<<endl;
	}
	return 0;
}
