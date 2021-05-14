#include <bits/stdc++.h>

using namespace std;

const int nmax = 100;

class Masina
{
protected:
        double pret, lungime, litraj;

public:

    //constructori
    Masina(): pret(0), lungime(0), litraj(0){}
    Masina(double p, double lg, double l): pret(p), lungime(lg), litraj(l){}
    Masina(Masina &m): pret(m.pret), lungime(m.lungime), litraj(m.litraj){}

    //destructor
    ~Masina(){}

    virtual void Citire(){}
    virtual void Afisare(){}
    virtual bool operator ==(Masina &m)
    {
        if(this -> pret == m.pret && this -> lungime == m.lungime && this -> litraj == m.litraj)
            return true;

        return false;
    }

    //getteri
    double get_pret(){ return pret; }
    double get_lungime(){ return lungime; }
    double get_litraj(){ return litraj; }


    //setteri
    void set_pret(double p){ pret = p; }
    void set_lungime(double lg){ lungime = lg; }
    void set_litraj(double l){ litraj = l; }
};


class Mini: public Masina{
public:

    //constructori
    Mini(): Masina(){}
    Mini(double p, double lg, double l): Masina(p, lg, l){}
    Mini(Mini &m)
    {
        pret = m.get_pret();
        lungime = m.get_lungime();
        litraj = m.get_litraj();
    }

    //destructor
    ~Mini(){}

    void Citire()
    {
        cin >> *this;
    }

    void Afisare()
    {
        cout << *this;
    }


    //operatori
    friend istream &operator >> (istream &in, Mini &m)
    {
        bool ok = false;
        cout << "Pret: "; cin >> m.pret;
        while(!ok)
        {
        cout << "Lungime : ";
            cin >> m.lungime;
            if(m.lungime > 0 && m.lungime < 4)
                ok = true;
            else
                cout << "Lungime invalida. Introduceti o valoare de tip double( > 0 si < 4)\n";
        }
        cout << "Litraj: "; cin >> m.litraj;

        return in;
    }

    friend ostream &operator << (ostream &out, Mini &m)
    {
        out << "Pret: " << m.pret << '\n';
        out << "Lungime: " << m.lungime << '\n';
        out << "Litraj: " << m.litraj << '\n';
        return out;
    }

    Mini &operator =(Mini& m)
    {
        if(this != &m) //verificam daca nu sunt deja egale
        {
            pret = m.get_pret();
            lungime = m.get_lungime();
            litraj = m.get_litraj();
        }

        return *this;
    }

    bool operator ==(Masina &m)
    {
        Mini *aux = dynamic_cast<Mini*>(&m);

        if(aux != NULL)
            if(pret == aux -> get_pret() && lungime == aux -> get_lungime() && litraj == aux -> get_litraj())
                return true;

        return false;
    }

};


class Mica: public Masina{
public:

    //constructori
    Mica(): Masina(){}
    Mica(double p, double lg, double l): Masina(p, lg, l){}
    Mica(Mica &m)
    {
        pret = m.get_pret();
        lungime = m.get_lungime();
        litraj = m.get_litraj();
    }

    //destructor
    ~Mica(){}

    void Citire()
    {
        cin >> *this;
    }
    void Afisare()
    {
        cout << *this;
    }

    Mica &operator =(Mica &m)
    {
        if(this != &m) //verificam daca nu sunt deja egale
        {
            pret = m.get_pret();
            lungime = m.get_lungime();
            litraj = m.get_litraj();
        }
        return *this;
    }

    bool operator ==(Masina &m)
    {
        Mica *aux = dynamic_cast<Mica*>(&m);

        if(aux != NULL)
        {
            if(pret == aux -> get_pret() && lungime == aux -> get_lungime() && litraj == aux -> get_litraj())
                return true;

        return false;
        }
    }

    friend istream &operator >> (istream &in, Mica &m)
    {
        bool ok = false;
        cout << "Pret: "; cin >> m.pret;
        while(!ok)
        {
        cout << "Lungime : ";
            cin >> m.lungime;
            if(m.lungime >= 3.85 && m.lungime <= 4.1)
                ok = true;
            else
                cout << "Lungime invalida. Introduceti o valoare de tip double( >= 3.85 si <= 4.1)\n";
        }
        cout << "Litraj: "; cin >> m.litraj;

        return in;
    }

    friend ostream &operator << (ostream &out, Mica &m)
    {
        out << "Pret: " << m.pret << '\n';
        out << "Lungime: " << m.lungime << '\n';
        out << "Litraj: " << m.litraj << '\n';
        return out;
    }

};


class Compacta: public Masina{
    string model;

public:
    //constructori
    Compacta(): Masina(), model(""){}
    Compacta(double p, double lg, double l, string m): Masina(p, lg, l), model(m){}
    Compacta(Compacta &c)
    {
        pret = c.get_pret();
        lungime = c.get_lungime();
        litraj = c.get_litraj();
        model = c.get_model();
    }

    //destructor
    ~Compacta(){}

    //getter
    string get_model() { return model; }

    //setter
    void set_model(string m) { model = m; }

    void Citire()
    {
        cin >> *this;
    }

    void Afisare()
    {
        cout << *this;
    }

    Compacta &operator = (Compacta &m)
    {
        pret = m.get_pret();
        lungime = m.get_lungime();
        litraj = m.get_litraj();
        model = m.get_model();
        return *this;
    }

    bool operator ==(Masina &m)
    {
        Compacta *aux = dynamic_cast<Compacta*>(&m);

        if(aux != NULL)
            if(pret == aux -> get_pret() && lungime == aux -> get_lungime() && litraj == aux -> get_litraj() && model == aux -> get_model())
                return true;

        return false;
    }

    friend istream &operator >> (istream &in, Compacta &c)
    {
        bool ok = false;
        cout << "Pret: "; cin >> c.pret;
        while(!ok)
        {
        cout << "Lungime : ";
            cin >> c.lungime;
            if(c.lungime >= 4.2 && c.lungime <= 4.5)
                ok = true;
            else
                cout << "Lungime invalida. Introduceti o valoare de tip double( >= 4.2 si <= 4.5)\n";
        }
        cout << "Litraj: "; cin >> c.litraj;

        ok = false;

        while(!ok)
        {
            cout << "Alege din modelele: hatchback, combi, sedan\n";
            cout << "Model: " ;
            cin >> c.model;

            if((c.model.compare("hatchback") == 0) || (c.model.compare("combi") == 0) || (c.model.compare("sedan") == 0))
                ok = true;
            else
                cout << "Model invalid\n";

        }

        return in;
    }

    friend ostream &operator << (ostream &out, Compacta &c)
    {
        out << "Pret: " << c.pret << '\n';
        out << "Lungime: " << c.lungime << '\n';
        out << "Litraj: " << c.litraj << '\n';
        out << "Model: " << c.model << '\n';
        return out;
    }

};


class Monovolume: public Masina{

    int nr_pers, ani_vechime;
    double discount;
    bool sh;
    static const int reducere;

public:
    //constructori
    Monovolume(): Masina(), nr_pers(0), ani_vechime(0), discount(0), sh(0){}
    Monovolume(double p, double lg, double l, int nr, int nr_ani, double disc, bool s): Masina(p, lg, l), nr_pers(nr), ani_vechime(nr_ani), discount(disc), sh(s){}
    Monovolume(Monovolume &m)
    {
        pret = m.get_pret();
        lungime = m.get_lungime();
        litraj = m.get_litraj();
        nr_pers = m.get_nr_pers();
        ani_vechime = m.get_ani_vechime();
        discount = m.get_discount();
        sh = m.get_sh();
    }

    //destructor
    ~Monovolume(){}

    //getteri
    int get_nr_pers(){ return nr_pers; }
    int get_ani_vechime(){ return ani_vechime; }
    double get_discount(){ return discount; }
    bool get_sh(){ return sh; }

    //setteri

    void set_nr_pers(int nr){ nr_pers = nr; }
    void set_ani_vechime(int nr_ani){ ani_vechime = nr_ani; }
    void set_discount(double disc){ discount = disc; }
    void set_sh(bool s){ sh = s; }

    void Citire()
    {
        cin >> *this;
    }

    void Afisare()
    {
        cout << *this;
    }

    Monovolume &operator =(Monovolume &m)
    {
        pret = m.get_pret();
        lungime = m.get_lungime();
        litraj = m.get_litraj();
        nr_pers = m.get_nr_pers();
        ani_vechime = m.get_ani_vechime();
        discount = m.get_discount();
        sh = m.get_sh();

        return *this;
    }

    bool operator ==(Masina &m)
    {
        Monovolume *aux = dynamic_cast<Monovolume*>(&m);

        if(aux != NULL)
            if(pret == aux -> get_pret() && lungime == aux -> get_lungime() && litraj == aux -> get_litraj() && nr_pers == aux -> get_nr_pers()
                && ani_vechime == aux -> get_ani_vechime() && discount == aux -> get_discount() && sh == aux -> get_sh())
               return true;

        return false;
    }

    friend istream &operator >> (istream &in, Monovolume &m)
    {
        bool ok = false;
        cout << "Pret: "; cin >> m.pret;
        while(!ok)
        {
        cout << "Lungime : ";
            cin >> m.lungime;
            if(m.lungime > 0 && m.lungime <= 8)
                ok = true;
            else
                cout << "Lungime invalida. Introduceti o valoare de tip double( > 0 si <= 8)\n";
        }
        cout << "Litraj: "; cin >> m.litraj;

        ok = false;


        while(!ok)
        {
            cout << "Numar persoane: ";
            cin >> m.nr_pers;

            if(m.nr_pers > 0 && m.nr_pers < 8)
                ok = true;
            else
                cout << "Valoare invalida. Introduceti o valoare de tip int( > 0 si < 8) \n";
        }

        ok = false;
        while(!ok)
        {
            cout << "Ani vechime: "; cin >> m.ani_vechime;
            if(m.ani_vechime > 0)
                ok = true;
            else
                cout << "Numarul de ani vechime trebuie sa fie pozitiv \n";
        }

        ok = false;

        while(!ok)
        {
            cout << "Discount pe an vechime: ";
            cin >> m.discount;

            if(m.discount > 0 && m.discount < m.pret)
                ok = true;
            else
                cout << "Discount-ul trebuie sa fie un numar pozitiv mai mic decat pretul autoturismului (" << m.pret << ") \n";
        }

        cout << "Sh? (Introduceti 1 daca masina este sh sau 0 daca este noua): ";
        cin >> m.sh;


        return in;
    }

    friend ostream &operator << (ostream &out, Monovolume &m)
    {
        out << "Pret: " << m.pret << '\n';
        out << "Lungime: " << m.lungime << '\n';
        out << "Litraj: " << m.litraj << '\n';
        out << "Numar persoane: " << m.nr_pers << '\n';
        out << "Ani vechime: " << m.ani_vechime << '\n';
        out << "Discount: " << m.discount << '\n';
        out << "Sh: " << m.sh << '\n';
        return out;
    }
};

const int Monovolume::reducere = 10;


template<class T> class Vanzare;
template<class T> istream& operator >>(istream& in, Vanzare<T> &m);
template<class T> ostream& operator <<(ostream& out, Vanzare<T> &m);

template<class T>
class Vanzare{
    int nr_masini, nr_vandute;
    T** stoc;
    T** vandute;
public:
    //constructor
    Vanzare()
    {
        nr_masini = 0;
        nr_vandute = 0;
        stoc = new T*[nmax];
        vandute = new T*[nmax];
    }

    //destructor
    //~Vanzare();

    //getteri
    int get_nr_masini(){ return nr_masini; }
    int get_nr_vandute(){ return nr_vandute; }

    void adauga_masina(Masina &m);
    void afisare_stoc();
    void afisare_vandute();

    bool Este_in(Masina &m)
    {
        for(int i = 0; i < nr_masini; i++)
        {
            if(*stoc[i] == m)
                return false;
        }
            return true;
    }

    friend ostream& operator << <>(ostream& out, Vanzare& v);
    friend istream& operator >> <>(istream& in, Vanzare& v);

    Vanzare<T> &operator -=(Masina &m)
    {
        Mini *mini = dynamic_cast<Mini*>(&m);
        Mica *mica = dynamic_cast<Mica*>(&m);
        Compacta *compacta = dynamic_cast<Compacta*>(&m);
        Monovolume *monovolume = dynamic_cast<Monovolume*>(&m);

        for(int i = 0; i < nr_masini; i++)
        {
            if(*stoc[i] == m)
            {
                for(int j = i; j < nr_masini - 1; j++)
                    stoc[j] = stoc[j + 1];

                nr_masini--;

                if(mini != NULL)
                {
                    Mini *aux = new Mini;
                    *aux = *mini;
                    vandute[nr_vandute++] = dynamic_cast<T*>(aux);
                }

                if(mica != NULL)
                {
                    Mica *aux = new Mica;
                    *aux = *mica;
                    vandute[nr_vandute++] = dynamic_cast<T*>(aux);
                }

                if(compacta != NULL)
                {
                    Compacta *aux = new Compacta;
                    *aux = *compacta;
                    vandute[nr_vandute++] = dynamic_cast<T*>(aux);
                }

                if(monovolume != NULL)
                {
                    Monovolume *aux = new Monovolume;
                    *aux = *monovolume;
                    vandute[nr_vandute++] = dynamic_cast<T*>(aux);
                }

            }

        }
        return *this;
    }

};

template<class T>
void Vanzare<T>::adauga_masina(Masina &m)
{
    Mini *mini = dynamic_cast<Mini*>(&m);
    Mica *mica = dynamic_cast<Mica*>(&m);
    Compacta *compacta = dynamic_cast<Compacta*>(&m);
    Monovolume *monovolume = dynamic_cast<Monovolume*>(&m);

    if(mini != NULL)
    {
        Mini *aux = new Mini;
        *aux = *mini;
        stoc[nr_masini++] = dynamic_cast<T*>(aux);
    }

    if(mica != NULL)
    {
        Mica *aux = new Mica;
        *aux = *mica;
        stoc[nr_masini++] = dynamic_cast<T*>(aux);
    }

    if(compacta != NULL)
    {
        Compacta *aux = new Compacta;
        *aux = *compacta;
        stoc[nr_masini++] = dynamic_cast<T*>(aux);
    }

    if(monovolume != NULL)
    {
        Monovolume *aux = new Monovolume;
        *aux = *monovolume;
        stoc[nr_masini++] = dynamic_cast<T*>(aux);
    }
}

template<class T>
void Vanzare<T>::afisare_stoc()
{
    cout << '\n';

     if(nr_masini == 0)
        cout << "Nicio masina pe stoc pana in acest moment.\n";
    else
    {
        cout << "Masini pe stoc (" << nr_masini << ") : \n";

        for(int i = 0; i < nr_masini; i++)
        {
            cout << "Masina " << i + 1 << ": \n";
            stoc[i] -> Afisare();
            cout << '\n';
        }
    }

    cout << '\n';
}

template<class T>
void Vanzare<T>::afisare_vandute()
{
    cout << '\n';
    if(nr_vandute == 0)
        cout << "Nicio masina vanduta pana in acest moment.\n";
    else
    {
        cout << "Masini vandute (" << nr_vandute << "): \n";

        for(int i = 0; i < nr_vandute; i++)
        {
            cout << "Masina " << i + 1 << ": \n";
            vandute[i] -> Afisare();
            cout << '\n';
        }
    }

    cout << '\n';
}

template<class T>
istream &operator >> (istream &in, Vanzare<T> &v)
{
    int tip;
    int nr_stoc;

    cout << "Introduceti numarul de masini de pe stoc: "; cin >> nr_stoc;

    cout << "Alege tipul masinii:\n1.Mini\n2.Mica\n3.Compacta\n4.Monovolume\n5.Toate tipurile\n";
    cin >> tip;
    switch(tip)
    {
        case 1:
        {
            cout << "Masina de tipul Mini!\n";
            for(int i = 0; i < nr_stoc; i++)
            {
                cout << "Masina " << i + 1 << ":\n";
                Mini m;
                cin >> m;
                v.adauga_masina(m);
                cout << '\n';
            }
            break;
        }

        case 2:
        {
            cout << "Masina de tipul Mica!\n";

            for(int i = 0; i < nr_stoc; i++)
            {
                cout << "Masina " << i + 1 << ":\n";
                Mica m;
                cin >> m;
                v.adauga_masina(m);
                cout << '\n';
            }
            break;
        }

        case 3:
        {
            cout << "Masina de tipul Compacta!\n";

            for(int i = 0; i < nr_stoc; i++)
            {
                cout << "Masina " << i + 1 << ":\n";
                Compacta c;
                cin >> c;
                v.adauga_masina(c);
                cout << '\n';
            }
            break;
        }

        case 4:
        {
            cout << "Masina de tipul Monovolume!\n";

            for(int i = 0; i < nr_stoc; i++)
            {
                cout << "Masina " << i + 1 << ":\n";
                Monovolume m;
                cin >> m;
                v.adauga_masina(m);
                cout << '\n';
            }
            break;
        }

        case 5:
            {

                for(int i = 0; i < nr_stoc; i++)
                {
                    cout << "Masina " << i + 1 << ":\n";
                    cout << "Alegeti tipul masinii:\n1.Mini\n2.Mica\n3.Compacta\n4.Monovolume\n";
                    bool ok = false;
                    int tip_masina = 9;
                    while(!ok)
                    {
                        cin >> tip_masina;

                        if(tip_masina > 0 && tip_masina < 5)
                            ok = true;
                        else
                            cout << "Tipul introdus este invalid!\n";
                    }

                    switch(tip_masina)
                    {
                        case 1:
                        {
                            Mini m;
                            cin >> m;
                            v.adauga_masina(m);
                            break;
                        }
                        case 2:
                        {
                            Mica m;
                            cin >> m;
                            v.adauga_masina(m);
                            break;
                        }
                        case 3:
                        {
                            Compacta c;
                            cin >> c;
                            v.adauga_masina(c);
                            break;
                        }
                        case 4:
                        {
                            Monovolume m;
                            cin >> m;
                            v.adauga_masina(m);
                            break;
                        }
                        break;
                    }
                    cout << '\n';
                }
            }
        break;
    }

    return in;
}

template<class T>
ostream &operator <<(ostream &out, Vanzare<T> &v)
{
    cout << '\n';
    cout << "Masini pe stoc: \n";

    for(int i = 0; i < v.nr_masini; i++)
    {
        cout << "Masina " << i + 1 << ": \n";
        v.stoc[i] -> Afisare();
        cout << '\n';
    }

    cout << '\n';
    if(v.nr_vandute > 0)
    {

    cout << "Masini vandute: \n";

    for(int i = 0; i < v.nr_vandute; i++)
        v.vandute[i] -> Afisare();
    }
    else
        cout << "Nicio masina vanduta pana la momentul actual!\n";

    cout << '\n';

    return out;
}


void Optiuni()
{
    cout << "1. Adauga o masina pe stoc\n";
    cout << "2. Adauga n masini pe stoc\n";
    cout << "3. Vinde o masina de pe stoc\n";
    cout << "4. Afiseaza masinile de pe stoc\n";
    cout << "5. Afiseaza masinile vandute\n";
    cout << "0. Pentru a opri programul\n";
}


set<pair<Masina*, bool>>s;

void MeniuInteractiv() //cu set
{
    int nr;
    Vanzare<Masina>garaj;
    //garaj.set_tip(5);

    while(true)
    {
        Optiuni();
        cout << "Alege optiunea: "; cin >> nr;
        if(nr < 0 || nr > 5)
            cout << "\nOptiune invalida!\n\n";
        else

    switch(nr)
    {
        case 1:
        {
            int tip;
            while(true)
            {
                cout << "Alege tipul masinii:\n1.Mini\n2.Mica\n3.Compacta\n4.Monovolume\n";
                cin >> tip;
                if(tip < 0 || tip > 4)
                    cout << "Tip invalid!\n";
                else
                    break;
            }

            switch(tip)
            {
                case 1:
                {
                    Mini m;
                    cin >> m;
                    cout << '\n';
                    s.insert(make_pair(&m, true));
                    garaj.adauga_masina(m);
                    break;
                }
                case 2:
                {
                    Mica m;
                    cin >> m;
                    cout << '\n';
                    s.insert(make_pair(&m, true));
                    garaj.adauga_masina(m);
                    break;
                }
                case 3:
                {
                    Compacta c;
                    cin >> c;
                    cout << '\n';
                    s.insert(make_pair(&c, true));
                    garaj.adauga_masina(c);
                    break;
                }
                case 4:
                {
                    Monovolume m;
                    cin >> m;
                    cout << '\n';
                    s.insert(make_pair(&m, true));
                    garaj.adauga_masina(m);
                }
                break;
            }
            break;
        }
        case 2:
        {
            cout << "\nIntroduceti numarul masinilor pe care doriti sa-le adaugati: ";
            int nr_m;
            cin >> nr_m;

            for(int i = 0; i < nr_m; i++)
            {
                int tip;
                while(true)
                {
                    cout << "Alege tipul masinii:\n1.Mini\n2.Mica\n3.Compacta\n4.Monovolume\n";
                    cin >> tip;
                    if(tip < 0 || tip > 4)
                        cout << "Tip invalid!\n";
                    else
                        break;
                }

            switch(tip)
            {
                    case 1:
                    {
                        Mini m;
                        cin >> m;
                        cout << '\n';
                        s.insert(make_pair(&m, true));
                        garaj.adauga_masina(m);
                        break;
                    }
                    case 2:
                    {
                        Mica m;
                        cin >> m;
                        cout << '\n';
                        s.insert(make_pair(&m, true));
                        garaj.adauga_masina(m);
                        break;
                    }
                    case 3:
                    {
                        Compacta c;
                        cin >> c;
                        cout << '\n';
                        s.insert(make_pair(&c, true));
                        garaj.adauga_masina(c);
                        break;
                    }
                    case 4:
                    {
                        Monovolume m;
                        cin >> m;
                        cout << '\n';
                        s.insert(make_pair(&m, true));
                        garaj.adauga_masina(m);
                    }
                    break;
                }
            }
            break;
        }
        case 3:
        {

            if(garaj.get_nr_masini() == 0)
                cout << "\nNu mai sunt masini pe stoc!\n\n";
            else
            {


            int tip;
            bool ok = false;


            cout << "\nIntroduceti datele masinii pe care doriti sa o vindeti:\n";
            while(!ok)
            {
                cout << "Alege tipul masinii:\n1.Mini\n2.Mica\n3.Compacta\n4.Monovolume\n";
                cin >> tip;
                if(tip < 0 || tip > 4)
                    cout << "Tip invalid!\n";
                else
                    break;
            }

            switch(tip)
            {
                case 1:
                {
                    Mini m;
                    cin >> m;
                    if(s.find(pair<Masina*, bool>(&m, true)) != s.end())
                    {
                        garaj -= m;
                        s.erase(pair<Masina*, bool>(&m, true));
                    }
                    else
                        cout << "Aceasta masina nu se afla pe stoc!\n\n";
                    break;
                }
                case 2:
                {
                    Mica m;
                    cin >> m;
                    if(s.find(pair<Masina*, bool>(&m, true)) != s.end())
                    {
                        garaj -= m;
                        s.erase(pair<Masina*, bool>(&m, true));
                    }
                    else
                        cout << "Aceasta masina nu se afla pe stoc!\n\n";
                    break;
                }
                case 3:
                {
                    Compacta c;
                    cin >> c;
                    if(s.find(pair<Masina*, bool>(&c, true)) != s.end())
                    {
                        garaj -= c;
                        s.erase(pair<Masina*, bool>(&c, true));
                    }
                    else
                        cout << "Aceasta masina nu se afla pe stoc!\n\n";
                    break;
                }
                case 4:
                {
                    Monovolume m;
                    cin >> m;
                    if(s.find(pair<Masina*, bool>(&m, true)) != s.end())
                    {
                        garaj -= m;
                        s.erase(pair<Masina*, bool>(&m, true));
                    }
                    else
                        cout << "Aceasta masina nu se afla pe stoc!\n\n";
                }
                break;
                }
            }
            break;
        }
        case 4:
        {
            garaj.afisare_stoc();
            break;
        }
        case 5:
        {
            garaj.afisare_vandute();
            break;
        }

        case 0:
            exit(0);
    }

    }
}

void MeniuInteractiv2() //fara set
{
    int nr;
    Vanzare<Masina>garaj;

    while(true)
    {
        Optiuni();
        cout << "Alege optiunea: "; cin >> nr;
        if(nr < 0 || nr > 5)
            cout << "\nOptiune invalida!\n\n";
        else

        switch(nr)
        {
            case 1:
            {
                int tip;
                while(true)
                {
                    cout << "Alege tipul masinii:\n1.Mini\n2.Mica\n3.Compacta\n4.Monovolume\n";
                    cin >> tip;
                    if(tip < 0 || tip > 4)
                        cout << "Tip invalid!\n";
                    else
                        break;
                }

                switch(tip)
                {
                    case 1:
                    {
                        Mini m;
                        cin >> m;
                        cout << '\n';
                        if(garaj.Este_in(m))
                            garaj.adauga_masina(m);
                        else
                            cout << "\nMasina este deja pe stoc!\n\n";
                        break;
                    }
                    case 2:
                    {
                        Mica m;
                        cin >> m;
                        cout << '\n';
                        if(garaj.Este_in(m))
                            garaj.adauga_masina(m);
                        else
                            cout << "\nMasina este deja pe stoc!\n\n";
                        break;
                    }
                    case 3:
                    {
                        Compacta c;
                        cin >> c;
                        cout << '\n';
                        if(garaj.Este_in(c))
                            garaj.adauga_masina(c);
                        else
                            cout << "\nMasina este deja pe stoc!\n\n";
                        break;
                    }
                    case 4:
                    {
                        Monovolume m;
                        cin >> m;
                        cout << '\n';
                        if(garaj.Este_in(m))
                            garaj.adauga_masina(m);
                        else
                            cout << "\nMasina este deja pe stoc!\n\n";
                    }
                    break;
                }
                break;
            }
            case 2:
            {
                cout << "\nIntroduceti numarul masinilor pe care doriti sa-le adaugati: ";
                int nr_m;
                cin >> nr_m;

                for(int i = 0; i < nr_m; i++)
                {
                    int tip;
                    while(true)
                    {
                        cout << "Alege tipul masinii:\n1.Mini\n2.Mica\n3.Compacta\n4.Monovolume\n";
                        cin >> tip;
                        if(tip < 0 || tip > 4)
                            cout << "Tip invalid!\n";
                        else
                            break;
                    }

                 switch(tip)
                {
                        case 1:
                        {
                            Mini m;
                            while(true)
                            {
                                cin >> m;
                                cout << '\n';
                                if(garaj.Este_in(m))
                                {
                                    garaj.adauga_masina(m);
                                    break;
                                }
                                else
                                    cout << "\nMasina este deja pe stoc!\n\n";
                            }
                            break;
                        }
                        case 2:
                        {
                            Mica m;
                            while(true)
                            {
                                cin >> m;
                                cout << '\n';
                                if(garaj.Este_in(m))
                                {
                                    garaj.adauga_masina(m);
                                    break;
                                }
                                else
                                    cout << "\nMasina este deja pe stoc!\n\n";
                            }
                            break;
                        }
                        case 3:
                        {
                            Compacta c;
                            cin >> c;
                            cout << '\n';
                            while(true)
                            {
                                if(garaj.Este_in(c))
                                {
                                    garaj.adauga_masina(c);
                                    break;
                                }
                                else
                                    cout << "\nMasina este deja pe stoc!\n\n";
                            }
                            break;
                        }
                        case 4:
                        {
                            Monovolume m;
                            while(true)
                            {
                                cin >> m;
                                cout << '\n';
                                if(garaj.Este_in(m))
                                {
                                    garaj.adauga_masina(m);
                                    break;
                                }
                                else
                                    cout << "\nMasina este deja pe stoc!\n\n";
                            }
                        }
                        break;
                    }
                }
                break;
            }
            case 3:
            {

                if(garaj.get_nr_masini() == 0)
                    cout << "\nNu mai sunt masini pe stoc!\n\n";
                else
                {


                int tip;
                bool ok = false;


                cout << "\nIntroduceti datele masinii pe care doriti sa o vindeti:\n";
                while(!ok)
                {
                    cout << "Alege tipul masinii:\n1.Mini\n2.Mica\n3.Compacta\n4.Monovolume\n";
                    cin >> tip;
                    if(tip < 0 || tip > 4)
                        cout << "Tip invalid!\n";
                    else
                        break;
                }

                switch(tip)
                {
                    case 1:
                    {
                        Mini m;
                        cin >> m;
                         if(garaj.Este_in(m))
                                cout << "\nMasina nu este pe stoc!\n\n";
                            else
                                garaj -= m;
                        break;
                    }
                    case 2:
                    {
                        Mica m;
                        cin >> m;
                        if(garaj.Este_in(m))
                                cout << "\nMasina nu este pe stoc!\n\n";
                            else
                                garaj -= m;
                        break;
                    }
                    case 3:
                    {
                        Compacta c;
                        cin >> c;
                        if(garaj.Este_in(c))
                                cout << "\nMasina nu este pe stoc!\n\n";
                            else
                                garaj -= c;
                        break;
                    }
                    case 4:
                    {
                        Monovolume m;
                        cin >> m;
                        if(garaj.Este_in(m))
                                cout << "\nMasina nu este pe stoc!\n\n";
                            else
                                garaj -= m;
                    }
                    break;
                    }
                }
                break;
            }
            case 4:
            {
                garaj.afisare_stoc();
                break;
            }
            case 5:
            {
                garaj.afisare_vandute();
                break;
            }

            case 0:
                exit(0);
        }

    }
}



int main()
{
    //MeniuInteractiv();  //cu set
    MeniuInteractiv2(); //fara set

    return 0;
}
