# ---------------------------------------------------------------------------------------
# FILE NAME:	Makefile
# 
# DESCRIPTION: 	Makefile for a C++ Program
#
# PURPOSE:		Build a program executable on Linux
# 
# MODIFICATION HISTORY: 
#
# Author		 	Date			Modifications(s)
# ---------		 	----------		------------------
# Conner Fissell		2019-09-18		Version 1
#						2019-09-23		Version 2 modified for .h files		
# ________________________________________________________________________________________

#		This is our original generic makefile command that will build
#		any stand alone ".cpp" source file
#		Usage: e.g. make hello

.cpp :
	g++ -o $* $*.cpp -std=c++11

#		Next, these will build the executables that have dependencies on .h files
#		Usage: e.g. make -f Makefile2 sales_struct_v14 

cust_ports : cust_ports.h
 





