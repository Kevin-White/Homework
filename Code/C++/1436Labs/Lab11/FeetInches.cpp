// Implementation file for the FeetInches class
#include <cstdlib>       // Needed for abs()
#include "FeetInches.h"
#include <iostream>

//************************************************************
// Definition of member function simplify. This function     *
// checks for values in the inches member greater than       *
// twelve or less than zero. If such a value is found,       *
// the numbers in feet and inches are adjusted to conform    *
// to a standard feet & inches expression. For example,      *
// 3 feet 14 inches would be adjusted to 4 feet 2 inches and *
// 5 feet -2 inches would be adjusted to 4 feet 10 inches.   *
//************************************************************

void FeetInches::simplify()
{
   if (inches >= 12)
   {
      feet += (inches / 12);
      inches = inches % 12;
   }
   else if (inches < 0)
   {
      feet -= ((abs(inches) / 12) + 1);
      inches = 12 - (abs(inches) % 12);
   }
}

//**********************************************
// Overloaded binary + operator.               *
//**********************************************

FeetInches FeetInches::operator + (const FeetInches &right)
{
   FeetInches temp;

   temp.inches = inches + right.inches;
   temp.feet = feet + right.feet;
   temp.simplify();
   return temp;
}

//**********************************************
// Overloaded binary - operator.               *
//**********************************************

FeetInches FeetInches::operator - (const FeetInches &right)
{
   FeetInches temp;

   temp.inches = inches - right.inches;
   temp.feet = feet - right.feet;
   temp.simplify();  
   return temp;
} 

FeetInches FeetInches::operator -- (){
    --inches;
    simplify();
    return *this;
}
FeetInches FeetInches::operator ++ (){
    ++inches;
    simplify();
    return *this;
}

FeetInches FeetInches::operator += (const FeetInches &right){
    inches += right.inches;
    feet+= right.inches;
    simplify();
    return *this;
    
}
bool FeetInches::operator <= (const FeetInches &right){
    if(feet <= right.feet){
        return true;
    } else if(feet == right.feet && inches <= right.inches){
        return true;
    }
    return false;
    
}

bool FeetInches::operator < (const FeetInches &right){
 if(feet <= right.feet){
     if(feet == right.feet & inches < right.inches){
         return true;
     }else if(feet < right.feet){
        return true;
     }
 }
 return false;
}

bool FeetInches::operator > (const FeetInches &right){
 if(feet >= right.feet){
     if(feet == right.feet & inches > right.inches){
         return true;
     }else if(feet > right.feet){
        return true;
     }
 }
 return false;
}

bool FeetInches::operator >= (const FeetInches &right){
    if(feet >= right.feet){
        return true;
    } else if(feet == right.feet && inches >= right.inches){
        return true;
    }
    return false;
    
}

bool FeetInches::operator != (const FeetInches &right){
    if(feet == right.feet && inches == right.inches){
        return false;
    }
    return true;
}
bool FeetInches::operator == (const FeetInches &right){
    if(feet == right.feet && inches == right.inches){
        return true;
    }
    return false;
}

FeetInches FeetInches::operator * (const FeetInches &right)
{
   FeetInches temp;

   temp.inches = inches * right.inches;
   temp.simplify();
   temp.feet = (feet * right.feet) + temp.feet;
   temp.simplify();
   return temp;
}


    




