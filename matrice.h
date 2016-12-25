//
//  matrice.h
//  2015 2
//
//  Created by QW on 16/12/24.
//  Copyright © 2016年 QW. All rights reserved.
//

#ifndef matrice_h
#define matrice_h
#include <iostream>
using namespace std;

class matrice{
private:
    int nbligne;
    int nbCol;
    double **elements;
public:
    matrice();
    matrice(int ,int);
    matrice(const matrice&);
    ~matrice();
    void lecture();
    bool matriceCarree();
    bool matriceDiagonale();
    friend ostream& operator<<(ostream& flux, const matrice& m);
    matrice operator+(matrice &droite);
    matrice operator*(matrice &droite);
};


#endif /* matrice_h */
