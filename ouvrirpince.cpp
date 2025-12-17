#include "ouvrirpince.h"
#include "contexterobot.h"
#include <iostream>

void OuvrirPince::executer(ContexteRobot& ctx) {
    afficherNom();
    ctx.ouvrirPince();
}

void OuvrirPince::afficherNom() const {
    std::cout << "Action : OuvrirPince" << std::endl;
}
