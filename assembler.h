//	assembler.h
//Ryan Paglinawan
//CSE 460
//CalState San Bernardino
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
#include <bitset>

using namespace std;

class NullPointerException: public runtime_error{
public:
	NullPointerException(): runtime_error("NULL Pointer"){

	} 
};

class Assembler{

	typedef void (Assembler::*FP)(string);
	map<string, FP> instr;
	
	//	opcodes and their functions
	void load();
	void loadi();
	void store();	
	void add(); //	These functions will set a CARRY bit to the sr per the SRS
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
	void shl(); //	This function will set the CARRY bit
	void shla(); //	This will be the shift left arithmetic and sign extend 
	void shr(); //	This function will set the CARRY bit
	void shra(); //	This will be the shift left arithmetic and sign extend 
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
	int sr;
	ifstream assemblyProg;
	ofstream assemblyOut;
	int form;
	Assembler();
	//	this is the opcode string that the
	int assemble(char opFile, char ouFile);
};
#endif