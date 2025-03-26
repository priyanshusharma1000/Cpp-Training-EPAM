/*
Pimpl Idiom
Pimpl (Pointer-to-Implementation) idiom, also known as a private class data, compiler firewall, or handle classes, is a technique used in C++ to hide the implementation details of a class by using a forward declaration to a private structure or class, keeping the public interface of the class clean, and reducing compile-time dependencies.
*/
/*
benefit of using pimpl:
->Hide implemented details
->Reduce Compilation Time
->True Encapsulation
->Binary Compatibility
*/
class MyClass_Impl; // forward declaration

class MyClass
{
public:
    MyClass();
    ~MyClass();
    void some_method();

private:
    MyClass_Impl *pimpl; // pointer to the implementation
};