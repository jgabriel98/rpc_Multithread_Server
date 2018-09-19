#include <iostream>
#include <string>
#include "rpc/client.h"

typedef struct{
    std::string ip;
    short porta;
} NetAddr;

int main() {
    // Creating a client that connects to the nameService
    rpc::client resolver("127.0.0.1", 7440);


    //auto addr = resolver.call("resolveName", "mathServer").as<NetAddr>;
    rpc::client client("127.0.0.1", 9000);

    // Calling a function with paramters and converting the result to int
    auto result = client.call("div", 2.0, 3.0).as<double>();
    std::cout << "The result of "<< 2.0<<"/"<<3.0 <<" is: " << result << std::endl;

    auto sqrt_result = client.call("sqrt", 9.0).as<double>();
    std::cout << "The result of sqrt("<<9.0f<<") is: " << sqrt_result << std::endl;

    return 0; 
}