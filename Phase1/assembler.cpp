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

int Assembler::assemble(fstream& opFile, fstream& ouFile)
{
	string line, opcode;
	int rd, rs, constant;
	//remember constant is also address or ADDR
	
	while (!opFile.eof()) {
		rd=-1; rs=-1; constant=-129; // init to invalid values

		// the following line is the trick
		istringstream istr(line.c_str());
		cout << "Debug: Is reading file" << endl; 
		istr >> opcode;
		if (opcode == "load")
		{
			istr >> rd >> constant;
			Assembler::load(rd, constant); 
		}
		else if (opcode == "loadi")
		{
			istr >> rd >> constant;
			Assembler::loadi(rd, constant); 
		}
		else if (opcode == "store")
		{
			istr >> rd >> constant;
			Assembler::store(rd, constant); 
		}
		else if (opcode == "add")
		{
			istr >> rd >> rs;
			Assembler::add(rd, rs); 
		}
		else if (opcode == "addi")
		{
			istr >> rd >> constant;
			Assembler::addi(rd, constant); 
		}
		else if (opcode == "addc")
		{
			istr >> rd >> rs;
			Assembler::addc(rd, rs); 
		}
		else if (opcode == "addci")
		{
			istr >> rd >> constant;
			Assembler::addci(rd, constant); 
		}
		else if (opcode == "sub")
		{
			istr >> rd >> rs;
			Assembler::sub(rd, rs); 
		}
		else if (opcode == "subi")
		{
			istr >> rd >> constant;
			Assembler::subi(rd, constant); 
		}
		else if (opcode == "subc")
		{
			istr >> rd >> rs;
			Assembler::subc(rd, rs); 
		}
		else if (opcode == "subci")
		{
			istr >> rd >> constant;
			Assembler::subci(rd, constant); 
		}
		else if (opcode == "and")
		{
			istr >> rd >> rs;
			Assembler::sysand(rd, rs); 
		}
		else if (opcode == "andi")
		{
			istr >> rd >> constant;
			Assembler::andi(rd, constant); 
		}
		else if (opcode == "xor")
		{
			istr >> rd >> rs;
			Assembler::sysxor(rd, rs); 
		}
		else if (opcode == "xori")
		{
			istr >> rd >> constant;
			Assembler::xori(rd, constant); 
		}
		else if (opcode == "compl")
		{
			istr >> rd;
			Assembler::syscompl(rd); 
		}
		else if (opcode == "shl")
		{
			istr >> rd;
			Assembler::shl(rd); 
		}
		else if (opcode == "shla")
		{
			istr >> rd;
			Assembler::shla(rd); 
		}
		else if (opcode == "shr")
		{
			istr >> rd;
			Assembler::shr(rd); 
		}
		else if (opcode == "shra")
		{
			istr >> rd;
			Assembler::shra(rd); 
		}
		else if (opcode == "compr")
		{
			istr >> rd >> rs;
			Assembler::compr(rd, rs); 
		}
		else if (opcode == "compri")
		{
			istr >> rd >> constant;
			Assembler::compri(rd, constant); 
		}
		else if (opcode == "getstat")
		{
			istr >> rd >> rs;
			Assembler::getstat(rd, rs); 
		}
		else if (opcode == "putstat")
		{
			istr >> rd >> rs;
			Assembler::putstat(rd, rs); 
		}
		else if (opcode == "jump")
		{
			istr >> rd >> constant;
			Assembler::jump(rd, constant); 
		}
		else if (opcode == "jumpl")
		{
			istr >> rd >> constant;
			Assembler::jumpl(rd, constant); 
		}
		else if (opcode == "jumpe")
		{
			istr >> rd >> constant;
			Assembler::jumpe(rd, constant); 
		}
		else if (opcode == "jumpg")
		{
			istr >> rd >> constant; 
			Assembler::jumpg(rd, constant); 
		}
		else if (opcode == "call")
		{
			istr >> rd >> constant; 
			Assembler::call(rd, constant); 
		}
		else if (opcode == "return")
		{
			//should pop and restore VM status
			Assembler::sysreturn(); 
		}
		else if (opcode == "read")
		{
			istr >> rd; 
			Assembler::read(rd); 
		}
		else if (opcode == "write")
		{
			istr >> rd; 
			Assembler::write(rd); 
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
		ouFile << final << endl;
		getline(opFile, line);
	}
	return 1;
}
//opcode and their functions
//	I know these will not work but my original compilition would spit out
//	a segmetation fault
int Assembler::load(int rd, int constant)
{
	form = 0b00000;
	i = 0b0;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::loadi(int rd, int constant)
{	
	form = 0b00000;
	i = 0b1;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::store(int rd, int constant)
{
	form = 0b00001;
	i = 0b1;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::add(int rd, int constant)
{
	form = 0b00010;
	i = 0b0;
	final = form;
	final = (final << 2)|rd;//00010 00 0 01 000000
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
	//00010 00 0 00000001
}
int Assembler::addi(int rd, int constant)
{
	form = 0b00010;
	i = 0b1;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::addc(int rd, int constant)
{
	form = 0b00011;
	i = 0b0;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::addci(int rd, int constant)
{
	form = 0b00011;
	i = 0b1;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::sub(int rd, int constant)
{
	form = 0b00100;
	i = 0b0;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::subi(int rd, int constant)
{
	form = 0b00100;
	i = 0b1;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::subc(int rd, int constant)
{	
	form = 0b00101;
	i = 0b0;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::subci(int rd, int constant)
{	
	form = 0b00101;
	i = 0b1;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::sysand(int rd, int constant)
{
	form = 0b00110;
	i = 0b0;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::andi(int rd, int constant)
{
	form = 0b00110;
	i = 0b1;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::sysxor(int rd, int constant)
{
	form = 0b00111;
	i = 0b0;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::xori(int rd, int constant)
{
	form = 0b00111;
	i = 0b1;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::syscompl(int rd)
{
	form = 0b01000;
	i = 0b0;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final <<= 8;
	return final;
}
int Assembler::shl(int rd)
{
	form = 0b01001;
	i = 0b0;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final <<= 8;
	return final;
}
int Assembler::shla(int rd)
{
	form = 0b01010;
	i = 0b0;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final <<= 8;
	return final;
}
int Assembler::shr(int rd)
{
	form = 0b01011;
	i = 0b0;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final <<= 8;
	return final;
}
int Assembler::shra(int rd)
{
	form = 0b01100;
	i = 0b0;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final <<= 8;
	return final;
}
int Assembler::compr(int rd, int rs)
{
	form = 0b01101;
	i = 0b0;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 2)|rs;
	final <<= 6;
	return final;
}
int Assembler::compri(int rd, int constant)
{
	form = 0b01101;
	i = 0b1;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::getstat(int rd, int rs)
{
	form = 0b01110;
	i = 0b0;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 2)|rs;
	final <<= 6;
	return final;
}
int Assembler::putstat(int rd, int rs)
{
	form = 0b01111;
	i = 0b0;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 2)|rs;
	final <<= 6;
	return final;
}
int Assembler::jump(int rd, int constant)
{
	form = 0b10000;
	i = 0b1;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::jumpl(int rd, int constant)
{
	form = 0b10001;
	i = 0b1;

	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;	
}
int Assembler::jumpe(int rd, int constant)
{
	form = 0b10010;
	i = 0b1;

	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;
	return final;
}
int Assembler::jumpg(int rd, int constant)
{
	form = 0b10011;
	i = 0b1;

	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;

	return final;
}
int Assembler::call(int rd, int constant)
{
	form = 0b10100;
	i = 0b1;
	final = form;
	final = (final << 2)|rd;
	final = (final << 1)|i;
	final = (final << 8)|constant;

	return final;
}
int Assembler::sysreturn()
{
	form = 0b10101;
	final = form;
	final <<= 11;

	return final;
}
int Assembler::read(int rd)
{
	form = 0b10110;
	final = form;
	final = (final << 2)|rd;
	final <<= 9;

	return final;
}
int Assembler::write(int rd)
{	
	form = 0b10111;
	final = form;
	final = (final << 2)|rd;
	final <<= 9;

	return final;
}
int Assembler::halt()
{
	form = 0b11000;
	final = form;
	final <<= 11;

	return final;
}
int Assembler::noop()
{
	form = 0b11001;
	final = form;
	final <<= 11;

	return final;
}
