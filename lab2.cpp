#include <iostream>
/*lass Wekt
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
    Wekt(const Wekt& We)
    {
        dlug   = We.dlug;
        pojemn = dlug;
        st     = new double[dlug];
        std::cout << "Jestem kopjujacy\n";
        for (int i = 0; i < dlug; i++)
            st[i] = We.st[i];
    }
    Wekt& operator=(const Wekt& We)
    {
        dlug   = We.dlug;
        pojemn = dlug;
        st     = new double[dlug];
        std::cout << "Jestem operator kopjujacy\n";
        for (int i = 0; i < dlug; i++)
            st[i] = We.st[i];
        return *this;
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
};*/

class Resource
{
public:
    double get() { return 123; }
};

class ResourceManager
{
    Resource* Q;

public:
    ResourceManager() { Q = new Resource{}; }
    ~ResourceManager() { delete Q; }
    double get() { return Q->get(); }
    ResourceManager(const ResourceManager& aa) : Q{aa.Q} {}
    ResourceManager& operator=(const ResourceManager& aa)
    {
        Q = aa.Q;
        return *this;
    }
    ResourceManager(const ResourceManager&& aa) : Q{(aa.Q)} {}
    ResourceManager& operator=(const ResourceManager&& aa)
    {
        Q = (aa.Q);
        return *this;
    }
};

int main()
{
    /* Wekt W(4);

     W.ZmienDlug(6);
     std::cout << "\n";
     W.print();
     W.ZmienDlug(2);
     std::cout << "\n";
     W.print();
     W.ZmienDlug(6);

     std::cout << "\n";
     W.print();
     Wekt V(W);
     Wekt U(3);
     U = V;
     U = U;*/

    ResourceManager A;
    ResourceManager B(A);
    ResourceManager C = B;
    ResourceManager D = std::move(B);

    std::cout << D.get() << B.get() << "\n";
    double *a, *b;
    double  c = 3;
    a         = &c;
    b         = a;
    std::cout << *b << " " << *a << "\n";
}
