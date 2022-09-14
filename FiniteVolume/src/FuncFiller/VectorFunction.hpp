/**
 * @file VectorFunction.hpp
 * @author Shuang Hu (22135017@zju.edu.cn)
 * @brief Functional,store the vector functions by an abstract class
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Core/Vec.h"
/**
 * @brief class for a vector function \mathbf{R}^{Dim1}\rightarrow\mathbf{R}^{Dim2}
 * 
 * @tparam Dim1 
 * @tparam Dim2 
 */
template<int Dim1,int Dim2>
class VectorFunction{
public:
    VectorFunction()=default;
    virtual const Vec<Real,Dim2> operator()(const Vec<Real,Dim1>& pt) const = 0;
};
