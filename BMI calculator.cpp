//
//  main.cpp
//  bmi calculator
//
//  Created by Shannen on 19/02/2021.
//

//
//  main.cpp
//  BMI CALCULATOR
//
//  Created by Shannen Hemrom- 30023338.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;

class BMI
{

    
public:
    
    double initial_weight;
    double height;
    float final_BMI;
    
    //Ask the user for client BMI details
    void Add_Client()
    {
        cout<<"Please enter your initial weight(kilograms):"<<endl;
        cin>>initial_weight;
        cout<<"Please enter your height(meters): "<<endl;
        cin>>height;
        
        
    }
    
    
    //function to calculate the client BMI
   void CalculateBMI()
    {
         final_BMI=initial_weight/(height*height);
    
        
    }
    
    void displayclass()
    {
        if (final_BMI<=18.5)
        {
            cout<<"Classification:Underweight"<<endl;
        }
        
        else if (18.5<=final_BMI && final_BMI<=25)
        {
            cout<<"Classification:Normal Range"<<endl;
            
        }
        
        else if (25<=final_BMI && final_BMI<=30)
        {
            cout<<"Classification:Overweight"<<endl;
           
        }

        else if(30<=final_BMI)
        {
            cout<<"Classification:Obese"<<endl;
            
        }
    }
    
    
    void displayBMI()
    {
        cout<<"Initial weight: "<<initial_weight<<endl;
        cout<<"Height: "<<height<<endl;
        cout<<"BMI: "<<final_BMI<<endl;
        displayclass();
    }
 
    
};


class Client
    {
    private:
        string name;
        string phone_1;
        string phone_2;
        string email;
        vector<BMI> bmi_v;
         
    public:
        
        //this will call the functions which calculate the BMI and gives the classification.
        void addbmitoclient()
        {
            //here we are storing the clients bmi details within the vector.
            cout<<"Please add the clients current details:"<<endl;
            BMI bmi;
            bmi.Add_Client();
            bmi.CalculateBMI();
            bmi_v.push_back(bmi);
            
            
            
        }
        
        //I then got the client detaills and called the above fucntion below to add the BMI data to the client object.
       void clientdata()
        {
            cout<<"Type clients name: "<<endl;
            cin.ignore(1000, '\n');
            cin.clear();
            getline(cin,name);
            cout<<"Type clients email: "<<endl;
            cin.clear();
            getline(cin,email);
            cout<<"Type clients main phone number: ";
            cin>>phone_1;
            cout<<endl;
            cout<<"Type clients emergency number: ";
            cin>>phone_2;
            cout<<endl;
           
            addbmitoclient();
           
        }
        
    void display_info()
        {
            
            cout<<"Name: "<<name<<endl;
            cout<<"Main phone: "<<phone_1<<endl;
            cout<<"Emergency phone: "<<phone_2<<endl;
            cout<<"Email: "<<email<<endl;
            printBMI();
            
        }
        
        vector<BMI> getbmiinfo()
        {
            return bmi_v;
        }
        
        void printBMI()
        {
            for (int i=0; i<bmi_v.size(); i++)
            {
                cout<<"Bmi"<<(i+1)<<endl;
                bmi_v[i].displayBMI();
            }
        }
        

        
        
        



        void editdetails()
        {
            Client cl;
            cout<<"What would you like to edit: ";
            cout<<"1.Name"<<endl;
            cout<<"2.Main phone"<<endl;
            cout<<"3.Emergency phone"<<endl;
            cout<<"4.Email"<<endl;
            cout<<":";
            
            int input;
            cin>>input;
            
            if (input==1)
            {
                cout<<"Type in new name: ";
                cin>>name;
            }
            
            else if(input==2)
            {
                cout<<"Type in a new main phone number: ";
                cin>>phone_1;
            }
            
            else if (input==3)
            {
                cout<<"Type in new emergency phone number: ";
                cin>>phone_2;
            }
            
            else if(input==4)
            {
                cout<<"Type in new email address: ";
                cin>>email;
            }
           
            
        }
        
        
        void addnewbmi()
        {
            
            addbmitoclient();
        }
        
        
        
        string getname()
        {
            return name;
        }
        
        
        
        
    };


class Menu
{
private:
    vector<Client> clients;
    
    //loop the Client vector and and take the client names from within
    //the i+1 will allow for a list e.g 1 amy 2 jack etc
    void printClientsvector()
    {
        for (int i=0 ; i < clients.size(); i++) {
            cout<<(i+1)<<" "<<clients[i].getname()<<endl;
        }
    }
    
    void addnewclient()
    {
        //here we add a new client we call the Client class initialize it and then call the function to add their details.We then store this into the vector (clients).
        Client client;
        client.clientdata();
        clients.push_back(client);
    }
    
    
    
    
    void Displayclientdetails()
    {
        //this function will allow the user to view all the clients that have been inputted
        cout<<"Enter which client you would like to view"<<endl;
        
        printClientsvector();
        
        int input;
        cin>>input;
        
        clients[input-1].display_info();

        
    }
    
    void add_to_file()
       {
           ofstream file;
           file.open("bmipatientdata.txt.txt");

            ofstream outPutFile; //create output file objec
        outPutFile.open("run_logger.dat", ios::binary); //open the file wanted
        //for (int i = 0; i < clients; i++) //loop over all the person records
        //{
            //Client client = clients[i];
            //outPutFile.write(reinterpret_cast<char*>(&client), sizeof(client));
        //}
        outPutFile.close();
    
       }

    void load_fromfile()
    {
        char loadfile [150];
        
        ifstream myfile;
        myfile.open("/Users/shannen/Desktop/Loadfromfile.txt");
        
        myfile>>loadfile;
        
        while (myfile.good())
        {
            cout<<loadfile<<endl;
            myfile>>loadfile;
        }
        
        
        
        
        
        
        
    }
    
    

    
    void editclients()
    {
        cout<<"Please enter which client you would like to edit"<<endl;
        printClientsvector();
        
        int input;
        cin>>input;
        
        clients[input-1].editdetails();
        
    }
    
    void addnewbmitoclient()
    {
        cout<<"Please enter which client you would like to add a new BMI too"<<endl;
        printClientsvector();
        
        int input;
        cin>>input;
        
        clients[input-1].addnewbmi();
    }
    
    
    void instructions()
    {
        string input_2;
    cout<<"-----------------------"<<endl;
    cout<<"     Instructions:"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"If your BMI is less than 18.5 your classification is underweight."<<endl;
    cout<<"If your BMI is inbetween 18.5 and 25 your classification is Normal."<<endl;
    cout<<"If your BMI is inbetween 25 and 30 your classification is Overweight."<<endl;
    cout<<"If your BMI is over 30 your classification is Obese."<<endl;
    cout<<endl;
    cout<<"Would you like to add a client"<<endl;
    cout<<endl<<endl;
    cout<<"(Y/N):";
    cin>>input_2;

    if (input_2==("Y"))
    {
        addnewclient();
    }

    else exit(0);




    }
    
public:
    
    
    void Menu_look()
    {
    
        int input;
                 do
                {
                    cout<<endl;
                    cout<<endl;
                    cout<<"----------------------------------"<<endl;
                    cout<<"          BMI CALCULATOR"<<endl;
                    cout<<"----------------------------------"<<endl<<endl;
                    cout<<"Enter 1 to Calculate BMI"<<endl;
                    cout<<"Enter 2 to see the instrucitons"<<endl;
                    cout<<"Enter 3 to Add to a file"<<endl;
                    cout<<"Enter 4 to Edit details"<<endl;
                    cout<<"Enter 5 to Add a new Bmi to an existing client"<<endl;
                    cout<<"Enter 6 to load from a file"<<endl;
                    cout<<"Enter 7 to view all clients"<<endl;
                    cout<<"Enter 8 to Exit the program"<<endl;
                    cout<<"----------------------------------"<<endl<<endl;
                    cout<<"->";
                    cin>>input;
                
                    
                    
                        switch(input)
                    {
                    case 1:
                            addnewclient();
                            
                    break;
                            
                       
                    case 2:
                    
                            instructions();

                    break;
                        
                       
                    case 3:
                            
                            
                    break;
                        
                    case 4:
                          editclients();
                            
                    break;
                       
                            
                    case 5:
                            addnewbmitoclient();
                            
                    break;
                        
                            
                    case 6:
                            load_fromfile();
                    break;
                        
                            
                    case 7:
                            Displayclientdetails();

                    break;
                            
                    case 8:
                    exit(0);
                    break;
                            
    }
                    
    }
            while(input!=8);
    }
            

            
            
            
    
        
        
       
};



int main()
    
    {
        Menu mn;
        mn.Menu_look();
        
    }

