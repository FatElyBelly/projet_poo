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
