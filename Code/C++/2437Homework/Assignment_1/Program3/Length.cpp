#include <string>
#include <iostream>
#include "Length.h"
using namespace std;
//Kevin White
//Worked on with Will Jamison

Length::Length(){
    yards = 0;
    feet = 0;
    inches = 0;

}

Length::Length(int y, int f, int i){
    yards = y;
    feet = f;
    inches = i;
}

void Length::Clean(){
    if(inches >= 12){
        while (inches >= 12)
        {
            feet++;
            inches -= 12;
        }
        
    }
    if(feet >= 3){
        while (feet >= 3)
        {
            yards++;
            feet -= 3;
        }
        
    }
}

void Length::setYard(int y){
    yards = y;
}
int Length::getYard(){
    return yards;
}

void Length::setFeet(int f){
    feet = f;
    Clean();
}
int Length::getFeet(){
    return feet;
}

void Length::setInch(int i){
    inches = i;
    Clean();
}
int Length::getInch(){
    return inches;
}

Length Length::operator+(const Length &right){
    Length add;
    add.inches = this->inches + right.inches;
    add.feet = this->feet + right.feet;
    add.yards = this->yards + right.yards;
    add.Clean();
    return add;

}

Length Length::operator+(const int right){
    Length add;
    add.inches += right;
    add.Clean();
    return add;
}

Length Length::operator-(const Length &right){
    Length sub;
    sub.inches = this->inches - right.inches;
    sub.feet = this->feet - right.feet;
    sub.yards = this->yards - right.yards;
    sub.Clean();
    return sub;
}

void Length::operator=(const Length &right){
    this->inches = right.inches;
    this->feet = right.feet;
    this->yards = right.yards;
    Clean();
}

bool Length::operator==(const Length &right){
if (this->yards == right.yards){
    if(this->feet == right.feet){
        if(this->inches == this->inches){
            return true;
        }
    }
}
return false;
}

bool Length::operator<(const Length &right){
    if(this->yards < right.yards){
        return true;
    }else if(this->yards == right.yards){
        if(this->feet < right.feet){
            return true;
        }else if(this->feet == right.feet){
            if(this->inches < right.inches){
            return true;
            }
        }
    }
    return false;
}

bool Length::operator>(const Length &right){
    if(this->yards > right.yards){
        return true;
    }else if(this->yards == right.yards){
        if(this->feet > right.feet){
            return true;
        }else if(this->feet == right.feet){
            if(this->inches > right.inches){
            return true;
            }
        }
    }
    return false;
}

bool Length::operator!=(const Length &right){
if (this->yards == right.yards){
    if(this->feet == right.feet){
        if(this->inches == this->inches){
            return false;
        }
    }
}
return true;
}

void Length::operator+=(const Length &right){
    this->yards += right.yards;
    this->feet += right.feet;
    this->inches += right.inches;
    this->Clean();
}

void Length::operator+=(const int right){
    this->inches = right;
    this->Clean();
}