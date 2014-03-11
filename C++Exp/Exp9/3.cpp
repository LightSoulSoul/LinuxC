#include <iostream>

#define FRIEND

class Money
{
private:
    double yuan, jiao, fen;
public:
    ~Money() { }
    Money() { this->yuan = 0; this->jiao = 0; this->fen = 0; }
    Money(const double y, const double j, const double f):
            yuan(y), jiao(j), fen(f) { }
    #ifdef MEMBER
    Money& operator --()
    {
        --yuan;
        return *this;
    }
    const Money operator--(int)
    {
        Money tmp = *this;
        --(*this);
        return Money(tmp);
    }
    #endif
    #ifdef FRIEND
    friend Money& operator--(Money &rhs);
    friend Money operator--(Money &lhs, int _i);
    #endif
    void display()
    {
        std::cout << this->yuan << " Yuan "
                  << this->jiao << " Jiao "
                  << this->fen  << " Fen " << std::endl;
    }
};

int main()
{
    Money m1(10,8,5), m2, m3;
    m2 = --m1;
    m3 = m1--;
    m1.display();
    m2.display();
    m3.display();
    return 0;
}

#ifdef FRIEND

Money& operator--(Money &rhs)
{
    --rhs.yuan;
    return rhs;
}
Money operator--(Money &lhs, int _i)
{
    Money tmp = lhs;
    --(lhs);
    return Money(tmp);
}

#endif
