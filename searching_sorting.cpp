#include<iostream>
using namespace std ;

void display_arr(int n, int arr[]){
	cout<<"sorted array : ";
	for(int i=0; i<n; i++){
		cout<< arr[i]<<" " ;
	}
}

// bubble sort
void bubble_sort(int n, int arr[]){
	int counter=1 ;
	// loop will run n-1 times ( Passes == n-1)
	for(int i=1; i<n; i++){
		for(int j=0; j<n-counter; j++){
			// comparing adjacent integer in array
			if(arr[j]>arr[j+1]){
				// swapping adjacent integer
				int temp = arr[j] ;
				arr[j] = arr[j+1] ;
				arr[j+1] = temp ;
			}
		}
		counter++ ;
	}	
}

// Insertion sort
void insertion_sort(int n, int arr[]){
	int current_integer, i, j;
	// suppose previous array of index 1 is sorted
	for(i=1; i<n; i++){
		current_integer = arr[i];
		j=i-1 ;
		// compering current integer with previous integer in array
		while (j>=0 && current_integer < arr[j]){
			// swapping integer at j+1 from j
			arr[j+1] = arr[j] ;
			j-- ;
		}
		arr[j+1] = current_integer ;
	}

}



void linear_search(int n, int key, int arr[]){

	for(int i=0; i<n; i++){
		if(key==arr[i]){
			cout<<"integer Found at index "<<i <<endl;
		}
	}
}

void binary_search(int n, int key, int arr[]){
	int low = 0;
	int mid ;
	n -=1 ;
	while (low <= n)
	{
		mid = (low+n)/2 ;
		if(key==arr[mid]){
			cout<<"integer Found at index "<<mid <<endl;
			break;
		}else if (key < arr[mid])
		{
			n = mid-1 ;
		}else{
			low = mid+1 ;
		}
		
	}
	
}

int main(){

	int n, ch, key; 
	cout<<"Enter number : " ;
	cin>>n ; 
	
	int arr[n] ;
	cout<<"Enter array element : " ;
	for(int i=0; i<n; i++){
		cin>>arr[i] ;
	}
	do{
		cout<<"What you want to do ?\n1. sorting \n2. searching\n3. display array\n4. EXIT \nEnter your choice : ";
		cin>>ch ;
		if(ch==1){
			cout<<"choose Any one\n1. Bubble sort\n2. insertion sort\nEnter your choice : " ;
			cin>>ch ;
			switch (ch)
			{
			case 1:
				bubble_sort(n, arr);
				break;
			case 2:
				insertion_sort(n, arr);
				break;
			default:
				cout<<" Invalid choice " ;
				break;
			}
		}
		else if (ch==2)
		{
			cout<<"choose Any one\n1. Linear search\n2. Binary search\nEnter your choice : " ;
			cin>>ch ;
			cout<<"Enter number you want to search : " ;
			cin>>key;
			switch (ch)
			{
			case 1:
				linear_search(n, key, arr);
				break;
			case 2:
				binary_search(n, key, arr);
				break;
			
			default:
				cout<<" Invalid choice " ;
				break;
			}
		}else{
			display_arr(n, arr) ;
		}
	}while (ch != 4);


	return 0;
}
