#include "soapcalcService.h"
#include "calc.nsmap"


int main(int argc, char **argv)
{ calcService calc;
  if (argc < 2)
    calc.serve();       /* serve as CGI application */
  else
  { int port = atoi(argv[1]);
    if (!port)
    { fprintf(stderr, "Usage: calcserver++ <port>\n");
      exit(0);
    }
    /* run iterative server on port until fatal error */
    if (calc.run(port))
    { calc.soap_stream_fault(std::cerr);
      exit(-1);
    }
  }
  return 0;
}

int calcService::add(double a, double b, double *result)
{
  *result = a + b;
  return SOAP_OK;
}

int calcService::mul(double a, double b, double *result)
{
  *result = a * b;
  return SOAP_OK;
}


int calcService::sub(double a, double b, double *result)
{
  *result = a - b;
  return SOAP_OK;
}


int calcService::div(double a, double b, double *result)
{
  *result = a / b;
  return SOAP_OK;
}
