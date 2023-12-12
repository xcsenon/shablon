#include <iostream>

// AbstractClass
class AbstractClass {
public:
    // Template method
    void templateMethod() const {
        primitiveOperation1();
        primitiveOperation2();
        concreteOperation();
        hook(); // Optional hook method
    }

protected:
    // Primitive operations to be implemented by subclasses
    virtual void primitiveOperation1() const = 0;
    virtual void primitiveOperation2() const = 0;

    // Concrete operation with a default implementation
    void concreteOperation() const {
        std::cout << "Default implementation of concreteOperation." << std::endl;
    }

    // Optional hook method with a default empty implementation
    virtual void hook() const {}
};

// ConcreteClassA
class ConcreteClassA : public AbstractClass {
protected:
    void primitiveOperation1() const override {
        std::cout << "ConcreteClassA: primitiveOperation1." << std::endl;
    }

    void primitiveOperation2() const override {
        std::cout << "ConcreteClassA: primitiveOperation2." << std::endl;
    }
};

// ConcreteClassB
class ConcreteClassB : public AbstractClass {
protected:
    void primitiveOperation1() const override {
        std::cout << "ConcreteClassB: primitiveOperation1." << std::endl;
    }

    void primitiveOperation2() const override {
        std::cout << "ConcreteClassB: primitiveOperation2." << std::endl;
    }

    void hook() const override {
        std::cout << "ConcreteClassB: hook." << std::endl;
    }
};

int main() {
    ConcreteClassA concreteA;
    ConcreteClassB concreteB;

    std::cout << "Calling template method on ConcreteClassA:" << std::endl;
    concreteA.templateMethod();

    std::cout << "\nCalling template method on ConcreteClassB:" << std::endl;
    concreteB.templateMethod();

    return 0;
}
