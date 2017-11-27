/*
XOR.cpp
Matthew Costuros
snoborder420@yahoo.com
AIM: Rpi Matty
Proper usage is XOR.exe filename Key
Encrypt the file with a key 324
XOR.exe plain.txt 324
Decrypt that file
XOR.exe plain.enc  324
Encrypt a top secret file
XOR.exe keepsafe.txt 56765
Decrypt that secret file
XOR.exe keepsafe.end 56765
*/
#include <iostream.h>
#include <string.h>
#include <stdio.h>
int XOR(char * filename, unsigned long key);
int main(int argv, char ** argc)
{
	unsigned long key;
	char filename[100];
	//if they used command line arguments pass the filename and key to xor function
	if( argv == 3)
	{
		if( XOR(argc[1],(unsigned int)atol(argc[2]) ) )
		{
			cout << "There was an error trying to encrypt/decrypt the file " <<  argc[1] << endl;
		}
	}
	//other wise prompt for the key and filename
	else
	{
		cout << "What is the filename?" << endl;
		cin.getline(filename,99,'\n');
	
		cout << "What is the key?" << endl;
		cin >> key;
		
		//tell the user about command line then call xor function
		cout << "Next time you can use the command line, the format is " << argc[0] << " filename key" << endl;
		if( XOR(filename,key) )
		{
			cout << "There was an error trying encrypt/decrpyt the file " << filename << endl;
		}
	}
	return 0;
}
int XOR(char * filename, unsigned long key)
{
	FILE * input = NULL , *output = NULL;
	char * outfilename = NULL;
	int len = strlen(filename);
	unsigned char buffer;
	if( (filename[len-4] == '.') && (filename[len-3] == 'e') && (filename[len-2] == 'n') && (filename[len-1] == 'c') )
	{
		// our input file is encoded then we will create a file without the .end extension
		outfilename = new char[len+1]; //make room for the name+\0
		strcpy(outfilename,filename); //copy the string name
		outfilename[len-4] = '\0'; //put the \0 before the .enc extension to cut it off
	}
	else
	{
		outfilename = new char[len+5]; //make room for the name + .enc + \0
		strcpy(outfilename,filename); //copy the file name
		strncat(outfilename,".enc",4); //add the .enc extension
	}
	input =	fopen(filename,"rb");
	if( input == NULL)
	{
		cout << "Error opening file " << filename << endl;
		delete [] outfilename; //free the memory before leaving
		outfilename = NULL;
		return 1;
	}
	
	output = fopen(outfilename,"wb");
	if( output == NULL )
	{
		cout << "Error creating output file " << outfilename << endl;
		delete [] outfilename; //free the mem before leaving
		outfilename = NULL;
		return 1;
	}
	while( ! feof(input) )
	{
		//get some data
		if( fread(&buffer,sizeof(unsigned char),1,input) != 1 )
		{
			//if we didnt get any data, but we are not at the eof, then an error has occured
			if( ! feof(input) )
			{
				delete [] outfilename;
				outfilename = NULL;
				fclose(input);
				fclose(output);
				
				return 1;
			}
		}
		else
		{
			//xor that data
			buffer ^= key; 
		
			//write some data
			fwrite(&buffer,sizeof(unsigned char),1,output);
		}
	}
	//close the files and free that memory
	fclose(input);
	fclose(output);
	delete [] outfilename;
	return 0;
}
