# CS301Proj

Compiler structure: 
Main method, reads each line, if line valid passes it onto Function.h as total string, unless jump(read TO FIGURE OUT). 
Function.h returns proper binary string to main; main writes it to out file. 
AFTER out is written in binary,
loop through and conver to hex. 

Functions.h: uses lineTakeIn(string expression, /*int offset*/) to bring in line
Expression WILL NOT have spaces before or after, one space/comma where needed, if not it will throw exception 
Binary will be treated as strings, only offsets and immediates treated as ints. 

TO FIGURE OUT:
When code does a jump, it moves that int amount away from the current instruction. This may have to be calculated in main and passed into my 
lineTakeIn as an int. 