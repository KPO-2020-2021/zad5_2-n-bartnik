#pragma once

#include "Drone.hh"
#include "Prism.hh"
#include "lacze_do_gnuplota.hh"
#include "Ground.hh"

class Scene
{

protected:
    PzG::LaczeDoGNUPlota Lacze;
    Drone *TabDronow[2];
    Ground *plaszczyzna;

    int k = 0;
public:
    Scene();
    void Rysuj();
    bool menu();
    ~Scene()
    {
        free(plaszczyzna);
        for (int i = 0; i < 2; i++)
            free(TabDronow[i]);
    }
};
