#include <iostream>
#include <memory>
class BackEnd;
class FrontEnd
{
    std::shared_ptr<BackEnd> m_ptr; 
    public:
    FrontEnd()
    {
        std::cout<< "FrontEnd Consstructor" <<std::endl;
    }
    ~FrontEnd()
    {
        std::cout << "FrontEnd Destructor " << "BAckEnd ptr ref_cout " <<m_ptr.use_count()<< std::endl;
    }
    void setBackEndClass(std::shared_ptr<BackEnd> &ptr)
    {
        m_ptr = ptr;
    }
 
};
 
class BackEnd
{
    std::weak_ptr<FrontEnd> m_ptr; 
    public:
    BackEnd(std::shared_ptr<FrontEnd> &ptr)
    {
        m_ptr = ptr;
        std::cout<< "BackEnd Consstructor" <<std::endl;
    }
    ~BackEnd()
    {
        std::cout << "BackEnd Destructor " << "FrontEnd ptr ref_cout " <<m_ptr.use_count()<< std::endl;
    }
};
 
 
int main()
{
    std::shared_ptr<FrontEnd> fptr(new FrontEnd()); 
    std::shared_ptr<BackEnd> bptr(new BackEnd(fptr));
    fptr->setBackEndClass(bptr);
    std::cout <<"FrontEnd usecout is: " << fptr.use_count() << std::endl;
    std::cout << "BackEnd Use count is :" << bptr.use_count() << std::endl;
    return 0;
}