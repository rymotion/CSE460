//	assembler.h
//	Ryan Paglinawan
//	CSE 460 
#ifndef ASSEMBLER_H
#define ASSEMBLER_H
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

class NullPointerException: public runtime_error{
public:
	NullPointerException(): runtime_error("NULL Pointer"){

	} 
};

class Assembler{

	typedef void (Assembler::*FP)(string);
private:
	//map <string, int> instruction;
	int pc;
    int ir;
    int sr;
    int sp;
    int base;
    int limit;
    int clock;//	This one I will replace
	//	opcodes and their functions
	void load();
	void loadi();
	void store();
	//	These functions will set a CARRY bit to the sr per the SRS
	void add();
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
	//	This function will set the CARRY bit
	void shl();
	//	This will be the shift left arithmetic and sign extend 
	void shla();
	//	This function will set the CARRY bit
	void shr();
	//	This will be the shift left arithmetic and sign extend 
	void shra();
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
public:
	int i;
	int OP;
	int reg;
	int other;
	Assembler();
	//	this is the opcode string that the
	int assemble(FILE * opFile, FILE * ouFile);
};
#endif