#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// trouver la taille de la clé
int tailleCle(const string cle)
{
    return static_cast<int>(cle.size());
}

// vérifier si la clé est valide
void verificationCle(string& cle)
{
    int i{ 0 };
    while (tailleCle(cle) < 5 || tailleCle(cle) > 20)
    {
        cout << "Erreur : votre clé doit contenir entre 5 et 20 caractères.\nEntrer une clé valide : ";
        cin >> cle;
    }
    while (cle[i])
    {
        if (cle[i] < 33 || cle[i] > 126)
        {
            cout << "Erreur : votre clé ne doit contenir que des caracteres anglais.\nEntrer une clé valide : ";
            cin >> cle;
            i = 0;
        }
        else
        {
            i++;
        }
    }
}

// encodage du fichier
bool encodage(const string& fichierEntre, const string& fichierSorti, const string& cle)
{
    ifstream entre(fichierEntre);
    ofstream sorti(fichierSorti);

    // verifie si les fichiers ont été ouvert et créé
    if (entre && sorti)
    {
        char lettreFichier{ ' ' };
        int positionLettreCle{ 0 };

        // recupère les caractères du fichier un par un
        while (entre.get(lettreFichier))
        {

            // verifie si le caractère en compris en 32 et 126
            if (lettreFichier >= 32 && lettreFichier <= 126)
            {
                int decalage{ cle[positionLettreCle] - 'a' };
                int lettreEncodee{ lettreFichier + decalage };
                while (lettreEncodee > 126)
                {
                    lettreEncodee -= 95;
                }
                sorti << char(lettreEncodee);
                positionLettreCle = (positionLettreCle + 1) % tailleCle(cle);
            }

            // si le caractère est un retour à la ligne
            else if (lettreFichier == 10 || lettreFichier == 13)
            {
                sorti << lettreFichier;
            }
            else
            {
                return false;
            }
        }
        cout << "Encodage terminé." << endl;
    }
    else
    {
        cout << "Erreur lors de l'ouverture des fichiers." << endl;
    }
    return true;
}

// decodage du fichier
void decodage(const string& fichierEntre, const string& fichierSorti, const string& cle)
{
    ifstream entre(fichierEntre);
    ofstream sorti(fichierSorti);

    // verifie si les fichiers ont été ouvert et créé
    if (entre && sorti)
    {
        char lettreFichier{ ' ' };
        int positionLettreCle{ 0 };

        // recupère les caractères du fichier un par un
        while (entre.get(lettreFichier))
        {

            // si le caractère est un retour à la ligne
            if (lettreFichier == 10 || lettreFichier == 13)
            {
                sorti << lettreFichier;
            }
            else
            {
                int decalage{ cle[positionLettreCle] - 'a' };
                int lettreDecodee{ lettreFichier - decalage };
                while (lettreDecodee < 32)
                {
                    lettreDecodee += 95;
                }
                sorti << char(lettreDecodee);
                positionLettreCle = (positionLettreCle + 1) % tailleCle(cle);
            }
        }
        cout << "Décodage terminé." << endl;
    }
    else
    {
        cout << "Erreur lors de l'ouverture des fichiers." << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "");

    int choix{ 0 };
    string fichierEntre{ "" };
    string fichierSorti{ "" };
    string cle{ "" };

    // menu
    while (choix != 1 && choix != 2)
    {
        cout << "---------- M_E_N_U ----------\nQue voulez-vous faire ?\n1) Encoder un fichier.\n2) Décoder un fichier." << endl;
        cin >> choix;
    }
    cout << "Entrer le nom du fichier à traiter : ";
    cin >> fichierEntre;
    cout << "Entrer le nom du fichier à produire : ";
    cin >> fichierSorti;
    cout << "Entrer la clé de traitement : ";
    cin >> cle;

    // verifie si la clé est valide
    verificationCle(cle);

    // determine la routine à exécuter
    if (choix == 1)
    {
        if (!encodage(fichierEntre, fichierSorti, cle))
        {
            cout << "Code erreur -1 : Certains caractères du fichier ne sont pas supportés" << endl;
        }
    }
    else
    {
        decodage(fichierEntre, fichierSorti, cle);
    }
    system("pause");
    return 0;
}