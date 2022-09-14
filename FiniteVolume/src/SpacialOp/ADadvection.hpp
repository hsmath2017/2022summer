/**
 * @file ADadvection.hpp
 * @author Shuang Hu (22135017@zju.edu.cn)
 * @brief Advection operator for Advection operator on Advection-Diffusion problem
 * @version 0.1
 * @date 2022-08-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "SpacialOp.hpp"
#include "InnerProduct.hpp"
template<int Dim>
class AD_Advection:public SpacialOp<Dim,Real,Real>
{
public:
    using rVec=Vec<Real,Dim>;
private:
    Tensor<rVec,Dim> u;
public:
    AD_Advection(const RectDomain<Dim>& aDomain, int numGhost):SpacialOp<Dim,Real,Real>(aDomain,numGhost){
    };
    void setvel(const Tensor<rVec,Dim>& vel){
        u.resize(vel.box());
        auto bx=vel.box();
        loop_box_2(bx,i,j){
            u(i,j)=vel(i,j);
        }
    }
    void apply(const Tensor<Real,Dim>& origin, Tensor<Real,Dim>& res);
};
template<int Dim>
void AD_Advection<Dim>::apply(const Tensor<Real,Dim>& origin, Tensor<Real,Dim>& res){
    res.clear();
    assert(res.box()==origin.box());
    for(int d=0;d<Dim;d++){
        Tensor<Real,Dim> ud;
        auto bx=u.box();
        assert(bx==origin.box());
        loop_box_2(bx,i,j){
            ud(i,j)=u(i,j)[d];
        }
        InnerProduct<Dim> IP(this->domain,this->nGhost,ud,d);
        Tensor<Real,Dim> ans;
        IP.apply(origin,ans);
        loop_box_2(res.box(),i,j){
            Vec<int,2> e=unit(d);
            Vec<int,2> O{i,j};
            Vec<int,2> tmp1=O+e;
            Vec<int,2> tmp2=O;
            res(i,j)=res(i,j)+(ans(tmp1)-ans(tmp2));
        }
    }
    Vec<Real,Dim> dx=this->domain.spacing();
    res=(-1.0/dx[0])*res;
}