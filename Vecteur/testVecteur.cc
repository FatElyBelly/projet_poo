#include <iostream>
#include "Vecteur.h"

using namespace std;

int main() {
	Vecteur3D vecteur1;
	Vecteur3D vecteur2;
	
	vecteur1.set_comp(2, 3, 4);
	vecteur2.set_comp(3, 3, 4);
	
	cout << vecteur1.norme() << endl;
	cout << vecteur1.norme2() << endl;
	cout << vecteur2.norme() << endl;
	
	if (vecteur1.compare(vecteur2, 1)) {
		cout << "Same vector" << endl;
	} else { cout << "Diff vector" << endl; }
	
	Vecteur3D vecteur3;
	vecteur3 = vecteur1.addition(vecteur2);
	vecteur3.affiche();
	
	vecteur3 = vecteur1.unitaire();
	vecteur3.affiche();

	return 0;
}
