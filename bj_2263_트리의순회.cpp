#include<bits/stdc++.h>
using namespace std;
int n;
int inorder[100000], postorder[100000];
vector<int> preorder;
int find_idx(int v, int arr[], int begin){
    for(int i=0; i<n; i++){
        if(arr[begin+i]==v) return begin+i;
    }
    return -1;
}
void get_inorder(int post_left, int in_left, int treelen){
    if(treelen<=0) return;
    int post_root = post_left+treelen-1;
    int rootvalue = postorder[post_root];
    preorder.push_back(rootvalue);
    if(treelen==1) return;
    int in_root = find_idx(rootvalue, inorder, in_left);
    int len_l = in_root-in_left;
    int len_r = treelen-len_l-1;
    get_inorder(post_left, in_left, len_l);
    get_inorder(post_left+len_l, in_root+1, len_r);
}
int main(){
    cin>>n;
    for(int i=0; i<n; i++) cin>>inorder[i];
    for(int i=0, a; i<n; i++) cin>>postorder[i];
    get_inorder(0,0,n);
    for(auto v: preorder) cout<<v<<' ';
}

/*
#1
6
6 4 2 5 1 3
6 4 5 2 3 1
ans: 1 2 4 6 5 3

#2
6
3 1 6 4 2 5
3 6 4 5 2 1
ans: 1 3 2 4 6 5
 * */