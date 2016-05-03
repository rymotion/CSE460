//test code for assembler
#include "assembler.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <map>
#include <stdexcept>
#include <vector>
#include <fstream>

using namespace std;
int main(int argc, char const *argv[])
{
	//first we input the file then we read the file for opcodes, integers(registers), and integers
	std::fstream inF;
	std::fstream outF;

	outF.open("outputFile.o", ios::out | ios::binary);
	inF.open(argv[1]);
	if (!inF.is_open()) {
		cout << "Your .s failed to open. in the assemble prog :<\n";
		exit(1);
	}
	
	Assembler a;	
	a.Assembler::assemble(inF, outF);
	cout << "input file to assembler = good\n";
	
	inF.close();
	outF.close();
	return 0;
}