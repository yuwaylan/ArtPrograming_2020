from sys import argv
import re

inputFile = argv[1] # temp command argument
data = u""          # temp all data inside file (String)
result = []	        # temp all match pattern results (List)
Str = ""            # temp Starttime (String)
output = []         # temp final data (String)

#1. open file and 
#2. Parser #includes
#3. 
#?. ignore all annotation like // /**/

with open(inputFile, 'r') as myFile:
    data = myFile.read()

