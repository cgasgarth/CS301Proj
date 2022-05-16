# CS301Proj

Compiler structure: 
Main method, reads each line, if line valid attempt at function passes it onto Function.h as total string, Functions.h will return "UNDEFINED COMMAND" in vector if command is not valid. 

Function.h returns a vector containing binary strings of translated command to main; main writes it to out file, keeping track of the lines written. 

AFTER out is written in binary,
Loop through and add label offsets/ locations in code.
Then convert to hex. 

Functions.h: uses lineTakeIn(string expression, int lineNum) to bring in line
Expression can come in as long as it doesnt have comments with it, functions.h will clean the expression. 
Binary will be treated as strings. 