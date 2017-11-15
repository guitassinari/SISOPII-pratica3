//gsoap ns service name:        calc Simple calculator service
//gsoap ns service protocol:    SOAP
//gsoap ns service style:       rpc
//gsoap ns service encoding:    encoded
//gsoap ns service namespace:   http://localhost/calc.wsdl
//gsoap ns service location:    http://localhost:8000


//gsoap ns schema namespace:    urn:calc


//gsoap ns service method-documentation: add Sums two values
int ns__add(double a, double b, double *result);

int ns__mul(double a, double b, double *result);

int ns__sub(double a, double b, double *result);

int ns__div(double a, double b, double *result);
