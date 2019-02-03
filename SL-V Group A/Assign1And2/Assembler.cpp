#include <iostream>
#include "AssemblerPass2/AssemblerPass2.cpp"
#include "AssemblerPass1/AssemblerPass1.cpp"

using namespace std;

int main(int argc, char* argv[]) {

    char* filename = argv[1];

    AssemblerPass1 assemblerPass1;
    assemblerPass1.assemblerPass1Driver(filename);

    AssemblerPass2 assemblerPass2(assemblerPass1);
    assemblerPass2.assemblerPass2Driver();
    return 0;
}