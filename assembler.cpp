//Assembler
//Ryan Paglinawan
#include "assembler.h"
#include "virtualmachine.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <map>
#include <stdexcept>
#include <vector>
#include <fstream>
//#include "virtualmachine.h"

using namespace std;

Assembler::Assembler(string OPc)
{
	string temp = OPc;

		/*switch(temp){

		case 'load':
			&Assembler::load();
			break;

		case 'loadi':
			&Assembler::loadi();
			break;

		case 'store':
			&Assembler::store();
			break;

		case 'add':
			&Assembler::add();
			break;

		case 'addi':
			&Assembler::addi();
			break;

		case 'addc':
			&Assembler::addc();
			break;

		case 'addci':
			&Assembler::addci();
			break;

		case 'sub':
			&Assembler::sub();
			break;

		case 'subi':
			&Assembler::subi();
			break;

		case 'subc':
			&Assembler::subc();
			break;

		case 'subci':
			&Assembler::subci();
			break;

		case 'and':
			&Assembler::sysand();
			break;

		case 'andi':
			&Assembler::andi();
			break;

		case 'xor':
			&Assembler::sysxor();
			break;

		case 'xori':
			&Assembler::xori();
			break;

		case 'compl':
			&Assembler::syscompl();
			break;

		case 'shl':
			&Assembler::shl();
			break;

		case 'shla':
			&Assembler::shla();
			break;

		case 'shr':
			&Assembler::shr();
			break;

		case 'shra':
			&Assembler::shra();
			break;

		case 'compr':
			&Assembler::compr();
			break;

		case 'compri':
			&Assembler::compri();
			break;

		case 'getstat':
			&Assembler::getstat();
			break;

		case 'putstat':
			&Assembler::putstat();
			break;

		case 'jump':
			&Assembler::jump();
			break;

		case 'jumpl':
			&Assembler::jumpl();
			break;

		case 'jumpe':
			&Assembler::jumpe();
			break;

		case 'jumpg':
			&Assembler::jumpg();
			break;

		case 'call':
			&Assembler::call();
			break;

		case 'return':
			&Assembler::sysreturn();
			break;

		case 'read':
			&Assembler::read();
			break;

		case 'write':
			&write();
			break;

		case 'halt':
			&Assembler::halt();
			break;

		case 'noop':
			&Assembler::noop();
			break;
	
		}*/
	instr
}

int Assembler::assemble(FILE * opFile, FILE * ouFile)
{	
	char opcode[8];
	FILE * infp = opFile;
	int OP;
	int i;
	int line = 0;
	eof = false;
	do{
		fscanf(infp,"%s,%d,%d", opcode, &reg, &other);
		Assembler::Assembler(opcode);
		line++;

	}
	while(!eof && infp -> fopen()){
		fclose(fp);
	}
	//write something here that ignores comments
	return 1;
}
//opcode and their functions
void Assembler::load()
{
	//r[reg] = mem[ADDR]
	reg = other;
	OP = 0;
	i = 0;

}
void Assembler::loadi()
{
	//r[RD] = CONST
	OP = 0;
	i = 1;
}
void Assembler::store()
{
	//mem[ADDR] = r[RD]

	OP = 1;
	i = 1;
}
void Assembler::add()
{
	//r[RD] = r[RD] + r[RS]
	OP = 2;
	i = 0;
}
void Assembler::addi()
{
	//r[RD] = r[RD] + CONST
	OP = 2;
	i = 1; 
}
void Assembler::addc()
{
	//r[RD] = r[RD] + r[RS] + CARRY
	OP = 3;
	i = 0;
}
void Assembler::addci()
{
	//r[RD] = r[RD] + CONST + CARRY
	OP = 3;
	i = 1;
}
void Assembler::sub()
{
	//r[RD] = r[RD] - r[RS]
	OP = 4;
	i = 0;
}
void Assembler::subi()
{
	//r[RD] = r[RD] - CONST
	OP = 4;
	i = 1;
}
void Assembler::subc()
{
	//r[RD] = r[RD] - r[RS] - CARRY
	OP = 5;
	i = 0;
}
void Assembler::subci()
{
	//r[RD] = r[RD] - CONST - CARRY
	OP = 5;
	i = 1;
}
void Assembler::sysand()
{
	//r[RD] = r[RD] & r[RS]
	OP = 6;
	i = 0;
}
void Assembler::andi()
{
	//r[RD] = r[RD] & CONST
	OP = 6;
	i = 1;
}
void Assembler::sysxor()
{
	//r[RD] = r[RD] ^ r[RS]
	OP = 7;
	i = 0;
}
void Assembler::xori()
{
	//r[RD] = r[RD] ^ CONST
	OP = 7;
	i = 1;
}
void Assembler::syscompl()
{
	//r[RD] = ~ r[RD]
	OP = 8;
}
void Assembler::shl()
{
	//r[RD] = r[RD] << 1, shift-in-bit = 0
	OP = 9;
}
void Assembler::shla()
{
	OP = 10;
}
int Assembler::shr()
{
	//r[RD] = r[RD] >> 1, shift-in-bit = 0
	OP = 11;
}
int Assembler::shra()
{
	OP = 12;
}
void Assembler::compr()
{
	//if r[RD] < r[RS] set LESS reset EQUAL and GREATER; 
	//if r[RD] == r[RS] set EQUAL reset LESS and GREATER;
	//if r[RD] > r[RS] set GREATER reset EQUAL and LESS
	OP = 13;
	i = 0;
}
void Assembler::compri()
{
	//if r[RD] < CONST set LESS reset EQUAL and GREATER; 
	//if r[RD] == CONST set EQUAL reset LESS and GREATER; 
	//if r[RD] > CONST set GREATER reset EQUAL and LESS
	OP = 13;
	i = 1;

}
void Assembler::getstat()
{
	OP = 14;
}
void Assembler::putstat()
{
	OP = 15;
}
void Assembler::jump()
{
	OP = 16;
	i = 1;
	pc = reg;
}
void Assembler::jumpl()
{
	OP = 17;
	i = 1;
	if (sr == 8)
	{
		pc = reg;
	}
}
void Assembler::jumpe()
{
	OP = 18;
	i = 1;
	if (sr == 4)
	{
		pc = reg;
	}
}
void Assembler::jumpg()
{
	OP = 19;
	i = 1;
	if (sr == 2)
	{
		pc = reg;
	}
}
void Assembler::call()
{
	OP = 20;
	i = 1;
}
void Assembler::sysreturn()
{
	OP = 21;
}
void Assembler::read()
{
	OP = 22;
}
void Assembler::write()
{	
	OP = 23;
	puts();
}
void Assembler::halt()
{
	OP = 24;
	eof = true;
}
void Assembler::noop()
{
	OP = 25;
	clock++;
}