//testbench
//Ryan Paglinawan

#include "virtualmachine.h"
#include "assembler.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib>
#include <fstream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	Assembler as;
	VirtualMachine vm;
	as.assemble();
	vm.run();
	return 0;
}//main os	