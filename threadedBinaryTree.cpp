#include<iostream>
using namespace std;


struct node
{
    int data;
    int lth, rth ;
    struct node *left, *right;

    node(int value){
        this->data = value ;
        this->lth = this->rth = 1 ;
        this->left = this->right = NULL ;
    }
    
};

class TBT{
    public :
    struct node* root, * head ;

    TBT(){
        head = new node(0) ;
        head->lth = 0;
        head->left = root ;
        head->right = head ;
        root = NULL ;
    }
    struct node* insert(struct node* root, int value);
    void inorder() ;
    void preorder() ;

};

node* TBT::insert(struct node* root1, int value){
    
    if(root1==NULL){
        
        root = new node(value) ;
        root->left = head ;
        root->right = head ;
        cout<<"inserted.........."<<endl ;
        return root ;
    }
    
    if(root1->data > value){
        if(root1->lth == 1){
            node *temp = new node(value) ;
            temp->left = root1->left ;
            temp->right = root1 ;
            root1->lth = 0 ;
            root1->left = temp ;
            cout<<"inserted.........."<<endl ;
        }
        else{
            root1->left = insert(root1->left, value) ;
        }
    }
    else if(root1->data < value){
        if(root1->rth == 1){
            node *temp = new node(value) ;
            temp->left = root1 ;
            temp->right = root1->right ;
            root1->rth = 0 ;
            root1->right = temp ;
            cout<<"inserted.........."<<endl ;
        }
        else{
            root1->right = insert(root1->right, value) ;
        }
    }

    return root1 ;

}

node* inordersuccser(node* root){
    if(root->rth==0){
        root = root->right ;

        while(root->lth==0){
            root = root->left ;
        }
        return root ;
    }
    else{
        return root->right ;
    }
}

void TBT:: inorder(){

    node * root1 = root ;
    while (root1->lth == 0)
    {
        root1 = root1->left ;
    }

    while (root1!=head)
    {
        cout<<" "<<root1->data ;
        root1 = inordersuccser(root1) ;
    
    }
 
}

void TBT::preorder(){
    node * root1 = root ;

    while (root1 != head){
        cout<<root1->data<<" " ;
        if(root1->lth==0){
            root1 = root1->left ;
        }
        else{
            root1 =root1->right ;
            if(root1->rth == 0){
                root1 = root1->right ;
            }
        }
    }
    
}


int main(){

    int value ;
    TBT tree ;


    for(int i= 0; i<7 ;i++){
        cout<<"Enter value you want to insert " ;
        cin>>value ;
        tree.root = tree.insert(tree.root , value) ;
    }

    cout<<"Inorder : " ;
    tree.inorder() ;
    cout<<"\nPreorder : " ;
    tree.preorder() ;

    return 0;
}