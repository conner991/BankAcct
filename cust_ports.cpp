/* --------------------------------------------------------------------------------------------------
FILE NAME:         cust_ports.cpp

DESCRIPTION:       A program that reads in Finacial information from current customers
                   and allows the user to create accounts and reports with interest 
                   projections for new customers as well. Also writes reports and customer
                   info to text and binary files if desired.     

USAGE:             ./cust_ports (with additional command line prompts)

COMPILER:          GNU g++ compiler on Linux

NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Conner Fissell     2019-09-25         1.0  Original basic version, copied
                                           alot over from previous Labs.

Conner Fissell     2019-09-30         1.1  Continued focus on my Customer file read 
                                           read in parsing functions.
                                           
Conner Fissell     2019-10-01         1.2  Trouble with file read in functions continues 
                                           so moved on to building the rest of the program.

Conner Fissell     2019-10-05         1.3  Added to menu function, made additional interactive 
                                           menu choice function (handle_options), created multiple 
                                           customer report displaying functions and made the compound
                                           interest formaula function.

Conner Fissell     2019-10-06         1.4  Added necessary interactive user prompts to the 
                                           create_rec function.

Conner Fissell     2019-10-07         1.5  Made more changes to the layout of my input file parsing
                    through                functions and FINALLY achieved desired data separation.
                   2019-10-09

Conner Fissell     2019-10-10         1.6  Created the initial_file_option() function which handles the DB 
                                           file input at program start. Modified the main_menu() function, 
                                           created the create_SnB() function.

Conner Fissell     2019-10-11         1.   Added skip_spaces() functionality support to the file parsing function,
                                           modified the create_rec() function to work more accurately with the 
                                           create_SnB() function, 
  
                                                                                        
                                                                                                                                                                                                                   

                                                                                 
-------------------------------------------------------------------------------------------------- */ 

#include "cust_ports.h"    // gonna insert .h stuff



/* -----------------------------------------------------------------------------
FUNCTION:          main(int argc, char* argv[]) 

DESCRIPTION:       the programs entry point

RETURNS:           0
NOTES:             int argc = Number of parameters on the command line
                   char *argv[] = an array of pointers to c strings
------------------------------------------------------------------------------- */
int main(int argc, char* argv[])
{   
    int num_cust = 0;
    int mod_cust_index = 0;
    bool mode;
    char file[] = "CustDB.dat";
    Customer* cust = new Customer [10];
              
          

    if (argc == 1)
    {   
        initial_file_option(file);                  
        main_menu(file, cust, num_cust);                          // Interactive mode
        

    }

    else
    {
        commd_line(argc, argv, cust, num_cust, mode);       // Handles command line prompts
    }
    
    

    

    delete []cust;



    cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;
    
    return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          initial_file_option(char file[])

DESCRIPTION:       Determines if the user wants to use a default DB file or create 
                   their own.

RETURNS:           nothing (void)

NOTES:              
------------------------------------------------------------------------------- */
void initial_file_option(char file[])
{   
    char choice;
    char file_choice[20];
    
    

    do 
    {   
        cout << endl;
        cout << "Do you want use the default DB file " << file << " to modify?  [Y/N] " << endl;
        cout << "If choice is N, then unique DB file will be created. ";
        choice = cin.get();
        cout << endl;


    
        if (choice == 'Y') 
        {        
            cout << "Okay, " << file << " it is. " << endl << endl;
        }

        else if (choice == 'N')
        {
            cout << "Okay, what would you like to call this new DB file? Please make it a .dat file ";
            cin >> file_choice;
            cout << "Excellent Choice, " << file_choice << " it is. " << endl;
            strcpy(file, file_choice); 
        }

        else
        {
            cout << "Not a valid option, either Y or N please." << endl << endl;
        }
        
        


    } while (choice != 'Y' && choice != 'N');

    



}



/* -----------------------------------------------------------------------------
FUNCTION:          commd_line(int argc, char* argv[], Customer* cust, int &num_cust, bool mode)

DESCRIPTION:       Begins the process of parsing through the argc commands.

RETURNS:           nothing (void)

NOTES:              
------------------------------------------------------------------------------- */
void commd_line(int argc, char* argv[], Customer* cust, int &num_cust, bool mode)
{   
   

        for (int i = 0; i < argc; i++)
        {
            //read_file(argv[1], cust, num_cust, mode);     // Input from file
        
            
            check_arg(argv[i]);
            
        
            cout << endl;
        
        
        }    
    
               

    cout << endl;

}

/* -----------------------------------------------------------------------------
FUNCTION:          check_arg(char_arg[])

DESCRIPTION:       check_arg function uses bools, a for loop and multiple "if" 
                   statements to see if the first and second character of the parameter
                   that gets sent in contains the valid characters: "-" and "?hifap" , 
                   when using the test4.sh command...If not the case, then function 
                   displays invalid argument. If argument is valid, displays the option
                   (second character) and the value (all the characters after).  

RETURNS:           nothing (void)

NOTES:             
------------------------------------------------------------------------------- */
void check_arg(char arg[])
{

    char buf[100];
    const char DASH = '-';
    char valid_options[] = "hfiorap";
    char *p = valid_options;

    // Test first parameters first character
    bool first_char = arg[0] == DASH;	
    // Test first parameters second character
    bool second_char = false;		
	
        for(; *p != 0; ++p)
        {
		
            second_char = arg[1] == *p;
		
            if (second_char == true)
            { 
                break;
            }
    
        }
	
        if (!first_char || !second_char)
        {
	        cout << "Invalid argument" << endl;
        }
	
        else
        {		
	    
            // look for a string
            if (arg[2] != 0)
            {
		        // save string to buffer
                strcpy(buf, arg+2);		
		        cout << " Value: " << buf;
	        }

            else 
            {

            }
	
            cout << endl;
        }	


}

/* -----------------------------------------------------------------------------
FUNCTION:          main_menu(char file[], Customer* cust, int &num_cust)

DESCRIPTION:       Main Menu function that determines how the user navigates through
                   the interactive mode of this program.

RETURNS:           nothing (void)
NOTES:              
------------------------------------------------------------------------------- */
void main_menu(char file[], Customer* cust, int &num_cust)
{   
    
    int cust_option_1 = 0;
    int cust_option_2 = 0;
    int cust_option_3 = 0;
    int cust_option_4;
    int new_num_cust = 0;
    char menu_choice;
    char choice;
    //char* infile;
    //fstream infile(file, ios::in | ios::out);
    fstream fout("Customer_Rpt.txt", ios::out);
    
    

    read_file(file, cust, num_cust);                    /*after this we get how many customers there are 
                                                        and all of the data is now in the structures*/

    do 
    {   

	show_main_menu();			
        cout << endl;
        cout << "What would you like to do? ";
	cin >> menu_choice;
        cout << endl << endl;

		
        

		switch (menu_choice) 
        {
  
			case '1': ;     create_rec(cust, num_cust, new_num_cust, cust_option_1);
                            // New Customer Portfolio, Interactive data input

                            
				break;


			case '2': ;     create_SnB(cust, new_num_cust, cust_option_2);
                            //Create stock and bond accounts for added Customer
                            
				break;


			case '3': ;     cust_option_3 = 1;                
                            handle_options(cust, new_num_cust, cust_option_3);
                            // Info for 1 Customer, using a customer ID prompt
                            
				break;

                
   		         case 'a': ;     cust_option_3 = 2;
                            handle_options(cust, new_num_cust, cust_option_3);
                            // INFO for ALL Customers
                                            
                            
               			 break;
                    
                
           		 case '4': ;     cust_option_4 = 1;
                        		    portfolio_report(fout, cust, new_num_cust, cust_option_4);
                           	 // Portfolio projections using a customer ID prompt, SINGLE
                            
                            
               			 break;

                
           		 case '5': ;     cust_option_4 = 2;
                           		 portfolio_report(fout, cust, new_num_cust, cust_option_4);
                            // Write a report using a number of years prompt, screen will show report style output
                            // for ALL CUSTOMERS and a report FILE shall be written (Customer_Rpt.txt)
                            // Program shall give the user the choice of picking a differnt name for the report 
                            // file. IF SO, the user shall be prompted to to enter the alternative name of the file
                            
               			 break;


           		 case '6': ;     DB_file_out(fout, cust);
                            // Write data to a Data Base file, program shall prompt for using the same file name or a new
                            // file name. THe output format should be virtually the same as the input file.

               			 break;

		}
			
	
	
	} while (menu_choice != 'q');

    

}

/* -----------------------------------------------------------------------------
FUNCTION:          show_main_menu()

DESCRIPTION:       Displays the Main Menu to the screen

RETURNS:           nothing (void)

NOTES:              
------------------------------------------------------------------------------- */
void show_main_menu()
{
    cout << "------------------------------------------------------" << endl;
    cout << "           The Fiancial Portfolio Program             " << endl;
    cout << "                    MAIN MENU                         " << endl;
    cout << "------------------------------------------------------" << endl << endl;
    cout << "         1.  Create New Customer Portfolios           " << endl;
    cout << "                                                      " << endl;
    cout << "         2.  Create Stock and Bond Accounts           " << endl;
    cout << "             for the Customer and Invest Funds        " << endl;
    cout << "                                                      " << endl;
    cout << "         3.  Display Information for one Customer     " << endl;
    cout << "             and their Accounts                       " << endl;
    cout << "                                                      " << endl;
    cout << "         a.  Display Information for all Customers    " << endl;
    cout << "             and their Accounts                       " << endl;
    cout << "                                                      " << endl;
    cout << "         4.  Display Projections of the Portfolio     " << endl;
    cout << "             Accounts Value in the Future             " << endl;
    cout << "                                                      " << endl;
    cout << "         5.  Write a Report to the Sceen and a File   " << endl;
    cout << "                                                      " << endl;
    cout << "         6.  Write the data out to a Database File    " << endl;
    cout << "                                                      " << endl;
    cout << "         q.  Quit the program                         " << endl;
    cout << "                                                      " << endl << endl;
    cout << "Enter your choice [ 1 2 3 a 4 5 6 or q ]: " << endl << endl;

}


/* -----------------------------------------------------------------------------
FUNCTION:          create_rec(Customer* cust, int &num_cust, int &new_num_cust, int &cust_option_1)

DESCRIPTION:       Function that allows the user to create a customer portfolio
                   depending on the file that was read in.

RETURNS:           nothing (void)

NOTES:              
------------------------------------------------------------------------------- */
void create_rec(Customer* cust, int &num_cust, int &new_num_cust, int &cust_option_1)
{   


    if(num_cust == 0)
    {
        get_cust_info(cust, num_cust);
    }

    else
    {
        cust_option_1++;
        new_num_cust = (num_cust + cust_option_1);
        get_cust_info(cust, new_num_cust);

    }
    
    
    

    
    cout << endl;
    cout << setw(3) << new_num_cust << " Customers Total Now" << endl;
    cout << endl;



    
}

/* -----------------------------------------------------------------------------
FUNCTION:          get_cust_info(Customer* cust, int &new_num_cust)

DESCRIPTION:       Lets the user enter the Customer Information

RETURNS:           nothing (void)

NOTES:              
-------------------------------------------------------------------------------*/
void get_cust_info(Customer* cust, int &new_num_cust)
{
    
    cout << "Info for New Customer #" << new_num_cust << endl << endl;
        
    cout << "Create Customer ID: ";
    cin >> cust[new_num_cust].Customer_ID;
    cout << endl;
        
    cout << "First Name: ";
    cin >> cust[new_num_cust].First_name;
    cout << endl;
    
    cout << "Last Name: ";
    cin >> cust[new_num_cust].Last_name;
    cout << endl;

    cout << "Middle Name: ";
    cin >> cust[new_num_cust].Middle_name;
    cout << endl;

    cout << "Tax ID: ";
    cin >> cust[new_num_cust].Tax_ID_number;
    cout << endl;

    cout << "Phone Number: ";
    cin >> cust[new_num_cust].Phone_number;
    cout << endl;




}

/* -----------------------------------------------------------------------------
FUNCTION:          create_SnB(Customer* cust, int &new_num_cust, int &cust_option_2)

DESCRIPTION:       Allows the user to add individual account information to 
                   customer portfolios.

RETURNS:           nothing (void)

NOTES:              
-------------------------------------------------------------------------------*/
void create_SnB(Customer* cust, int &new_num_cust, int &cust_option_2)
{   
    int new_cust_accts;


    if (new_num_cust == 0)
    {
        cout << "No new customer account information has been added to the database." << endl;
        cout << "Cannot create new Stock and Bond accounts. " << endl << endl;
    }

    else
    {   


        cout << "How many accounts do you want to make for Customer #" << new_num_cust  << "? Limit of 5: ";
        cin >> new_cust_accts;
        cout << endl << endl;

        for (int i = 0; i < new_cust_accts; i++)
        {
            cout << "Account ID: ";
            cin >> cust[new_num_cust].acc_info[i].Acct_ID;
            cout << endl;

            cout << "Initial Account Balance: ";
            cin >> cust[new_num_cust].acc_info[i].Acct_Balance;
            cout << endl;

            cout << "Growth Rate: ";
            cin >> cust[new_num_cust].acc_info[i].Growth_Rate;
            cout << endl;

            cout << "Compounds Per Year: ";
            cin >> cust[new_num_cust].acc_info[i].Comp_per_yr;
            cout << endl;

            cust[new_num_cust].cust_acct_num++;

        }

        
        
    }




}

/* -----------------------------------------------------------------------------
FUNCTION:          read_file(char file[], Customer *cust, int &num_cust)

DESCRIPTION:       Reads in a DB file and sends it to read_recs().

RETURNS:           nothing (void)

NOTES:              
------------------------------------------------------------------------------- */
void read_file(char file[], Customer *cust, int &num_cust)
{   
    
    fstream infile(file, ios::in | ios::out);
    

    if(!infile)         // Test for errors
    {
        cout << "\nError opening file: " << file << "\n\n";
    }

    else
    {   
        cout << endl;
        cout << "Input file: " << file << endl;
        num_cust = read_recs(infile, cust);                                                     
        
    }
    //infile.close();
}



/* -----------------------------------------------------------------------------
FUNCTION:          read_recs(fstream &in, Customer *cust)

DESCRIPTION:       Reads customer records iteratively, using array element
                   addresses

RETURNS:           int (cust_index)

NOTES:              
------------------------------------------------------------------------------- */
int read_recs(fstream &in, Customer *cust)
{   
    int cust_index = 0;


    while (cust_index < 10)
    {
        read_cust_info(in, &cust[cust_index]);
        if (in.eof()) break;
        cust[cust_index++].cust_num = cust_index;    // Stores the number of the certain portfolio in the s array of cust_num
    }

    
    cout << endl;
    cout << setw(3) << cust_index << " Customers Total" << endl;
    cout << endl;

    return cust_index;
    
}

/* -----------------------------------------------------------------------------
FUNCTION:          read_cust_info(fstream &in, Customer* cust)

DESCRIPTION:       Here is where the customer information gets separated out and 
                   sent to the appropriate structure members.

RETURNS:           nothing (void)

NOTES:             
-------------------------------------------------------------------------------*/ 
void read_cust_info(fstream &in, Customer* cust)
{   

    int const LINE_SIZE = 20;
    char temp1[50];
    char* p = &temp1[0];
    char temp2[50];


    in.getline(temp1, LINE_SIZE, '\n');
    p = skip_spaces(temp1);
    strcpy(cust->Customer_ID, p);

    in.getline(temp1, LINE_SIZE, ',');
    p = skip_spaces(temp1);
    strcpy(cust->Last_name, p);

    in.getline(temp1, LINE_SIZE, ',');
    p = skip_spaces(temp1);
    strcpy(cust->First_name, p);

    in.getline(temp1, LINE_SIZE, '\n');
    p = skip_spaces(temp1);
    strcpy(cust->Middle_name, p);

    in.getline(temp1, LINE_SIZE, '\n');
    p = skip_spaces(temp1);
    strcpy(cust->Tax_ID_number, p);

    in.getline(temp1, LINE_SIZE, '\n');
    p = skip_spaces(temp1);
    strcpy(cust->Phone_number, p);


    for(int i = 0; i < ARRAY_SIZE(cust->acc_info); i++)
    {
        

        in.getline(temp2, 49);
        
        if(*temp2 == '\0')
        {
            break;
        }

	    read_acct_line(&cust->acc_info[i], temp2);

        cust->cust_acct_num++;

    }
    

    	
}

/* -----------------------------------------------------------------------------
FUNCTION:          read_acct_line(Acc_Info* acct, char* line_p)

DESCRIPTION:       Uses the strchr() and skip_spaces() functions to separate out
                   the 4 account info datatypes from each line and send them to 
                   their appropriate structure members.

RETURNS:           nothing (void)

NOTES:             
-------------------------------------------------------------------------------*/
void  read_acct_line(Acc_Info* acct, char* line_p)
{
	char* p2;
	
    
    p2 = line_p;
    line_p = skip_spaces(p2);

    p2 = strchr(line_p, ' ');
    *p2 = 0;
    strcpy(acct->Acct_ID, line_p);      // uppercase function here

    line_p = skip_spaces(p2 + 1);
    p2 = strchr(line_p, ' ');
    *p2 = 0;
    acct->Acct_Balance = atof(line_p);

    line_p = skip_spaces(p2 + 1);
    p2 = strchr(line_p, ' ');
    *p2 = 0;
    acct->Growth_Rate = atof(line_p);

    line_p = skip_spaces(p2 + 1);
    acct->Comp_per_yr = atoi(line_p);


}


/* -----------------------------------------------------------------------------
FUNCTION:          skip_spaces(char* line)

DESCRIPTION:       Skips over leading spaces in a C-String

RETURNS:           (char*) pointer to first non-space character

NOTES:             
-------------------------------------------------------------------------------*/
char* skip_spaces(char* line)
{

	char* p = line;
	
	while(isspace(*p))          // Skips over leading spaces
	{
		p++;		
	}


	return p;

}

/* -----------------------------------------------------------------------------
FUNCTION:          handle_options(Customer* cust, int &new_num_cust, int cust_option)

DESCRIPTION:       Where customer information gets sorted.   

RETURNS:           nothing (void)

NOTES:                    
------------------------------------------------------------------------------- */
void handle_options(Customer* cust, int &new_num_cust, int &cust_option_3)
{   
    char proj_holder[5];
    char* proj_ptr = &proj_holder[0];
    char ID_holder[10];
    int num_yrs;
    int num_yrs2;

    if (cust_option_3 == 1)           // Option 3, ONE Customer
    {
        cout << "Enter Customer ID: ";
        cin >> ID_holder;
        cout << endl << endl;

        for (int x = 0; x < new_num_cust; x++)
        {
            if (!strcmp(ID_holder, cust[x].Customer_ID))
            {
                show_cust_info_1(cust + x);
            }

            
            
        }

    }


    else if (cust_option_3 == 2)          // Option a.) ALL CUSTOMERS
    {
        for (int x = 0; x < new_num_cust; ++x)
        {
            show_cust_info_1(cust + x);
            	
        }
    }



    else
    {
        cout << endl << endl;
    }
    

}

/* -----------------------------------------------------------------------------
FUNCTION:          one_cust_port_rep(Customer* cust, int num_yrs)

DESCRIPTION:       Runs through the accounts of a specific customer and claculates the necessary 
                   information to be displayed to the screen.

RETURNS:           nothing (void)

NOTES:             
-------------------------------------------------------------------------------*/
void one_cust_port_rep(Customer* cust, int num_yrs)
{   
    char proj_holder[5];
    char* proj_ptr = &proj_holder[0];
    double projection;
    

    for (int i = 0; i < cust->cust_acct_num; i++)
    {
       // do_proj_math(cust->acc_info[i], num_yrs);

        
    }




}

/* -----------------------------------------------------------------------------
FUNCTION:          all_cust_port_rep(Customer* cust, int num_yrs, int num_cust)

DESCRIPTION:       Runs through the accounts of each customer and claculates the necessary 
                   information to be displayed to the screen. 

RETURNS:           nothing (void)

NOTES:             
-------------------------------------------------------------------------------*/
void all_cust_port_rep(Customer* cust, int num_yrs, int num_cust)
{
    char proj_holder[5];
    char* proj_ptr = &proj_holder[0];
    double projection;

    for (int i = 0; i < num_cust; i++)
    {
       // do_proj_math(cust->acc_info[i], num_yrs);

        
    }

}

/* -----------------------------------------------------------------------------
FUNCTION:          do_proj_math(Acc_Info* acct, int num_yrs)

DESCRIPTION:       

RETURNS:           nothing (void)

NOTES:             
-------------------------------------------------------------------------------*/
void do_proj_math(Customer* cust, int num_yrs)
{   
    char proj_holder[5];
    char* proj_ptr = &proj_holder[0];
    double projection;
    
    
    
    //projection = cust->acct.Acct_Balance * pow((1 + (cust->acc_info.Growth_Rate / cust->acc_info.Comp_per_yr)) , (cust->acc_info.Comp_per_yr * num_yrs));
    
    proj_ptr++;
    
    
    
    //projection = atof();

    
    


}

/* -----------------------------------------------------------------------------
FUNCTION:          show_cust_info_1(Customer* cust)

DESCRIPTION:       Sends the customer information to the display screen

RETURNS:           nothing (void)

NOTES:             
-------------------------------------------------------------------------------*/
void show_cust_info_1(Customer* cust)
{
    
    cout << "Record No. : " << cust->cust_num << endl;
    cout << "Customer ID: " << cust->Customer_ID << endl;
    cout << "Last   Name: " << cust->Last_name << endl;
    cout << "First  Name: " << cust->First_name << endl;
    cout << "Middle Name: " << cust->Middle_name << endl;
    cout << "Tax ID Num : " << cust->Tax_ID_number << endl;
    cout << "Phone #    : " << cust->Phone_number << endl;
    cout << "Num. Accts : " << cust->cust_acct_num << endl;
    cout << setw(20) << "Acct ID" << setw(15) << "Balance" << setw(10) << "Rate" << setw(10) << "C/Y" << endl;
    cout << setw(20) << "-------" << setw(15) << "-------" << setw(10) << "----" << setw(10) << "---" << endl;

    for (int i = 0; i < cust->cust_acct_num; i++)
    {
        cout << "Acct No. " << i + 1 << " :  " << cust->acc_info[i].Acct_ID << setw(16) << setprecision(2) << fixed;
        cout << cust->acc_info[i].Acct_Balance << setw(9) << cust->acc_info[i].Growth_Rate << setw(10);
        cout << cust->acc_info[i].Comp_per_yr << endl;
    
    }
    
    cout << endl << endl;
    


}

/* -----------------------------------------------------------------------------
FUNCTION:          portfolio_report(fstream& fout, Customer* cust, int &new_num_cust, int &cust_option_4)

DESCRIPTION:       Function that either implements Main Menu option #4 or #5.

RETURNS:           nothing (void)

NOTES:             
-------------------------------------------------------------------------------*/
void portfolio_report(fstream& fout, Customer* cust, int &new_num_cust, int cust_option_4)
{   
    char proj_holder[5];
    char* proj_ptr = &proj_holder[0];
    char ID_holder[10];
    int num_yrs;
    int num_yrs2;
    
    
    
    if (cust_option_4 == 1)      // ONE Portfolio Report Option 4
    {
        cout << "Enter Customer ID: ";
        cin >> ID_holder;
        cout << endl << endl << "Enter Number of Years: ";
        cin >> num_yrs;
        cout << endl << endl;

        for (int x = 0; x < new_num_cust; x++)
        {
            if (!strcmp(ID_holder,cust[x].Customer_ID))
            {
                one_cust_port_rep(cust + x, num_yrs);
            }

        
            

        }


    }


    else if (cust_option_4 == 2)  // write a report for all customers, to screen and to (Customer_Rpt.txt)
    {
        cout << "How many years would you like to project all customers and their respective accounts out to?  ";
        cin >> num_yrs2;
        cout << endl;

        for (int x = 0; x < new_num_cust; x++)
        {
            
            
            all_cust_port_rep(cust + x, num_yrs2, new_num_cust);
            show_cust_port_rep_out(fout, cust + x, num_yrs2);
        
            

        }
    }

    
    else
    {
        cout << endl << endl;
    }
    




}

/* -----------------------------------------------------------------------------
FUNCTION:          show_cust_port_rep(Customer* cust, int num_yrs)

DESCRIPTION:       Displays customer portfolio reports to the screen 

RETURNS:           nothing (void)

NOTES:              
-------------------------------------------------------------------------------*/
void show_cust_port_rep(Customer* cust, int num_yrs)
{

    cout << "CustID" << setw(13) << "Last_Name" << setw(19) << "First_Name";
    cout << setw(14) << "Middle" << setw(14) << "TAX ID" << setw(16) << "Phone" << endl;
    cout << "------" << setw(13) << "---------" << setw(19) << "----------";
    cout << setw(14) << "------" << setw(14) << "------" << setw(25) << "---------------" << endl;
    cout << cust->Customer_ID << setw(13) << cust->Last_name << setw(19) << cust->First_name << setw(14);
    cout << cust->Middle_name << setw(14) << cust->Tax_ID_number << setw(16) << cust->Phone_number << endl; 
    cout << setw(91) << "---------------------------------------------------------------------------------" << endl;
    

    cout << setw(18) << "Accounts" << setw(19) << "Balance" << setw(21) << "% Rate   C/Y" << setw(29);
    cout << "Projections " << "(" << num_yrs << ") year(s)" << endl;
    cout << setw(18) << "--------" << setw(19) << "-------" << setw(21) << "------   ---" << setw(29);
    cout << "-----------        " << endl;
     
        for (int i = 0; i < cust->cust_acct_num; i++)
        {
            cout << setw(18) << cust->acc_info[i].Acct_ID << setw(19) << cust->acc_info[i].Acct_Balance << setw(21);
            cout << cust->acc_info[i].Growth_Rate << "   " << cust->acc_info[i].Comp_per_yr << setw(29);
            cout << "Projection 1 yr" << endl;
        }

    cout << setw(18) << "-------" << endl;
    cout << setw(18) << "Totals: " << endl;


}

/* -----------------------------------------------------------------------------
FUNCTION:          show_cust_port_rep_out(Customer* cust, int num_yrs)

DESCRIPTION:       Displays customer portfolio reports to the screen 

RETURNS:           nothing (void)

NOTES:              
-------------------------------------------------------------------------------*/
void show_cust_port_rep_out(fstream& fout, Customer* cust, int num_yrs)
{

    fout << "CustID" << setw(13) << "Last_Name" << setw(19) << "First_Name";
    fout << setw(14) << "Middle" << setw(14) << "TAX ID" << setw(16) << "Phone" << endl;
    fout << "------" << setw(13) << "---------" << setw(19) << "----------";
    fout << setw(14) << "------" << setw(14) << "------" << setw(25) << "---------------" << endl;
    fout << cust->Customer_ID << setw(13) << cust->Last_name << setw(19) << cust->First_name << setw(14);
    fout << cust->Middle_name << setw(14) << cust->Tax_ID_number << setw(16) << cust->Phone_number << endl; 
    fout << setw(91) << "---------------------------------------------------------------------------------" << endl;
    

    fout << setw(18) << "Accounts" << setw(19) << "Balance" << setw(21) << "% Rate   C/Y" << setw(29);
    fout << "Projections " << "(" << num_yrs << ") year(s)" << endl;
    fout << setw(18) << "--------" << setw(19) << "-------" << setw(21) << "------   ---" << setw(29);
    fout << "-----------        " << endl;
     
        for (int i = 0; i < cust->cust_acct_num; i++)
        {
            cout << setw(18) << cust->acc_info[i].Acct_ID << setw(19) << cust->acc_info[i].Acct_Balance << setw(21);
            cout << cust->acc_info[i].Growth_Rate << "   " << cust->acc_info[i].Comp_per_yr << setw(29);
            cout << "Projection 1 yr" << endl;
        }

    fout << setw(18) << "-------" << endl;
    fout << setw(18) << "Totals: " << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          DB_file_out(fstream &fout, Customer* cust)

DESCRIPTION:       Sends the customer information to an output file

RETURNS:           nothing (void)

NOTES:             
-------------------------------------------------------------------------------*/
void DB_file_out(fstream& fout, Customer* cust)
{
    char file_choice[30];
    
    cout << "Do you want to use the same file name or a new file name to write to the ";
    cout << "Data Base file? ";
    cin >> file_choice;
    cout << endl << endl;

        
        
            
            
    show_DB_file_out(fout, cust);
        
            

        
    




}

/* -----------------------------------------------------------------------------
FUNCTION:          show_DB_file_out(fstream &fout, Customer* cust)

DESCRIPTION:       Sends the customer information to an output file

RETURNS:           nothing (void)

NOTES:             
-------------------------------------------------------------------------------*/
void show_DB_file_out(fstream &fout, Customer* cust)
{
    
    fout << cust->cust_num << endl;
    fout << cust->Customer_ID << endl;
    fout << cust->Last_name << ", " << cust->First_name << ", " << cust->Middle_name << endl;
    fout << cust->Tax_ID_number << endl;
    fout << cust->Phone_number << endl;
    fout << cust->cust_acct_num << endl;
    
    for (int i = 0; i < cust->cust_acct_num; i++)
    {
        fout << cust->acc_info[i].Acct_ID << setw(16) << fixed << cust->acc_info[i].Acct_Balance << setw(9);
        fout << cust->acc_info[i].Growth_Rate << setw(10) << cust->acc_info[i].Comp_per_yr << endl; 
    
    }
    
    
    fout << endl << endl;

    
}



