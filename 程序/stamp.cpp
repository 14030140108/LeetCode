#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

int stamp_type[50];
int stamp_num[1000];
int type_len,num_len;
int answer[5],answer_type[5],stamp_count,stamp_Sumtype;
int result[5],result_type,result_count;
int counts,flag;

bool input(){
	int i=0;
	int type,num;
	memset(stamp_type,0,50);
	memset(stamp_num,0,1000);
	for(;;){
		if(scanf("%d",&type)!=1) return false;
		if(type==0) break;
		stamp_type[i++]=type;
	}
	type_len=i;
	sort(stamp_type,stamp_type+type_len);
	i=0;
	for(;;){
		if(scanf("%d",&num)!=1)  return false;
		if(num==0)  break;
		stamp_num[i++]=num;
	}
	num_len=i;
	return true;
} 

int maxn(int a[],int n){
	int max=-1;
	for(int i=0;i<=n;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	return max;
}

void update_result(){
	stamp_Sumtype=1;
	for(int i=0;i<=stamp_count-1;i++){
		if(answer_type[i]!=answer_type[i+1])
			stamp_Sumtype++;
	}
	if(stamp_Sumtype>result_type){
		memset(result,0,5);
		flag=0;
		for(int i=0;i<=stamp_count;i++)
			result[i]=answer[i];
		result_type=stamp_Sumtype;
		result_count=stamp_count; 
	}
	else if(stamp_Sumtype==result_type){
		if(stamp_count<result_count){
			memset(result,0,5);
			flag=0;
			for(int i=0;i<=stamp_count;i++)
				result[i]=answer[i];
			result_type=stamp_Sumtype;
			result_count=stamp_count;
		}
		else if(stamp_count==result_count){
			if(maxn(answer,stamp_count)>maxn(result,result_count)){
				memset(result,0,5);
				flag=0;
				for(int i=0;i<=stamp_count;i++)
					result[i]=answer[i];
				result_type=stamp_Sumtype;
				result_count=stamp_count;
			}
			else if(maxn(answer,stamp_count)==maxn(result,result_count)){
				flag=1;
			}
		}
	}
}

void dfs(int tp,int ans,int customer){
	ans+=stamp_type[tp];
	answer[counts]=stamp_type[tp];
	answer_type[counts]=tp;
	if(ans==customer){
		stamp_count=counts;
		update_result();
		return;
	}
	if(ans>customer)return;	
	if(counts==3) return;
	
	for(int i=tp;i<type_len;i++){
		counts++;
		dfs(i,ans,customer);	
		counts--; 
	}
	return;
}

int main(){
	while(input()){
		for(int k=0;k<num_len;k++){
			result_type=0;
			result_count=0;
			memset(result,0,5);
			for(int y=0;y<type_len;y++){
				counts=0;
				dfs(y,0,stamp_num[k]);
			}
			if(flag==0){
				if(result_count==0||result_type==0){
					cout<<stamp_num[k]<<" ---- "<<"none"<<endl; 
				}
				else{
					cout<<stamp_num[k]<<"("<<result_type<<"):"; 
					for(int x=0;x<=result_count-1;x++){
						cout<<result[x]<<" ";
					}
					cout<<result[result_count]<<endl;
				}
			}
			else if(flag==1){
				cout<<stamp_num[k]<<"("<<result_type<<"):"<<"tie"<<endl;  
			}
		}
	}
	return 0;
}
