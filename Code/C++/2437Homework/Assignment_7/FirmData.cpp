//********************************************************************
//Name: Kevin White
//Class: COSC 2437 F21
//Instructor: Marwa Hassan
//Assignment 7
//Date: 11/16/2021
//Program description: Functions for FirmData.h
//*********************************************************************
#include <string>
#include <iostream>
#include "FirmData.h"
using namespace std;

void FirmData::setName(string n){
    name = n;
}

void FirmData::setIndustry(string i){
    industry = i;
}

void FirmData::setheadQuarterCity(string hqc){
    headquarterCity = hqc;
}

void FirmData::setFoundingYear(int fy){
    foundingYear = fy;
}

void FirmData::setRevenues(double r){
    revenues = r;
}

string FirmData::getName(){
    return name;
}

string FirmData::getIndustry(){
    return industry;
}

string FirmData::setheadQuarterCity(){
    return headquarterCity;
}

int FirmData::getFoundingYear(){
    return foundingYear;
}

double FirmData::getRevenues(){
    return revenues;
}

bool FirmData::operator==(const FirmData &right){
    return(name == right.name);
}

bool FirmData::operator!=(const FirmData &right){
    return(name != right.name);
}