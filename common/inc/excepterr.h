/**
 * \class ExceptErr
 *
 * \brief implement a customized exception 
 *
 * This class implement the exception notion. Full raceback (stack) can be retrieved. 
 * Usage:
 *     throw ExceptErr(<errnum>, <errlevel>, <somme comments about the err>, __FILE__, __FUNCTION__, __LINE__);
 *     when catching
 *     catch(ExceptErr& e)
 *     {
 *         e.addStackInfo(__FILE__, __FUNCTION__, __LINE__);
 *         throw;//handled in the invoker funct
 *         or
 *         cerr<<e.what();//at the last catch in main()
 *     }
 *     catch(const exception& e)
 *     {
 *         throw;//handled in the invoker funct
 *         or
 *         cerr<<e.what();//at the last catch() in main()
 *     }
 * will yield    
 *     exception!!: open tttt failure
 *     module: /home/developpement/t/common/src/appli.cpp - function: readIniFile(), - line: 50
 *     module: /home/developpement/t/t1/src/tester.cpp - function: testIt()  - line: 56
 *     module: /home/developpement/t/t1/src/t1.cpp - function: main()  - line: 59
 *
 */
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
