//********************************************************************
//Name:Kevin White
//Class: COSC 1436 SP21
//Instructor: Marwa Hassan
//Assignment 5
//Date: 3/18/2021
//Program description: Takes text from the user and encrypts the text
//*********************************************************************

/* Marwa Hassan SP21 */
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

void tokenize(const string&, vector<string>&);
int spaceCount(string userInput);
string unpunct(string userInput);
void encrypt( vector<string>&);

int main ()
{
    string userInput;
    int spCount;
    vector<string> tokens;

    cout<<"Please enter a text: "<<endl;
    getline(cin, userInput);
    cout << endl;
    spCount = spaceCount(userInput);  //write the function spaceCount
    cout<<"The text you entered has "<< spCount+1 <<" tokens."<<endl;
    
    userInput = unpunct(userInput);  //write the function unpunct
    
    cout<<"After removing the punctuation: "<< endl <<userInput<<endl;
    
    // Display the tokens
    cout<<"The encrypted tokens: \n";
    tokenize(userInput, tokens);
    encrypt(tokens);
    for(auto e : tokens)
        cout << e <<endl;
    cout << endl;
    // write and call the functions needed to perform the encryption
    
    // display the encrypted strings (the results)
    cout << "The encrypted text:" << endl;
    for(auto e : tokens)
        cout << e <<"";
    cout<<endl;
    
    return 0;
}


void tokenize(const string& s, vector<string>& tokens)
{
    int tokenStart = 0;  // Starting position of the next token
    
    // Find the first occurrence of the delimiter.
    int delim = s.find(' ');
    
    // While we haven't run out of delimiters...
    while (delim != string::npos)
    {
        // Extract the token...substring
        string tok = s.substr(tokenStart, delim - tokenStart);
        
        // Push the token onto the tokens vector.
        if(tok != "") //if the user enters multiple spaces, skip
            tokens.push_back(tok);
        
        // Move delim to the next character position.
        delim++;
        
        // Move tokenStart to delim.
        tokenStart = delim;
        
        // Find the next occurrence of the delimiter staring from the current position.
        delim = s.find(' ', delim);
    }
    //If no more delimiters, extract the last token.
    //Modifed Pr10-23.cpp:
    //The if condition is moved outside the loop in case there is only one token
    if (delim == string::npos)
    {
        // Extract the token.
        //string tok = s.substr(tokenStart, delim - tokenStart); //this also works
        string tok = s.substr(tokenStart, (s.length()) - tokenStart);
        
        // Push the token onto the vector.
        tokens.push_back(tok);
    }
}

//*************************************************
// spaceCount function
// This function counts the number of spaces in the string
//
// Return Value
// ------------
// int count The number of paces
//
// Parameters
// ------------
// string userInput The string the user enters
//*************************************************
int spaceCount(string userInput)
{
    int count = 0;
    for(int i = 0; i < userInput.size(); i++){
        if(userInput[i] == ' '){
            count++;
        }
    }
    return count;
}

//*************************************************
// unpunct function
// This function Removes punctuation
//
// Return Value
// ------------
// string userInput strinf without punctuation
//
// Parameters
// ------------
// string userInput The users string
//*************************************************
string unpunct(string userInput)
{
    for(int i = 0; i < userInput.size(); i++){
        if(ispunct(userInput[i])){
            userInput.erase(i--, 1);
        }
    }
    return userInput;
}

//*************************************************
// encrypt function
// This function encrypts the tokens
//
// Return Value
// ------------
// N/A
//
// Parameters
// ------------
// vector <string> tokens Holds every word from the origional string the user input
//*************************************************
void encrypt(vector<string>& tokens){
    for(int i = 0; i < tokens.size(); i++){
        if(tokens[i].size() <= 3){
            string hold = ">";
            for(int j = tokens[i].size(); j >= 0; j--){
                hold += tokens[i][j];
            }
            hold += "[";
            tokens[i] = hold;
        }else if(tolower(tokens[i][0]) == 'a' || tolower(tokens[i][0]) == 'e' || tolower(tokens[i][0]) == 'i' || tolower(tokens[i][0]) == 'o' || tolower(tokens[i][0]) == 'u' ){
            string hold;
            hold.append(tokens[i], tokens[i].size()-3,tokens[i].size());
            hold += '@';
            hold.append(tokens[i], 0, tokens[i].size()-3);
            tokens[i] = hold;
        }else{
            string hold;
            hold.append(tokens[i], 3, tokens[i].size());
            hold.append(tokens[i], 0, 3);
            hold += "*";
            tokens[i] = hold;
        }
    }
}
