#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int olcu = 5; 
    const int birlerinSayi = 5; 
    const int maxCehd = 20;

    int matris[olcu][olcu] ; // 5x5 matris
    int tapilanBirler = 0; 

    // 1 leri yerlesdirmek tesadufi
    srand(time(NULL));
    for (int i = 0; i < birlerinSayi; ) {
        int setir = rand() % olcu;
        int sutun = rand() % olcu;
        if (matris[setir][sutun] == 0) {
            matris[setir][sutun] = 1;
            i++;
        }
    }

    cout << "Matrisdeki 1 leri tapmaga calisin (0 ve 5 arasi ededler daxil edin )\n";

    for (int cehd = 1; cehd <= maxCehd; cehd++) {
        int setir, sutun;
        cout << "Cehd " << cehd << ": \n";
        cout<<"setir:";
        cin>>setir;
        cout<<"sutun:";
        cin>>sutun;

        // Koordinatlarý yoxlamaq
        if (setir < 0 or setir > olcu or sutun < 0 or sutun > olcu) {
            cout << "Duzgun koordinatlar daxil edin! (0-dan 5-e qeder)\n";
            continue;
        }

        

        // Netice
        if (matris[setir][sutun] == 1) {
            cout << "Aferin! 1 tapdiz!\n";
            tapilanBirler++;
            matris[setir][sutun] = 0; 
        } else {
            cout << "tapa bilmediz.\n";
        }

        cout << "tapdiginiz 1-ler: " << tapilanBirler << endl;
        cout<<"-------------------------------\n";
        
        if (tapilanBirler == birlerinSayi) {
            cout << "halaldi! butun 1-leri tapdiz!\n";
            cout<<"hem de sadece "<<cehd<< " cehd ile , mohtesem!!!";
            break;
        }
    }

    if (tapilanBirler < birlerinSayi) {
        cout << "game over! tapdiginiz 1-ler: " << tapilanBirler << endl;
    }

    return 0;
}

