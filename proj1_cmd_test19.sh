#!/bin/sh

set -v

./cust_ports -h						# demonstrates -h option

# Text file options
./cust_ports -f CustDB19.dat -cust RS001 -info		# demos customer info
./cust_ports -f CustDB19.dat -cust VG003 -info		# demos customer info

./cust_ports -f CustDB19.dat -cust JBG58 -12		# demos FV projections
./cust_ports -f CustDB19.dat -20			# demos FV projections for all

./cust_ports -f CustDB19.dat -out zzz.dat		# demonstrates -out option
./cust_ports -f CustDB19.dat -out zzz.bin		# demonstrates -out option

./cust_ports -f CustDB19.dat -rpt report2.txt		# demos -rpt option (default)
./cust_ports -f CustDB19.dat -rpt report2.txt -12	# demos -rpt option (12 years)

# Binary file options
# Note:  In order to test the binary options, you need to first create the binary file
# with your program, because everyone's binary structure will be different.
# E.g. ./cust_ports -f CustDB19.dat -out CustDB19.bin

./cust_ports -f CustDB19.bin -cust PMC55 -info		# demos customer info
./cust_ports -f CustDB19.bin -info			# demos customer info for all

./cust_ports -f CustDB19.bin << EOF			# demos -f starts interactive
q
n
EOF
