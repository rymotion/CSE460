//Assembler
//Ryan Paglinawan
#include "assembler.h"
#include "virtualmachine.h"

using namespace std;

typedef void (*FP) (string);

Assembler::Assembler()
{
	//I really don"t know what the fuck goes here
}

Assembler::translate(string OPc)
{
	string temp = OPc

		switch(temp){

		case "load":
			Assembler::load();
			break;

		case "loadi":
			Assembler::loadi();
			break;

		case "store":
			Assembler::store();
			break;

		case "add":
			Assembler::add();
			break;

		case "addi":
			Assembler::addi();
			break;

		case "addc":
			Assembler::addc();
			break;

		case "addci":
			Assembler::addci();
			break;

		case "sub":
			Assembler::sub();
			break;

		case "subi":
			Assembler::subi();
			break;

		case "subc":
			Assembler::subc();
			break;

		case "subci":
			Assembler::subci();
			break;

		case "and":
			Assembler::sysand();
			break;

		case "andi":
			Assembler::andi();
			break;

		case "xor":
			Assembler::sysxor();
			break;

		case "xori":
			Assembler::xori();
			break;

		case "compl":
			Assembler::syscompl();
			break;

		case "shl":
			Assembler::shl();
			break;

		case "shla":
			Assembler::shla();
			break;

		case "shr":
			Assembler::shr();
			break;

		case "shra":
			Assembler::shra();
			break;

		case "compr":
			Assembler::compr();
			break;

		case "compri":
			Assembler::compri();
			break;

		case "getstat":
			Assembler::getstat();
			break;

		case "putstat":
			Assembler::putstat();
			break;

		case "jump":
			Assembler::jump();
			break;

		case "jumpl":
			Assembler::jumpl();
			break;

		case "jumpe":
			Assembler::jumpe();
			break;

		case "jumpg":
			Assembler::jumpg();
			break;

		case "call":
			Assembler::call();
			break;

		case "return":
			Assembler::sysreturn();
			break;

		case "read":
			Assembler::read();
			break;

		case "write":
			write();
			break;

		case "halt":
			Assembler::halt();
			break;

		case "noop":
			Assembler::noop();
			break;

		}
}
int Assembler::assemble()
{
	string opcode;
	try{
		stdio::scanf()
		Assembler::translate(opcode);
	}

	catch{

	}
}
//opcode and their functions
void Assembler::load()
{

}
void Assembler::loadi()
{

}
void Assembler::store()
{

}
void Assembler::add()
{

}
void Assembler::addi()
{

}
void Assembler::addc()
{

}
void Assembler::addci()
{

}
void Assembler::sub()
{

}
void Assembler::subi()
{

}
void Assembler::subc()
{

}
void Assembler::subci()
{

}
void Assembler::sysand()
{

}
void Assembler::andi()
{

}
void Assembler::sysxor()
{

}
void Assembler::xori()
{

}
void Assembler::syscompl()
{

}
void Assembler::shl()
{

}
void Assembler::shla()
{

}
void Assembler::shr()
{

}
void Assembler::shra()
{

}
void Assembler::compr()
{

}
void Assembler::compri()
{

}
void Assembler::getstat()
{

}
void Assembler::putstat()
{

}
void Assembler::jump()
{

}
void Assembler::jumpl()
{

}
void Assembler::jumpe()
{

}
void Assembler::jumpg()
{

}
void Assembler::call()
{

}
void Assembler::sysreturn()
{

}
void Assembler::read()
{

}
void Assembler::write()
{

}
void Assembler::halt()
{

}
void Assembler::noop()
{

}