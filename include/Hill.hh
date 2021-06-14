

#pragma once
#include "GeoSolid.hh"

#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;
class Hill : public GeoSolid
{

public:


    Hill(Vector<3> srodek=Vector3D(), double h=50, double w=50, double d=50, string NazwaPlikuPis="../datasets/blok1.dat");
     Hill(Hill& pr);
 ~Hill(){free(wymiary);}
};

