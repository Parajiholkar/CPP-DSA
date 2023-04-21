#include<iostream>
using namespace std;

class circularQueue{
    private:
    int front, rear, max ;
    int *arr ;

    public :
    circularQueue(int s){
        max = s ;
        front = -1 ;
        rear = -1 ;
        arr = new int[s] ;
    }

    void Enqueue(int value);
    void Dequeue();
    void Display() ;
    bool isFull() ;
    bool isEmpty() ;
};

bool circularQueue::isFull(){
    if ((rear+1)%max == front)
    {
        return true ;
    }

    return false ;
}

bool circularQueue::isEmpty(){
    if(front==-1 && rear == -1){
        return true;
    }

    return false;
}

void circularQueue::Enqueue(int value){

    if(isFull()){
        cout<<"Queue Overflow"<<endl ;
        return ;
    }

    if(front==-1 && rear == -1){
        front++ ;
        rear++ ;
    }
    else{
        rear = (rear+1)%max ;
    }

    arr[rear] = value ;
    cout<<"Insert Successfully " ;
}

void circularQueue::Dequeue(){
    if(isEmpty()){
        cout<<"Underflow"<<endl ;
        return ;
    }

    if(front==rear){
        front = -1 ;
        rear = -1 ;
        cout<<"Delete Successfully " ;
    }
    else{
        front = (front+1)%max ;
        cout<<"Delete Successfully " ;
    }


}


void circularQueue::Display(){


    if(isEmpty()){
        cout<<"Queue is Empty "<<endl ;
    }
    else{
        cout<<"Element in Queue : " ;
        int i=front ;
        do{
            cout<<arr[i]<<" " ;
            i = (i+1)%max ;

        }while(i != (rear+1)%max);
        cout<<endl ;
    }
}

int main(){
    int ch, size, value ;

    cout<<"Enter size of Circular Queue : " ;
    cin>>size ;
    circularQueue q1(size) ;
    do
    {  cout<<"\n1. Enqueue ( insert ) \n2. Dequeue ( delete )\n3. Display\n4. Exit " ;
        cout<<"\nEnter your choice : " ;
        cin>>ch ;
        if(ch==1){
            cout<<"Enter value you want to insert : " ;
            cin>>value ;
            q1.Enqueue(value) ;
        }
        else if(ch==2){
            q1.Dequeue() ;
        }
        else if(ch==3){
            q1.Display() ;
        }
        else{
            cout<<"Exit !"<<endl ;
        }
    } while (ch!=4);

    return 0;
}

/*

OUTPUT -> 
Enter size of Circular Queue : 5

1. Enqueue ( insert ) 
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 1
Enter value you want to insert : 4
Insert Successfully 
1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 1
Enter value you want to insert : 3
Insert Successfully 
1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 1
Enter value you want to insert : 2
Insert Successfully 
1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 1
Enter value you want to insert : 1
Insert Successfully 
1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 1
Enter value you want to insert : 5
Insert Successfully 
1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 1
Enter value you want to insert : 8
Queue Overflow

1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 3
Element in Queue : 4 3 2 1 5 

1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 2
Delete Successfully 
1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 3
Element in Queue : 3 2 1 5 

1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 2
Delete Successfully 
1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 3
Element in Queue : 2 1 5 

1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 1
Enter value you want to insert : 8
Insert Successfully 
1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 1
Enter value you want to insert : 9
Insert Successfully 
1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 2
Delete Successfully 
1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 3
Element in Queue : 1 5 8 9 

1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 2
Delete Successfully 
1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 2
Delete Successfully 
1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 2
Delete Successfully 
1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 2
Delete Successfully 
1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 2
Underflow

1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 3
Queue is Empty 

1. Enqueue ( insert )
2. Dequeue ( delete )
3. Display
4. Exit 
Enter your choice : 4
Exit !
*/