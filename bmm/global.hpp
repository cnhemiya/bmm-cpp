/// LICENSE  MulanPSL2
/// @author  cnhemiya@qq.com
/// @date    2022-02-06 16:00
///
/// @file bmm/global.hpp
/// @brief 全局设置

#ifndef _BMM_GLOBAL_HPP_
#define _BMM_GLOBAL_HPP_

#if __cplusplus < 201703L
#error "请更换支持 C++ 17 标准的 C++ 编译器。Please replace the C++ compiler that supports the C++ 17 standard"
#endif

#ifndef _BMM_NAMESPACE_BEGIN_
#define _BMM_NAMESPACE_BEGIN_ namespace bmm {
#endif

#ifndef _BMM_NAMESPACE_END_
#define _BMM_NAMESPACE_END_ }
#endif

#endif // _BMM_GLOBAL_HPP_