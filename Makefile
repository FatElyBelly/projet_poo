CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11, ou autre suivant vos préférences

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall         # pour les purs et durs
# CXXFLAGS += -fsanitize=address    # pour analyse dynamique du code
# CXXFLAGS += -g                    # pour debugger
# CXXFLAGS += -O2                   # pour optimiser la vitesse

all: Vecteur/testVecteur

Vecteur.o: Vecteur/Vecteur.cc Vecteur/Vecteur.h

testVecteur.o: Vecteur/testVecteur.cc Vecteur/Vecteur.h

testVecteur: Vecteur/testVecteur.o Vecteur/Vecteur.o
