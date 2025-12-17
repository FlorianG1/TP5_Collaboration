#include "poserObjet.h"
using namespace std;

PoserObjet::PoserObjet(double p_x, double p_y, double p_z) : m_x(p_x), m_y(p_y), m_z(p_z) {}

void PoserObjet::executer(ContexteRobot& ctx) {
    ctx.deplacerVers(m_x, m_y,  m_z);
    ctx.deplacerVers(m_x, m_y,  (m_z - m_z));
    ctx.ouvrirPince();
    ctx.deplacerVers(m_x, m_y,  m_z);
}

void PoserObjet::afficherNom() const {
    cout << "Action : Deplacer de " << m_x << "," << m_y << "," << m_z << "." << endl;
}
