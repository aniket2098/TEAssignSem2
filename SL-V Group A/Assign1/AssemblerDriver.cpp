#include <iostream>
#include "AssemblerPass1.cpp"
#include "AssemblerPass2.cpp"

using namespace std;

int main(int argc, char* argv[]) {

    char* filename = argv[1];
    AssemblerPass1 assemblerPass1;
    assemblerPass1.assemblerPass1Driver(filename);

    return 0;
}