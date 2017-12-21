#include<iostream>
#include<cstdio>
#include<cstring> 
#include<queue>
using namespace std;
struct Node{
	bool have_value;
	int value;
	Node *left,*right;
	Node():have_value(false),left(NULL),right(NULL){}
};
Node *root;
char str[256];
bool failed;
Node* newnode(){
	return new Node();
}

void addNode(int v,char *s){
	Node *u=root;
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='L'){
			if(u->left==NULL)
			u->left=newnode();
			u=u->left;
		}
		else if(s[i]=='R'){
			if(u->right==NULL)
			u->right=newnode();
			u=u->right;
		}
	}
	if(u->have_value) failed=true;
	u->value=v;
	u->have_value=true;
}

bool input(){
	failed=false;
	root=newnode();
	for(;;){
		if(scanf("%s",str)!=1) return false;
		if(!strcmp(str,"()"))  break;
		int v;
		sscanf(&str[1],"%d",&v);
		addNode(v,strchr(str,',')+1); 
	}
	return true;
}

bool bfs(vector<int> &result){
	queue<Node *> q;
	result.clear();
	q.push(root);
	while(!q.empty()){
		Node *u=q.front();
		q.pop();
		if(!u->have_value) return false;
		result.push_back(u->value);
		if(u->left!=NULL) q.push(u->left);
		if(u->right!=NULL) q.push(u->right);
		
	}
	return true;
}
void remove_tree(Node *u){
	if(u==NULL)
	return ;
	remove_tree(u->left);
	remove_tree(u->right);
	delete(u);
}
int main(){
	vector<int> results;
	while(input()){
		if(!bfs(results)||failed)
			cout<<"not complete"<<endl;
		else{
			for(int i=0;i<results.size()-1;i++){
				cout<<results[i]<<" ";
			}
			cout<<results[results.size()-1];
			cout<<endl;
		}
		remove_tree(root);
	}
	return 0;
}
