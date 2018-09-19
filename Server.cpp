#include "rpc/server.h"
#include "rpc/this_handler.h"
#include <math.h>

double divide(double a, double b) {
    if(b == 0){
        rpc::this_handler().respond_error("Division by zero");
    }
    return a / b;
}

struct subtractor{
    double operator()(double a, double b) { return a - b; }
};

struct multiplier{
    double multiply(double a, double b) { return a * b; }
};

int main(int argc, char *args[]){
    rpc::server servidor(9000);
    servidor.bind("div", &divide);
    servidor.bind("sqrt", [](double a){
        return sqrt(a);
    });

    servidor.run();
}