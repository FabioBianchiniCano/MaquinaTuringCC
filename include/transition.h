#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Transition {
  private:
    string inputChar;
    string outputChar;
    string idStateTo;
    string idStateFrom;
    string direction;

  public:
    Transition();
    Transition(string, string, string, string, string);
    string getInputChar();
    string getOutputChar();
    string getIdStateTo();
    string getIdStateFrom();
    string getDirection();
    void setInputChar(string);
    void setOutputChar(string);
    void setIdStateTo(string);
    void setStateFrom(string);
    void setDirection(string);
    void operator=(Transition);
    friend ostream& operator<<(ostream&, const Transition&);

};