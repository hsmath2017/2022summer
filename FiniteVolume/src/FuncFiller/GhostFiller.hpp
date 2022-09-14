/**
 * @file GhostFiller.hpp
 * @author Shuang Hu (22135017@zju.edu.cn)
 * @brief Fill the Ghost Cells of each node.
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "VectorFunction.hpp"
#include "numlib.h"
#include "Tensor.h"
#include "TensorExpr.h"
#include "RectDomain.h"
#include <vector>
/**
 * @brief Boundary-Condition Types.
 * 
 */
enum BdryType{ Dirichlet = 0, Neumann = 1, Periodic = 2};
/**
 * @brief Fill the Ghost Cells.
 * 
 * @tparam Dim: Dimension of problem domain.
 * @tparam BCType: Boundary Condition Type.
 * @tparam T: The datatype of elements.
 */
template<BdryType BCType,class T,int Dim>
class GhostFiller;
/**
 * @brief specializer
 * 编者注：实在不是什么光彩的处理方案...
 * @tparam BCType Boundary Condition Type
 * @tparam T 
 */
template<BdryType BCType,class T>
class GhostFiller<BCType,T,2>{
public:
    using rVec=Vec<Real,2>;
private:
    RectDomain<2> domain;
    std::vector<Tensor<T,1>> bdryCond;//bdryCond[0]:up,bdryCond[1]:left,bdryCond[2]:down,bdryCond[3]:right
    //orientation:down-up left-right.
    int nGhost;
    template<int Dim2>
    Vec<Real,Dim2> FaceAverage(const rVec& lo, const rVec& hi, Real t0,
    const VectorFunction<3,Dim2>* func) const{
        Vec<Real,Dim2> ans;
        for(int i=0;i<Dim2;i++){
            if(lo[0]==hi[0]){
                assert(lo[1]!=hi[1]);
                auto f=[func,t0,lo[0]](Real y){
                    return func->operator()(lo[0],y,t0);
                };
                ans[i]=quad<3>(f,lo[1],hi[1]);
                ans[i]=ans[i]/(hi[1]-lo[1]);
            }else if(lo[1]==hi[1]){
                auto f=[func,t0,lo[1]](Real x){
                    return func->operator()(x,lo[1],t0);
                };
                ans[i]=quad<3>(f,lo[0],hi[0]);
                ans[i]=ans[i]/(hi[0]-lo[0]);
            }else{
                std::cerr<<"Not a straight edge!"<<std::endl;
                abort();
            }
        }
        return ans;
    }
public:
    GhostFiller(const RectDomain<Dim>& aDomain, int numGhost):domain(aDomain),nGhost(numGhost)
    {
        //initialize variable: bdryCond
        auto lo=domain.lo();
        auto hi=domain.hi();
        bdryCond.resize(4);
        bdryCond[0].resize(Box<1>{lo[0],hi[0]});
        bdryCond[2].resize(Box<1>{lo[0],hi[0]});
        bdryCond[1].resize(Box<1>{lo[1],hi[1]});
        bdryCond[3].resize(Box<1>{lo[1],hi[1]});
    };
    template<int Dim2>
    void fillBdry(const VectorFunction<3,Dim2>* func, Real t0);
    void fillGhost(Tensor<T,2>& res) const;    
};
template<BdryType BCType,class T>
template<int Dim2>
void GhostFiller<BCType,T,2>::fillBdry(const VectorFunction<3,Dim2>* func, Real t0){
    //step0: the information of problem domain
    auto dx=domain.spacing();
    auto lo=domain.lo();
    auto hi=domain.hi();
    //step1: fill each sides.
    for(int i=0;i<3;i++){
        Box<1> bx=bdryCond[i].box();
        loop_box_1(bx,j){
            Vec<Real,2> alo;
            Vec<Real,2> ahi;
            switch (i)
            {
            case 0:
                Real y=dx[1]*(hi[1]+1);
                ahi[1]=alo[1]=y;
                alo[0]=dx[0]*j;
                ahi[0]=dx[0]*(j+1);
                bdryCond[i](j)=FaceAverage(alo,ahi,t0,func);
                break;
            case 1:
                Real x=dx[0]*lo[0];
                alo[0]=ahi[0]=x;
                alo[1]=dx[1]*j;
                ahi[1]=dx[1]*(j+1);
                bdryCond[i](j)=FaceAverage(alo,ahi,t0,func);
                break;
            case 2:
                Real y=dx[1]*lo[1];
                alo[1]=ahi[1]=y;
                alo[0]=dx[0]*j;
                ahi[0]=dx[0]*(j+1);
                bdryCond[i](j)=FaceAverage(alo,ahi,t0,func);
                break;
            case 3:
                Real x=dx[0]*(hi[0]+1);
                alo[0]=ahi[0]=x;
                alo[1]=dx[1]*j;
                ahi[1]=dx[1]*(j+1);
                bdryCond[i](j)=FaceAverage(alo,ahi,t0,func);
                break;
            }
        }
    }
}
template<BdryType BCType,class T>
void GhostFiller<BCType,T,2>::fillGhost(Tensor<T,2>& res) const{
    auto bx=res.box();
    auto lo=domain.lo();
    auto hi=domain.hi();
    assert(bx==domain.getGhostedBox());
    std::vector<Real> coe_for_one;//coefficient for <\phi>_{i+e^{d}}
    std::vector<Real> coe_for_two;//coefficient for <\phi>_{i+2e^{d}}
    if(BCType==Periodic){
        for(int i=0;i<4;i++){
            Tensor<T,1> bdry=bdryCond[i];
            loop_box_1(bdry,j){
                switch(i)
                {
                case 0:
                    res(j,hi[1]+1)=res(j,lo[1]);
                    res(j,hi[1]+2)=res(j,lo[1]+1);
                    break;
                case 1:
                    res(lo[0]-1,j)=res(hi[0],j);
                    res(lo[0]-2,j)=res(hi[0]-1,j);
                    break;
                case 2:
                    res(j,lo[1]-1)=res(j,hi[1]);
                    res(j,lo[1]-2)=res(j,hi[1]-1);
                    break;
                case 3:
                    res(hi[0]+1,j)=res(lo[0],j);
                    res(hi[0]+2,j)=res(lo[0]+1,j);
                    break;
                }
            }
        }
        return;
    }
    else if(BCType==Dirichlet){
        coe_for_one={-13.0/3,3.0/3,-1.0/3,4};
        coe_for_two={-70.0/3,32.0/3,-7.0/3,16};
    }else if(BCType==Neumann){
        coe_for_one={0.5,0.9,-0.5,0.1,1.2*domain.spacing[0]};
        coe_for_two={-7.5,14.5,-7.5,1.5,6*domain.spacing[1]};
    }
    for(int i=0;i<4;i++){
        Tensor<T,1> bdry=bdryCond[i];
        auto bdryBox=bdry.box();
        loop_box_1(bdryBox,j){
            Real ans1=0;
            Real ans2=0;
            int n=coe_for_one.size();
            switch (i)
            {
            case 0:
                for(int k=0;k<n-1;k++){
                    ans1=ans1+coe_for_one[k]*res(j,hi[1]-k);
                    ans2=ans2+coe_for_two[k]*res(j,hi[1]-k);        
                }
                ans1+=coe_for_one[n-1]*bdry(j);
                ans2+=coe_for_two[n-1]*bdry(j);
                res(j,hi[1]+1)=ans1;
                res(j,hi[1]+2)=ans2;
                break;
            case 1:
                for(int k=0;k<n-1;k++){
                    ans1+=coe_for_one[k]*res(lo[0]+k,j);
                    ans2+=coe_for_two[k]*res(lo[0]+k,j);
                }
                ans1+=coe_for_one[n-1]*bdry(j);
                ans2+=coe_for_two[n-1]*bdry(j);
                res(lo[0]-1,j)=ans1;
                res(lo[0]-2,j)=ans2;
                break;
            case 2:
                for(int k=0;k<n-1;k++){
                    ans1+=coe_for_one[k]*res(j,lo[1]+k);
                    ans2+=coe_for_two[k]*res(j,lo[1]+k);
                }
                ans1+=coe_for_one[n-1]*bdry(j);
                ans2+=coe_for_two[n-1]*bdry(j);
                res(j,lo[1]-1)=ans1;
                res(j,lo[1]-2)=ans2;
                break;
            case 3:
                for(int k=0;k<n-1;k++){
                    ans1+=coe_for_one[k]*res(hi[0]-k,j);
                    ans2+=coe_for_two[k]*res(hi[0]-k,j);
                }
                ans1+=coe_for_one[n-1]*bdry(j);
                ans2+=coe_for_two[n-1]*bdry(j);
                res(hi[0]+1,j)=ans1;
                res(hi[0]+2,j)=ans2;
                break;
            }
        }
        return;
    }
}