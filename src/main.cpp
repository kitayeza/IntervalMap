#include <iostream>
#include "../inc/IMap.h"

int main() {
    Interval::intervalMap<int,char> M('A');
    std::cout<<M[8]<<std::endl;
    M.assert(0,11,'b');
    std::cout<<M[8]<<std::endl;
    M.assert(8,11,'A');
    std::cout<<M[8]<<std::endl;

}
