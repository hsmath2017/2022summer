/**
 * @file FuncFiller.hpp
 * @author Shuang Hu (22135017@zju.edu.cn)
 * @brief Fill the discrete mesh with integral average.
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "VectorFunction.hpp"
#include "Tensor.h"
#include "TensorExpr.h"
#include "RectDomain.h"
#include "numlib.h"
/**
 * @brief Fill the discrete mesh.
 * 
 * @tparam Dim 
 */
template<int Dim>
class FuncFiller{
public:
    using rVec=Vec<Real,Dim>;
    using iVec=Vec<int,Dim>;
private:
    RectDomain<Dim> domain;
    //quadrature, by 4th-order Gaussian integration rule.
    template<int Dim2>
    Vec<Real,Dim2> Quadrature(const rVec& lo,const rVec& hi,const VectorFunction<Dim,Dim2>* func) const{
        Vec<Real,Dim2> res;
        for(int i=0;i<Dim2;i++){
            auto funcslice=[func,i](const rVec& pt){
                return func->operator()(pt)[i];
            };
            res[i]=quad<3>(funcslice,lo,hi);
        }
        return res;
    };
public:
    FuncFiller(const RectDomain& adomain):domain(adomain){};
    template<int Dim2>
    //fill the cells via quadrature rule.
    void fill( Tensor<Vec<Real,Dim2>,Dim>& target, const VectorFunction<Dim,Dim2>* func) const;
};
template<>
template<int Dim2>
void FuncFiller<2>::fill( Tensor<Vec<Real,Dim2>,2>& target, const VectorFunction<2,Dim2>* func) const{
    assert(domain.getCentering()==CellCentered);
    assert(target.box()==domain.getGhostedBox());
    auto dx=domain.spacing();
    loop_box_2(domain,i,j){
        rVec lo=dx*iVec{i,j};
        rVec hi=dx*iVec{i+1,j+1};
        target(i,j)=Quadrature(lo,hi,func);
        target(i,j)/=prod(dx); 
    }
}