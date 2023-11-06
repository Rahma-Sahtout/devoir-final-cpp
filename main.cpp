#include <stdlib.h>
#include <iostream>
using namespace std ;
class stack{
 int nb_max ; //  max de la pile
 int nb_valeurs ;//nombre la pile
 int * val_public ;// pointeur sur les valeurs publics
 public :
     // constructeur
    stack (int n = 20){
       int  max=n;
        val_public = new int [nb_max] ;
        nb_valeurs = 0 ;
    }
    // destructeur
    ~stack (){
        delete val_public;
    }
// constructeur par recopie
    stack (stack & p) {
        nb_max = p.nb_max ;
        nb_valeurs = p.nb_valeurs ;
    val_public = new int [nb_max] ;
        int i ;
    for (i=0 ; i<nb_valeurs ; i++)
    val_public[i] = p.val_public[i] ;
    }



    stack & operator << (int n){
        if (nb_valeurs < nb_max)
            val_public[nb_valeurs++] = n ;
    return (*this) ;
    }
    stack & operator >> (int & n) {
        if (nb_valeurs > 0)
            n = val_public[--nb_valeurs] ;
    return (*this) ;
    };
    //test pile pleine
    int operator ++ () {
        return (nb_valeurs == nb_max) ;
    }
    //test pile vide
    int operator -- () {
        return (nb_valeurs == 0) ;
    }
};
