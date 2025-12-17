#include "rotation.h"
#include <iostream>
using namespace std;

Rotation::Rotation(int p_angle) {
    m_angle = p_angle;
}

void Rotation::executer(ContexteRobot& ctx) {
    afficherNom();
    ctx.rotation(m_angle);
}

void Rotation::afficherNom() const {
    cout << "Action : Rotation " << m_angle << " degres"<< endl;
}
