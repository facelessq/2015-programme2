//
//  matrice.cpp
//  2015 2
//
//  Created by QW on 16/12/24.
//  Copyright © 2016年 QW. All rights reserved.
//

#include "matrice.h"
#include <iostream>
#include <fstream>
using namespace  std;

matrice::matrice()
{
    nbligne=0;
    nbCol=0;
    elements=NULL;
}

matrice::matrice(int nl,int nc)
{
    nbCol=nc;
    nbligne=nl;
    elements=new double*[nl];
    for(int i=0;i<nl;i++)
    {    elements[i]=new double[nc];
        cout<<"pour ligne "<<i+1<<", les "<<nbCol<<" elements:"<<endl;
        for(int j=0;j<nc;j++)
            cin>>elements[i][j];
    }
}

matrice::matrice(const matrice& m)
{
    nbCol=m.nbCol;
    nbligne=m.nbligne;
    elements=new double*[nbligne];
    for(int i=0;i<nbligne;i++)
    {   elements[i]=new double[nbCol];
        for(int j=0;j<nbCol;j++)
            elements[i][j]=m.elements[i][j];
    }

}

matrice::~matrice()
{
    for(int i=0;i<nbligne;i++)
        delete[] elements[i];
    delete[] elements;
}

void matrice::lecture()
{
    int nbl,nbC;
    ifstream f;
    f.open("Donnees.txt");
    f>>nbl>>nbC;
    if(elements!=NULL)
    {    for (int i=0; i<nbligne; i++)
            delete[] elements[i];
        delete[] elements;
    }
    nbligne=nbl;
    nbCol=nbC;
    for(int i=0;i<nbligne;i++)
        for(int j=0;i<nbCol;j++)
            f>>elements[i][j];
    f.close();
    
}

bool matrice::matriceCarree()
{
    if(nbligne==nbCol)return true;
    else return false;
}

bool matrice::matriceDiagonale()
{
    if(this->matriceCarree()==false)
    {
        cout<<"la matrice n'est pas carree "<<endl;
        return false;
    }
    for(int i=0;i<nbligne;i++)
        for(int j=0;j<nbCol;j++)
            while(i!=j){
                if(elements[i][j]!=0)
                    return false;
            }
    return true;
}

ostream& operator<<(ostream& flux, const matrice& m)
{
    for(int i=0;i<m.nbligne;i++)  //要用m.  因为是m的元素了！！！！
    {   for(int j=0;j<m.nbCol;j++)
            flux<<m.elements[i][j]<<'\t';
        flux<<'\n';
    }
    return flux;
}

//返回值不加&写+ * 不然可能会出错 = =
matrice matrice::operator+(matrice &droite)  //返回值要写前面 然后再写属于哪个类！ （除了virtual）
{
    matrice C;//注意这里！没有括号！用的是constructeur par defaut!
    if(nbligne==droite.nbligne&&nbCol==droite.nbCol)
    {
      for(int i=0;i<droite.nbligne;i++)
       for(int j=0;j<droite.nbCol;j++)
           C.elements[i][j]=droite.elements[i][j]+elements[i][j];
    }
    else cout<<"erreur +"<<endl;
    return C;
}

matrice matrice::operator*(matrice &droite)
{
    matrice C;         //如果不写下面的 那么c的element就是null 无法进行C.elements[i][j]的各种操作
    C.elements=new double*[nbligne];
    for(int i=0 ;i<nbligne;i++)
        C.elements[i]=new double[droite.nbCol];
    for(int i=0;i<nbligne;i++)
        for(int j=0;j<droite.nbCol;j++)
            C.elements[i][j]=0;
    if(nbCol==droite.nbligne)
    {
        for(int i=0;i<nbligne;i++)
            for(int j=0;j<droite.nbCol;j++)
                for(int k=0;k<nbCol;k++)
                    C.elements[i][j]=C.elements[i][j]+elements[i][k]*droite.elements[k][j];
    }
    else cout<<"erreur *"<<endl;
    return C;
}


