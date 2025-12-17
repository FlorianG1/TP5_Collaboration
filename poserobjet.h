#ifndef POSEROBJET_H
#define POSEROBJET_H
#include "actionrobot.h"
#include "sequenceactions.h"
#include "AllerA.h"
#include "OuvrirPince.h"
#include <iostream>

class PoserObjet : public ActionRobot {
private:
    double m_x, m_y, m_z;

    SequenceActions m_actions;

public:
    // Constructeur
    PoserObjet(double x, double y, double z);

    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};

#endif
