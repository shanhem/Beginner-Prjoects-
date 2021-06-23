//
//  main.cpp
//  Comp systems encode c++
//
//  Created by Shannen on 15/01/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;




string decto_bin(int dec_number)
{
    
    
    string binaryOutput="";
   
    //while number is greater than 0, we keep dividing by 2
    while (dec_number>0)
    {
        //gets the remainder using %
        int remainder=dec_number % 2;
        
        //divides the number by 2
        dec_number=dec_number/2;
        
        binaryOutput=binaryOutput+ to_string(remainder);
}
    reverse(binaryOutput.begin(), binaryOutput.end());
    
    
    return binaryOutput;
}


    


    string binToHex_1(string binaryOutput)
    {

   //multiple of 4
        while ((binaryOutput.length() % 4) != 0) {

        binaryOutput = "0" + binaryOutput;

    }

        string hexOutput = "";

    //convert to hexadecimal.

        int index = 0;
    
        while (index + 3 < binaryOutput.length()) {

        string fourDigits = binaryOutput.substr(index, 4);


        if (fourDigits == "0000") {
            hexOutput = hexOutput + "0";
        }
        else if (fourDigits == "0001")
        {
            hexOutput = hexOutput + "1";
        }
        else if (fourDigits == "0010")
        {
            hexOutput = hexOutput + "2";
        }
        else if (fourDigits == "0011")
        {
            hexOutput = hexOutput + "3";
        }
        else if (fourDigits=="0100")
        {
            hexOutput = hexOutput + "4";
        }
        else if (fourDigits == "0101")
        {
            hexOutput = hexOutput + "5";
        }
        else if (fourDigits == "0110")
        {
            hexOutput = hexOutput + "6";
        }
        else if (fourDigits == "0111")
        {
            hexOutput = hexOutput + "7";
        }
        else if (fourDigits == "1000")
        {
            hexOutput = hexOutput + "8";
        }
        else if (fourDigits == "1001")
        {
            hexOutput = hexOutput + "9";
        }
        else if (fourDigits == "1010")
        {
            hexOutput = hexOutput + "A";
        }
        else if (fourDigits == "1011")
        {
            hexOutput = hexOutput + "B";
        }
        else if (fourDigits == "1100")
        {
            hexOutput = hexOutput + "C";
        }
        else if (fourDigits == "1101")
        {
            hexOutput = hexOutput + "D";
        }
        else if (fourDigits == "1110")
        {
            hexOutput = hexOutput + "E";
        }
        else if (fourDigits == "1111")
        {
            hexOutput = hexOutput + "F";
        }
        index = index + 4;
    }
    return hexOutput;
}

string endianConversion(string conversion)
{
    string firstInput = "";
    firstInput += conversion[2]; firstInput += conversion[3];
    firstInput += conversion[0]; firstInput += conversion[1];

    return firstInput;
}


int main()
{
    //ask the user for a command
    cout<<"Please enter your assembly command followed by two numbers"<<endl;
    cout<<"Seperate the destination and the source with spaces example, Add A, 2 "<<endl;
    cout<<"When entering any addresses that are hex do not include the H at the end as the program will not recognise the input"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
    
    //get the user from the user
    string userInput;
    getline(cin,userInput);
    
    //we can now look for the space
    int spaceLocation = userInput.find(" ");
    
    //get first command (add,devide etc)
    string opcode = userInput.substr(0,spaceLocation);
    
    //now we need the 2 numbers this will collect both of them into the string.
    string Src_Dest=userInput.substr(spaceLocation +1,userInput.length());
    string Src_Dest_2=userInput.substr(spaceLocation +1,userInput.length());
    
    //we need to split the two numbers with the second space
    spaceLocation=Src_Dest.find(", ");
    spaceLocation=Src_Dest_2.find(", ");
    
    //got the two arguments
    string Destination=Src_Dest.substr(0,spaceLocation);
    string Source=Src_Dest.substr(spaceLocation + 2, Src_Dest.length());
 
    
   
    
  
    
    
 
    
    string instruction;
    string op_output="";
    string sour_output="";
    string dest_output="";
  
    //-------------------------------------------------------------------------------------------------------------------------------------
    
    if(opcode.compare("ADD")==0)
    {
        op_output+="00";
    }

    else if (opcode.compare("MOVE")==0 || opcode.compare("STORE")==0 || opcode.compare("LOAD")==0 )
    {
        op_output+="01";
    }
    
    else if(opcode.compare("JMP")==0||opcode.compare("JPP")==0||opcode.compare("JPN")||opcode.compare("JPZ")==0)
    {
       op_output+="10";
    }
    
 
    //-------------------------------------------------------------------------------------------------------------------------------------
    
    int Dest_H = 0;
    
    
    if (Destination.compare("A")==0)
    {
        dest_output+="000";
    }
    else if (Destination.compare("B")==0) {
        dest_output+="001";
    }
    else if (Destination.compare("C")==0) {
        dest_output+="010";
    }
    else if (Destination.compare("D")==0) {
        dest_output+="011";
    }
    else if (Destination.compare("E")==0) {
        dest_output+="100";
    }
    
    //If the destination is a hexidecimal address
    
    if (Destination.compare("A") !=0 && Destination.compare("B") !=0 && Destination.compare("C") !=0 && Destination.compare("D") !=0 && Destination.compare("E") !=0)
    {
       Dest_H=stoi(Src_Dest_2.substr(0,spaceLocation));
    }

    if (opcode.compare("STORE")==0 && Dest_H>0)
    {
        dest_output+="110";
        
    }
    
    //-------------------------------------------------------------------------------------------------------------------------------------


    
    //if the source is a letter
    if (Source.compare("A")==0)
    {
        sour_output+="000";
       
    }
    else if (Source.compare("B")==0)
    {
        
        sour_output+="001";
    }
    else if (Source.compare("C")==0)
    {
        
        sour_output+="010";
    }
    else if (Source.compare("D")==0)
    {
        
        sour_output+="011";
    }
    else if (Source.compare("E")==0)
    {
        
        sour_output+="100";
    }
    
    //if the source is a number then values are 101
   
    int Source_101 = 0;
    
    if (Source.compare("A") !=0 && Source.compare("B") !=0 && Source.compare("C") !=0 && Source.compare("D") !=0 && Source.compare("E") !=0)
    {
        Source_101=stoi(Src_Dest_2.substr(spaceLocation + 2, Src_Dest.length()));
    }
    
    
        
    if ((opcode.compare("ADD")==0 && Source_101>0) || (opcode.compare("MOVE")==0 && Source_101>0))
        {
        
            sour_output+="101";
            
        }

    else if((opcode.compare("JMP")==0 && Source_101>0) || (opcode.compare("JPZ")==0 && Source_101>0) ||(opcode.compare("JPN")==0 && Source_101>0) ||(opcode.compare("JPP")==0 && Source_101>0))
            {
            
                sour_output+="101";
                
            }
        
        
    else if (opcode.compare("LOAD")==0 && Source_101>0)
    {
        sour_output+="110";
        
    }
    
   else if (opcode.compare("STORE")==0 && Source_101>0)
    {
        sour_output+="110";
        
    }
        
   
    
    //PRINTING OUT DETAILS
    //-------------------------------------------------------------------------------------------------------------------------------------
    
    
    instruction=op_output+dest_output+sour_output;
    string extension_101;
    string instruction_bin = binToHex_1(instruction);
    
    
    
    
    cout << "Instruction: " << instruction<<" "<<"in Hex: "<<instruction_bin<<endl;
    
    
    
    
    //THIS WILL PRINT OUT THE DETAILS FOR A SOURCE
        if ((opcode.compare("ADD")==0 && Source_101>0) || (opcode.compare("MOVE")==0 && Source_101>0))
        {
            
            extension_101=decto_bin(Source_101);
            cout<<extension_101<< "(" << Source_101 << ")" << endl;
            instruction = binToHex_1(instruction);
            cout <<"Instruction in Hexadecimal: "<< instruction<<endl;
            cout<<"Extension in Hex: ";
            string exten_hex=binToHex_1(extension_101);
            cout<<exten_hex<< "(" << extension_101 << ")";
        }
    
    
    //This will print LOAD!
     if (opcode.compare("LOAD")==0 && Source_101>0)
    {
        
        extension_101=decto_bin(Source_101);
        cout<< Source_101<< endl;
        instruction = binToHex_1(instruction);
        string str=to_string(Source_101);
        str=endianConversion(str);
        cout <<"Instruction in Hexadecimal: "<<instruction<<str<<endl;
            
    }
        
    
    //This is to print out the details of STORE!
        else if(Dest_H>0)
        {
            
            cout<< "(" << Dest_H << ")" << endl;
            instruction = binToHex_1(instruction);
            string d_st=to_string(Dest_H);
            d_st=endianConversion(d_st);
            cout <<"Instruction in Hexadecimal: "<<instruction<<d_st<<endl;
            cout<<"Extension in Hex: ";
            cout<<d_st;
          
        }
    
       
            
        

    







}
    








