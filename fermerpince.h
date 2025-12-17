#ifndef FERMERPINCE_H
#define FERMERPINCE_H
#include "actionrobot.h"
#include "contexterobot.h"
#include <iostream>

class FermerPince : public ActionRobot {
public:
    FermerPince() = default;

    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};

#endif // FERMERPINCE_H
