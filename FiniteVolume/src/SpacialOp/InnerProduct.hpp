/**
 * @file InnerProduct.hpp
 * @author Shuang Hu (22135017@zju.edu.cn)
 * @brief InnerProduct Operator on the boundary of the rectangle domain.
 * @version 0.1
 * @date 2022-08-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "SpacialOp.hpp"
template<int Dim>
class InnerProduct:public SpacialOp<Dim,Real,Real>{
private:
    int dim;
    Tensor<Real,Dim> phi;// The function apply is made to calculate <\phi,\delta>.
public:
    InnerProduct(const RectDomain<Dim>& aDomain, int numGhost,const Tensor<Real,Dim>& aphi, int adim):SpacialOp<Dim,Real,Real>(aDomain,numGhost),phi(aphi),dim(adim){};
    void apply(const Tensor<Real,Dim>& origin, Tensor<Real,Dim>& res){
        RectDomain<Dim> faceDomain=this->domain.stagger(dim);
        assert(origin.box()==faceDomain.getGhostedBox());
        res.resize(faceDomain.getGhostedBox());
        Vec<Real,Dim> dx=this->domain.spacing();
        if(Dim==2){
            Real h=dx[0];
            loop_box_2(faceDomain,i,j){
                Real ans=origin(i,j)*phi(i,j);
                int codim=1-dim;
                Vec<int,2> e=unit(codim);
                Vec<int,2> upside={i,j}+e;
                Vec<int,2> downside={i,j}-e;
                ans=ans+(1.0/48)*(phi(upside[0],upside[1])-phi(downside[0],downside[1]))*(origin(upside[0],upside[1])-origin(downside[0],downside[1]));
                res(i,j)=ans;
            }
        }
    };
};