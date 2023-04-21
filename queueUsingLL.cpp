#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next ;
};

class queue{
    private :
    struct node *front ,*rear ;
    public :
    queue(){
        front = NULL ;
        rear = NULL ;
    }
    void enqueue() ;
    void dequeue() ;
    int size() ;
    int peek() ;

};


int main(){


    return 0;
}