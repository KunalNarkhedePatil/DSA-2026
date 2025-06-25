#include <iostream> 

class Base 
{
    public: 
        // INHERITOR 
        void f()
        {
            std::cout << "Base::f()" << std::endl; 
        }

        // WILL BE OVERRIDDEN BY DERIVED CLASS 
        // BUT NOT MADE VIRTUAL IN BASE CLASS
        void g1()
        {
            std::cout << "Base::g1()" << std::endl; 
        }

        // WILL BE OVERRIDDEN BY DERIVED CLASS 
        // FOR EXTENSION: WILL BE MADE VIRTUAL IN BASE 
        virtual void g2()
        {
            std::cout << "Base::g2()" << std::endl;   
        }
        
        // WILL BE OVERDDEN BY DERIVED CLASS 
        // FOR REPLACEMENT : WILL BE MADE VIRTUAL IN BASE 
        virtual void g3()
        {
            std::cout << "Base::g3()" << std::endl; 
        }
}; 

class Derived : public Base 
{
    public: 
        // OVERRIDING Base::g1(), but Base::g1() IS NOT 
        // VIRTUAL 
        void g1()
        {
            std::cout << "Derived::g1()" << std::endl; 
        }
        // OVERRIDING Base::g2() FOR EXTENDING 
        void g2() 
        {   
            // this == CALLING OBJECT OF THE TYPE DERIVED 
            // Only calling g2() or calling this->g2() 
            // will result into recursive calls to Derived::g2()
            std::cout << "Derived::g2()" << std::endl; 
            std::cout << "Calling Base::g2() for extension" << std::endl; 
            this->Base::g2(); 
            std::cout << "Derived::g2():Derived specific logic" << std::endl; 
            std::cout << "Returning from Derived::g2()" << std::endl; 
        }

        // OVERRIDING Base::g3() BY OVERRIDING IT 
        void g3()
        {
            std::cout << "Derived::g3()" << std::endl; 
        }

        void h()
        {
            std::cout << "Derived::h()" << std::endl; 
        }
}; 

void testWithDerivedPtr(void); 
void testWithBasePtr(void); 

int main(void)
{
    testWithDerivedPtr();
    testWithBasePtr(); 
    return (0); 
}

void testWithDerivedPtr(void)
{
    Derived* pD = new Derived; 

    // INHERITOR Base::f() 
    pD->f(); 

    // OVERRIDDEN BY DERIVED BUT NOT MADE VIRTUAL 
    // Base::g1() 
    pD->Base::g1(); 

    // OVERRIDDEN BY DERIVED FOR EXTENSION : MADE VIRTUAL 
    // Base::g2() 
    pD->Base::g2(); 

    // OVERRIDDEN BY DERIVED FOR REPLACEMENT : MADE VIRTUAL 
    // Base::g3() 
    pD->Base::g3();
    
    // Derived::g1() 
    pD->g1(); 

    // Derived::g2() 
    pD->g2(); 

    // Derived::g3()
    pD->g3(); 

    // DERIVED SPECIIC FUNCTION 
    // Derived::h() 
    pD->h(); 

    delete pD; 
    pD = 0; 
}

void testWithBasePtr(void)
{
    Base* pB = new Derived; 

    // Base::f() 
    pB->f(); 

    // Base::g1() 
    pB->g1(); 

    // Base::g2() 
    pB->Base::g2(); 

    // Base::g3() 
    pB->Base::g3(); 

    // Derived::g1() 
    // pB->Derived::g1(); // WILL NOT WORK 
    dynamic_cast<Derived*>(pB)->g1(); 
    
    // Derived::g2() 
    pB->g2(); 

    // Derived::g3() 
    pB->g3(); 

    // Derived::h() 
    dynamic_cast<Derived*>(pB)->h(); 

    delete pB; 
    pB = 0; 
}



-------------------------------------
#include <iostream> 
#include <cstdio> 

class B1{
    public: 
        int n1, n2; 
}; 

class B2
{
    public: 
        double d1, d2; 

        void test()
        {
            printf("In B2::test():addr(this):%zu\n", (std::size_t)this); 
        }
}; 

class D : public B1, public B2 
{
    public: 
        short s1, s2, s3, s4; 

    public: 
        void print_slices()
        {
            std::size_t offB1 = (std::size_t)(&this->n1) - (std::size_t)this; 
            std::size_t offB2 = (std::size_t)(&this->d1) - (std::size_t)this; 
            std::size_t offD = (std::size_t)(&this->s1) - (std::size_t)this; 

            printf("offB1 = %zu, offB2 = %zu, offD = %zu\n", offB1, offB2, offD); 
        }
}; 

int main(void)
{
    printf("sizeof(B1) = %zu\n", sizeof(B1));   // 8 
    printf("sizeof(B2) = %zu\n", sizeof(B2));   // 16 
    printf("sizeof(D) = %zu\n", sizeof(D));    // 32 

    D objD; 

    objD.print_slices(); 

    printf("address of objD:%zu\n", (std::size_t)&objD); 

    objD.test(); // B2::test(&objD); 

    return 0; 
}


------------------------------------