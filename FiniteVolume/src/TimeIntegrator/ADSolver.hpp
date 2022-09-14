/**
 * @file ADSolver.hpp
 * @author Shuang Hu (22135017@zju.edu.cn)
 * @brief Store and solve the Advection-Diffusion equation.
 * @version 0.1
 * @date 2022-08-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "RungeKutta.hpp"
#include "Laplacian.hpp"
#include "ADadvection.hpp"
template<int Dim,BdryType BCType>
class ADSolver:public RungeKutta<Dim,Real>
{
private:
    VectorFunction<Dim+1,1>* f;
    VectorFunction<Dim+1,Dim>* u;
    VectorFunction<Dim,1>* init_value;
    VectorFunction<Dim+1,1>* bdry_value;
    Real nu;
    RectDomain<Dim> domain;
    FuncFiller<Dim> init_filler;
    GhostFiller<Dim,BCType> ghost_filler;
    Tensor<Real,Dim> res;
    Real t0;
    Real te;
    Real dt;
    Laplacian<Dim,Real> lap;
    AD_Advection<Dim> adv;
public:
    ADSolver(const RectDomain<Dim>& aDomain,int nGhost):domain(aDomain),lap(aDomain,nGhost),adv(aDomain,nGhost){};

    void set_param(VectorFunction<Dim+1,1>* force,VectorFunction<Dim+1,Dim>* vel,VectorFunction<Dim,1>* init,VectorFunction<Dim+1,1>* bdry,Real anu,Real init_time, Real final_time, Real dt);

    void apply(Tensor<Real,Dim>& input, Tensor<Real,Dim>& rhs, Real t);

    void solve();

    void draw();
};