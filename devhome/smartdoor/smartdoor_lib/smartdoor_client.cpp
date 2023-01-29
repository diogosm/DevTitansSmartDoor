#include "smartdoor_lib.h"

using namespace std;                                   // Permite usar string, ifstream diretamente ao invés de std::string
using namespace android::base;                         // Permite usar GetBoolProperty ao invés de android::base::GetBoolProperty

namespace devhome::smartdoor {                       // Entra no pacote devhome::smartdoor

int Smartdoor::connect() {
    char dirPath[] = "/sys/kernel/smartdoor";
    struct stat dirStat;
    if (stat(dirPath, &dirStat) == 0)
        if (S_ISDIR(dirStat.st_mode))
            return 1;                                  // Se o diretório existir, retorna 1

    // Diretório não existe, vamos verificar a propriedade
    bool allowSimulated = GetBoolProperty("devhome.smartdoor.allow_simulated", true);
    if (!allowSimulated)
        return 0;                                      // Dispositivo não encontrado
    else
        return 2;                                      // Usando valores simulados
}

int Smartdoor::readFileValue(string file) {
    int connected = this->connect();

    if (connected == 2) {                               // Usando valores simulados
        if (file == "door") //verificar "door"
            return this->simValorPorta;
        else if (file == "threshold")
            return this->simThresholdValue;
        else {
            // "door" (aberto_ou_fechado): Gera um número: 0 ou 1
            random_device dev;
            mt19937 rng(dev());
            uniform_int_distribution<mt19937::result_type> dist100(0,1);
            return (int) dist100(rng);
        }
    }

    else if (connected == 1) {                          // Conectado. Vamos solicitar o valor ao dispositivo
        int value;
        string filename = string("/sys/kernel/smartdoor/") + file;
        ifstream file(filename);                        // Abre o arquivo do módulo do kernel

        if (file.is_open()) {                           // Verifica se o arquivo foi aberto com sucesso
            file >> value;                              // Lê um inteiro do arquivo
            file.close();
            return value;
        }
    }

    // Se chegou aqui, não foi possível conectar ou se comunicar com o dispositivo
    return -1;
}

bool Smartdoor::writeFileValue(string file, int value) {
    int connected = this->connect();

    if (connected == 2) {                                // Usando valores simulados
        if (file == "door") {// verificar "door"
            this->simValorPorta = value;
            return true;
        }
        else if (file == "threshold") {
            this->simThresholdValue = value;
            return true;
        }
    }

    else if (connected == 1) {                          // Conectado. Vamos solicitar o valor ao dispositivo
        string filename = string("/sys/kernel/smartdoor/") + file;
        ofstream file(filename, ios::trunc);            // Abre o arquivo limpando o seu conteúdo

        if (file.is_open()) {                           // Verifica se o arquivo foi aberto com sucesso
            file << value;                              // Escreve o valorPorta no arquivo
            file.close();
            return true;
        }
    }

    // Se chegou aqui, não foi possível conectar ou se comunicar com o dispositivo
    return false;
}

int Smartdoor::getDoor() {
    return this->readFileValue("door");
}

bool Smartdoor::setDoor(int valorPorta) {
    return this->writeFileValue("door", valorPorta);
}

int Smartdoor::getValorPorta() {
    return this->readFileValue("door");
}

int Smartdoor::getThreshold() {
    return this->readFileValue("threshold");
}

bool Smartdoor::setThreshold(int thresholdValue) {
    return this->writeFileValue("threshold", thresholdValue);
}

} // namespace
