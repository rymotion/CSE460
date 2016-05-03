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
#include <sstream>

using namespace std;

instruction ins;

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
	return tick;
}

int VirtualMachine::fetch(){
	// I don't know what this means
	ins = mem[pc++];
}

int VirtualMachine::run(fstream& inObj, fstream& outObj){
	mem.pushback();
	string line, opcode;
	int rd, rs, constant, i;
	fstream vmIn;
	fstream vmOut;
	outObj[] = "out.out" 
	vmIn.open(inObj, ios::in);
	vmOut.open(outObj, ios::out);
	if (!inObj || !outObj) {
		cout << "Your .s failed to open.\n";
		exit(1);
	}

	while (!vmIn.eof()) {
		rd=-1; rs=-1; constant=-129; // init to invalid values

		// break apart the binary string
		istringstream str(line.str());
		opcode = (opcode << 5) | str;
		rd = (rd << 2) | str;
		i = (i << 1) | str;
		rs = (rs << 2) | str;
		constant = (constant << 6) | str;
		// the following line is the trick
		if (opcode == 0b00000 && i == 0b0)
		{
			constant = (constant << 8) | str;
			VirtualMachine::load(rd, constant);
		}
		else if (opcode == 0b00000 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::loadi(rd, constant);
		}
		else if (opcode == 0b00001 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::store(rd, constant);
		}
		else if (opcode == 0b00010 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::add(rd, rs);
		}
		else if (opcode == 0b00010 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::addi(rd, constant);
		}
		else if (opcode == 0b00011 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::addc(rd, rs);
		}
		else if (opcode == 0b00011 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::addci(rd, constant);
		}
		else if (opcode == 0b00100 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::sub(rd, rs);
		}
		else if (opcode == 0b00100 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::subi(rd, constant);
		}
		else if (opcode == 0b00101 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::subc(rd, rs);
		}
		else if (opcode == 0b00101 && i == 0b1)
		{
			rs = (rs << 2) | str;
			constant = (constant << 8) | str;
			VirtualMachine::subci(rd, constant);
		}
		else if (opcode == 0b00110 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::sysand(rd, rs);
		}
		else if (opcode == 0b00110 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::andi(rd, constant);
		}
		else if (opcode == 0b00111 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::sysxor(rd, rs);
		}
		else if (opcode == 0b00111 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::xori(rd, constant);
		}
		else if (opcode == 0b01000 && i == 0b0)
		{
			
			VirtualMachine::syscompl(rd);
		}
		else if (opcode == 0b01001 && i == 0b0)
		{
			
			VirtualMachine::shl(rd);
		}
		else if (opcode == 0b01010 && i == 0b0)
		{
			
			VirtualMachine::shla(rd);
		}
		else if (opcode == 0b01011 && i == 0b0)
		{
			
			VirtualMachine::shr(rd);
		}
		else if (opcode == 0b01100 && i == 0b0)
		{
			
			VirtualMachine::shra(rd);
		}
		else if (opcode == 0b01101 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::compr(rd, rs);
		}
		else if (opcode == 0b01101 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::compri(rd, constant);
		}
		else if (opcode == 0b01110 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::getstat(rd, rs);
		}
		else if (opcode == 0b01111 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::putstat(rd, rs);
		}
		else if (opcode == 0b10000 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::jump(rd, constant);
		}
		else if (opcode == 0b10001 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::jumpl(rd, constant);
		}
		else if (opcode == 0b10010 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::jumpe(rd, constant);
		}
		else if (opcode == 0b10011 && i == 0b1)
		{
			constant = (constant << 8) | str; 
			VirtualMachine::jumpg(rd, constant);
		}
		else if (opcode == 0b10100 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::call(rd, constant);
		}
		else if (opcode == 0b10101 && i == 0b0)
		{
			//should pop and restore VM status
			//str >> >>; 
			VirtualMachine::sysreturn();
		}
		else if (opcode == 0b10110 && i == 0b0)
		{
			 
			VirtualMachine::read(rd);
		}
		else if (opcode == 0b10111 && i == 0b0)
		{
			 
			VirtualMachine::write(rd);
		}
		else if (opcode == 0b11000 && i == 0b0)
		{
			VirtualMachine::halt();
			//execute halt
		}
		else if (opcode == 0b11001 && i == 0b0)
		{
			VirtualMachine::noop();
		}
	}
}	

void VirtualMachine::decode(){
	string line;
	int opcode, rd, rs, constant, i;
	/*
	fstream vmIn;
	fstream vmOut;
	outObj[] = "out.out" 
	vmIn.open(inObj, ios::in);
	vmOut.open(outObj, ios::out);
	if (!inObj || !outObj) {
		cout << "Your .s failed to open.\n";
		exit(1);
	}
	*/

	getline(vmIn, line);
	while (!vmIn.eof()) {
		rd=-1; rs=-1; constant=-129; // init to invalid values

		// break apart the binary string
		istringstream str(line.str());
		opcode = (opcode << 5) | str;
		rd = (rd << 2) | str;
		i = (i << 1) | str;
		rs = (rs << 2) | str;
		constant = (constant << 6) | str;
		// the following line is the trick
		if (opcode == 0b00000 && i == 0b0)
		{
			constant = (constant << 8) | str;
			VirtualMachine::load(rd, constant);
		}
		else if (opcode == 0b00000 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::loadi(rd, constant);
		}
		else if (opcode == 0b00001 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::store(rd, constant);
		}
		else if (opcode == 0b00010 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::add(rd, rs);
		}
		else if (opcode == 0b00010 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::addi(rd, constant);
		}
		else if (opcode == 0b00011 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::addc(rd, rs);
		}
		else if (opcode == 0b00011 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::addci(rd, constant);
		}
		else if (opcode == 0b00100 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::sub(rd, rs);
		}
		else if (opcode == 0b00100 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::subi(rd, constant);
		}
		else if (opcode == 0b00101 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::subc(rd, rs);
		}
		else if (opcode == 0b00101 && i == 0b1)
		{
			rs = (rs << 2) | str;
			constant = (constant << 8) | str;
			VirtualMachine::subci(rd, constant);
		}
		else if (opcode == 0b00110 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::sysand(rd, rs);
		}
		else if (opcode == 0b00110 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::andi(rd, constant);
		}
		else if (opcode == 0b00111 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::sysxor(rd, rs);
		}
		else if (opcode == 0b00111 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::xori(rd, constant);
		}
		else if (opcode == 0b01000 && i == 0b0)
		{
			
			VirtualMachine::syscompl(rd);
		}
		else if (opcode == 0b01001 && i == 0b0)
		{
			
			VirtualMachine::shl(rd);
		}
		else if (opcode == 0b01010 && i == 0b0)
		{
			
			VirtualMachine::shla(rd);
		}
		else if (opcode == 0b01011 && i == 0b0)
		{
			
			VirtualMachine::shr(rd);
		}
		else if (opcode == 0b01100 && i == 0b0)
		{
			
			VirtualMachine::shra(rd);
		}
		else if (opcode == 0b01101 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::compr(rd, rs);
		}
		else if (opcode == 0b01101 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::compri(rd, constant);
		}
		else if (opcode == 0b01110 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::getstat(rd, rs);
		}
		else if (opcode == 0b01111 && i == 0b0)
		{
			rs = (rs << 2) | str;
			VirtualMachine::putstat(rd, rs);
		}
		else if (opcode == 0b10000 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::jump(rd, constant);
		}
		else if (opcode == 0b10001 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::jumpl(rd, constant);
		}
		else if (opcode == 0b10010 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::jumpe(rd, constant);
		}
		else if (opcode == 0b10011 && i == 0b1)
		{
			constant = (constant << 8) | str; 
			VirtualMachine::jumpg(rd, constant);
		}
		else if (opcode == 0b10100 && i == 0b1)
		{
			constant = (constant << 8) | str;
			VirtualMachine::call(rd, constant);
		}
		else if (opcode == 0b10101 && i == 0b0)
		{
			//should pop and restore VM status
			//str >> >>; 
			VirtualMachine::sysreturn();
		}
		else if (opcode == 0b10110 && i == 0b0)
		{
			 
			VirtualMachine::read(rd);
		}
		else if (opcode == 0b10111 && i == 0b0)
		{
			 
			VirtualMachine::write(rd);
		}
		else if (opcode == 0b11000 && i == 0b0)
		{
			VirtualMachine::halt();
			//execute halt
		}
		else if (opcode == 0b11001 && i == 0b0)
		{
			VirtualMachine::noop();
		}

		//this last line will put the results into the output file
		
		getline(vmIn, line);
	}
}

int VirtualMachine::rtClock(){
	return tick++;
}
void VirtualMachine::load(int rd, int constant)
{
	r[q] = mem[w];
	rtClock();
}
void VirtualMachine::loadi(int rd, int constant)
{
	r[q] = w;
	rtClock();
}
void VirtualMachine::store(int rd, int constant)
{
	mem[w] = r[q];
	rtClock();
}
void VirtualMachine::add(int rd, int rs)
{
	r[q] = r[q] + r[w];
	rtClock();
}
void VirtualMachine::addi(int rd, int constant)
{
	r[q] = r[q] + w;
	rtClock();
}
void VirtualMachine::addc(int rd, int rs)
{
	sr &= 1;
	r[q] = r[q] + r[w] + (sr & 1);
	rtClock();
}
void VirtualMachine::addci(int rd, int constant)
{
	sr &= 1;
	r[q] = r[w] + w + sr;
	rtClock();
}
void VirtualMachine::sub(int rd, int rs)
{
	r[q] = r[q] - r[w];
	rtClock();
}
void VirtualMachine::subi(int rd, int constant)
{
	r[q] = r[q] - w;
	rtClock();
}
void VirtualMachine::subc(int rd, int rs)
{	
	sr &= 1;
	r[q] = r[q] - r[w] - sr;
	rtClock();
}
void VirtualMachine::subci(int rd, int constant)
{	
	sr = sr & 1;
	r[q] = r[q] - w - sr;
	rtClock();
}
void VirtualMachine::sysand(int rd, int rs)
{
	r[q] = r[q] & r[w];
	rtClock();
}
void VirtualMachine::andi(int rd, int constant)
{
	r[q] = r[q] & w;
	rtClock();
}
void VirtualMachine::sysxor(int rd, int rs)
{
	r[q] = r[q] ^ r[w];
	rtClock();
}
void VirtualMachine::xori(int rd, int constant)
{
	r[q] = r[q] ^ w;
	rtClock();
}
void VirtualMachine::syscompl(int rd)
{
	r[q] = ~ r[q];
	rtClock();
}
void VirtualMachine::shl(int rd)
{
	r[q] = r[q] << 1; //shift-in-bit = 0
	rtClock();
}
void VirtualMachine::shla(int rd)
{
	//sign extention
	rtClock();
}
void VirtualMachine::shr(int rd)
{
	r[q] = r[q] >> 1; //shift-in-bit = 0
	rtClock();
}
void VirtualMachine::shra(int rd)
{
	//sign extention
	rtClock();
}
void VirtualMachine::compr(int rd, int rs)
{
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
void VirtualMachine::compri(int rd, int constant)
{

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
void VirtualMachine::getstat(int rd, int rs)
{
	rtClock();
}
void VirtualMachine::putstat(int rd, int rs)
{
	rtClock();
}
void VirtualMachine::jump(int rd, int constant)
{
	rtClock();
}
void VirtualMachine::jumpl(int rd, int constant)
{
	rtClock();
}
void VirtualMachine::jumpe(int rd, int constant)
{
	rtClock();
}
void VirtualMachine::jumpg(int rd, int constant)
{
	rtClock();
}
void VirtualMachine::call(int rd, int constant)
{
	rtClock();
}
void VirtualMachine::sysreturn()
{
	rtClock();
}
void VirtualMachine::read(int rd)
{
	rtClock();
}
void VirtualMachine::write(int rd)
{	
	rtClock();
}
void VirtualMachine::halt()
{
	cout << "halt called stopping program." << endl;
}
void VirtualMachine::noop()
{
	cout << "noop called nothing has been done." << endl;
}
