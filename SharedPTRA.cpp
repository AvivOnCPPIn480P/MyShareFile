#include <iostream>
#include <Windows.h>
#include <memory>
class sPTR {
public:
    sPTR(int* number) {
        p = number;
        count = new int(0);
    }

    sPTR() {
        p = nullptr;
        count = new int(0);
    }
    
    sPTR(const sPTR& other) {
        this->p = other.p; 
        this->count = other.count;
        if (nullptr != other.p) {
            (*this->count)++;
        }
    }

    sPTR& operator=( sPTR& other) {
        this->p = other.p; 
        this->count = other.count;
        (*this->count)++;
        return *this;
    }
    
    ~sPTR() {
        (*count)--;
        if (*count < 0) {
                delete p;
                delete count;
        }
    }
private:
    int* count = nullptr;
    int* p = nullptr;
};
int main()
{
    int* a = new int(3);
    sPTR x1 = sPTR(a);
    sPTR x2 = sPTR(x1);
    sPTR x3;
    x3 = x2;
}
 
