#include<iostream>
using namespace std;

struct queuenode{
    int front, rear, size ;
    int *arr ;
};


class queue{
    private :
        struct queuenode q1 ;

    public :
    queue(int s){
        q1.size = s ;
        q1.front = -1;
        q1.rear = -1;
        q1.arr = new int[s] ;
    }
    bool empty();
    bool full();
    void Enqueue(int value) ;
    void dequeue() ;
    int front();
    int rear();

};

bool queue::empty(){
    if(q1.front== -1 || q1.front>q1.rear ){
        return true;
    }

    return false;
}

bool queue::full(){
    if(q1.rear == q1.size-1){
        return true;
    }
    return false;
}

void queue::Enqueue(int value){
    if(full()){
        cout<<" overflow "<<endl ;
        return ;
    }

    q1.rear ++ ;
    q1.arr[q1.rear] = value ;

    if(q1.front == -1){
        q1.front ++ ;
    }

}

void queue::dequeue(){
    if(empty()){
        cout<<" underflow "<<endl ;
        return ;
    }
    if(q1.front==q1.rear){
        q1.front = -1 ;
        q1.rear = -1 ;
    }
    q1.front ++ ;

}

int queue::front(){
    return q1.arr[q1.front];
}

int queue::rear(){
    return q1.arr[q1.rear];
}



int main(){

    queue q(7) ;

    cout<<"empty : "<<q.empty()<<endl;
    cout<<"full : "<<q.full()<<endl ;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    cout<<"empty : "<<q.empty()<<endl ;
    cout<<"full : "<<q.full()<<endl;
    q.Enqueue(4);
    q.Enqueue(5);
    q.Enqueue(6);
    q.Enqueue(7);

    cout<<"empty : "<<q.empty()<<endl;
    cout<<"full : "<<q.full()<<endl;

    cout<<q.front()<<" " ;
    q.dequeue();
    cout<<q.front()<<" " ;
    q.dequeue();
    cout<<q.front()<<" " ;
    q.dequeue();
    cout<<q.front()<<" " ;
    q.dequeue();
    cout<<q.front()<<" " ;
    q.dequeue();
    cout<<q.front()<<" " ;
    q.dequeue();
    cout<<q.front()<<" "<<endl ;
    q.dequeue();

    cout<<"empty : "<<q.empty()<<endl;
    cout<<"full : "<<q.full()<<endl;
    
    return 0;
}