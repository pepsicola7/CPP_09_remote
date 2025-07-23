
#include "bigint.hpp"

bigint::bigint():num("0")
{
};

bigint::~bigint()
{
};

bigint::bigint(const bigint& other)
{
    num = other.num;
};

bigint::bigint(const std::string& n)
{
    if (n.empty() || !std::all_of(n.begin(), n.end(), ::isdigit) || (n.size() > 1 && n[0] == '0'))
    {
        std::cerr << "Invalid number string" << std::endl;
        num = "0";
    }
    num = n;
};

bigint::bigint(size_t n): num(std::to_string(n))
{
};

void bigint::remove_zero()
{
    num.erase(0, num.find_first_not_of("0"));
    if (num.empty())
        num == "0";
}

bool bigint::operator<(const bigint& other) const
{
    if (num.size() != other.num.size())
        return (num.size() < other.num.size());
    else
        return (num < other.num);
};
bool bigint::operator>(const bigint& other) const
{
    return (other < *this);
}; // !!

bool bigint::operator<=(const bigint& other) const
{
    return !(*this > other);
};

bool bigint::operator>=(const bigint& other) const
{
    return !(*this < other);
};

bool bigint::operator==(const bigint& other) const
{
    return (num == other.num);
};

bool bigint::operator!=(const bigint& other) const
{
    return (num != other.num);
};

std::string add_string(const std::string& n1, const std::string& n2)
{
    std::string resultat;
    int carry = 0;
    
    int i = n1.size() - 1;
    int j = n2.size() - 1;
    while (i >= 0 || j>= 0 || carry)
    {
        int digit1 = (i >= 0) ? n1[i] - '0' : 0;
        int digit2 = (j >= 0) ? n2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        resultat.push_back(sum % 10 + '0'); 
        i--;
        j--;
    }
    std::reverse(resultat.begin(), resultat.end());
    return (resultat);
}

bigint  bigint::operator+(const bigint& other) const
{
    return bigint(add_string(num, other.num));
};

bigint&  bigint::operator+=(const bigint& other)
{
    num = add_string(num, other.num);
    return (*this);
};

bigint  bigint::operator-(const bigint& other) const
{
    (void)other;
    return (bigint());
};

bigint bigint::operator<<(size_t shift) const
{
    if (num == "0")
        return (*this);
    return (num + std::string(shift, '0'));
};

bigint& bigint::operator<<=(size_t shift)
{
    num += std::string(shift, '0');
};

bigint& bigint::operator>>=(size_t shift)
{
    if (num.size() <= shift)
        num = "0";
    else
        num = num.substr(0, num.size() - shift);
    return (*this);
};

bigint& bigint::operator++()
{
    return (*this += bigint(1));
};

bigint bigint::operator++(int)
{
    bigint temp(*this);
    ++(*this);
    return(temp);
};
