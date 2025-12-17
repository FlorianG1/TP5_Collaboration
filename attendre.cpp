#include "attendre.h"
#include <iostream>

Attendre::Attendre(int p_duree)
{
    m_duree = p_duree;
}

void Attendre::executer(ContexteRobot& ctx){
    afficherNom();
    ctx.attendre(m_duree);
}

void Attendre::afficherNom() const {
    std::cout << "Action : Attente de "<< m_duree << std::endl;
}
