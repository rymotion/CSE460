//Assembler
//Ryan Paglinawan
#include "assembler.h"
#include "virtualmachine.h"
#include <map>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <cstdlib>  // for exit()
#include <iostream> // for cout, ...
#include <fstream>  // for fstream::open()
#include <string>
#include <sstream>  // for istringstream

using namespace std;

Assembler::Assembler(FILE * iFile)
{
	FILE * imFile; //This is the name of the imported file 
	iFile = imFile

	fstream assemblyProg;
	string line, opcode;
	int rd, rs, constant;

	assemblyProg.open(imFile, ios::in);
	if (!assemblyProg.is_open()) {
		cout << "Your .s failed to open.\n";
		exit(1);
	}

	getline(assemblyProg, line);
	while (!assemblyProg.eof()) {
		rd=-1; rs=-1; constant=-129; // init to invalid values

		// the following line is the trick
		istringstream str(line.c_str());
		str >> opcode;
		if (opcode == "load")
		{
			/* code */
		}
		else if (opcode == "loadi")
		{
			/* code */
		}
		else if (opcode == "store")
		{
			/* code */
		}
		else if (opcode == "add")
		{
			//str >> rd >> rs;
		}
		else if (opcode == "addi")
		{
			//str >> rd >> constant;
		}
		else if (opcode == "addc")
		{
			/* code */
		}
		else if (opcode == "addci")
		{
			//cout << "Some other opcode: ";
		}
		else if (opcode == "sub")
		{

		}
		else if (opcode == "subi")
		{

		}
		else if (opcode == "subc")
		{

		}
		else if (opcode == "subci")
		{

		}
		else if (opcode == "and")
		{
			/* code */
		}
		else if (opcode == "andi")
		{
			/* code */
		}
		else if (opcode == "xor")
		{
			/* code */
		}
		else if (opcode == "xori")
		{
			/* code */
		}
		else if (opcode == "compl")
		{
			/* code */
		}
		else if (opcode == "shl")
		{
			/* code */
		}
		else if (opcode == "shla")
		{
			/* code */
		}
		else if (opcode == "shr")
		{
			/* code */
		}
		else if (opcode == "shra")
		{
			/* code */
		}
		else if (opcode == "compr")
		{
			/* code */
		}
		else if (opcode == "compri")
		{
			/* code */
		}
		else if (opcode == "getstat")
		{
			/* code */
		}
		else if (opcode == "putstat")
		{
			/* code */
		}
		else if (opcode == "jump")
		{
			/* code */
		}
		else if (opcode == "jumpl")
		{
			/* code */
		}
		else if (opcode == "jumpe")
		{
			/* code */
		}
		else if (opcode == "jumpg")
		{
			/* code */
		}
		else if (opcode == "call")
		{
			/* code */
		}
		else if (opcode == "return")
		{
			/* code */
		}
		else if (opcode == "read")
		{
			/* code */
		}
		else if (opcode == "write")
		{
			/* code */
		}
		else if (opcode == "halt")
		{
			/* code */
		}
		else if (opcode == "noop")
		{
			/* code */
		}


		cout << opcode << " " << rd << " " << rs << " " << constant << endl;
		getline(assemblyProg, line);
	}
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