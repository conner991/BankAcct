/* -------------------------------------------------------------------------
FILE NAME:         cust_ports.h

DESCRIPTION:       Header file for the Financial Portfolio Program. Contains 
                   all the prototypes, structures, #includes, #define and 
                   the PROGRAMMER_NAME[] global constant char.  

USAGE:

COMPILER:          GNU g++ compiler on Linux

NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Conner Fissell     2019-09-25         1.0  Original version basic version, copied alot 
                                           over from Lab 4.

Conner Fissell     2019-09-28         1.1  Started adding basic program functions to match 
                                           the .cpp file e.g main_menu().

Conner Fissell     2019-10-05         1.2  Added menu choice function (handle_options),
                                           show_cust_report_rep() and compound interest formula 
                                           function prototypes.

Conner Fissell     2019-10-07                                                                                                                    
                    through           1.3  Added more file parsing prototypes e.g skip_spaces
                   2019-10-09        

Conner Fissell     2019-10-10
                    through           1.4  Added final function prototypes e.g get_cust_info(), 
                   2019-10-11              DB_file_out().
                                                                                    
----------------------------------------------------------------------------- */ 
#ifndef __CUST_PORTS_H__
#define __CUST_PORTS_H__

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

struct Command_Line_Info
{
    
};


struct Acc_Info 
{
	char Acct_ID[20];
    double Acct_Balance;
    double Growth_Rate;
    int Comp_per_yr;
};

struct Customer
{
	char Customer_ID[20];		
	char Last_name[20];
    char First_name[20];
    char Middle_name[20];
    char Tax_ID_number[20];
    char Phone_number[20];
    int cust_num;
    int cust_acct_num;
    Acc_Info acc_info[5];	
	 	
};


// Prototypes
void initial_file_option(char[]);
void main_menu(char[], Customer*, int&);
void show_main_menu();
void commd_line(int, char**, Customer*, int&, bool);
void check_arg(char[]);
void struct_setup(int, char*, Customer*);
void read_file(char[], Customer*, int&);
int read_recs(fstream&, Customer*);
void read_cust_info(fstream&, Customer*);
void read_acct_line(Acc_Info*, char*);
char* skip_spaces(char*);
void create_SnB(Customer*, int&, int&);
void create_rec(Customer*, int&, int&, int&);
void get_cust_info(Customer*, int&);
void do_proj_math(Customer*, int);
void handle_options(Customer*, int&, int&);
void portfolio_report(fstream&, Customer*, int&, int);
void DB_file_out(fstream&, Customer*);
void show_DB_file_out(fstream&, Customer*);
void rep_file_out(fstream&);
void show_cust_info_1(Customer*);
void one_cust_port_rep(Customer*, int);
void all_cust_port_rep(Customer*, int, int);
void show_cust_port_rep_out(fstream&, Customer*, int);
void show_cust_port_rep(Customer*, int);


// Global constant
const char PROGRAMMER_NAME[] = "Conner Fissell";

#endif      // __CUST_PORTS_H__


