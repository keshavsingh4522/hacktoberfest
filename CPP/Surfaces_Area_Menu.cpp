#include <iostream>
#include <conio.h>
using namespace std;

char pilih, ulang;
float masukkan[3];

float luasSegitiga(float alas, float tinggi)
{
    return (0.5 * alas * tinggi);
}
float luasLingkaran(float r)
{
    return (3.14 * (r * r));
}
float luasPersegiPanjang(int panjang, int lebar)
{
    return (panjang * lebar);
}

void segitiga()
{
    cout << "=== TRIANGLE AREA MENU ===\n\n";
    cout << "INPUT HIGH VALUE : ";
    cin >> masukkan[0];
    cout << "ENTER BASE VALUE : ";
    cin >> masukkan[2];
    masukkan[1] = luasSegitiga(masukkan[0], masukkan[2]);
    cout << "\nAREA OF TRIANGLE : " << masukkan[1];
}

void lingkaran()
{
    cout << "=== CIRCLE AREA MENU ===\n\n";
    cout << "INPUT FINGER VALUE : ";
    cin >> masukkan[0];
    masukkan[1] = luasLingkaran(masukkan[0]);
    cout << "\nAREA OF CIRCLE : " << masukkan[1];
}

void persegipanjang()
{
    cout << "== RECTANGLE AREA MENU ==\n\n";
    cout << "INPUT LONG VALUE : ";
    cin >> masukkan[0];
    cin.ignore();
    cout << "INPUT WIDE VALUE : ";
    cin >> masukkan[2];
    cin.ignore();
    masukkan[1] = luasPersegiPanjang(masukkan[0], masukkan[2]);
    cout << "\nAREA OF RECTANGLE : " << masukkan[1];
}

void keluar()
{
    cout << "\n";
    cout << "=== EXIT FROM MENU ===\n";
    cout << "\n";
    cout << "Enter Something\n";
    getchar();
}

int main()
{
menu:
    cout << "============================\n";
    cout << "==== BUILDING AREA MENU ====\n\n";
    cout << "1.TRIANGLE AREA MENU\n";
    cout << "2.CIRCLE AREA MENU\n";
    cout << "3.RECTANGLE AREA MENU\n";
    cout << "4.EXIT\n";
    cout << "CHOICE (1,2,3,4) : ";
    cin >> pilih;
    cin.ignore();
    cout << "==========================\n";

    switch (pilih)
    {
    case '1':
        segitiga();
        getch();
        break;

    case '2':
        lingkaran();
        getch();
        break;

    case '3':
        persegipanjang();
        getch();
        break;

    case '4':
    exit:
        keluar();
        return 0;

    default:
        cout << "YOUR CHOICE IS NOT IN THE SYSTEM\n";
    }
    cout << "\n\nBACK TO MAIN MENU? (y/n) : ";
    cin >> ulang;
    cin.ignore();
    if (ulang == 'y' || ulang == 'Y')
        goto menu;
    else if (ulang == 'n' || ulang == 'N')
        goto exit;
    getch();
}