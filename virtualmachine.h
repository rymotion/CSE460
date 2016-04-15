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
    //program counter
    int pc;
    int ir;
    int sr;
    int sp;
    int base;
    int limit;
    int clock;
    
public:
	//primary constructor for VM
	VirtualMachine();
	int runtime();
    int fetch();//this is going to be the instruction regester incrementer
    void run();
	void setLess();
    void setEqual();
    void setGreat();
    void rtClock();//runtime clock of the program
};
#endif