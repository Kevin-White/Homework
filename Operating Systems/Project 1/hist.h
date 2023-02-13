#ifndef Hist_H
#define Hist_H
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;
class hist{
        private:
                string data[10];
                int count;
        public:
                hist();
                void add(string);
                string get(string);
                void display();
hist::hist(){
        count = 0;
        for(int i = 0; i < 10; i++){
                data[i] = "";
void hist::add(string userInput){
        if(count < 10){
                data[9 - count] = userInput;
                count++;
        }else{
                for(int i = 9; i > 0; i--){
                        data[i] = data[i-1];
                data[0] = userInput;
string hist::get(string userInput){
        int in;
        if(userInput == ""){
                in = 0;
        }else{
                in = atoi(userInput.c_str());
        if(in > count || in < 0){
                return "echo ERROR";
        }else{
                return data[10-count+in];
void hist::display(){
        for(int i = 0; i < count; i++){
                cout << count-i-1 << ": " << data[9-i] << endl;
#endif