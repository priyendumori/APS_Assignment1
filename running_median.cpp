#include <iostream>

using namespace std;

class MaxHeap{

    public:

    int *arr;
    int max_size;
    int heap_size;

    MaxHeap(int n){
        arr=new int[n];
        max_size=n;
        heap_size=0;
    }


    void max_heapify(int i){
        int l=2*i+1;
        int r=2*i+2;
        int largest;
        if(l<=heap_size && arr[l]>arr[i]){
            largest=l;
        }
        else largest=i;

        if(r<=heap_size && arr[r]>arr[largest]) largest=r;
        
        if(largest!=i){
            int temp=arr[i];
            arr[i]=arr[largest];
            arr[largest]=temp;
            max_heapify(largest);
        }
    }

    int get_max(){
        return arr[0];
    }

    int extract_max(){
        if(heap_size<1){
            //error
        }

        int max=arr[0];
        arr[0]=arr[heap_size-1];
        heap_size--;
        max_heapify(0);
        return max;
    }

    void insert(int element){
        if(heap_size==max_size){
            //error
        }

        heap_size++;
        arr[heap_size-1]=element;

        int i=heap_size-1;
        while (i != 0 && arr[(i-1)/2] < arr[i])
        {
            int temp=arr[i];
            arr[i]=arr[(i-1)/2];
            arr[(i-1)/2]=temp;

            i = (i-1)/2;
        }
    }

};

class MinHeap{

    public:

    int *arr;
    int max_size;
    int heap_size;

    MinHeap(int n){
        arr=new int[n];
        max_size=n;
        heap_size=0;
    }


    void min_heapify(int i){
        int l=2*i+1;
        int r=2*i+2;
        int smallest;
        if(l<=heap_size && arr[l]<arr[i]){
            smallest=l;
        }
        else smallest=i;

        if(r<=heap_size && arr[r]<arr[smallest]) smallest=r;
        
        if(smallest!=i){
            int temp=arr[i];
            arr[i]=arr[smallest];
            arr[smallest]=temp;
            min_heapify(smallest);
        }
    }

    int get_min(){
        return arr[0];
    }

    int extract_min(){
        if(heap_size<1){
            //error
        }

        int min=arr[0];
        arr[0]=arr[heap_size-1];
        heap_size--;
        min_heapify(0);
        return min;
    }

    void insert(int element){
        if(heap_size==max_size){
            //error
        }

        heap_size++;
        arr[heap_size-1]=element;

        int i=heap_size-1;
        while (i != 0 && arr[(i-1)/2] > arr[i])
        {
            int temp=arr[i];
            arr[i]=arr[(i-1)/2];
            arr[(i-1)/2]=temp;

            i = (i-1)/2;
        }
    }

};

int main(){

    int a[10]={2,4,1,3,8,10,15,65,20,7 };
    MaxHeap leftheap(10);
    MinHeap rightheap(10);

    leftheap.insert(a[0]);
    //cout<<a[0]<<" ";
    float medianarr[10];
    medianarr[0]=a[0];
    int current_median=a[0];
    for(int i=1;i<10;i++){

        if(a[i]>current_median){
            if(leftheap.heap_size < rightheap.heap_size ){
                int temp=rightheap.extract_min();
                leftheap.insert(temp);
            }
            rightheap.insert(a[i]);

            if(rightheap.heap_size > leftheap.heap_size ) medianarr[i]=rightheap.get_min();
            else medianarr[i]= (rightheap.get_min()+leftheap.get_max())/2.0;
        }
        else{
            if(leftheap.heap_size > rightheap.heap_size){
                int temp=leftheap.extract_max();
                rightheap.insert(temp);
            }
            leftheap.insert(a[i]);

            if(rightheap.heap_size < leftheap.heap_size ) medianarr[i]=leftheap.get_max();
            else medianarr[i]= (rightheap.get_min()+leftheap.get_max())/2.0;
        }

    }

    for(int i=0;i<10;i++){
        cout<<medianarr[i]<<" ";
    }
    cout<<endl;
    return 0;
}