#ifndef COMPLEX_NUM_H
#define COMPLEX_NUM_H
#include <iostream>




using namespace std;

template<typename T>
        class complex_num
        {
        private:
            T _M_real_num;
            T _M_imag_num;
        public:
            complex_num()   {}
            complex_num(T _real):_M_real_num(_real), _M_imag_num(0) {}
            complex_num(T _real, T _imag): _M_real_num(_real), _M_imag_num(_imag)   {}
            complex_num(const complex_num<T>&rhs):_M_real_num(rhs._M_real_num), _M_imag_num(rhs._M_imag_num)    {}
            ~complex_num(){}

            T real(){ return _M_real_num;}
            T imag(){ return _M_imag_num;}

            complex_num<T>&operator =(const complex_num<T>& __z)
            {
                if(this != &__z)
                {
                    _M_real_num = __z._M_real_num;
                    _M_imag_num = __z._M_imag_num;
                }
                return *this;
            }

            complex_num<T>& operator+=(const complex_num<T>& __z)
            {
                _M_real_num += __z._M_real_num;
                _M_imag_num += __z._M_imag_num;

                return *this;
            }

            complex_num<T>& operator-=(const complex_num<T>& __z)
            {
                _M_real_num -= __z._M_real_num;
                _M_imag_num -= __z._M_imag_num;

                return *this;
            }

            complex_num<T> operator+(const complex_num<T>& __x)
            {
                complex_num<T> tmp(*this);
                tmp += __x;
                return tmp;
            }

            complex_num<T>operator-(const complex_num<T>& __x)
            {
                complex_num<T> tmp(*this);
                tmp -= __x;
                return tmp;
            }

            complex_num<T> operator*(const complex_num<T>& __x)
            {

                return complex_num<T>(_M_real_num * __x._M_real_num - _M_imag_num * __x._M_imag_num, _M_real_num * __x._M_imag_num + _M_imag_num * __x._M_real_num);
            }

            complex_num<T> operator/(const complex_num<T>& __x)
            {

                T r = __x._M_real_num * __x._M_real_num + __x._M_imag_num * __x._M_imag_num;
                complex_num<T>tmp((_M_real_num * __x._M_real_num + _M_imag_num * __x._M_imag_num)/r, (_M_imag_num * __x._M_real_num - _M_real_num * __x._M_imag_num)/r);
                return tmp;

            }

            friend ostream & operator<< (ostream &out, const complex_num &c)
            {
                out << "(" << c._M_real_num << ", " << c._M_imag_num << ")";
                return out;
            }
            friend istream & operator>> (istream &in, complex_num &c)
            {
                cout << "real: "; in >> c._M_real_num;
                cout << "imag: "; in >> c._M_imag_num;
                return in;
            }
        };




#endif // COMPLEX_NUM_H
