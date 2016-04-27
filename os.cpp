//testbench
//Ryan Paglinawan
//CSE 460
//CalState San Bernardino
#include "virtualmachine.h"
#include "assembler.h"
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <map>
#include <bitset>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	Assembler as;
	VirtualMachine vm;
	
	//open *.s for input AKA argv[1]
	//open *.o four output AKA argv[]
	
	std::fstream inF;
	std::fstream outF;
	std::fstream inObj;
	std::fstream outObj;
	char outputFile[] = "ouFt.o";
	char outputObject[] = "outOBJ.out";

	outF.open(outputFile); 
	inF.open(argv[1]);
	if (!inF.is_open()) {
		cout << "Your .s failed to open.\n";
		exit(1);
	}
	as.Assembler::assemble(inF, outF);
	inF.close();
	outF.close();

	//close *.o for output on assemble AKA argv[]
	//open *.o for input for virtual machine AKA argv[]
	
	inObj.open(outputFile);
	outObj.open(outputObject);
	if (!inObj.is_open()) {
		cout << "Your .s failed to open.\n";
		exit(1);
	}
	vm.VirtualMachine::run(inObj, outObj);
	outObj.close();
	inObj.close();

	//source file and object file
	return 0;
}//main os	