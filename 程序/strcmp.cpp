#include<iostream>
using namespace std;

int strcmp(char *str1,char *str2){
	while(*str1==*str2){
		if(*str1=='\0')
		return 0;
		*str1++;
		*str2++;
	}
	return *str1-*str2;
}

int strcmp1(char *str1,char *str2){
	int x;
	while(!(x=*str1-*str2)&&*str1){
		*str1++;
		*str2++;
	}
	if(x>0)
	x=1;
	if(x<0)
	x=-1;
	return x; 
}
int main(){
	char *p="hello";
	char *q="hello w";
	cout<<strcmp1(p,q);
} 
