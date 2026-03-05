#include <iostream>
#include <cmath>

class Vecteur3D {
	public:
		// Sets
		void set_comp(double const& x, double const& y, double const& z) {
			comp_x=x;
			comp_y=y;
			comp_z=z;
		}
		
		// Gets
		double get_comp_x() const {
			return comp_x;
		}
		double get_comp_y() const {
			return comp_y;
		}
		double get_comp_z() const {
			return comp_z;
		}
		
		// Affiche
		void affiche() const {
			std::cout << comp_x << " " << comp_y << " " << comp_z << " ";
		}
		
		// Arithmetique de vecteurs
		bool compare(Vecteur3D const& autreVecteur, double const& marge=1e-10) const {
			if ( (std::abs(autreVecteur.get_comp_x() - comp_x) > marge) or (std::abs(autreVecteur.get_comp_y() - comp_y) > marge) or (std::abs(autreVecteur.get_comp_z() - comp_z) > marge)) {
				return false;
			}
			return true;
		}
		
		Vecteur3D addition(Vecteur3D const& autreVecteur) const {
			Vecteur3D resultatVecteur;
			resultatVecteur.set_comp(comp_x+autreVecteur.get_comp_x(), comp_y+autreVecteur.get_comp_y(), comp_z+autreVecteur.get_comp_z());
			return resultatVecteur;
		}
		
		Vecteur3D soustraction(Vecteur3D const& autreVecteur) const {
			Vecteur3D resultatVecteur;
			resultatVecteur.set_comp(comp_x-autreVecteur.get_comp_x(), comp_y-autreVecteur.get_comp_y(), comp_z-autreVecteur.get_comp_z());
			return resultatVecteur;
		}
		
		Vecteur3D oppose() const {
			Vecteur3D resultatVecteur;
			resultatVecteur.set_comp(comp_x*(-1), comp_y*(-1), comp_z*(-1));
			return resultatVecteur;
		}
		
		Vecteur3D mult(double const& s) const {
			Vecteur3D resultatVecteur;
			resultatVecteur.set_comp(comp_x*s, comp_y*s, comp_z*s);
			return resultatVecteur;
		}
		
		double prod_scal(Vecteur3D const& autreVecteur) const {
			return comp_x*autreVecteur.get_comp_x()+comp_y*autreVecteur.get_comp_y()+comp_z*autreVecteur.get_comp_z();
		}
		
		Vecteur3D prod_vect(Vecteur3D const& autreVecteur) const {
			Vecteur3D resultatVecteur;
			resultatVecteur.set_comp(comp_y*autreVecteur.get_comp_z() - comp_z*autreVecteur.get_comp_y(), comp_z*autreVecteur.get_comp_x() - comp_x*autreVecteur.get_comp_z(), comp_x*autreVecteur.get_comp_y() - comp_y*autreVecteur.get_comp_x());
			return resultatVecteur;
		}
		
		double norme2() const {
			return std::pow(comp_x, 2)+std::pow(comp_y, 2)+std::pow(comp_z, 2);
		}
		
		double norme() const {
			return std::sqrt(norme2());
		}
		
		Vecteur3D unitaire() const {
			Vecteur3D resultatVecteur;
			double n=norme();
			resultatVecteur.set_comp(comp_x/n, comp_y/n, comp_z/n);
			return resultatVecteur;
		}
		
	private:
		double comp_x;
		double comp_y;
		double comp_z;
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
