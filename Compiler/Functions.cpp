#include <string>
#include <stdexcept>
#include "Functions.h"

using namespace std;

int Converter::regAddress(string reg){
    switch(reg){ //write cases for every register
        case ("$r0" || "$zero" || "$0"):
            return 10000011100; //exambple binary string
            break;
        case ("$r1" || "$at" || "$1"):
            return 10011010100101; //example binary string
            break;
        default:
            throw std::invalid_argument( "Register does not exist" );

    }

}
int Converter::add(string var1, string var2, string var3){

}

int Converter::addi(string var1, string var2, int val){

}