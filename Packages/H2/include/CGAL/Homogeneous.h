// ======================================================================
//
// Copyright (c) 1999 The CGAL Consortium
//
// This software and related documentation is part of an INTERNAL release
// of the Computational Geometry Algorithms Library (CGAL). It is not
// intended for general use.
//
// ----------------------------------------------------------------------
// 
// release       : 
// release_date  : 
// 
// file          : Homogeneous.h
// package       : Kernel_basic
// revision      : $Revision$
// revision_date : $Date$
// author(s)     : Stefan Schirra
//
// coordinator   : MPI, Saarbruecken
// ======================================================================
 
#ifndef CGAL_HOMOGENEOUS_H
#define CGAL_HOMOGENEOUS_H

#include <CGAL/Homogeneous/Homogeneous_base.h>
#include <CGAL/Handle_for.h>
#include <CGAL/Kernel/Type_equality_wrapper.h>
#include <CGAL/Quotient.h>

CGAL_BEGIN_NAMESPACE

template < typename RT_, typename FT_, typename Kernel >
struct Homogeneous_base_ref_count
  : public Homogeneous_base< Kernel >
{
    typedef RT_                                           RT;
    typedef FT_                                           FT;

    // The mecanism that allows to specify reference-counting or not.
    template < typename T >
    struct Handle { typedef Handle_for<T>    type; };

    template < typename Kernel2 >
    struct Base {
        typedef Homogeneous_base_ref_count<RT_,FT_,Kernel2> Type;
    };

    // TODO: cleanup (use Rational_traits<> instead)
    static FT make_FT(const RT & num, const RT& denom)
    { return FT(num, denom); }

    static FT make_FT(const RT & num)
    { return FT(num); }

    static RT FT_numerator(const FT &r)
    { return r.numerator(); }

    static RT FT_denominator(const FT &r)
    { return r.denominator(); }
};

template < typename RT_, typename FT_ = Quotient<RT_> >
struct Homogeneous
  : public Type_equality_wrapper<
                Homogeneous_base_ref_count<RT_, FT_, Homogeneous<RT_, FT_> >,
                Homogeneous<RT_, FT_> >
{};

CGAL_END_NAMESPACE

CGAL_ITERATOR_TRAITS_POINTER_SPEC_TEMPLATE(CGAL::Homogeneous)

#endif // CGAL_HOMOGENEOUS_H
