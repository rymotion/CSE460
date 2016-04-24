//Ryan PAglinawan and
//CSE 460
//CalState San Bernardino
//We will load a #.s file into this and it should generate a .o
#include <iostream>
#include <vector>
#include "virtualmachine.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <map>
#include <stdexcept>


using namespace std;

VirtualMachine::VirtualMachine(){
	r = std::vector<int> (REG_FILE_SIZE);//this is going to be the memory register
	mem = std::vector<int> (MEM_SIZE);//the content of memory is in this registers
	
	pc = 0;
    ir = 0;
    sr = 0;
    sp = 0;
    base = 0;
    limit = 0;
    clock;//<-This can be represented as a class

}

int VirtualMachine::runtime(){

	return pc++;
}

int VirtualMachine::fetch(){
	ir 
	return ir++;
}

void VirtualMachine::run(.o, .in, .out){

}

void VirtualMachine::setLess(){

}

void VirtualMachine::setEqual(){

}

void VirtualMachine::setGreat(){

}

void VirtualMachine::rtClock(){

}

int VirtualMachine::clock(){

}

main()
{
	class format1 {
	public:
		unsigned UNUSED:6;
		unsigned RS:2;
		unsigned I:1;
		unsigned RD:2;
		unsigned OP:5;
	};

	class format2 {
	public:
		unsigned ADDR:8;
		unsigned I:1;
		unsigned RD:2;
		unsigned OP:5;
	};


	class format3 {
	public:
		int CONST:8;
		unsigned I:1;
		unsigned RD:2;
		unsigned OP:5;
	};

	union instruction {
		int i;
		format1 f1;
		format2 f2;
		format3 f3;
	};

	instruction ins;

	ins.i = 0xa007;
	//ins.i = 4288;
	//ins.i = 1093;

	//cout << hex;
	cout << ins.i << endl;
	cout << ins.f1.OP << " " << ins.f1.RD << " " << ins.f1.I << " " << ins.f1.RS << " " << ins.f1.UNUSED << endl;
	cout << ins.f2.OP << " " << ins.f2.RD << " " << ins.f2.I << " " << ins.f2.ADDR << endl;
	cout << ins.f3.OP << " " << ins.f3.RD << " " << ins.f3.I << " " << ins.f3.CONST << endl;
}