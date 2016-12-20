#!/usr/bin/python
# -*-coding:Utf-8 -*
from random import randrange
from math import ceil
print("casino tourne !")

def couleur_nb(nb):
    if (nb%2 == 0):
        couleur_resultat = 'noir'
    else:
        couleur_resultat = 'rouge'
    return couleur_resultat

try:
    while True:
        nbr_mise = input("misez un nombre entre 1 et 49 - 0  pour quitter ")
        if (nbr_mise == 0):
            break
        somme_mise = input("miser une somme ")
        assert nbr_mise >=0 and nbr_mise <50 
        couleur_mise = couleur_nb(nbr_mise)
        print ("Le nombre/couleur mise est : %d / %s. La somme misee est %d: " 
                %(nbr_mise, couleur_mise, somme_mise))
        
        case_tiree = randrange(50)
        print("la case tiree est %d" %case_tiree)
        couleur_tiree = couleur_nb(case_tiree)
        print("la couleur tiree est : %s" % couleur_nb(case_tiree))
    print ("    merci!!")
except AssertionError:
    print("entre 0 et 49 !!!")
except:
    print ("erreur dans casino")

