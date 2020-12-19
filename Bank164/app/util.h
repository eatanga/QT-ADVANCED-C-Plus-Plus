#ifndef UTIL_H
#define UTIL_H

template<class T>
class Util
{
public:
    Util();
    T &max(T &a,T $b);
};

template<class T>
T  &max(T &a,T &b){
    if (b > a) {

            return b;

        } else {

            return a;

        }
}

#endif // UTIL_H
