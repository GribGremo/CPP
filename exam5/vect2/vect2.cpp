#include <iostream>
#include "vect2.hpp"
#include "log.hpp"

    Vect2::Vect2() : _n1(0), _n2(0){
        LOG("Vect2 default constructor");
    }
    Vect2::Vect2(const int n1, const int n2): _n1(n1), _n2(n2){
        LOG("Vect2 custom constructor");

    }
    Vect2::Vect2(const Vect2& v): _n1(v._n1), _n2(v._n2){
        LOG("Vect2 copy constructor");

    }
    Vect2::~Vect2(){
        LOG("Vect2 destructor");
    }

    Vect2& Vect2::operator=(const Vect2& v){ // C'est le seul qui modifie reellement le vecteur d'origine, tous les autres vont envoyes une representation de ce calcul mais pas modifier, c'est logique
        _n1 = v._n1;
        _n2 = v._n2;
        return (*this);
    }
    //Temp est temporaire n'existe que dans cette fonction si tu renvois une ref de temp, elle n'existera plus, du coup on return forcement une copie
    //arythmetic operators

    Vect2 Vect2::operator+(const Vect2& v)const{//this n'est pas une ref mais un pointeur donc ->
        LOG("OP+vec");
        return (Vect2(this->_n1 + v._n1,this->_n2 + v._n2));
    }
    Vect2 Vect2::operator-(const Vect2& v)const{
        return (Vect2(this->_n1 - v._n1,this->_n2 - v._n2));
    }
    Vect2 Vect2::operator*(const Vect2& v)const{
        return (Vect2(this->_n1 * v._n1,this->_n2 * v._n2));
    }

    Vect2 Vect2::operator+(int n)const{
        return (Vect2(this->_n1 + n,this->_n2 + n));
    }
    Vect2 Vect2::operator-(int n) const{
        return (Vect2(this->_n1 - n,this->_n2 - n));
    }
    Vect2 Vect2::operator*(int n)const{
        return (Vect2(this->_n1 * n,this->_n2 * n));
    }

    //location operator
    int& Vect2::operator[](int i){
        if (i == 0)
            return (this->_n1);
        return (this->_n2);
    }
    const int& Vect2::operator[](int i) const{
        if (i == 0)
            return (this->_n1);
        return (this->_n2);
    }

    //incremental/decremental operators
    Vect2& Vect2::operator++(){
        this->_n1 += 1;
        this->_n2 += 1;
        return (*this);
    }
    Vect2 Vect2::operator++(int){// On return un temp, impossible de retourner l'original, puisqu'on veut son etat precedent, du coup pas de chainage possible puisque ce qui est renvoue est une temp pas l'originale.
        Vect2 temp = *this;
        this->_n1 += 1;
        this->_n2 += 1;
        return (temp);
    }
    Vect2& Vect2::operator--(){
        this->_n1 -= 1;
        this->_n2 -= 1;
        return (*this);
    }
    Vect2 Vect2::operator--(int){
        Vect2 temp = *this;
        this->_n1 -= 1;
        this->_n2 -= 1;
        return (temp);
    }
/////////////////////////////////////
    Vect2& Vect2::operator+=(int n){
        this->_n1 += n;
        this->_n2 += n;
        return (*this);
    }
    Vect2& Vect2::operator-=(int n){
        this->_n1 -= n;
        this->_n2 -= n;
        return (*this);
    }
    Vect2& Vect2::operator*=(const int n){
        this->_n1 *= n;
        this->_n2 *= n;
        return (*this);
    }
/////////////////////////////////////
    Vect2& Vect2::operator+=(const Vect2& v){
        this->_n1 += v._n1;
        this->_n2 += v._n2;
        return (*this);
    }
    Vect2& Vect2::operator-=(const Vect2& v){
        this->_n1 -= v._n1;
        this->_n2 -= v._n2;
        return (*this);
    }
    Vect2& Vect2::operator*=(const Vect2& v){
        this->_n1 *= v._n1;
        this->_n2 *= v._n2;
        return (*this);
    }

    //comparison operators
    bool Vect2::operator==(const Vect2& v)const{
        return (v._n1 == this->_n1 && v._n2 == this->_n2);
    }
    bool Vect2::operator!=(const Vect2& v)const{
        return (v._n1 != this->_n1 || v._n2 != this->_n2);
    }

    //unary operator
    Vect2 Vect2::operator-()const{//Encore une fois on ne souhaite pas modifier l'instance c'est juste une representation temporaire donc pas de ref
        return (Vect2(this->_n1 * (-1),this->_n2 * (-1)));
    }

    //stream operator
    std::ostream& operator<<(std::ostream& os, const Vect2& v){
        os << "{" << v.getNone() << ", " << v.getNtwo() << "}";
        return (os);
    }

    //arythmetic operators // Ces operateurs sont employes dans le cas int serait avant l'operateur suivi d'une vect2
    Vect2 operator*(int n, const Vect2& v){
        return (Vect2(n * v.getNone(), n * v.getNtwo()));
    }
    Vect2 operator+(int n, const Vect2& v){
        return (Vect2(n + v.getNone(), n + v.getNtwo()));
    }
    Vect2 operator-(int n, const Vect2& v){
        return (Vect2(n - v.getNone(), n - v.getNtwo()));
    }

    //GETTERS/SETTERS

    int Vect2::getNone()const{
        return(this->_n1);
    }

    int Vect2::getNtwo()const{
        return(this->_n2);
    }

    void Vect2::setNone(int n){
        this->_n1 = n;
    }

    void Vect2::setNtwo(int n){
        this->_n2 = n;
    }

