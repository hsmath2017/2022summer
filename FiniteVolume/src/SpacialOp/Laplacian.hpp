/**
 * @file Laplacian.hpp
 * @author Shuang Hu (22135017@zju.edu.cn)
 * @brief Laplacian operator
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "SpacialOp.hpp"
template<int Dim,class T>
class Laplacian:public SpacialOp<Dim,T,T>{
public:
    Laplacian(const RectDomain<Dim>& aDomain, int numGhost):SpacialOp<Dim,T,T>(aDomain,numGhost){};
    void apply(const Tensor<T,Dim>& origin, Tensor<T,Dim>& res){
        auto dx=this->domain.spacing();
        res.resize(origin.box());
        auto bx=origin.box();
        if(Dim==2){
            std::vector<Real> coe=1.0/(12*dx[0]*dx[0])*{-1,16,-30,16,-1};
            std::vector<int> coe_for_change={-2,-1,0,1,2};
            loop_box_2(bx,i,j){
                Real ans=0;
                Vec<int,2> origin{i,j};
                for(int i=0;i<Dim;i++){
                    Vec<int,2> change=unit(i);
                    for(int i=0;i<coe.size();i++){
                        auto newpt=origin+coe_for_change[i]*change;
                        ans=ans+coe[i]*origin(newpt[0],newpt[1]);
                    }
                }
                res(i,j)=ans;   
            }
        }
    }
};
