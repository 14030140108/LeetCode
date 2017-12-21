#include<iostream>
#include<string> 
#include<algorithm>
using namespace std;
bool cmp(const string &s1,const string &s2){
	return s1.size()<s2.size();
}
int main(){
	string str[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
/*	for(int i=0;i<n;i++){
		for(int j=n-1;j>0;j--){
			if(cmp(str[j-1],str[j])){
				string temp=str[j-1];
				str[j-1]=str[j];
				str[j]=temp;
			}
		}
	}*/
	sort(str,str+n,cmp);
	for(int i=0;i<n;i++){
		cout<<str[i]<<endl; 
	}
	return 0;
} 
