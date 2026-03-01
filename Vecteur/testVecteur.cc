#include <iostream>
#include <array>
#include <cmath>

struct Coord {
	double x;
	double y;
	double z;
};

class Vecteur3D {
	public:
		void set_coord(double x, double y, double z) {
			coord.x=x;
			coord.y=y;
			coord.z=z;
		}
		
		Coord get_coord() const {
			return coord;
		}
		
		void affiche() const {
			std::cout << coord.x << " " << coord.y << " " << coord.z << " ";
		}
		
		bool compare(Vecteur3D autreVecteur, double marge=1e-10) const {
			if ( (std::abs(autreVecteur.get_coord().x - coord.x) > marge) or (std::abs(autreVecteur.get_coord().y - coord.y) > marge) or (std::abs(autreVecteur.get_coord().z - coord.z) > marge)) {
				return false;
			}
			return true;
		}
		
		// Arithmetique de vecteurs
		Vecteur3D addition(Vecteur3D autreVecteur) const {
			Vecteur3D resultatVecteur;
			resultatVecteur.set_coord(coord.x+autreVecteur.coord.x, coord.y+autreVecteur.coord.y, coord.z+autreVecteur.coord.z);
			return resultatVecteur;
		}
		
		Vecteur3D soustraction(Vecteur3D autreVecteur) const {
			Vecteur3D resultatVecteur;
			resultatVecteur.set_coord(coord.x-autreVecteur.coord.x, coord.y-autreVecteur.coord.y, coord.z-autreVecteur.coord.z);
			return resultatVecteur;
		}
		
		double prod_scal(Vecteur3D autreVecteur) const {
			return coord.x*autreVecteur.coord.x+coord.y*autreVecteur.coord.y+coord.z*autreVecteur.coord.z;
		}
		
		Vecteur3D prod_vect(Vecteur3D autreVecteur) const {
			Coord resultatCoord;
			resultatCoord.x = coord.y*autreVecteur.coord.y - coord.z*autreVecteur.coord.y;
			resultatCoord.y = coord.z*autreVecteur.coord.x - coord.x*autreVecteur.coord.z;
			resultatCoord.z = coord.x*autreVecteur.coord.y - coord.y*autreVecteur.coord.x;
			Vecteur3D resultatVecteur;
			resultatVecteur.set_coord(resultatCoord.x, resultatCoord.y, resultatCoord.z);
			return resultatVecteur;
		}
		
		double norme() const {
			return std::sqrt(std::pow(coord.x, 2)+std::pow(coord.y, 2));
		}
		
		double norme2() const {
			return std::pow(coord.x, 2)+std::pow(coord.y, 2);
		}
		
	private:
		Coord coord;
};


int main() {
	Vecteur3D vecteur1;
	Vecteur3D vecteur2;
	
	vecteur1.set_coord(2, 3, 4);
	vecteur2.set_coord(3, 3, 4);
	
	std::cout << vecteur1.norme() << std::endl;
	std::cout << vecteur1.norme2() << std::endl;
	std::cout << vecteur2.norme() << std::endl;
	
	if (vecteur1.compare(vecteur2, 1)) {
		std::cout << "Same vector" << std::endl;
	} else { std::cout << "Diff vector" << std::endl; }
	
	Vecteur3D vecteur3;
	vecteur3 = vecteur1.addition(vecteur2);
	vecteur3.affiche();

	return 0;
}
