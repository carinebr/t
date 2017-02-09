#ifndef APPLI_H_INCLUDED
#define APPLI_H_INCLUDED

/// \file application data handler
/// \brief application data handling
class ifstream;

class Appli
{
    public :
        static Appli* getInstance();
        ///destructor
        ~Appli(void);
        void someFunction();
    private:
        static Appli* m_Instance;
        ///constructor
        Appli();
};
#endif  //APPLI_H_INCLUDED
