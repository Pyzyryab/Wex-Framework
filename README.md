# Wex Framework

Welcome to the `Wex Framwework`, a lightweight, portable, idiomatic, fast and scalable web framework for `modern C++` 

## Motivation behind the project

Take care that this it's not designed like to be a production ready project. It's a posibility, yes, but the foundation of this work it's to learn about five main things:

    - Modern C++ (C++20 will be the target until a new release, trying to implement Coroutines, Concepts, Modules... always looking to bring the latest but stable language feature)
    - Advanced modern software desing architecture
    - SOLID design patterns and principles
    - Low level web stuff (Websockets, TCP/UDP implementation protocols, resource routing)
    - C++ test drive development (GoogleTest fwk will be used)


## Basic style guide conventions (Work in progress)

In order to someday let people join into the development of this framework, a `C++` style guidelines will be defined since the beginning and applied across the whole framework development and designing while it's been writting.

 - Delimitter openning key will be written after the last word of the function, class or struct declaration. 
```
    // Function
    void foo() const override {
        // Body
    }

    // Class or Struct
    struct MyStruct {
        // Members
    }


    // Class
    class MyCustomType : public MyBaseCustomType {
        private:
            // Private members and methods
        public:
            // Public members and methods
    } 

    : alternative : 

    class MyCustomType
        : public MyBaseCustomType { // If this one it's applied, put a new line after the public inherit signature part and the members/method zone

        private:
            // Private members and methods
        public:
            // Public members and methods
    }
```

The most important rule applied here it's that every time you break a line, tab ident the next line with 4 spaces.
1 tab distance it's written (if possible) with 4 spaces.

Same applies for the `if - else` statements and `for` and `while` loops declarations.

End users of the APIs here provided, in the other hand, can write C++ in the way that best fills it's desires, but we always recommend to stick to the same guidelines provided here, in order to have a same pattern in the whole ecosystem

