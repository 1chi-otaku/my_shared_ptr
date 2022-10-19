#include <iostream>
#include "my_shared_ptr.h"
using namespace std;

int main() {

    my_shared_ptr<int> obj;
    my_shared_ptr<int> box1(obj);
  
    my_shared_ptr<int> box2(box1); // calls copy constructor
 
    box1 = obj;
    return 0;

}