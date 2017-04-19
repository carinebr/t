#include <exception>
#include <string>
using namespace std;
 
class ExceptErr: public exception
{
public:
    ExceptErr(int num, int level, const string & phrase, const string& module, int line) throw();
 
    virtual const char* what() const throw();
     
    int getLevel() const throw();
    
    virtual ~ExceptErr() throw();
 
private:
    int m_num;
    int m_level;
    string m_phrase;
    string m_module;
    int m_line;
};
