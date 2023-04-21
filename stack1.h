#include<iostream>
using namespace std ;

struct node{
    char data;
    struct node *next;
};

class stack
{
private:
    struct node *top;
    int size ;
public:
    stack(int s){
        top = NULL;
        size = s ;
    }
    int noOfElement();
    bool isEmpty();
    bool isFull();
    void push(char value);
    char pop();
    char gettop() ;
    void Display();
};

bool stack :: isEmpty(){             // " :: " = scope resolution operator
    if(top==NULL){
        return true;
    }else{
        return false;
    }
}

bool stack :: isFull(){
    if(size == noOfElement()){
        return true;
    }else{
        return false;
    }
}

void stack::push(char value)
{

    if(isFull()){
        cout<<"stack overflow..."<<endl ;
    }else{
        struct node *newnode;
        newnode = new struct node ;
        newnode->data = value ;
        newnode->next = top;
        top = newnode ;
    }
}




char stack::pop(){

    if(isEmpty()){
        cout<<"stack in Underflow..."<<endl ;
        return 0 ;
    }else
    {
        struct node *nodeToDelete ;
        char data = top->data ;
        nodeToDelete = top ;
        top = top->next ;
        delete(nodeToDelete);
        return data ;

    }
    
}



void stack::Display()
{
    struct node *temp;
    temp = top ;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next ;
    }
    cout<<endl;
    
}

char stack::gettop(){
    return top->data ;
}

int stack :: noOfElement(){
    
    int count = 0;
    struct node *temp;
    temp = top ;
    while (temp != NULL)
    {
        count++ ;
        temp = temp->next ;
    }
    return count;

}

