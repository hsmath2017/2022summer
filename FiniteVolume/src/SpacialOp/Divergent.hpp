/**
 * @file Divergent.hpp
 * @author Shuang Hu (22135017@zju.edu.cn)
 * @brief Divergent operator
 * @version 0.1
 * @date 2022-08-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "SpacialOp.hpp"
template<int Dim>
class Divergent:public SpacialOp<Dim,Vec<Real,Dim>,Real>{
public:
    void apply(const Tensor<Vec<Real,Dim>,Dim>& origin, Tensor<Real,Dim>& res){
        auto dx=this->domain.spacing();
        Real h=dx[0];
        std::vector<Real> coefficient=1.0/(12*h)*{-1.0,8.0,-8.0,1.0};
        std::vector<int> move={2,1,-1,-2};
        res.resize(this->domain.getGhostedBox());
        if(Dim==2){
            loop_box_2(this->domain,i,j){
                Real ans=0;
                for(int k=0;k<Dim;k++){
                    Vec<int,2> e=unit(k);
                    for(int l=0;l<move.size();l++){
                        Vec<int,2> tmp={i,j}+move[l]*e;
                        ans=ans+coefficient[l]*origin(tmp[0],tmp[1])[k];
                    }
                }
                res(i,j)=ans;
            }
        }
    }
};