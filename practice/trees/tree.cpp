#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data){
        this->data=data;

    }
};

TreeNode<int>*takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*>q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int>*f=q.front();
        q.pop();
        cout<<"Enter number of children of "<<f->data<<endl;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int childData;
            cout<<"Enter"<<i<<"th child of"<<f->data<<endl;
            cin>>childData;

            TreeNode<int>* child=new TreeNode<int>(childData);
            q.push(child);
            f->children.push_back(child);

        }
    
    }
    return root;
    
 }


 void PrintTree(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        PrintTree(root->children[i]);
        if(i<root->children.size()-1){
            cout<<",";
        }
    }
 }

 int main(){
    TreeNode<int>* root=takeInputLevelWise();
    PrintTree(root);
    return 0;
 }