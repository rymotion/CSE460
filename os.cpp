//testbench
//Ryan Paglinawan

#include "virtualmachine.h"
#include "assembler.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	Assembler as;
	VirtualMachine vm;
	//open *.s for input AKA argv[1]
	//open *.o four output AKA argv[]
	FILE * inF;
	FILE * outF;

	outF = stdio::fopen(); 
	inF = stdio::fopen(argv[1], "w+");
	as.Assembler::assemble(inF, outF);
	fclose(inF);
	fclose(outF);
	//close *.o for output on assemble AKA argv[]
	//open *.o for input for virtual machine AKA argv[]
	inF = stdio::fopen(argv[1], "w+");
	outF = stdio::fopen();
	vm.VirtualMachine::run(inF, .in, outF);
	fclose(outF);
	//source file and opbject file
	return 0;
}//main os	