#ifndef APPLI_H_INCLUDED
#define APPLI_H_INCLUDED

class ifstream;

class Appli
{
    public :
        static Appli* getInstance();
        //destructor
        ~Appli(void);
    private:
        //constructor
        static Appli* m_Instance;
        Appli();
};
#endif  //APPLI_H_INCLUDED
