// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
      int left = 2*i;
      int right = left +1;
      
      int max_idx = i;
      
      if(left < n && arr[i] < arr[left]){
          max_idx = left;
      }
      if(right < n && arr[max_idx] < arr[right]){
          max_idx = right;
      }
      
      if(max_idx != i){
          swap(arr[i],arr[max_idx]);
          heapify(arr,n,max_idx);
      }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
    for(int i=n/2;i>=0;i--){
        heapify(arr,n,i);
    }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        int j = n;
        while(j>1){
            swap(arr[0],arr[j-1]);
            j--;
            heapify(arr,j,0);
        }
    }
};

