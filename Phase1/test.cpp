//test.cpp
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <map>
#include <bitset>
#include <iostream>

 using namespace std;

int main()
 {
 	int i = 0b00000;
 	int y = 0b00001;
 	int t = 0b00010;
 	int v = 0b00011;
 	int x = 0b00100;
    int final;
    
     final = i;
     final = (final << 5)|y;
     final = (final << 5)|t;
     final = (final << 5)|v;
     final = (final << 5)|x;
     cout << final << endl;
 	/*cout << i << endl;
 	cout << i + y << endl;
 	cout << i + y + t + v + x << endl;
    cout << i << i+y << i + y + t + v + x << endl;*/
 	cout << "test code ran" << endl;
 	return 0;
 }