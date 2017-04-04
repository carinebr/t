#include <exception>
#include <string>
using namespace std;
 
class ExceptErr: public exception
{
public:
    ExceptErr(int num = 0, const string & phrase = "", int level = 0) throw();
 
    virtual const char* what() const throw();
     
    int getLevel() const throw();
    
    virtual ~ExceptErr() throw();
 
private:
    int m_num;
    string m_phrase;
    int m_level;
};
