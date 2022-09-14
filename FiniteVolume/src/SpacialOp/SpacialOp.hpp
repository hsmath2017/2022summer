/**
 * @file SpacialOp.h
 * @author Shuang Hu (22135017@zju.edu.cn)
 * @brief Spacial Operator virtual class
 * @version 0.1
 * @date 2022-08-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Tensor.h"
#include "FuncFiller.hpp"
#include "GhostFiller.hpp"
#include <vector>
template<int Dim,class T1,class T2>
class SpacialOp{
protected:
    RectDomain<Dim> domain;
    int nGhost;
public:
    SpacialOp(const RectDomain<Dim>& adomain,int numGhost):domain(adomain),nGhost(numGhost){};
    void getFaceAvg(const Tensor<T1,Dim>& origin, Tensor<T1,Dim>& res,
    int dim);
    virtual void apply(const Tensor<T1,Dim>& origin, Tensor<T2,Dim>& res) = 0;
};
/**
 * @brief Spacial Operator for DIM=2
 * 
 * @tparam T1 
 * @tparam T2 
 */
// template<class T1,class T2>
// class SpacialOp<2,T1,T2>{
// protected:
//     RectDomain<2> domain;
//     int nGhost;
// public:
//     SpacialOp(const RectDomain<2>& adomain,int numGhost):domain(adomain),nGhost(numGhost){};
//     void getFaceAvg(const Tensor<T1,2>& origin, Tensor<T1,2>& res,
//     int dim);
//     virtual void apply(const Tensor<T1,Dim>& origin, Tensor<T2,Dim>& res) = 0;
// };
template<int Dim,class T1,class T2>
void SpacialOp<Dim,T1,T2>::getFaceAvg(const Tensor<T1,Dim>& origin, Tensor<T1,Dim>& res,int dim){
    //convert: cell-centered to face-centered
    auto facedomain=domain.stagger(dim);
    const std::vector<Real> coe={-1.0/12,7.0/12,7.0/12,-1.0/12};
    const std::vector<int> coe_for_stagger={-2,-1,0,1}; 
    //Then: Fill the value of face average.
    res.resize(facedomain.getGhostedBox());
    if(Dim==2){
        loop_box_2(facedomain,i,j){
            Vec<int,2> nowpt{i,j};
            Vec<int,2> change=unit(dim);
            Real ans=0;
            for(int i=0;i<4;i++){
                Vec<int,2> newpt=nowpt+coe_for_stagger[i]*change;
                ans=ans+coe[i]*origin(newpt[0],newpt[1]);
            }
            res(i,j)=ans;
        }
    }
};