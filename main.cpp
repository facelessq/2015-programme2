//
//  main.cpp
//  2015 2
//
//  Created by QW on 16/12/24.
//  Copyright © 2016年 QW. All rights reserved.
//

#include <iostream>
#include "matrice.h"
using namespace std;

int main()
{
    matrice a(1,2);
    matrice b(2,3);

    matrice c=a*b;
    cout<<a<<endl;
    cout<<c<<endl;
    return 0;
}
