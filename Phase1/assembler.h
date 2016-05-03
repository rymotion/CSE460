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
	int load(int rd, int constant);
	int loadi(int rd, int constant);
	int store(int rd, int constant);	
	int add(int rd, int rs); //	These functions will set a CARRY bit to the sr per the SRS
	int addi(int rd, int constant);
	int addc(int rd, int rs);
	int addci(int rd, int constant);
	int sub(int rd, int rs);
	int subi(int rd, int constant);
	int subc(int rd, int rs);
	int subci(int rd, int constant);
	int sysand(int rd, int rs);
	int andi(int rd, int constant);
	int sysxor(int rd, int rs);
	int xori(int rd, int constant);
	int syscompl(int rd);
	int shl(int rd); //	This function will set the CARRY bit
	int shla(int rd); //	This will be the shift left arithmetic and sign extend 
	int shr(int rd); //	This function will set the CARRY bit
	int shra(int rd); //	This will be the shift left arithmetic and sign extend 
	int compr(int rd, int rs);
	int compri(int rd, int constant);
	int getstat(int rd, int rs);
	int putstat(int rd, int rs);
	int jump(int rd, int constant);
	int jumpl(int rd, int constant);
	int jumpe(int rd, int constant);
	int jumpg(int rd, int constant);
	int call(int rd, int constant);
	int sysreturn();
	int read(int rd);
	int write(int rd);
	int halt();
	int noop();
public:
	
	int i;
    int OP;
    int form;
	int final;
	//int ext; // this is going to be the extantion to fill out the extra left over bits
	//std::fstream assemblyProg;
	//std::fstream assemblyOut;
	Assembler();
	//	this is the opcode string that the
	int assemble(fstream& opFile, fstream& ouFile);
};
#endif