#include<bits/stdc++.h>

using namespace std;

class Node{
public:

    int data;
    Node* left;
    Node* right;
    Node(){
    left = NULL;
    right= NULL;
    }




};

class BST{
public:
    Node* root;
    Node* Insert(Node* root , int key);
    void inOrder(Node* root);
    Node* findMinimum(Node* root);
    Node* findMaximum(Node* root);
    Node* searchNode(Node* root, int key);
    Node* Delete(Node* root , int key);


};

Node* BST :: Insert(Node* root , int key){
         if(root==NULL){
             Node* node = new Node;
             node->data = key;
             root=node;
             return root;
         }

         if(root->data>key){
            root->left = Insert(root->left , key);
            return root;
         }

          if(root->data<key){
            root->right = Insert(root->right , key);
            return root;
         }



}

void BST :: inOrder(Node* root ){

        if(root==NULL){
            return;
        }

        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);

}

Node* BST :: findMinimum(Node* root){

    if(root->left==NULL){
        return root;
    }

    return findMinimum(root->left);

}



Node* BST :: findMaximum(Node* root){

    if(root->right==NULL){
        return root;
    }

    return findMaximum(root->right);

}

Node* BST:: searchNode(Node* root, int key){


    if(root==NULL){
        cout<<"Data not found." <<endl;
        return root;
    }

    if(root->data==key){

        return root;
    }

    if(root->data > key){
        return searchNode(root->left , key);
    }
    if(root->data<key){
        return searchNode(root->right , key);
    }

}

Node* BST :: Delete(Node* root , int key){

    if(root==NULL){
        return NULL;
    }

   if(root->data > key){
     root->left = Delete(root->left , key);
     return root;
   }
   if(root->data < key){
        root->right = Delete(root->right , key);
        return root;
   }
   if(root->data == key){
    if(root->left==NULL && root->right==NULL){

        delete root;
        cout<<"Case 1 : Node deleted"<<endl;
        return NULL;
     }
     else if(root->left==NULL || root->right==NULL){
        if(root->left!=NULL){
            Node* temp=root->left;
            delete root;
             cout<<"Case 2 : Node deleted"<<endl;
            return temp;
        }

        else{
            Node* temp=root->right;
            delete root;
             cout<<"Case 2 : Node deleted"<<endl;
            return temp;

        }
     }

     else{
        cout<<"Case 3: Node deleted"<<endl;
        Node* minRight = findMinimum(root->right);
        root->data=minRight->data;
        root->right = Delete(root->right , root->data);
        return root;
     }
   }

}
int main(){
    system("COLOR F");
    BST* bst = new BST;
    cout<<"create a BST press -1 to stop : "<<endl;

    bst->root=NULL;

    int key;
    while(true){
        cin>>key;
        if(key==-1){
            break;
        }
        bst->root =bst->Insert(bst->root , key);

    }
    cout<<endl;
    cout<<"In Order : "<<endl;
    bst->inOrder(bst->root);
    cout<<endl;
    Node* minValue=bst->findMinimum(bst->root);
    cout<<endl;
    cout<<"Minimum Value : "<<minValue->data<<endl;
    cout<<endl;
    Node* maxValue=bst->findMaximum(bst->root);
    cout<<"Maximum Value : "<<maxValue->data;
    cout<<endl;
    cout<<endl;
    cout<<"Enter a data to find : "<<endl;
    int findData ;
    cin>>findData;
    cout<<endl;
    Node* found=bst->searchNode(bst->root, findData);
    if(found!=NULL){
        cout<<"Data found"<<endl;
        cout<<"Data : "<<found->data<<endl;
    }

    cout<<endl;
    cout<<"Enter a data to delete : "<<endl;
    int p;
    cin>>p;
    bst->root=  bst->Delete(bst->root,p);
    cout<<endl;
    cout<<endl;
    cout<<"In Order : "<<endl;
    bst->inOrder(bst->root);
    cout<<endl;





}


