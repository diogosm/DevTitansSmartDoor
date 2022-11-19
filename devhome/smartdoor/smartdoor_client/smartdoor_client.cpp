#include "smartdoor_client.h"

using namespace std;                  // Permite usar o cout e endl diretamente ao invés de std::cout

namespace devhome::smartdoor {      // Entra no pacote devtitans::door

void SmartdoorClient::start(int argc, char **argv) {
    cout << "Cliente Smartdoor!" << endl;

    if (argc < 2) {
        cout << "Sintaxe: " << argv[0] << "  " << endl;
        cout << "    Comandos: get-door, set-door, get-valorPorta, get-threshold, set-threshold" << endl;
        exit(1);
    }

    Smartdoor smartdoor;             // Classe da biblioteca Smartdoor

    // Comandos get-door e set-door
    if (!strcmp(argv[1], "get-door")) {
        cout << "Valor da Porta: " << smartdoor.getDoor() << endl;
    }
    //Testar setar 0 ou 1
    else if (!strcmp(argv[1], "set-door")){
        int doorValue = atoi(argv[2]);
        if (smartdoor.setDoor(doorValue))
            cout << "Valor da porta setado para " << doorValue << endl;
        else
            cout << "Erro ao setar valor da porta para " << doorValue << endl;
    }

    // Comando get-ValorPorta
    else if (!strcmp(argv[1], "get-valorPorta")) {
        cout << "Valor atual da porta: " << smartdoor.getValorPorta() << endl;
    }

    // Comandos get-threshold e set-threshold
    else if (!strcmp(argv[1], "get-threshold")) {
        cout << "Valor do Threshold: " << smartdoor.getThreshold() << endl;
    }
    else if (!strcmp(argv[1], "set-threshold")) {
        int thresholdValue = atoi(argv[2]);
        if (smartdoor.setThreshold(thresholdValue))
            cout << "Valor do Threshold setado para " << thresholdValue << endl;
        else
            cout << "Erro ao setar valor do Threshold para " << thresholdValue << endl;
    }

    else {
        cout << "Comando inválido." << endl;
        exit(1);
    }
}

} // namespace



// MAIN

using namespace devhome::smartdoor;

int main(int argc, char **argv) {
    SmartdoorClient client;               
    client.start(argc, argv);             
    return 0;
}
