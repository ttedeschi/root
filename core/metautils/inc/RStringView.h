// -*- C++ -*-
// Author: Philippe Canal, March 2015

/*************************************************************************
 * Copyright (C) 1995-2000, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef RStringView_H
#define RStringView_H

#if defined(__has_include)

#if !defined(__clang__) && defined(__GNUC__) && __cplusplus > 201103L
// Don't check with GCC and less than C++14
#else
#define R__CHECK_FOR_STRING_VIEW
#endif

#endif

#ifdef R__CHECK_FOR_STRING_VIEW
#if __has_include("string_view")

#define R_HAS_std_string_view_header

#elif __has_include("experimental/string_view")

#define R_HAS_lib_std_experimental_string_view

#endif
#endif // R__CHECK_FOR_STRING_VIEW

#ifdef R_HAS_std_string_view_header
#include <string_view>
#elif defined(R_HAS_lib_std_experimental_string_view)
#define R_HAS_std_experimental_string_view
#include <experimental/string_view>
#else
#include "RWrap_libcpp_string_view.h"
#endif

#if defined( R_HAS_std_experimental_string_view )

namespace std {

   template<class _CharT, class _Traits = std::char_traits<_CharT> >
   using basic_string_view = ::std::experimental::basic_string_view<_CharT,_Traits>;

   // basic_string_view typedef names
   typedef basic_string_view<char> string_view;
   typedef basic_string_view<char16_t> u16string_view;
   typedef basic_string_view<char32_t> u32string_view;
   typedef basic_string_view<wchar_t> wstring_view;

//   template<class _CharT, class _Traits = std::char_traits<_CharT> >
//   basic_string_view<_CharT,_Traits>
//   &operator=(basic_string_view<_CharT,_Traits> &lhs, const TString &rsh) {
//      *lhs = basic_string_view<_CharT,_Traits>(rsh);
//      return *lhs;
//   }
}

#endif // R_HAS_std_experimental_string_view

#endif // RStringView_H
