#include <iostream>

class Wekt
{
private:
    int     dlug;
    int     pojemn;
    double* st;

public:
    int Get_dlugosc() { return dlug; }
    int Get_pojemnosc() { return pojemn; }
    Wekt(int a) : dlug{a}
    {

        pojemn = dlug;
        st     = new double[a];
        for (int i = 0; i < a; i++)
            st[i] = 0;
    }
    ~Wekt() { delete[] st; }
    void print()
    {
        for (int i = 0; i < dlug; i++)
            std::cout << st[i] << " ";
    }
    void ZmienDlug(int b)
    {
        if (b < pojemn) {
            for (int i = b; i < pojemn; i++)
                st[i] = 0;
        }
        if (b > pojemn) {
            double* st2;
            st2 = st;
            st  = new double[b];
            for (int i = 0; i < pojemn; i++)
                st[i] = st2[i];
            delete[] st2;
            for (int i = pojemn; i < b; i++)
                st[i] = 0;
            pojemn = b;
        }
        dlug = b;
    }
    double& operator[](int y)
    {
        if (y + 1 > dlug)
            ZmienDlug(y + 1);
        return st[y];
    }
};

struct Kokardka
{
    Kokardka(int d) : dlugosc{d} {}

    int dlugosc;
};

struct Prezent
{
    Prezent(int dk) : k{dk} {}

    Kokardka k;
    // Inne pola ...
};

int main()
{
    Wekt W(4);
    W[1] = 1;
    W[4] = 6;

    W.print();

    /*   W.ZmienDlug(6);
         std::cout << "\n";
          W.print();
          W.ZmienDlug(2);
          std::cout << "\n";
          W.print();
          W.ZmienDlug(6);
          W.st[4] = 122;
          std::cout << "\n";
          W.print();*/

    Prezent Wee(6);
    std::cout << Wee.k.dlugosc << "\n";
}
