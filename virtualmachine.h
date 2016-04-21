//
#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <map>
#include  <stdexcept>

using namespace std;

class VirtualMachine {
private:
	static const int REG_FILE_SIZE = 4;
    static const int MEM_SIZE = 256;
    vector <int> r;
    vector <int> mem;
    //REMEMBER TO USE THESE
    
public:
    int pc;
    int ir;
    int sr;
    int sp;
    int base;
    int limit;
    int clock;
	//primary constructor for VM
	VirtualMachine();
	int runtime();//this is going to return the program counter
    int fetch();//this is going to be the instruction regester incrementer
    void run(.o, .in, .out);
	void setLess();
    void setEqual();
    void setGreat();
    void rtClock();//runtime clock of the program
};
#endif

/*
    two formats:
    OP RD I RS Unused
    OP RD I ADDR/CONST
*/