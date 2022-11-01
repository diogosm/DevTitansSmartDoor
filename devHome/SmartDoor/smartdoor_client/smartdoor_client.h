#pragma once                      // Inclui esse cabeçalho apenas uma vez

#include <iostream>               // std::cout (char-out) e std::endl (end-line)
#include <string.h>               // Função strcmp
#include <stdlib.h>               // Função atoi

#include "smartdoor_lib.h"        // Classe Smartlamp

namespace devtitans::smartdoor {  // Pacote que a classe abaixo pertence

class SmartDoor {           // Classe

    public:
        void start(int argc, char **argv);

};

} // namespace
