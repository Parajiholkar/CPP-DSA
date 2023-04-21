#include<iostream>
using namespace std ;

struct node{
    int data;
    struct node *next;
    
};

class Linkedlist
{
private:
    struct node *head;
public:
    node * newNodeCreate();
    void insertFirst();
    void insertAtLast();
    void insertAtAfter();
    void insertAtBefore();
    void deleteFirst();
    void deleteAtLast();
    void deleteAtAfter();
    void deleteAtBefore();
    void Display();
    Linkedlist(){
        head = NULL;
    }
};

node * Linkedlist ::newNodeCreate(){
    int value;
    cout<<"Enter value you want to insert ";
    cin>>value;
    struct node *newnode;
    newnode = new struct node ;
        
    newnode->data = value ;
    newnode->next = NULL;
    return newnode;
}

void Linkedlist::insertFirst()
{
    struct node *newnode = newNodeCreate();
    // if head is null that means  element is not present in linked list
    if(head == NULL){
        head = newnode ;
    }else{
        newnode->next = head;
        head = newnode ;
    }
}

void Linkedlist::insertAtLast(){
    cout<<"insert at last positon ";
    struct node *newnode = newNodeCreate();

    struct node *temp;
    temp = head ;                                           
    while (temp->next != NULL)
    {   
        temp = temp->next;
    }

    if(temp->next == NULL){
        temp->next = newnode ;
    }
    
}

void Linkedlist::insertAtAfter(){

    int k, value;
    cout<<"\nEnter number after that number value is inserted ";
    cin>>k;
    
    struct node *newnode = newNodeCreate();   
    struct node *temp;   

    temp = head ;
    while (temp->data != k && temp != NULL)
    {                                                       
        temp = temp->next ;
    }
    if(temp->data == k){
        newnode->next = temp->next ;
        temp->next = newnode;
    }else{
        cout<<"element is not found !";
    }
    
}

void Linkedlist::insertAtBefore(){
    int k, value;
    cout<<"\nEnter number before that number value is inserted ";
    cin>>k;
    struct node *newnode = newNodeCreate();
    struct node *temp;

    temp = head;
    while (temp->next->data != k && temp->next != NULL)    //  5 7 2 4 6
    {
        temp = temp->next;
    }
    if(temp->next->data == k){
        newnode->next = temp->next;
        temp->next = newnode ;
    }
    else{
        cout<<"element is not found !";
    }
}

void Linkedlist::deleteFirst(){

    struct node *nodeToDelete ;
    nodeToDelete = head ;
    head = head->next ;
    delete(nodeToDelete);
    cout<<endl;
}

void Linkedlist::deleteAtLast(){

    if(head->next == NULL){
        deleteFirst();
    }else{
        struct node *nodeToDelete, *temp ;
        temp = head ;
        while(temp->next->next != NULL){
            temp = temp->next ;
        }

        if(temp->next->next == NULL){
            nodeToDelete = temp->next;
            temp->next = NULL ;

            delete(nodeToDelete);
            cout<<endl;
        }
    }
}

void Linkedlist::deleteAtAfter(){

    int k;
    cout<<"\nEnter number next next node of that number is deleted  ";
    cin>>k;
    struct node *nodeToDelete, *temp;
    temp = head ;
    while(temp->data != k && temp != NULL){
        temp = temp->next ;
    }
    if(temp->data==k){
        nodeToDelete = temp->next ;
        temp->next = nodeToDelete->next;

        delete(nodeToDelete);
        cout<<"\n";
    }else
    {
        cout<<"Element is Not Found !";
    }
    

}

void Linkedlist::deleteAtBefore(){
    int k;
    cout<<"\nEnter number before node of that number is deleted ";
    cin>>k;
    struct node *nodeToDelete, *temp;
    temp = head ;
    while(temp->next->next->data != k && temp != NULL){
        temp = temp->next;
    }

    if(temp->next->next->data == k) {   
        nodeToDelete = temp->next ;
        temp->next = nodeToDelete->next;
        delete(nodeToDelete);
        cout<<"\n";
    }else{
        cout<<"Element is Not Found !";
    }
}

void Linkedlist::Display()
{
    struct node *temp;
    temp = head ;
    while (temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next ;
    }
    cout<<"NULL"<<endl;
    
}


int main(){
    Linkedlist l;
    l.insertFirst();
    l.insertFirst();
    l.insertFirst();
    l.insertFirst();
    l.Display();
    l.insertAtLast();
    l.Display();
    l.insertAtAfter();
    l.Display();
    l.insertAtBefore();
    l.Display();
 /*
    cout<<"delete first \n";
    l.deleteFirst();
    l.Display();
    l.deleteAtLast();
    cout<<"delete last \n";
    l.Display();
    l.deleteAtAfter();
    cout<<"delete after \n";
    l.Display();
    l.deleteAtBefore();
    cout<<"delete before \n";
    l.Display();
    */
/*
    int ch;
    cout<<"Enter choise 1 or 2 ";
    cin>>ch ;
   do{
    int ch;
    cout<<"Enter choise 1 or 2 ";
    cin>>ch ;
    cout<<"insert at after"<<endl ;
    l.insertAtAfter();
    cout<<"insert at before"<<endl ;
    l.insertAtBefore();
    cout<<"delete at after"<<endl ;
    l.deleteAtAfter();
    cout<<"delete at before"<<endl ;
    l.deleteAtBefore();
   }while(ch!=2);
*/
    


    return 0;
}