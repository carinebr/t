#include <exception>
#include <string>
using namespace std;
 
class ExceptErr: public exception
{
public:
    ExceptErr(int num, int level, const string& phrase, const string& module, const string& function, int line) throw();
 
    virtual const char* what() const throw();
     
    int getLevel() const throw();
    void addStackInfo(const char* module, const char* function, int line);
    
    virtual ~ExceptErr() throw();
 
private:
    int m_num;
    int m_level;
    string m_phrase;
};
