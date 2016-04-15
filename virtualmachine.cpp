//Ryan PAglinawan and
//CSE 460
//CalState San Bernardino
//We will load a #.s file into this and it should generate a .o
#include <iostream>
#include <vector>
#include "virtualmachine.h"


using namespace std;

VirtualMachine::VirtualMachine(){
	r = std::vector<int> (REG_FILE_SIZE);//this is going to be the memory register
	mem = std::vector<int> (MEM_SIZE);//the content of memory is in this registers
	
	this -> pc = 0;
    this -> ir = 0;
    this -> sr = 0;
    this -> sp = 0;
    this -> base = 0;
    this -> limit = 0;
    this -> clock = 0;//<-This can be represented as a class

}

int VirtualMachine::runtime(){

	return pc++;
}

int VirtualMachine::fetch(){
	
	return ir++;
}

void VirtualMachine::run(){

}

void VirtualMachine::setLess(){

}

void VirtualMachine::setEqual(){

}

void VirtualMachine::setGreat(){

}

void VirtualMachine::rtClock(){

}