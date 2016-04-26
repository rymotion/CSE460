//VM.h
//Ryan Paglinawan
//CSE 460
//CalState San Bernardino
#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <map>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <bitset>

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
    int tick;
	//primary constructor for VM
	VirtualMachine();
	int runtime();//this is going to return the program counter
    int fetch();//this is going to be the instruction regester incrementer
    void run(char inObj, char outObj);//.o is the input .out is the file we want out
    void rtClock();//runtime clock of the program
    void load();
    void loadi();
    void store();   
    void add(); //  These functions will set a CARRY bit to the sr per the SRS
    void addi();
    void addc();
    void addci();
    void sub();
    void subi();
    void subc();
    void subci();
    void sysand();
    void andi();
    void sysxor();
    void xori();
    void syscompl();
    void shl(); // This function will set the CARRY bit
    void shla(); //    This will be the shift left arithmetic and sign extend 
    void shr(); // This function will set the CARRY bit
    void shra(); //    This will be the shift left arithmetic and sign extend 
    void compr();
    void compri();
    void getstat();
    void putstat();
    void jump();
    void jumpl();
    void jumpe();
    void jumpg();
    void call();
    void sysreturn();
    void read();
    void write();
    void halt();
    void noop();
};

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
#endif

/*
    two formats:
    OP RD I RS UNUSED
    OP RD I ADDR/CONST
    this is going to be coming from the assembler.cpp file output
*/