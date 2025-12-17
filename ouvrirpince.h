#ifndef OUVRIRPINCE_H
#define OUVRIRPINCE_H
#include "actionrobot.h"
#include "contexterobot.h"
#include <iostream>

class OuvrirPince : public ActionRobot {
public:
    OuvrirPince() = default;

    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};

#endif // OUVRIRPINCE_H
