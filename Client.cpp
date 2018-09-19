#include <iostream>
#include "rpc/client.h"

int main() {
    // Creating a client that connects to the localhost on port 8080
    rpc::client client("127.0.0.1", 7441);

    // Calling a function with paramters and converting the result to int
    auto result = client.call("add", 2, 3).as<int>();
    std::cout << "The result is: " << result << std::endl;

    float sqrt_result = client.call("sqrt", 9.0f).as<float>();
    std::cout << "The result of sqrt("<<9.0f<<") is: " << sqrt_result << std::endl;

    return 0; 
}