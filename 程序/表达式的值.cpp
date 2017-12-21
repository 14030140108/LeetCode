#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main(){
	int a=100;
	char *p;
	p=new char[20]; 
	itoa(a,p,10);
	cout<<p;
}
