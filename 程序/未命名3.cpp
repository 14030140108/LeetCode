#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char str[100]="(11,LL)";
	char *s;
	s=strchr(str,',')+1;
	cout<<s;
}
