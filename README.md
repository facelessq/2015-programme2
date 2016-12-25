# 2015-programme2
c'est la programme 2 de cc4 2015

J'ai rencontrée une question 
dans la fonction main,  les code "cout<<c<<endl;" ne fonction pas, mais "cout<<a<<endl;" ou "cout<<b<<endl;" fonctionne quand même
j'ai met des breakpoints dans la fonction operator<< dans matrice.cpp, je trouve que quand j'arrive cout<<c<<endl; ,il saute les codes     
for(int i=0;i<m.nbligne;i++)  
    {   for(int j=0;j<m.nbCol;j++)
            flux<<m.elements[i][j]<<'\t';
        flux<<'\n';
    }
il arrive directement à "return flux"

