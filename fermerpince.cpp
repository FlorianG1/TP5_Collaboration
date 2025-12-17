#include "fermerpince.h"
#include "contexterobot.h"
#include <iostream>

void FermerPince::executer(ContexteRobot &ctx) {
    afficherNom();
    ctx.fermerPince();
}

void FermerPince::afficherNom() const {
    std::cout << "Action : FermerPince" << std::endl;
}
