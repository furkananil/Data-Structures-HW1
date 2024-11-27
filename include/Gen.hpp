#ifndef GEN_HPP
#define GEN_HPP

class Gen {
private:
    char data; 

public:
    Gen* next; 
    Gen* prev; 

    Gen(char data);
    char getData() const; 
    void setData(char data);
};
#endif 
