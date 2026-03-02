#include <iostream>
#include <cmath>

struct Comp {
	double x;
	double y;
	double z;
};

class Vecteur3D {
	public:
		void set_comp(double const& x, double const& y, double const& z) {
			comp.x=x;
			comp.y=y;
			comp.z=z;
		}
		
		Comp get_comp() const {
			return comp;
		}
		
		void affiche() const {
			std::cout << comp.x << " " << comp.y << " " << comp.z << " ";
		}
		
		bool compare(Vecteur3D const& autreVecteur, double const& marge=1e-10) const {
			if ( (std::abs(autreVecteur.get_comp().x - comp.x) > marge) or (std::abs(autreVecteur.get_comp().y - comp.y) > marge) or (std::abs(autreVecteur.get_comp().z - comp.z) > marge)) {
				return false;
			}
			return true;
		}
		
		// Arithmetique de vecteurs
		Vecteur3D addition(Vecteur3D const& autreVecteur) const {
			Vecteur3D resultatVecteur;
			resultatVecteur.set_comp(comp.x+autreVecteur.comp.x, comp.y+autreVecteur.comp.y, comp.z+autreVecteur.comp.z);
			return resultatVecteur;
		}
		
		Vecteur3D soustraction(Vecteur3D const& autreVecteur) const {
			Vecteur3D resultatVecteur;
			resultatVecteur.set_comp(comp.x-autreVecteur.comp.x, comp.y-autreVecteur.comp.y, comp.z-autreVecteur.comp.z);
			return resultatVecteur;
		}
		
		Vecteur3D oppose() const {
			Vecteur3D resultatVecteur;
			resultatVecteur.set_comp(comp.x*(-1), comp.y*(-1), comp.z*(-1));
			return resultatVecteur;
		}
		
		Vecteur3D mult(double const& s) const {
			Vecteur3D resultatVecteur;
			resultatVecteur.set_comp(comp.x*s, comp.y*s, comp.z*s);
			return resultatVecteur;
		}
		
		double prod_scal(Vecteur3D const& autreVecteur) const {
			return comp.x*autreVecteur.comp.x+comp.y*autreVecteur.comp.y+comp.z*autreVecteur.comp.z;
		}
		
		Vecteur3D prod_vect(Vecteur3D const& autreVecteur) const {
			Comp resultatComp;
			resultatComp.x = comp.y*autreVecteur.comp.z - comp.z*autreVecteur.comp.y;
			resultatComp.y = comp.z*autreVecteur.comp.x - comp.x*autreVecteur.comp.z;
			resultatComp.z = comp.x*autreVecteur.comp.y - comp.y*autreVecteur.comp.x;
			Vecteur3D resultatVecteur;
			resultatVecteur.set_comp(resultatComp.x, resultatComp.y, resultatComp.z);
			return resultatVecteur;
		}
		
		double norme2() const {
			return std::pow(comp.x, 2)+std::pow(comp.y, 2)+std::pow(comp.z, 2);
		}
		
		double norme() const {
			return std::sqrt(norme2());
		}
		
		Vecteur3D unitaire() const {
			Vecteur3D resultatVecteur;
			double n=norme();
			resultatVecteur.set_comp(comp.x/n, comp.y/n, comp.z/n);
			return resultatVecteur;
		}
		
	private:
		Comp comp;
};


int main() {
	Vecteur3D vecteur1;
	Vecteur3D vecteur2;
	
	vecteur1.set_comp(2, 3, 4);
	vecteur2.set_comp(3, 3, 4);
	
	std::cout << vecteur1.norme() << std::endl;
	std::cout << vecteur1.norme2() << std::endl;
	std::cout << vecteur2.norme() << std::endl;
	
	if (vecteur1.compare(vecteur2, 1)) {
		std::cout << "Same vector" << std::endl;
	} else { std::cout << "Diff vector" << std::endl; }
	
	Vecteur3D vecteur3;
	vecteur3 = vecteur1.addition(vecteur2);
	vecteur3.affiche();
	
	vecteur3 = vecteur1.unitaire();
	vecteur3.affiche();

	return 0;
}
