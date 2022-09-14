/**
 * @file Gradient.hpp
 * @author Shuang Hu (22135017@zju.edu.cn)
 * @brief Gradient Operator
 * @version 0.1
 * @date 2022-08-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "SpacialOp.hpp"
template<int Dim>
class Gradient:public SpatialOp<Dim,Real,Vec<Real,Dim>>{
public:
    Gradient(const RectDomain<Dim>& adomain,int numGhost):SpacialOp<Dim,Real,Vec<Real,Dim>>(adomain,numGhost){};
    void apply(const Tensor<Real,Dim>& origin, Tensor<Vec<Real,Dim>,Dim>& res){
        auto dx=this->domain.spacing();
        Real h=dx[0];
        const std::vector<Real> coefficient=1.0/(12*h)*{-1.0,8.0,-8.0,1.0};
        const std::vector<int> move={2,1,-1,-2};
        res.resize(this->domain.getGhostedBox());
        if(Dim==2){
            for(int k=0;k<Dim;k++){
                Real ans=0;
                Vec<int,2> e=unit(k);
                loop_box_2(this->domain,i,j){
                    for(int l=0;l<coefficient.size();l++){
                        Vec<int,2> tmp={i,j}+move[l]*e;
                        ans=ans+coefficient[l]*origin(tmp[0],tmp[1]);
                    }
                }
                res(i,j)[k]=ans;
            }
        }
    }
};