#ifndef ALLERA_H
#define ALLERA_H
#include "actionrobot.h"
#include "contexterobot.h"
#include <iostream>

class AllerA : public ActionRobot {
private:
    double m_x, m_y, m_z;

public:
    // Constructeur
    AllerA(double p_x, double p_y, double p_z);

    // Actions
    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};

#endif // ALLERA_H
