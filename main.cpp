#include<iostream>
#include"string.h"
#include<vector>
using namespace std;
class client
{
    private:
    int ci;
    string nom;
    public:
    client (int a, string b)
    {
        ci=a;
        nom=b;
    }
    ~client () {};
    int getci (void)
    {
        return ci;
    }
    void setci (int a)
    {
        ci=a;
    }
    string getnom (void)
    {
        return nom;
    }
    void setnom (string a)
    {
        nom=a;
    }

    void saisir ()
    {
        cout<<"donner le nom"<<endl;
        cin>>nom;
        cout<<"donner ci"<<endl;
        cin>>ci;
    }
    void affiche ()
    {
        cout<<nom<<endl<<ci;
    }
};

class livre
{
    private:
    int id;
    float prix;
    public:
    livre (int a, float b)
    {
        id=a;
        prix=b;
    }
    ~livre(){};
    void setid(int a)
    {
        id=a;
    }
    int getid()
    {
        return id;
    }
    void setprix(float a)
    {
        prix=a;
    }
    float getprix()
    {
        return prix;
    }
	void saisir()
	{
		cout<<"id livre= " <<endl;
		cin>>id;
		cout<<"prix="<<endl;
		cin>>prix;
	}
	void affiche ()
	{
		cout<<"id livre= "<<id<<endl;

		cout<<"prix= "<<prix<<endl;
	}
};
class emprunt : public client, public livre
{
    private:
    int num;
    public:
    emprunt(int a, string b, int c, float d, int e):client(a,b),livre(c,d) 
    {

        num=e;
    }
    ~emprunt() {};
    void affiche() 
    {
        cout<<num<<endl;
        livre::affiche();
        client::affiche();
    }
    float cotisation()
    {
        return (this->getprix()*0.1/100);
    }
    int getnum()
    {
        return num;
    }
};
class bib
{
    private:
    vector <emprunt> v;
    public:
    bib(){};
    ~bib(){};

    void affiche ()
    {
        for (int i=0;i<v.size();i++)
            {v[i].affiche();
            cout<<endl<<"-------"<<endl;}
    }
    void ajouter (emprunt a)
    {
        v.push_back(a);
    }
    /*void annuler (emprunt a)
    {
        v.erase(a);
    }*/
    float calculer (int a)
    {
        float r=0;
        for (int i=0;i<v.size();i++)
        {
            if (v[i].getci()==a)
            r+=v[i].cotisation();
        }
    }

    void getall (int c)
    {
        for (int i=0;i<v.size();i++)
        {
            if (v[i].getci()==c)
                cout<<v[i].getnum()<<endl;
        }
    }

};
int main()
{
    cout<<"HELLO"<<endl;
    client a(123,"kat");
    livre b (1,12);
    livre c (2,23);
    livre d (3,5);
    bib bi;
    emprunt m1 (500,"mark",120,4,1);
    emprunt m2 (400,"mark",120,4,2);
    emprunt m (500,"mark",120,4,3);

    bi.ajouter (m);
    bi.ajouter (m2);
    bi.ajouter (m1);
    bi.affiche();
    bi.getall(500);
}
