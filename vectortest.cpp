#include <stdlib.h>
#include <iostream>
#include "vector.h"

int main(){
    Vector v;
    v.back();
    v.print();
    v.push_back(10);
    v.print();
    v.push_back(20);
    v.print();
    v.push_back(30);
    v.print();
    v.push_back(40);
    v.print();
    v.push_back(50);
    v.print();
    v.pop_back();
    v.print();
    v.insert(2,25);
    v.print();
    v.push_back(60);
    v.print();
    v.push_back(70);
    v.print();
    v.push_back(80);
    v.print();
    v.erase(0);
    v.print();

    v.erase(20);
    std::cout<<v.size();
    return 0;
}