#include <stdlib.h>
#include <iostream>

class vector{

    public:
    
    int *array;
    int arraysize;
    int maxsize;

    vector(){
        arraysize=0;
        maxsize=2;
        array=(int *)malloc(2*sizeof(int));

        if(!array){
		    std::cout << "Memory allocation failed"<<std::endl;
		    exit(1);
	    }
    }

    vector(int initialSize, int value){
        if(initialSize<0){
            std::cout<<"Size cannot be negative"<<std::endl;
            exit(1);
        }
        arraysize=initialSize;
        maxsize=initialSize;
        array=(int *)malloc(initialSize*sizeof(int));
        if(!array){
		    std::cout << "Memory allocation failed"<<std::endl;
		    exit(1);
	    }
        for(int i=0;i<initialSize;i++){
            array[i]=value;
        }
    }


    int &operator[] (int index){
        if (index >= arraysize || index<0){
            std::cout << "Array index out of bound "<<std::endl;
            exit(1);
        }
        return array[index];
    }

    int size(){
        return arraysize;
    }

    void push_back(int value){
        if(maxsize>arraysize){
            array[arraysize]=value;
        }
        else{
            maxsize=maxsize*2;
            int *temp=(int *)malloc(maxsize*sizeof(int));
            if(!temp){
		        std::cout << "Memory allocation failed"<<std::endl;
                maxsize=maxsize/2;
		        exit(1);
	        }
            for(int i=0;i<arraysize;i++){
                temp[i]=array[i];
            }
            temp[arraysize]=value;
            free(array);
            array=temp;
        }
        arraysize++;
    }

    void insert(int index, int value){
        if(index>=arraysize || index<0){
            std::cout<<"Index out of range"<<std::endl;
            exit(1);
        }
        if(arraysize>=maxsize){  
            maxsize=maxsize*2;
            int *temp=(int *)malloc(maxsize*sizeof(int));
            if(!temp){
		        std::cout << "Memory allocation failed"<<std::endl;
		        maxsize=maxsize/2;
                exit(1);
	        }
            for(int i=0;i<arraysize;i++){
                temp[i]=array[i];
            }
            temp[arraysize]=value;
            free(array);
            array=temp;
        }
        
        for(int i=arraysize;i>index;i--){
            array[i]=array[i-1];
        }
        array[index]=value;
        arraysize++;
    }

    void pop_back(){
        if(arraysize<=0){
            std::cout<<"Vector empty"<<std::endl;
            exit(1);
        }
        arraysize--;

        if(arraysize*2==maxsize){
            int *temp=(int *)malloc(arraysize*sizeof(int));
            if(!temp){
		        std::cout << "Memory allocation failed"<<std::endl;
                exit(1);
	        }
            for(int i=0;i<arraysize;i++){
                temp[i]=array[i];
            }
            free(array);
            array=temp;
            maxsize=maxsize/2;
        }
    }

    void erase(int index){
        if(index>=arraysize || index<0){
            std::cout<<"Index out of range"<<std::endl;
            exit(1);
        }
        for(int i=index+1;i<arraysize;i++){
            array[i-1]=array[i];
        }
        arraysize--;

        if(arraysize*2==maxsize){
            int *temp=(int *)malloc(arraysize*sizeof(int));
            if(!temp){
		        std::cout << "Memory allocation failed"<<std::endl;
                exit(1);
	        }
            for(int i=0;i<arraysize;i++){
                temp[i]=array[i];
            }
            free(array);
            array=temp;
            maxsize=maxsize/2;
        }
    }

    int front(){
        if(arraysize>0)
            return array[0];
        std::cout<<"Vector empty"<<std::endl;
        exit(1);
    }

    int back(){
        if(arraysize>0)
            return array[arraysize-1];
        std::cout<<"Vector empty"<<std::endl;
        exit(1);
    }

    void print(){
        std::cout<<arraysize<<" "<<maxsize<<std::endl;
        for(int i=0;i<arraysize;i++){
            std::cout<<array[i]<<" ";
        }
        std::cout<<std::endl;
    }

};
