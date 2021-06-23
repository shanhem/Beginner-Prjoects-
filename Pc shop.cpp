#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdlib.h>


using namespace std;

class PCtype
{
    
public:
    
    string pctype;
    string make;
    string model;
    string opsystem;
    string notes;
    string displaytype;
    
    void pcdets()
    {
       
        cout<<"Please type in the PC type"<<endl;
        cout<<"1.Laptop   2.Desktop   3.Other"<<endl;
        cout<<">>";
        getline(cin,pctype);
       
       
        cout<<endl;
        cout<<"Please type in the make of PC"<<endl;
        cout<<"e.g Acer"<<endl;
        cout<<">>";
        getline(cin,make);
        cout<<endl;
        
        cout<<"Please type in the model"<<endl;
        cout<<"e.g liquid steel 2021"<<endl;
        getline(cin,model);
        cout<<endl;
        
        cout<<"Please type in the Operating system"<<endl;
        cout<<"1.Windows    2.macOS    3.Linux"<<endl;
        getline(cin,opsystem);
        cout<<">>";
        
        
        
        cout<<endl;
        
        cout<<"Please type in the Display Type"<<endl;
        cout<<"1.LCD    2.OLED    3.LED"<<endl;
        cin>>displaytype;
        cout<<">>";
        
        
        
        
        
        
        
        
        
        
    }
 
    
    
    void pcdisplay()
    {
        
        cout<<"Make:"<<make;
        cout<<endl;
        cout<<"Model:"<<model;
        cout<<endl;
        cout<<"Operating system:"<<opsystem;
        cout<<endl;
        cout<<"Display type:"<<displaytype;
        cout<<endl;
        
    }
    
};

class customers
{
public:
    string name;
    string address;
    string phonenum;
    string notes;
    class PCtype pcc;
    
    void cusdets()
    {
        cout<<endl;
        cout<<"Enter customers Name"<<endl;
        cin.ignore(1000,'\n');
        cin.clear();
        cout<<">>";
        getline(cin,name);
        cout<<endl;
        cout<<"Enter customers Address"<<endl;
        cout<<">>";
        getline(cin,address);
        cout<<endl;
        cout<<"Enter customers Phone number"<<endl;
        cout<<">>";
        getline(cin,phonenum);
        cout<<endl;
        pcc.pcdets();
        
        
        
        
    }
    
    void displayinfo()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Address:"<<address<<endl;
        cout<<"Phone number:"<<phonenum<<endl;
        cout<<"-----------------"<<endl;
        pcc.pcdisplay();
        cout<<endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};






class bookings
{
    
public:
    
    //class parts ptts;
    string servicereq;
    string date;
    string time;
    double quoteprice;
    string notes;
    class customers cs;
    class PCtype pcc;
    //class parts ptt;
   
    //price for the service required and the device
   
    void getinvoicedets()
    {
        cs.cusdets();
        
        cout<<endl;
        cout<<"Please type in the service required"<<endl;
        cout<<"Repair    Service    Other"<<endl;
        cout<<">>";
        cin>>servicereq;
        
        
        
        cout<<endl;
        
        cout<<"Please enter the Time of booking"<<endl;
        cout<<"e.g 14:30 pm"<<endl;
        cout<<">>";
        cin>>time;
       
        cout<<endl;
        cout<<"Please enter the date that you would like to book your appointment"<<endl;
        cout<<"e.g. 12/11/2021"<<endl;
        cin>>date;
        cout<<">>";
        
        cout<<endl;
        cout<<"Please enter the price:";
        cin>>quoteprice;
        cout<<endl;
        
      
     
        
        
        
    }
    
    
    void displayinvoice()
    {
        
            cout<<endl;
            cout<<endl;
            cs.displayinfo();
            cout<<"-----------------"<<endl;
            cout<<"Service required: "<<servicereq<<endl;
            cout<<"Time: "<<time<<endl;
            cout<<"Date:"<<date;
            cout<<endl;
            cout<<"-----------------"<<endl;
            cout<<"Invoice:"<<endl;
            cout<<"£";
            cout<<quoteprice<<endl;
            cout<<"-----------------"<<endl;
        
        
    }
    
    
    

    string getname()
    {
        return cs.name;
    }
    
   string getdate()
    {
        return date;;
    }
    
    
};

class parts
{
public:
    
    
            string itemname;
            string itemtype;
            string temcompat;
            float itemprice;
     

    string giveitemname()
    {
        return itemname;
    }
    
    void additem()
           {
        
        cout<<"\nEnter the item Name: ";
        cin.ignore(1000,'\n');
        getline(cin,itemname);
        cout<<"Enter the item type: ";
        getline(cin,itemtype);
        cout<<"Enter the compatibility";
        getline(cin,temcompat);
        cout<<"Enter the price of the item: ";
        cin>>itemprice;
        
           }

    void displayitem()
    {
        cout<<"Item name:"<<itemname<<endl;
        cout<<"Item type"<<itemtype<<endl;
        cout<<"Item compatibility"<<temcompat<<endl;
        cout<<"Item price"<<itemprice<<endl;
    }

    
  
    void partmenu()
    {
        int input;
        
        cout<<endl;
        cout<<"Parts Menu:"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"[1] Add item"<<endl;
        cout<<endl;
        cout<<"[2] Display items"<<endl;
        cout<<endl;
        cout<<"[3] Search item"<<endl;
        cout<<endl;
        cout<<"[4] Return to Main Menu"<<endl;
        cout<<endl<<endl;
        cin>>input;
        cout<<"Please select an option >>";
        
    }
   


    
};


class menu
{
public:
    
    parts ptt;
    vector <bookings> booking;
    vector <parts> part;
   
    
    
    //I make a vector that stores all the bookings information i can then loop this vector and print the client names out to make a list.
    void clientlist()
    {
        for (int i=0 ; i < booking.size(); i++)
        {
            cout<<(i+1)<<" ."<<booking[i].getname() <<endl;
        }
    }
    
    void itemlist()
    {
        for (int i=0; i<part.size(); i++) {
            cout<<(1+i)<<" ."<<part[i].giveitemname()<<endl;
        }
    }
    
    
    void openfile()
    {
        //save items to file and load back again
        string line;
        ifstream myfile("/Users/shannen/Desktop/Customer invoices.txt");
        if(myfile.is_open())
        {
            while (getline(myfile,line))
            {
                
            }
            
            
            
        }
    }
   
    
    
    void addnewinvoice()
    {
        //add new customer
        bookings bkk;
        bkk.getinvoicedets();
        //bkk.pcprice();
        booking.push_back(bkk);
        system("cls");
    }
    void additem()
    {
        parts ptt;
        ptt.additem();
        part.push_back(ptt);
        
    }
    
    void displayitems()
    {
        itemlist();
        int input;
        cout<<endl;
        cout<<"->";
        cin>>input;
        part[input-1].displayitem();
    }
    
    
    void displayclinetdetails()
    {
        //display customer details
        cout<<"Enter the client you would like to view"<<endl;
        clientlist();
        int input;
        cout<<endl;
        cout<<"->";
        cin>>input;
        booking[input-1].displayinvoice();
    }
    
    void findPart()
        {
            
            string findpart;
            cin.ignore(1000, '\n'); cin.clear();
            cout << "Enter the part you would like to search for: " << endl;
            getline(cin, findpart);

     

            for (int i=0; i<part.size(); i++)
            {
                if (findpart.compare(part[i].giveitemname())==0)
                {
                    cout<<endl;
                    part[i].displayitem();
                    return;
                }
            }
            cout << "This part is not available" << endl;
        }
    
    
    void daysbooked()
    {
        
        string dateinput;
        cout<<"To see bookings on a certain date please enter the date below"<<endl;
        cin.ignore(1000,'\n');
        cin>>dateinput;
        cout<<">>";
       
        cout<<"---------"<<endl;
       
            for(int i=0;i<booking.size();i++)
            {
                if (dateinput.compare(booking[i].getdate())==0)
                {
                    cout<<"Customers booked for:"<<dateinput<<endl;
                    cout<<booking[i].getname()<<endl;
                }
        }
        cout<<"---------"<<endl;
        
    }
    
        
    
    void menulook()
    {
        
        int input;
                 do
                {
                   
                    
                    cout<<endl;
                    cout<<"Main Menu"<<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<<"[1] Create a customer invoice"<<endl;
                    cout<<endl;
                    cout<<"[2] Check invoices booked"<<endl;
                    cout<<endl;
                    cout<<"[3] See customer details"<<endl;
                    cout<<endl;
                    cout<<"[4] Item menu"<<endl;
                    cout<<endl;
                    cout<<"[5] Exit program"<<endl;
                    cout<<endl<<endl;
                    cout<<"Please select an option >>";
                    cin>>input;
                
                    
                    switch (input)
                    {
                        case 1:
                            
                            addnewinvoice();
                            
                            break;
                            
                        case 2:
                           daysbooked();
                            break;
                            
                        case 3:
                            displayclinetdetails();
                            break;
                            
                        case 4:
                        {
                            int input1;
                            ptt.partmenu();
                            cin>>input1;
                            cout<<"-->";
                            cout<<endl;
                            switch (input1)
                            
                            {
                                case 1:
                                    additem();
                                    break;
                                    
                                case 2:
                                    displayitems();
                                    break;
                                
                                case 3:
                                    findPart();
                                    break;
                                    
                                case 4:
                                    if (input==4)
                                {
                                    menulook();
                                }
                                    break;
                        
                            }
                        }
                           
                            break;
                            
                        case 5:
                            
                            break;
                            
                    }
                }
        while (input!=5);
        {
            
        }
    }
                    
                  
   
};


int main()
{
    menu mn;
    mn.menulook();
}
