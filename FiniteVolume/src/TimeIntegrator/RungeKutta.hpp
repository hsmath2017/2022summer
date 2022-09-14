/**
 * @file RungeKutta.hpp
 * @author Shuang Hu (22135017@zju.edu.cn)
 * @brief Runge-Kutta Method
 * @version 0.1
 * @date 2022-08-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "SpacialOp.hpp"
template<int Dim,class DType>
class RungeKutta{
private:
    Tensor<Real,Dim> butlar;
    RectDomain<Dim> domain;
public:
    RungeKutta(const RectDomain<Dim>& aDomain):domain(aDomain){
        //write the butlar table HERE
    };

    virtual void getRHS(const Tensor<DType,Dim>& input, Tensor<DType,Dim>& rhs, Real t) = 0;

    void apply(Tensor<DType,Dim>& res, const Tensor<DType,Dim>& input, Real t0, Real k);
};
