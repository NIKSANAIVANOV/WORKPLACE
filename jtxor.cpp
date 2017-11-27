#include <iostream>	//cin & cout
#include <fstream>	//ifstream and ostream	
#include <string>	//string class
#include <cstdlib>	//exit, system, strtol
using namespace std;
/*
xorcrypt.cpp by James Turk (cozman)
Wednesday January 9th, 2002 (11:56PM EST)
Program Uses C++ to Demonstrate A Fairly Strong XOR Encryption.
Includes EOF error checking and automatic detection of when it is unencrypting a file.
Program Is Documented Well And Also Makes Good Use of the Built In String Class.
Checked by Custom Syntax Checker To Conform to Current C++ Standard.
Submitted to codejournal@cprogramming.com for Contest. (jturk@conceptofzero.com)
Program Is Dedicated to The greatest girl ever, Julia I Love you!
Program Compiles Error and Warning Free:
	g++ -o xorcrypt.exe xorcrypt.cpp [-Wall] [-O2]
	[] flags are optional
*/
char xorcrypt(char ch, long key) //function to return a character XOR'ed by a long key
{
	return ch ^ key;	//return ch XOR'ed by key
}
void error(void) //function to output error message and terminate
{
	cout << endl << "Fatal Error Occured, try a different key for this file." << endl;
	exit(EXIT_FAILURE);
}
int main(int argc, char *argv[])
{
	ifstream inf;	//input file variable
	ofstream outf;	//output file variable
	unsigned loc;	//location in string used for searching
	string fn;		//string for filename
	long key;		//stores key for program
	char tmp;		//variable to hold character read from input file
	
	if(argc == 3)	//if two command line args were passed
	{
		fn = argv[1];					//parse first command line element as original filename
		key = strtol(argv[2],NULL,0);	//parse second command line element as long key		
		inf.open(fn.c_str());			//open input file
	}
	else
	{
		cout << endl << "Please Enter Encryption Key: ";	//prompt user for encryption key
		cin >> key;											//get key from cin
	}
	
	
	while(!inf.is_open()) //while either of the files isn't properly open
	{
		cout << endl << "Please Enter Valid Filename To xOr-Crypt: ";	//prompt user for a filename
		cin >> fn;				//take fn_orig from cin
		inf.open(fn.c_str());	//open input file
	}
	
	loc = fn.find(".enc");		//check if file already contains .enc extension
	if(loc != string::npos)		//if it is found--
	{
		fn.replace(loc,4,".orig");	// --replace last .enc with .orig
	}
	else
	{
		fn += ".enc";				//encrypted name is same as original plus .enc
	}
	outf.open(fn.c_str());			//open output file
	
	while(inf) //while input file hasn't reached EOF
	{
		inf.get(tmp); 	//get the next character
		if(inf)			//if file is still not at EOF
		{
			if(xorcrypt(tmp,key) != EOF)		//as long as the char encrypted by the key isn't illegal
			{
				outf.put(xorcrypt(tmp,key));	//place encrypted char into output file
			}
			else
			{
				inf.close();		//close input file
				outf.close();		//close output file
				fn = "del " + fn;	//add "del " to beginning of current filename
				system(fn.c_str());	//execute delete command
				error(); 			//report error and exit
			}
		}
	}
	
	inf.close();	//close input file
	outf.close();	//close output file
	
	return 0;
}