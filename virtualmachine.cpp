//Ryan Paglinawan
//CSE 460
//CalState San Bernardino
//We will load a #.s file into this and it should generate a .o
#include <iostream>
#include <vector>
#include "virtualmachine.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <map>
#include <stdexcept>
#include <iomanip>
#include <bitset>


using namespace std;

VirtualMachine::VirtualMachine(){
	r = std::vector<int> (REG_FILE_SIZE);//this is going to be the memory register
	mem = std::vector<int> (MEM_SIZE);//the content of memory is in this registers
	
	pc = 0;
    ir = 0;
    sr = 0;
    sp = 0;
    base = 0;
    limit = 0;
    tick = 0;//<-This can be represented as a class

}

int VirtualMachine::runtime(){
	return pc++;
}

int VirtualMachine::fetch(){
	
}

void VirtualMachine::run(char inObj, char outObj){
	fstream vmIn;
	fstream vmOut;
	outObj[] = "out  " 
	vmIn.open(inObj, ios::in);
	vmOut.open(outObj, ios::out);
	if (!inObj || !outObj) {
		cout << "Your .s failed to open.\n";
		exit(1);
	}

	getline(vmIn, line);
	while (!vmIn.eof()) {
		rd=-1; rs=-1; constant=-129; // init to invalid values

		// the following line is the trick
		istringstream str(line.c_str());
		str >> opcode;
		if (opcode == "load")
		{
			str >> rd >> constant;
			Assembler::load(rd, constant);
		}
		else if (opcode == "loadi")
		{
			str >> rd >> constant;
			Assembler::loadi(rd, constant);
		}
		else if (opcode == "store")
		{
			str >> rd >> constant;
			Assembler::store(rd, constant);
		}
		else if (opcode == "add")
		{
			str >> rd >> rs;
			Assembler::add(rd, rs);
		}
		else if (opcode == "addi")
		{
			str >> rd >> constant;
			Assembler::addi(rd, constant);
		}
		else if (opcode == "addc")
		{
			str >> rd >> rs;
			Assembler::addc(rd, rs);
		}
		else if (opcode == "addci")
		{
			str >> rd >> constant;
			Assembler::addci(rd, constant);
		}
		else if (opcode == "sub")
		{
			str >> rd >> rs;
			Assembler::sub(rd, rs);
		}
		else if (opcode == "subi")
		{
			str >> rd >> constant;
			Assembler::subi(rd, constant);
		}
		else if (opcode == "subc")
		{
			str >> rd >> rs;
			Assembler::subc(rd, rs);
		}
		else if (opcode == "subci")
		{
			str >> rd >> constant;
			Assembler::subci(rd, constant);
		}
		else if (opcode == "and")
		{
			str >> rd >> rs;
			Assembler::sysand(rd, rs);
		}
		else if (opcode == "andi")
		{
			str >> rd >> constant;
			Assembler::andi(rd, constant);
		}
		else if (opcode == "xor")
		{
			str >> rd >> rs;
			Assembler::sysxor(rd, rs);
		}
		else if (opcode == "xori")
		{
			str >> rd >> constant;
			Assembler::xori(rd, constant);
		}
		else if (opcode == "compl")
		{
			str >> rd;
			Assembler::syscompl(rd);
		}
		else if (opcode == "shl")
		{
			str >> rd;
			Assembler::shl(rd);
		}
		else if (opcode == "shla")
		{
			str >> rd;
			Assembler::shla(rd);
		}
		else if (opcode == "shr")
		{
			str >> rd;
			Assembler::shr(rd);
		}
		else if (opcode == "shra")
		{
			str >> rd;
			Assembler::shra(rd);
		}
		else if (opcode == "compr")
		{
			str >> rd >> rs;
			Assembler::compr(rd, rs);
		}
		else if (opcode == "compri")
		{
			str >> rd >> constant;
			Assembler::compri(rd, constant);
		}
		else if (opcode == "getstat")
		{
			str >> rd;
			Assembler::getstat(rd);
		}
		else if (opcode == "putstat")
		{
			str >> rd;
			Assembler::putstat(rd);
		}
		else if (opcode == "jump")
		{
			str >> rd >> constant;
			Assembler::jump(rd, constant);
		}
		else if (opcode == "jumpl")
		{
			str >> rd >> constant;
			Assembler::jumpl(rd, constant);
		}
		else if (opcode == "jumpe")
		{
			str >> rd >> constant;
			Assembler::jumpe(rd, constant);
		}
		else if (opcode == "jumpg")
		{
			str >> rd >> constant; 
			Assembler::jumpg(rd, constant);
		}
		else if (opcode == "call")
		{
			str >> rd >> constant; 
			Assembler::call(rd, constant);
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
			Assembler::read(rd);
		}
		else if (opcode == "write")
		{
			str >> rd; 
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
		cout << opcode << " " << rd << " " << rs << " " << constant << endl;
		getline(assemblyProg, line);
	}

	vmIn.close();
	vmOut.close();
}

int VirtualMachine::rtClock(){
	return tick++;
}
void Assembler::load()
{
	r[q] = mem[w];
	OP = 0;
	i = 0;
	rtClock();
}
void Assembler::loadi()
{
	r[q] = w;
	OP = 0;
	i = 1;
	rtClock();
}
void Assembler::store()
{
	mem[w] = r[q];
	OP = 1;
	i = 1;
	rtClock();
}
void Assembler::add()
{
	r[q] = r[q] + r[w];
	OP = 2;
	i = 0;
	rtClock();
}
void Assembler::addi()
{
	r[q] = r[q] + w;
	OP = 2;
	i = 1; 
	rtClock();
}
void Assembler::addc()
{
	sr &= 1;
	r[q] = r[q] + r[w] + (sr & 1);
	OP = 3;
	i = 0;
	rtClock();
}
void Assembler::addci()
{
	sr &= 1;
	r[q] = r[w] + w + sr;
	OP = 3;
	i = 1;
	rtClock();
}
void Assembler::sub()
{
	r[q] = r[q] - r[w];
	OP = 4;
	i = 0;
	rtClock();
}
void Assembler::subi()
{
	r[q] = r[q] - w;
	OP = 4;
	i = 1;
	rtClock();
}
void Assembler::subc()
{	
	sr &= 1;
	r[q] = r[q] - r[w] - sr;
	OP = 5;
	i = 0;
	rtClock();
}
void Assembler::subci()
{	
	sr = sr & 1;
	r[q] = r[q] - w - sr;
	OP = 5;
	i = 1;
	rtClock();
}
void Assembler::sysand()
{
	r[q] = r[q] & r[w];
	OP = 6;
	i = 0;
	rtClock();
}
void Assembler::andi()
{
	r[q] = r[q] & w;
	OP = 6;
	i = 1;
	rtClock();
}
void Assembler::sysxor()
{
	r[q] = r[q] ^ r[w];
	OP = 7;
	i = 0;
	rtClock();
}
void Assembler::xori()
{
	r[q] = r[q] ^ w;
	OP = 7;
	i = 1;
	rtClock();
}
void Assembler::syscompl()
{
	r[q] = ~ r[q];
	OP = 8;
	rtClock();
}
void Assembler::shl()
{
	r[q] = r[q] << 1; //shift-in-bit = 0
	OP = 9;
	rtClock();
}
void Assembler::shla()
{
	OP = 10;
	//sign extention
	rtClock();
}
void Assembler::shr()
{
	r[q] = r[q] >> 1; //shift-in-bit = 0
	OP = 11;
	rtClock();
}
void Assembler::shra()
{
	OP = 12;
	//sign extention
	rtClock();
}
void Assembler::compr()
{
	OP = 13;
	i = 0;
	//not sure if I can import or modify the status register
	if (r[q] < r[w]) //set LESS reset EQUAL and GREATER;
	{
		sr & 0;
		sr & 8;
		rtClock();
	} 
	else if (r[q] == r[w]) //set EQUAL reset LESS and GREATER;
	{
		sr & 0;
		sr & 4;
		rtClock();
	}
	else if (r[q] > r[w]) //set GREATER reset EQUAL and LESS
	{
		sr & 0;
		sr & 2;
		rtClock();
	}
}
void Assembler::compri()
{
	OP = 13;
	i = 1;

	if (r[q] < w) //set LESS reset EQUAL and GREATER;
	{
		sr & 0;
		sr & 8;
		rtClock();
	} 
	else if (r[q] == w) //set EQUAL reset LESS and GREATER;
	{
		sr & 0;
		sr & 4;
		rtClock();
	} 
	else if (r[q] > w) //set GREATER reset EQUAL and LESS
	{
		sr & 0;
		sr & 2;
		rtClock();
	}
}
void Assembler::getstat()
{
	OP = 14;
	rtClock();
}
void Assembler::putstat()
{
	OP = 15;
	rtClock();
}
void Assembler::jump()
{
	OP = 16;
	i = 1;
	rtClock();
}
void Assembler::jumpl()
{
	OP = 17;
	i = 1;
	rtClock();
}
void Assembler::jumpe()
{
	OP = 18;
	i = 1;
	rtClock();
}
void Assembler::jumpg()
{
	OP = 19;
	i = 1;
	rtClock();
}
void Assembler::call()
{
	OP = 20;
	i = 1;
	rtClock();
}
void Assembler::sysreturn()
{
	OP = 21;
	rtClock();
}
void Assembler::read()
{
	OP = 22;
	rtClock();
}
void Assembler::write()
{	
	OP = 23;
	rtClock();
}
void Assembler::halt()
{
	OP = 24;
	throw std::exception();
	cout << tick;
}
void Assembler::noop()
{
	OP = 25;

}
