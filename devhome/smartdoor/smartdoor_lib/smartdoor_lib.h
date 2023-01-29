#pragma once                           // Inclui esse cabeçalho apenas uma vez

#include <fstream>                     // Classe ifstream
#include <android-base/properties.h>   // Função GetBoolProperty
#include <sys/stat.h>                  // Função e struct stat
#include <random>                      // Geração de números aleatórios (valores simulados)

using namespace std;                   // Permite usar string diretamente ao invés de std::string

namespace devhome::smartdoor {       // Pacote Smartdoor

class Smartdoor {
    public:
        /**
         * Verifica se o diretório /sys/kernel/smartdoor existe. Se existir
         * o dispositivo Smartdoor está conectado via USB. Caso contrário,
         * verifica a propriedade devhome.smartdoor.allow_simulated
         * para ver se valores simulados podem ser usados.
         *
         * Retorna:
         *      0: dispositivo não encontrado
         *      1: sucesso
         *      2: simulado (disp. não encontrado, mas usando valores simulados)
         */
        int connect();

        /**
         * Acessa e seta o valor da door.
         *
         * Valor retornado/setado:
         *      0: door desligado
         *      1: door ligado
         */
        int getDoor();
        bool setDoor(int doorValue);


        /**
         * Acessa o nível de door atual conforme reportado
         * pelo sensor.
         *
         * Retorna:
         *      0: door desligado
         *      1: door ligado
         */
        int getValorPorta();

        /**
         * Threshold - método adaptativo para futuras implementações
         * onde o smartdoor entra no modo
         * automático, em que door será ligado se <condição>
         * Caso contrário, door é desligado.
         *
         * Valor retornado/setado:
         *      0: door desligado
         *      1: door ligado
         */
        int getThreshold();
        bool setThreshold(int thresholdValue);

    private:
        /**
         * Métodos para ler e escrever valores nos arquivos "door",
         * "valorPorta" ou "threshold" do diretório /sys/kernel/smartdoor.
         */
        int readFileValue(string file);
        bool writeFileValue(string file, int value);

        /**
         * Armazena valores simulados para o caso do dispositivo não estar
         * conectado, mas a propriedade devhome.smartdoor.allow_simulated
         * for true.
         */
         int simValorPorta = 88;
         int simThresholdValue = 42;
};

} // namespace
