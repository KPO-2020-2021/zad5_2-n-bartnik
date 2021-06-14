#include "Scene.hh"
using namespace std;

Scene::Scene()
{
Vector<3> srod;

    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.UstawZakresY(-300, 300);
    Lacze.UstawZakresX(-300, 300);
    Lacze.UstawZakresZ(-300, 300);

    double tab_wymiary[3] = {600, 600, 0};
    Vector<3> kwadrat(tab_wymiary);
    plaszczyzna = new Ground(kwadrat, 20);


/*ustalanie losowanej pozycji klasy Hill*/
    srod[0]=rand()%400-200;
    srod[1]=rand()%400-200;
    srod[2]=50;

    /*dzięki funkcji push_front obiekt jest wypychany na pocżatek listy bloków*/
    lista.push_front(std::make_shared<Hill>(srod, 100, 50, 100, "../datasets/blok1.dat"));


   /*ustalanie losowanej pozycji klasy Pyramid*/
    srod[0]=rand()%400-200;
    srod[1]=rand()%400-200;
    srod[2]=50;

    /*dzięki funkcji push_front obiekt jest wypychany na pocżatek listy bloków*/
    lista.push_front(std::make_shared<Pyramid>(srod, 100, 50, 100, "../datasets/blok2.dat"));

/*ustalanie losowanej pozycji klasy Prism2*/
    srod[0]=rand()%400-200;
    srod[1]=rand()%400-200;
    srod[2]=50;

    /*dzięki funkcji push_front obiekt jest wypychany na pocżatek listy bloków*/
    lista.push_front(std::make_shared<Pyramid>(srod, 100, 50, 100, "../datasets/blok3.dat"));

/*Zwracanie wskaźnika do peirwszego elementu listy. Dzięki inkrementacji możliwe jest przejście po wszystkich elementach*/
 for( std::list<std::shared_ptr<GeoSolid>>::const_iterator i= lista.begin(); i!=lista.end(); i++)
  {
      Lacze.DodajNazwePliku((*i)->wez_nazwe().c_str(), PzG::RR_Ciagly, 2);
    (*i)->zapisz(); //zapisuje elements
  }
  
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
