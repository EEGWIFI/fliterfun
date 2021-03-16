#ifndef FILTER_IIR_H
#define FILTER_IIR_H

#include "Queue.hpp"

//fdatool coff


const int NL = 7;
//const double NUM[7] = {
//    0.02631390982951,                 0, -0.07894172948854,                 0,
//    0.07894172948854,                 0, -0.02631390982951
//};

//const int DL = 7;
//const double DEN[7] = {
//    1,   -4.521705366005,    8.561646472635,    -8.76682658309,
//5.159861520666,   -1.657007614218,   0.2240352520527
//};
const double NUM[7] = {
  3.961228562203e-08,2.376737137322e-07,5.941842843305e-07,7.922457124407e-07,
  5.941842843305e-07,2.376737137322e-07,3.961228562203e-08
};
const int DL = 7;
const double DEN[7] = {
                   1,   -5.772876907018,    13.93950674398,   -18.01956933687,
      13.15169982185,   -5.138258488637,   0.8395010112154
};





template<typename T>
class Filter_IIR
{
public:
    Filter_IIR();
    ~Filter_IIR();
    char filterData(T data,T* res);
private:
    unsigned int orders;
    Queue<T>* num;
    Queue<T>* den;

};

template<typename T>
Filter_IIR<T>::Filter_IIR(){
    orders = DL-1;  // 6阶！！！！！！
    num = new Queue<T>(DL);
    den = new Queue<T>(DL);
    for(int i = 0;i< orders; i ++){
        num->push(0);
        den->push(0);
    }

}

template<typename T>
Filter_IIR<T>::~Filter_IIR(){
    delete num;
    delete den;
}

template<typename T>
char Filter_IIR<T>::filterData(T data,T *res){
    unsigned int n = orders;
    T temp,temp_res;
    temp_res = data*NUM[0];
           while(n--){         //n-1 ~0
               num->at(n,temp);   // 新 -> 老
              temp_res += temp*NUM[DL-1-n];  // 此处已经减过1
               den->at(n,temp);
              temp_res -= temp*DEN[DL-1-n];
          }
    num->pop(temp);  //必须先pop
    den->pop(temp);
    num->push(data);
    den->push(temp_res);

    *res = temp_res;
    return 1;
}
#endif // FILTER_H