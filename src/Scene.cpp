#include "Scene.hh"
using namespace std;

Scene::Scene()
{

    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.UstawZakresY(-155, 155);
    Lacze.UstawZakresX(-155, 155);
    Lacze.UstawZakresZ(-155, 155);

    double tab_wymiary[3] = {310, 310, 0};
    Vector<3> kwadrat(tab_wymiary);
    plaszczyzna = new Ground(kwadrat, 20);
    Lacze.DodajNazwePliku(plaszczyzna->wez_nazwe().c_str(), PzG::RR_Ciagly, 2);
    plaszczyzna->zapisz();
    for (int i = 0; i < 2; i++)
    {
        double pozycja[3]{(double)(rand() % 220 - 110), (double)(rand() % 22 - 110), 25};
        TabDronow[i] = new Drone(i, Lacze, pozycja);
        TabDronow[i]->zapisz();
    }
    Lacze.Rysuj();
}

void Scene::Rysuj()
{
    Lacze.Rysuj();
}

bool Scene::menu()
{
    cout << "Wybierz aktywnego drona (0 lub 1)" << endl;
    cout << "Inny numer konczy program" << endl;
    int nr;
    cin >> nr;
    if (nr < 2)
    {
        TabDronow[nr]->sterowanie();
    }
    else
    {
        return false;
    }
    return true;
}
