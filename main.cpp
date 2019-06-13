#include <iostream>
#include "geometry1.h"

using namespace std;

//Funkcja wypisujaca elementy obiektu klasy PointArray:
void printArr(PointArray &pArr){
    if(pArr.getSize() == 0) cout << "Pusta tablica" << endl;
    else{
      for(int i = 0; i < pArr.getSize(); i++){
          cout << pArr.get(i)->getX() << "\t" << pArr.get(i)->getY() << endl;
      }
    }
}



//Funkcja wypisująca wlasności obiektu klasy Polygon:

//Przeladowanie operatora << dla trojkata:




int main() {
    /****************POINT*************/
    Point p1;
    Point p2(4, 4);
    Point p3;
    p3.setX(2);
    p3.setY(8);
    cout << p1.getX() << "\t" << p1.getY() << "\t" << p2.getX() << "\t" << p2.getY() << "\t" << p3.getX() << "\t"
         << p3.getY() << endl;


    /****************POINTARRAY*************/
    Point pa[3] = {p1, p2, p3};
    PointArray pArr(pa, 3);
    printArr(pArr);
    pArr.clear();
    printArr(pArr);
    Point p4(9, 9);
    pArr.push_back(p4);
    printArr(pArr);


    /****************TRIANGLE*************/
    Point a(1, 1), b(2, 8), c(3, 3);
    Triangle t(a, b, c);
    //wywolanie funkcji wypisujacej wlasnosci trojkata


    /********************Przeladowanie operatora "<<" dla trojkata**************/

    return 0;
}
