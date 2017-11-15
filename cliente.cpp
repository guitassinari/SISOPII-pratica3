#include "soapcalcProxy.h"
#include "calc.nsmap"
#include <iostream>
#include <string>

const char server[] = "http://localhost:8000";


int main(int argc, char **argv)
{
  calcProxy calc;
  //mudar endpoint se necessario
  calc.soap_endpoint = server;
  double result;

  std::string command;
  int finish = 0;

  while(finish == 0){
    std::getline (std::cin, command);

    char op;

    if(command.find("+")!=std::string::npos){
      op = '+';
    } else if (command.find("-")!=std::string::npos) {
      op = '-';
    } else if (command.find("*")!=std::string::npos) {
      op = '*';
    } else if (command.find("/")!=std::string::npos) {
      op = '/';
    }

    char * c = new char[command.length() + 1];
    strcpy(c, command.c_str());
    char * number = strtok(c, &op);
    int valid = 1;
    int gotFirst = 0;
    double firstNumber = NULL;
    double secondNumber = NULL;
    while (number != NULL)
    {
      if((int)*number < 48 || (int)*number > 57){
        valid = 0;
      }
      if(gotFirst == 0){
        gotFirst = 1;
        firstNumber = atof(number);
      } else {
        secondNumber = atof(number);
      }
      number = strtok(NULL, &op);
    }

    if(valid == 1){
      switch(op){
        case '+':
        if(calc.add(firstNumber, secondNumber, &result) == SOAP_OK) {
          std::cout << result << '\n';
        } else {
          calc.soap_stream_fault(std::cerr);
        }
        break;
        case '-':
        if(calc.sub(firstNumber, secondNumber, &result) == SOAP_OK) {
          std::cout << result << '\n';
        } else {
          calc.soap_stream_fault(std::cerr);
        }
        break;
        case '*':
        if(calc.mul(firstNumber, secondNumber, &result) == SOAP_OK) {
          std::cout << result << '\n';
        } else {
          calc.soap_stream_fault(std::cerr);
        }
        break;
        case '/':
        if(secondNumber == 0){
          std::cout << "Divisao por zero";
          break;
        }
        if(firstNumber == 0){
          std::cout << "0";
          break;
        }
        if(calc.div(firstNumber, secondNumber, &result) == SOAP_OK) {
          std::cout << result << '\n';
        } else {
          calc.soap_stream_fault(std::cerr);
        }
        break;
      }
    } else {
      std::cout << "Operadores invalidos";
    }
  }



  return 0;
}
