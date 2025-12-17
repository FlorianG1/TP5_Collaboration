#include <iostream>
#include <fstream>
#include <string>
#include "actionrobot.h"
#include "contexterobot.h"
#include "sequenceactions.h"
#include "ouvrirpince.h"
#include "fermerpince.h"
#include "deplacer.h"
#include "allera.h"
#include "poserobjet.h"
#include "attendre.h"
#include "rotation.h"
using namespace std;

int main() {

    ContexteRobot ctx(0, 0, 100, true);
    SequenceActions plan;

    ifstream fichier("data/plan.txt");
    if (!fichier.is_open()) {
        cerr << "Erreur : imposssible d'ouvrir le fichier plan.txt" << endl;
        return 1;
    }

    ofstream journal("data/journal.txt");
    if (!fichier.is_open()) {
        cout << "Erreur : impossible d'ouvrir le fichier journal.txt " << endl;
        return 1;
    }

    string commande;
    cout << "--- Execution du plan ---" << endl;

    while (fichier >> commande) {
        if (commande == "DEPLACER") {
            double dx, dy, dz;
            fichier >> dx >> dy >> dz;
            plan.ajouter(new Deplacer(dx, dy, dz));
            journal.seekp(0, ios::end);
            journal << commande << endl;
        }

        else if (commande == "OUVRIR_PINCE") {
            plan.ajouter(new OuvrirPince());
            journal.seekp(0, ios::end);
            journal << commande << endl;
        }

        else if (commande == "FERMER_PINCE") {
            plan.ajouter(new FermerPince());
            journal.seekp(0, ios::end);
            journal << commande << endl;
        }

        else if (commande == "POSER_OBJET") {
            double dx, dy, dz;
            fichier >> dx >> dy >> dz;
            plan.ajouter(new PoserObjet(dx, dy, dz));
            journal.seekp(0, ios::end);
            journal << commande << endl;
        }

        else if (commande == "ALLER_A") {
            double dx, dy, dz;
            fichier >> dx >> dy >> dz;
            plan.ajouter(new AllerA(dx, dy, dz));
            journal.seekp(0, ios::end);
            journal << commande << endl;
        }

        else if (commande == "ATTENDRE_2") {
            plan.ajouter(new Attendre(2));
            journal.seekp(0, ios::end);
            journal<<commande<<endl;
        }

        else if (commande == "ROTATION") {
            int angleRobot;
            fichier >> angleRobot;
            plan.ajouter(new Rotation(angleRobot));
            journal.seekp(0, ios::end);
            journal<<commande<<endl;
        }

        else {
            cerr << "Commande inconnue : " << commande << endl;
        }

    }

    plan.executer(ctx);
    fichier.close();
    journal.close();

    cout << "\n--- Etat final du robot ---" << endl;
    ctx.afficherPosition();
    plan.nettoyer();

    return 0;
}
