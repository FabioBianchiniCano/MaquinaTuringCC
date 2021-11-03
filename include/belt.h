#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Belt {
  private:
    string belt;
    int pointer = 1;
    char blank = '.';
    
  public:
    Belt();
    Belt(string, char);
    Belt(string);
    string getBelt();
    int getPointer();
    string getCurrent();
    string getRemainer();
    string rightChar();
    string leftChar();
    string nextCharByDir(string);
    void enlargeLeft();
    void enlargeRight();
    void writeChar(char);
    void operator=(Belt);
    friend ostream& operator<<(ostream&, const Belt&);

};