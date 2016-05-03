## operating system, assembler, and virtual machine makefile
os: assembler.o virtualmachine.o
	c++ os.0 assembler.o virtualmachine.o -o os -v
assembler.o: assembler.cpp
	c++ -c assembler.cpp -v
virtualmachine.o: virtualmachine.cpp
	c++ -c virtualmachine.cpp -v
os.o: os.cpp
	c++ -c os.cpp -v