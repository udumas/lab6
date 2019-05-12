//***************************************************
// Program: lab6.cpp
// Author: Joel Salisbury
// Date:    April 1, 2014
// Lab: #6
// Description: simple prefix calculator reads from file 
// and writes to standard output.
// expects to find values of the form operator Operand Operand
//
//***************************************************
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <math.h>
using namespace std;

const int ARRAY_SIZE=80; //default location for Arrays
const double PI=3.14159; 


// Precondition: char[] containing values separated by spaces
//               reference to integer represents the current location in the character []
//  PostCondition: reference to integer points to location of next location containing unparsed data
void read_and_clean(char line[], int& location);



// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is represented by a string of values in the character array.
double str2dbl(char[], int&);

// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of subtracting  numeric values included in the char[]
double subt(char[], int&);


// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of adding  numeric values included in the char[]
double add(char line[], int& location);


// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of mutiplying together numeric values included in the char[]
double mult(char[], int&);

// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of dividing first numeric value from second numeric value
// included in the char[]
double div(char[], int&);


// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of taking modulo of first numeric value by the second numeric value
// included in the char[]
int mod(char[], int&);

// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of cosine of the conversion to radians of the 
// degree value found in the char[]
double getCos(char[], int&);

// precondition: receives a character representing a set of print formating parameters to be implemented
// if e sets to print out values in scientific notation.
// if f returns values using decimal approximations to two decimal places
void mod2prn(char);

// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of tangent of the conversion to radians of the 
// degree value found in the char[]
double getTan(char[], int&);

// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of sine of the conversion to radians of the 
// degree value found in the char[]
double getSin(char[],int&);

// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of raising the first numeric value to the power of 
// the second numeric valuefound in the char[]
double getPower(char[], int&);


int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout.setf(ios::left);
	char line[ARRAY_SIZE];
    char next;
    double expression_value;
    ifstream fin("pfn.txt"); // setup file input stream 
    while(!fin.eof()) //while there is text in the file
    {
    fin.getline(line,ARRAY_SIZE); // get the next line from the file stream
                                  // storing the value into char[] line of location ARRAY_SIZE
    
	int location=0; // set location in array to 0
	read_and_clean(line, location); // send array to read_and_clean to move location to the location of the first character
    next=line[location]; // set character to character the array index is pointing to
    location++;         //increment index
    
    while(next!='\0') // do until end of char[]
    {
   int count=0;
   count++;

        next = tolower(next); 
        switch(next) // determines value located at next and performs associated task
        {
            case '-':
                if (isdigit(line[location]))
                {
                    str2dbl(line, location);
                }else{
                    expression_value=subt(line, location);
                    // cout << line << " = "
                    cout << expression_value << "\n";     
                }
            break;
            case '+':
                expression_value=add(line,location);
                //cout << line << " = " 
                cout << expression_value << "\n";
                break;

            case '/':
                expression_value=div(line,location);
                if(expression_value!=(-0))
                cout << expression_value << "\n";
                else 
                    cout << "\n";
                break;
            case '%':
                expression_value=mod(line,location);
                // cout << line << " = " << 
                cout << expression_value << "\n";
 
                break;
            case  's':
                expression_value=getSin(line, location);
                //cout << line << " = " << 
                cout << expression_value << "\n";

                break;
            case 't':
                expression_value=getTan(line,location);
                //cout << line << " = " 
                cout << expression_value << "\n";
                break;
            case 'c':
                expression_value = getCos(line,location);
                //cout << line << " = " 
                cout << expression_value << "\n";
                break;
            case '^':
                expression_value = getPower(line,location);
                //cout << line << " = " 
                cout << expression_value << "\n";

            case 'f':

            case 'e':
                mod2prn(next);
            break;
            case '.':
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                str2dbl(line, location);
            break;
        }
    location++;
    next=line[location]; //reset value of next to be the current index
    }
    }
	fin.close(); // close file
    return 0;
}

// Precondition: char[] containing values separated by spaces
//               reference to integer represents the current location in the character []
//  PostCondition: reference to integer points to location of next location containing unparsed data
void read_and_clean(char line[],int &location)
{
	char next=line[location];
	while(isspace(line[location]))
    {
        location++;
    }
	
}

	// Precondition: char[] containing values separated by spaces
//               reference to integer represents the current location in the character []
//  PostCondition: reference to integer points to location of next location containing unparsed data	
double str2dbl(char line[], int& location)
{
	
	int index;
	char digit_string[ARRAY_SIZE];
	char next=line[location];
	double returnValue_str2dbl;
	char nullVal= '\0';
    
	index=0;
    if(isspace(next))
    {
        read_and_clean(line, location);
    }
    next=line[location];
	while(isdigit(next)||next=='.')
    {   
        digit_string[index]=next;
        index++;
        location++;
        next=line[location];
    }
    digit_string[index]=nullVal;
    returnValue_str2dbl = atof(digit_string);
    location++;

    return returnValue_str2dbl;
    
}

// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of adding numeric values included in the char[]
double add(char line[], int& location)
{
    double operand1;
    double operand2;
    double returnvalue_add;
    operand1=str2dbl(line,location);
    operand2=str2dbl(line,location);
    returnvalue_add=operand1+operand2;
    cout << " + " << operand1 << " " << operand2 << " = ";
    // <<returnvalue_add << "\n";
    return returnvalue_add;
}

// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of subtracting  numeric values included in the char[]
double subt(char line[], int& location)
{
    double operand1;
    double operand2;
    double returnvalue_subtract;
    operand1=str2dbl(line,location);
    operand2=str2dbl(line,location);
    returnvalue_subtract=operand1-operand2;
    cout << " - " << operand1 << " " << operand2 << " = ";
    // <<returnvalue_subtract << "\n";
    return returnvalue_subtract;
}

// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of multiplying  numeric values included in the char[]
double mult(char line[], int& location)
{
    double operand1;
    double operand2;
    double returnvalue_mult;
    operand1=str2dbl(line,location);
    operand2=str2dbl(line,location);
    returnvalue_mult=operand1*operand2;
    cout  << " * " << operand1 << " " << operand2 << " = ";
    // <<returnvalue_mult << "\n";
    return returnvalue_mult;
}
// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of dividing first numeric value from second numeric value
// included in the char[]
double div(char line[], int& location)
{
    double operand1;
    double operand2;
    double returnvalue_div;
    operand1=str2dbl(line,location);
    operand2=str2dbl(line,location);
    if(operand2!=0)
        returnvalue_div=operand1/operand2;
    else{
        returnvalue_div= -0;
        cout << "Error cannot divide by 0\n";
    }
        cout << " / " << operand1 << " " << operand2 << " = "; 
        //<<returnvalue_div << "\n";
    return returnvalue_div;
}
// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of taking the modulo of the first numeric value by the 
// second numeric value
// included in the char[]
int mod(char line[], int& location)
{	
    double operand1;
    double operand2;
    double returnvalue_mod;
    operand1=floor(str2dbl(line,location)+.5);
    operand2=floor(str2dbl(line,location)+.5);
    returnvalue_mod=(int)operand1%(int)operand2;
    cout << " % " << (int)operand1 << " " << (int)operand2 << " = "; 
    //<<returnvalue_mod << "\n";
    return returnvalue_mod;
}


// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of cosine of the conversion to radians of the 
// degree value found in the char[]
double getCos(char line[],int& location)
{
    double operand;
    double radOperand;
    double returnValueCos;
    operand=str2dbl(line,location);
    radOperand=operand*(PI/180);
    returnValueCos = cos(radOperand);
    cout << " C " << operand << " = "; 
    //<< returnValueCos;

    return returnValueCos;
}



// precondition: receives a character representing a set of print formating parameters to be implemented
// if e sets to print out values in scientific notation.
// if f returns values using decimal approximations to two decimal places
void mod2prn(char next)
{
    switch(next)
  {
      case 'f': 
          cout.unsetf(ios::scientific);
          cout.setf(ios::fixed);
          cout.setf(ios::showpoint);
          cout.precision(2);
          cout.setf(ios::left);
          cout << "F\n";
          break;
      case 'e':
          cout.unsetf(ios::fixed); 
          cout.setf(ios::scientific);
          //cout.setf(ios::uppercase);
          //cout.setf(ios::showpoint);
          //cout.precision(2);
          cout.setf(ios::left);
          cout << "E\n";
          break;


      default:  break;
  }
}


// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of tangent of the conversion to radians of the 
// degree value found in the char[]
double getTan(char line[], int& location)
{
    double operand;
    double radOperand;
    double returnValueTan;
    operand=str2dbl(line,location);
    radOperand=operand*(PI/180);
    returnValueTan = tan(radOperand); 
    cout << " T " << operand << " = ";    
    return returnValueTan;
}


// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of sine of the conversion to radians of the 
// degree value found in the char[]
double getSin(char line[], int& location)
{
    double operand;
    double radOperand;
    double returnValueSin;
    operand=str2dbl(line,location);
    radOperand=operand*(PI/180);
    returnValueSin = sin(radOperand);
    cout << " S " << operand << " = "; 
    return returnValueSin;

}


// Precondition: char[] containing numeric data
//               reference to int points to first location of unparsed numeric or character values. 0-9, - or .
// PostCondition: returns a double that is the result of raising the first numeric value to the power of 
// the second numeric valuefound in the char[]
double getPower(char line[],int& location)
{
    double operand1;
    double operand2;
    double returnvalue_pow;
    operand1=str2dbl(line,location);
    operand2=str2dbl(line,location);
    returnvalue_pow=pow(operand1,operand2);
    cout << " ^ " << operand1 << " " << operand2 << " = ";
    // <<returnvalue_pow << "\n";
    return returnvalue_pow;
}
