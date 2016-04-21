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