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
    int run(fstream& inObj, fstream& outObj);//.o is the input .out is the file we want out
    void decode();
    void rtClock();//runtime clock of the program
    void load(int rd, int constant);
    void loadi(int rd, int constant);
    void store(int rd, int constant);    
    void add(int rd, int rs); // These functions will set a CARRY bit to the sr per the SRS
    void addi(int rd, int constant);
    void addc(int rd, int rs);
    void addci(int rd, int constant);
    void sub(int rd, int rs);
    void subi(int rd, int constant);
    void subc(int rd, int rs);
    void subci(int rd, int constant);
    void sysand(int rd, int rs);
    void andi(int rd, int constant);
    void sysxor(int rd, int rs);
    void xori(int rd, int constant);
    void syscompl(int rd);
    void shl(int rd); // This function will set the CARRY bit
    void shla(int rd); //    This will be the shift left arithmetic and sign extend 
    void shr(int rd); // This function will set the CARRY bit
    void shra(int rd); //    This will be the shift left arithmetic and sign extend 
    void compr(int rd, int rs);
    void compri(int rd, int constant);
    void getstat(int rd, int rs);
    void putstat(int rd, int rs);
    void jump(int rd, int constant);
    void jumpl(int rd, int constant);
    void jumpe(int rd, int constant);
    void jumpg(int rd, int constant);
    void call(int rd, int constant);
    void sysreturn();
    void read(int rd);
    void write(int rd);
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