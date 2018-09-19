#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include "rpc/server.h"
#include "rpc/this_handler.h"

using namespace std;


typedef struct{
    string ip;
    short porta;
} NetAddr;



void load_Names(const char *source, map<string, NetAddr> &mapaNomes){
    FILE *arq = fopen(source, "r");
    char line[256], name[100], ip[100];
    short port;

    while(!feof(arq)){
        if(fscanf(arq, "%[^\n]\n",line) <1) continue;
        if(line[0] == '#') continue;

        size_t pos = string(line).find('#');        //desconsidera tudo da linha apos '#'
        if( pos != string::npos ) line[pos] = '\0';
        
        sscanf(line, "%s%s%hi", name, ip, &port);
        mapaNomes[name] = {ip, port};
    }

    fclose(arq);
}

void foo(map<string, string> mapa){
    printf("foo chamado");
    string str = mapa.begin()->first;
}

NetAddr resolveName(string nome, map<string, NetAddr> mapaNomes){
    return mapaNomes[nome];
}



void run_service(){

}


int main(){
    rpc::server servidor(7440);
    map<string, NetAddr> mapaNomes;

    load_Names("names.txt", mapaNomes);

    cout<<"Nomes encontrados:\n";
    for(const auto &i: mapaNomes){
        cout<<i.first <<'\t'<< i.second.ip<<'\t'<< i.second.porta<<endl;
    }

    //servidor.bind("resolveName", &resolveName);
    servidor.bind("foo", &foo);


    servidor.run();

    return 0;
}