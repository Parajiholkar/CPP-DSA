#include<iostream>
using namespace std ;

void swapEle(int arr[], int i,int j){
    int temp = arr[j] ;
    arr[j] = arr[i] ;
    arr[i] = temp ;
}

int partition(int arr[], int low, int high){
	int pivot = low ;
    int i = low+1 ;
    int j = high ;
   
    while (arr[pivot] > arr[i] || arr[pivot] < arr[j]){
        if(arr[pivot] > arr[i]){
            i++ ;
        }else if (arr[pivot] < arr[j])
        {
            j-- ;
        }
    }

    if(j<i){
        swapEle(arr, j, pivot) ;
        return j ;
    }else
    {
        swapEle(arr, i, j) ;
        swapEle(arr, i, pivot) ; 
        return i ;
    }

}

void quickSort(int arr[], int low, int high){
	 

	if (low < high)
	{
		int pos = partition(arr, low, high) ;
		quickSort(arr, low, pos-1) ;
		quickSort(arr, pos+1, high) ;

	}

    
}

int main(){

    int n ; 
    
	cout<<"Enter number : " ;
	cin>>n ; 
	
	int arr[n] ;

	cout<<"Enter array element : " ;
	for(int i=0; i<n; i++){
		cin>>arr[i] ;
	}

    quickSort(arr, 0, n-1) ;

    cout<<"Sorted array : " ;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" " ;
	}

    return 0;
}