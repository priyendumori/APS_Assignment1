#include <iostream>
#include <iomanip>
using namespace std;

#define ll long long

class MaxHeap{

    public:

    ll *arr;
    ll max_size;
    ll heap_size;

    MaxHeap(ll n){
        arr=new ll[n];
        max_size=n;
        heap_size=0;
    }


    void max_heapify(ll i){
        ll l=2*i+1;
        ll r=2*i+2;
        ll largest;
        if(l<=heap_size && arr[l]>arr[i]){
            largest=l;
        }
        else largest=i;

        if(r<=heap_size && arr[r]>arr[largest]) largest=r;
        
        if(largest!=i){
            ll temp=arr[i];
            arr[i]=arr[largest];
            arr[largest]=temp;
            max_heapify(largest);
        }
    }

    ll get_max(){
        return arr[0];
    }

    ll extract_max(){

        ll max=arr[0];
        arr[0]=arr[heap_size-1];
        heap_size--;
        max_heapify(0);
        return max;
    }

    void insert(ll element){

        heap_size++;
        arr[heap_size-1]=element;

        ll i=heap_size-1;
        while (i != 0 && arr[(i-1)/2] < arr[i])
        {
            ll temp=arr[i];
            arr[i]=arr[(i-1)/2];
            arr[(i-1)/2]=temp;

            i = (i-1)/2;
        }
    }

};

class MinHeap{

    public:

    ll *arr;
    ll max_size;
    ll heap_size;

    MinHeap(ll n){
        arr=new ll[n];
        max_size=n;
        heap_size=0;
    }


    void min_heapify(ll i){
        ll l=2*i+1;
        ll r=2*i+2;
        ll smallest;
        if(l<=heap_size && arr[l]<arr[i]){
            smallest=l;
        }
        else smallest=i;

        if(r<=heap_size && arr[r]<arr[smallest]) smallest=r;
        
        if(smallest!=i){
            ll temp=arr[i];
            arr[i]=arr[smallest];
            arr[smallest]=temp;
            min_heapify(smallest);
        }
    }

    ll get_min(){
        return arr[0];
    }

    ll extract_min(){

        ll min=arr[0];
        arr[0]=arr[heap_size-1];
        heap_size--;
        min_heapify(0);
        return min;
    }

    void insert(ll element){
    
        heap_size++;
        arr[heap_size-1]=element;

        ll i=heap_size-1;
        while (i != 0 && arr[(i-1)/2] > arr[i])
        {
            ll temp=arr[i];
            arr[i]=arr[(i-1)/2];
            arr[(i-1)/2]=temp;

            i = (i-1)/2;
        }
    }

};

int main(){

    ll n;
    cin>>n;
    ll a[n];
    MaxHeap leftheap(n);
    MinHeap rightheap(n);

    for(ll i=0;i<n;i++){
        cin>>a[i];
        leftheap.arr[i]=-1;
        rightheap.arr[i]=-1;
    }

    leftheap.insert(a[0]);
    double medianarr[n];
    medianarr[0]=a[0];
    double current_median=a[0];
    cout<<fixed<<setprecision(1)<<medianarr[0]<<endl;
    
    for(ll i=1;i<n;i++){
        current_median=medianarr[i-1];
        if(a[i]>current_median){
            if(leftheap.heap_size < rightheap.heap_size ){
                ll temp=rightheap.extract_min();
                leftheap.insert(temp);
            }
            rightheap.insert(a[i]);
            if(rightheap.heap_size > leftheap.heap_size ) medianarr[i]=rightheap.get_min();
            else medianarr[i]= (rightheap.get_min()+leftheap.get_max())/2.0;

            cout<<medianarr[i]<<endl;
        }
        else{
            if(leftheap.heap_size > rightheap.heap_size){
                ll temp=leftheap.extract_max();
                rightheap.insert(temp);
            }
            leftheap.insert(a[i]);

            if(rightheap.heap_size < leftheap.heap_size ) medianarr[i]=leftheap.get_max();
            else medianarr[i]= (rightheap.get_min()+leftheap.get_max())/2.0;
        
            cout<<medianarr[i]<<endl;
        }
        
    }

    return 0;
}
