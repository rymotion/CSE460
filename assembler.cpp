//Assembler
//Ryan Paglinawan
//CSE 460
//CalState San Bernardino
#include "assembler.h"
#include <map>
#include <stdexcept>
#include <vector>
#include <cstdlib>  // for exit()
#include <iostream> // for cout, ...
#include <fstream>  // for fstream::open()
#include <string>
#include <sstream>  // for istringstream

using namespace std;

Assembler::Assembler()
{	
	/*
	instr["load"] = &Assembler::load;
	instr["loadi"] = &Assembler::loadi;
	instr["store"] = &Assembler::store;
	instr["add"] = &Assembler::add;
	instr["addi"] = &Assembler::addi;
	instr["addc"] = &Assembler::addc;
	instr["addci"] = &Assembler::addci;
	instr["sub"] = &Assembler::sub;
	instr["subi"] = &Assembler::subi;
	instr["subc"] = &Assembler::subc;
	instr["subci"] = &Assembler::subci;
	instr["and"] = &Assembler::sysand;
	instr["andi"] = &Assembler::andi;
	instr["xor"] = &Assembler::sysxor;
	instr["xori"] = &Assembler::xori;
	instr["compl"] = &Assembler::syscompl;
	instr["shl"] = &Assembler::shl;
	instr["shla"] = &Assembler::shla;
	instr["shr"] = &Assembler::shr;
	instr["shra"] = &Assembler::shra;
	instr["compr"] = &Assembler::compr;
	instr["compri"] = &Assembler::compri;
	instr["getstat"] = &Assembler::getstat;
	instr["putstat"] = &Assembler::putstat;
	instr["jump"] = &Assembler::jump;
	instr["jumpl"] = &Assembler::jumpl;
	instr["jumpe"] = &Assembler::jumpe;
	instr["jumpg"] = &Assembler::jumpg;
	instr["call"] = &Assembler::call;
	instr["return"] = &Assembler::sysreturn;
	instr["read"] = &Assembler::read;
	instr["write"] = &Assembler::write;
	instr["halt"] = &Assembler::halt;
	instr["noop"] = &Assembler::noop;
	*/
}

int Assembler::assemble(char opFile, char ouFile)
{
	char outputFilename[] = "ouFile.o";
	string line, opcode;
	int rd, rs, constant;
	//remember constant is also address or ADDR

	assemblyProg.open(opFile, ios::in);
	assemblyOut.open(ouFile, ios::out);
	if (!assemblyProg) {
		cout << "Your .s failed to open.\n";
		exit(1);
	}

	getline(assemblyProg, line, '!');
	assemblyProg.ignore();
	while (!assemblyProg.eof()) {
		rd=-1; rs=-1; constant=-129; // init to invalid values

		// the following line is the trick
		istringstream str(line.c_str());
		str >> opcode;
		if (opcode == "load")
		{
			str >> rd >> constant;
			Assembler::load();
		}
		else if (opcode == "loadi")
		{
			str >> rd >> constant;
			Assembler::loadi();
		}
		else if (opcode == "store")
		{
			str >> rd >> constant;
			Assembler::store();
		}
		else if (opcode == "add")
		{
			str >> rd >> rs;
			Assembler::add();
		}
		else if (opcode == "addi")
		{
			str >> rd >> constant;
			Assembler::addi();
		}
		else if (opcode == "addc")
		{
			str >> rd >> rs;
			Assembler::addc();
		}
		else if (opcode == "addci")
		{
			str >> rd >> constant;
			Assembler::addci();
		}
		else if (opcode == "sub")
		{
			str >> rd >> rs;
			Assembler::sub();
		}
		else if (opcode == "subi")
		{
			str >> rd >> constant;
			Assembler::subi();
		}
		else if (opcode == "subc")
		{
			str >> rd >> rs;
			Assembler::subc();
		}
		else if (opcode == "subci")
		{
			str >> rd >> constant;
			Assembler::subci();
		}
		else if (opcode == "and")
		{
			str >> rd >> rs;
			Assembler::sysand();
		}
		else if (opcode == "andi")
		{
			str >> rd >> constant;
			Assembler::andi();
		}
		else if (opcode == "xor")
		{
			str >> rd >> rs;
			Assembler::sysxor();
		}
		else if (opcode == "xori")
		{
			str >> rd >> constant;
			Assembler::xori();
		}
		else if (opcode == "compl")
		{
			str >> rd;
			Assembler::syscompl();
		}
		else if (opcode == "shl")
		{
			str >> rd;
			Assembler::shl();
		}
		else if (opcode == "shla")
		{
			str >> rd;
			Assembler::shla();
		}
		else if (opcode == "shr")
		{
			str >> rd;
			Assembler::shr();
		}
		else if (opcode == "shra")
		{
			str >> rd;
			Assembler::shra();
		}
		else if (opcode == "compr")
		{
			str >> rd >> rs;
			Assembler::compr();
		}
		else if (opcode == "compri")
		{
			str >> rd >> constant;
			Assembler::compri();
		}
		else if (opcode == "getstat")
		{
			str >> rd;
			Assembler::getstat();
		}
		else if (opcode == "putstat")
		{
			str >> rd;
			Assembler::putstat();
		}
		else if (opcode == "jump")
		{
			str >> rd >> constant;
			Assembler::jump();
		}
		else if (opcode == "jumpl")
		{
			str >> rd >> constant;
			Assembler::jumpl();
		}
		else if (opcode == "jumpe")
		{
			str >> rd >> constant;
			Assembler::jumpe();
		}
		else if (opcode == "jumpg")
		{
			str >> rd >> constant; 
			Assembler::jumpg();
		}
		else if (opcode == "call")
		{
			str >> rd >> constant; 
			Assembler::call();
		}
		else if (opcode == "return")
		{
			//should pop and restore VM status
			//str >> >>; 
			Assembler::sysreturn();
		}
		else if (opcode == "read")
		{
			str >> rd; 
			Assembler::read();
		}
		else if (opcode == "write")
		{
			str >> rd; 
			Assembler::write();
		}
		else if (opcode == "halt")
		{
			Assembler::halt();
			//execute halt
		}
		else if (opcode == "noop")
		{
			Assembler::noop();
		}

		//this last line will put the results into the output file
		assemblyOut << opcode << " " << rd << " " << rs << " " << constant << endl;
		getline(assemblyProg, line, '!');
	}
	assemblyProg.close();
	assemblyOut.close();
	return 1;
}
//opcode and their functions
//	I know these will not work but my original compilition would spit out
//	a segmetation fault
void Assembler::load()
{
	form = 0b00000;
	i = 0b0;
}
void Assembler::loadi()
{	
	form = 0b00000;
	i = 0b1;
}
void Assembler::store(string)
{
	form = 0b00001;
	i = 0b1;
}
void Assembler::add()
{
	form = 0b00010;
	i = 0b0;
}
void Assembler::addi()
{
	form = 0b00010;
	i = 0b1;
}
void Assembler::addc()
{
	form = 0b00011;
	i = 0b0;
}
void Assembler::addci()
{
	form = 0b00011;
	i = 0b1;
	
}
void Assembler::sub()
{
	form = 0b00100;
	i = 0b0;
}
void Assembler::subi()
{
	form = 0b00100;
	i = 0b1;
	
}
void Assembler::subc()
{	
	form = 0b00101;
	i = 0b0;
	
}
void Assembler::subci()
{	
	form = 0b00101;
	i = 0b1;
	
}
void Assembler::sysand()
{
	form = 0b00110;
	i = 0b0;
}
void Assembler::andi()
{
	form = 0b00110;
	i = 0b1;
}
void Assembler::sysxor()
{
	form = 0b00111;
	i = 0b0;
}
void Assembler::xori()
{
	form = 0b00111;
	i = 0b1;
}
void Assembler::syscompl()
{
	form = 0b01000;
}
void Assembler::shl()
{
	form = 0b01001;
}
void Assembler::shla()
{
	form = 0b01010;
}
void Assembler::shr()
{
	form = 0b01011;
}
void Assembler::shra()
{
	form = 0b01100;
}
void Assembler::compr()
{
	form = 0b01101;
	i = 0b0;
}
void Assembler::compri()
{
	form = 0b01101;
	i = 0b1;
}
void Assembler::getstat()
{
	form = 0b01110;
}
void Assembler::putstat()
{
	form = 0b01111;
}
void Assembler::jump()
{
	form = 0b10000;
	i = 0b1;
}
void Assembler::jumpl()
{
	form = 0b10001;
	i = 0b1;	
}
void Assembler::jumpe()
{
	form = 0b10010;
	i = 0b1;
}
void Assembler::jumpg()
{
	form = 0b10011;
	i = 0b1;
}
void Assembler::call()
{
	form = 0b10100;
	i = 0b1;
}
void Assembler::sysreturn()
{
	form = 0b10101;
}
void Assembler::read()
{
	form = 0b10110;
}
void Assembler::write()
{	
	form = 0b10111;
}
void Assembler::halt()
{
	form = 0b11000;
}
void Assembler::noop()
{
	form = 0b11001;
}
