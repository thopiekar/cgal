// Copyright (c) 2018  GeometryFactory (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org).
// You can redistribute it and/or modify it under the terms of the GNU
// General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
// SPDX-License-Identifier: GPL-3.0+
//
//
// Author(s)     : Maxime Gimeno

#ifndef CGAL_VERTEX_TO_POINT_TRAITS_ADAPTER_3_H
#define CGAL_VERTEX_TO_POINT_TRAITS_ADAPTER_3_H
#include <boost/call_traits.hpp>
#include <CGAL/property_map.h>
#include <CGAL/tags.h>
#include <CGAL/representation_tags.h>
#include <CGAL/Kernel_traits.h>

#include <CGAL/convex_hull_3.h>
#include <CGAL/result_of.h>



namespace CGAL {

namespace Convex_hull_impl{
template <class F, class VertexPointMap>
struct Forward_functor
  : public F
{
  VertexPointMap vpm_;
  
  Forward_functor(const VertexPointMap& vpm,
                  const F& f) : F(f), vpm_(vpm) {}
  
  
  template <class Vertex>
  typename cpp11::result_of<F(const Vertex&, const Vertex&)>::type
  operator() (const Vertex& p, const Vertex& q) const
  {
    return static_cast<const F*>(this)->operator()(get(vpm_,p),get(vpm_,q));
  }

  template <class Vertex>
  typename cpp11::result_of<F(const Vertex&, const Vertex&, const Vertex&)>::type
  operator() (const Vertex& p, const Vertex& q, const Vertex& r) const
  {
    return static_cast<const F*>(this)->operator()(
          get(vpm_,p),
          get(vpm_,q),
          get(vpm_,r));
  }

  template <class Vertex>
  typename cpp11::result_of<F(const Vertex&, const Vertex&, const Vertex&, const Vertex&)>::type
  operator() (const Vertex& p, const Vertex& q, const Vertex& r, const Vertex& s) const
  {
    return static_cast<const F*>(this)->operator()(
          get(vpm_,p), 
          get(vpm_,q),
          get(vpm_,r), 
          get(vpm_,s));
  }
};
}//end Convex_hull_impl
template<class Base_traits,class VertexPointMap>
class Vertex_to_point_traits_adapter
    :public Base_traits
{
  VertexPointMap vpm_;
  
  
public:
  Vertex_to_point_traits_adapter(const VertexPointMap& vpmap, Base_traits base=Base_traits())
    :Base_traits(base), vpm_(vpmap)
  {}
  typedef typename boost::property_traits<VertexPointMap>::key_type Vertex;
  typedef Vertex Point_3;
  typedef Convex_hull_impl::Forward_functor<typename Base_traits::Equal_3, VertexPointMap> Equal_3;
  typedef Convex_hull_impl::Forward_functor<typename Base_traits::Collinear_3, VertexPointMap> Collinear_3;
  typedef Convex_hull_impl::Forward_functor<typename Base_traits::Coplanar_3, VertexPointMap> Coplanar_3;
  typedef Convex_hull_impl::Forward_functor<typename Base_traits::Less_distance_to_point_3, VertexPointMap> Less_distance_to_point_3; 
  
  class Less_signed_distance_to_plane_3
      :public Base_traits::Less_signed_distance_to_plane_3
  {  
    VertexPointMap vpm_;
    const typename Base_traits::Less_signed_distance_to_plane_3& base;
  public:
    typedef typename Base_traits::Plane_3 Plane_3;
    
    typedef bool             result_type;
    
    Less_signed_distance_to_plane_3(
        const VertexPointMap& map,
        const typename Base_traits::Less_signed_distance_to_plane_3& base):
      Base_traits::Less_signed_distance_to_plane_3(base),vpm_(map), base(base){}
    
    bool
    operator()( const Plane_3& h, const Vertex& p, const Vertex& q) const
    {
      return base(h, get(vpm_,p), get(vpm_,q));
    }
  };
  
  class Compare_x_3:public Base_traits::Compare_x_3
  {
    VertexPointMap vpm_;
    const typename Base_traits::Compare_x_3& base;
  public:    
    typedef CGAL::Comparison_result         result_type;
    
    Compare_x_3(
        const VertexPointMap& map,
        const typename Base_traits::Compare_x_3& base):
      Base_traits::Compare_x_3(base),vpm_(map), base(base){}
    
    result_type
    operator()( const Point_3& p, const Point_3& q) const
    {
      return base( get(vpm_,p), get(vpm_,q));
    }
  };
  
  class Compare_y_3:public Base_traits::Compare_y_3
  {
    VertexPointMap vpm_;
    const typename Base_traits::Compare_y_3& base;
  public:    
    typedef CGAL::Comparison_result         result_type;
    
    Compare_y_3(
        const VertexPointMap& map,
        const typename Base_traits::Compare_y_3& base):
      Base_traits::Compare_y_3(base),vpm_(map), base(base){}
    
    result_type
    operator()( const Point_3& p, const Point_3& q) const
    {
      return base( get(vpm_,p), get(vpm_,q));
    }
  };
  
  class Compare_z_3:public Base_traits::Compare_z_3
  {
    VertexPointMap vpm_;
    const typename Base_traits::Compare_z_3& base;
  public:    
    typedef CGAL::Comparison_result         result_type;
    
    Compare_z_3(
        const VertexPointMap& map,
        const typename Base_traits::Compare_z_3& base):
      Base_traits::Compare_z_3(base),vpm_(map), base(base){}
    
    result_type
    operator()( const Point_3& p, const Point_3& q) const
    {
      return base( get(vpm_,p), get(vpm_,q));
    }
  };
  
  Compare_x_3 compare_x_3_object () const {return Compare_x_3(vpm_, static_cast<const Base_traits*>(this)->compare_x_3_object() );}
  Compare_y_3 compare_y_3_object () const {return Compare_y_3(vpm_, static_cast<const Base_traits*>(this)->compare_y_3_object() );}
  Compare_z_3 compare_z_3_object () const {return Compare_z_3(vpm_, static_cast<const Base_traits*>(this)->compare_z_3_object() );}
  Equal_3 equal_3_object () const {return Equal_3(vpm_,static_cast<const Base_traits*>(this)->equal_3_object() );}
  Collinear_3 collinear_3_object () const {return Collinear_3(vpm_,static_cast<const Base_traits*>(this)->collinear_3_object() );}
  Coplanar_3 coplanar_3_object () const {return Coplanar_3(vpm_,static_cast<const Base_traits*>(this)->coplanar_3_object() );}
  Less_distance_to_point_3 less_distance_to_point_3_object() const {
    return Less_distance_to_point_3(vpm_,static_cast<const Base_traits*>(this)->less_distance_to_point_3_object() );}
  Less_signed_distance_to_plane_3 less_signed_distance_to_plane_3_object() const {
    return Less_signed_distance_to_plane_3(
          vpm_,static_cast<const Base_traits*>(this)->less_signed_distance_to_plane_3_object() );
  }
  
  class Construct_plane_3:public Base_traits::Construct_plane_3
  {  
    VertexPointMap vpm_;
    const typename Base_traits::Construct_plane_3& base;
  public:
    Construct_plane_3(const VertexPointMap& map, const typename Base_traits::Construct_plane_3& base):
      Base_traits::Construct_plane_3(base),vpm_(map), base(base){}
    typename Base_traits::Plane_3 operator()(const Point_3& p, const Point_3& q, const Point_3& r)const 
    {
      return base(get(vpm_,p),get(vpm_,q),get(vpm_,r));
    }
  };
  Construct_plane_3 construct_plane_3_object() const
  {return Construct_plane_3(vpm_,static_cast<const Base_traits*>(this)->construct_plane_3_object());}
  
  class Has_on_positive_side_3:public Base_traits::Has_on_positive_side_3
  {  
    VertexPointMap vpm_;
    const typename Base_traits::Has_on_positive_side_3& base;
  public:
    Has_on_positive_side_3(const VertexPointMap& map,const typename Base_traits::Has_on_positive_side_3& base):
      Base_traits::Has_on_positive_side_3(base),vpm_(map), base(base){}
    
    typedef typename Base_traits::Plane_3          Plane_3;
  public:
    typedef bool          result_type;
    
    result_type
    operator()( const Plane_3& pl, const Point_3& p) const
    { 
      return base(pl, get(vpm_, p));
    }
  };
  Has_on_positive_side_3 has_on_positive_side_3_object() const {return Has_on_positive_side_3(
          vpm_,static_cast<const Base_traits*>(this)->has_on_positive_side_3_object() );}
  
  template<class Base_proj_traits>
  class Proj_traits_3:public Base_proj_traits
  {
    VertexPointMap vpm_;
    typedef Base_proj_traits Btt;
  public:
    Proj_traits_3(const VertexPointMap& map,const Btt& base):
      Base_proj_traits(base),vpm_(map){}
    typedef Point_3 Point_2;
    typedef Convex_hull_impl::Forward_functor<typename Btt::Equal_2, VertexPointMap> Equal_2;
    typedef Convex_hull_impl::Forward_functor<typename Btt::Less_xy_2, VertexPointMap> Less_xy_2;
    typedef Convex_hull_impl::Forward_functor<typename Btt::Less_yx_2, VertexPointMap> Less_yx_2;
    typedef Convex_hull_impl::Forward_functor<typename Btt::Less_signed_distance_to_line_2, VertexPointMap> Less_signed_distance_to_line_2;
    typedef Convex_hull_impl::Forward_functor<typename Btt::Left_turn_2, VertexPointMap> Left_turn_2;
    
    class Less_rotate_ccw_2:public Btt::Less_rotate_ccw_2
    {
      VertexPointMap vpm_;
      const typename Btt::Less_rotate_ccw_2& base;
    public:
      Less_rotate_ccw_2(const VertexPointMap& map,const typename Btt::Less_rotate_ccw_2& base):
        Btt::Less_rotate_ccw_2(base),vpm_(map), base(base){}
    public:      
      bool operator()(Point_2 e, Point_2 p,Point_2 q) const
      { 
        return base(get(vpm_, e), get(vpm_, p), get(vpm_, q));
      }
    };
    
    Equal_2 equal_2_object () const {return Equal_2(vpm_,static_cast<const Btt*>(this)->equal_2_object() );}
    Less_xy_2 less_xy_2_object ()const{return Less_xy_2(vpm_,static_cast<const Btt*>(this)->less_xy_2_object() );}
    Less_yx_2 less_yx_2_object ()const{return Less_yx_2(vpm_,static_cast<const Btt*>(this)->less_yx_2_object() );}
    Less_signed_distance_to_line_2 less_signed_distance_to_line_2_object ()const
    {return Less_signed_distance_to_line_2(vpm_,static_cast<const Btt*>(this)->Less_signed_distance_to_line_2() );}
    Less_rotate_ccw_2 less_rotate_ccw_2_object ()const
    {return Less_rotate_ccw_2(vpm_,static_cast<const Btt*>(this)->less_rotate_ccw_2_object() );}
    Left_turn_2 left_turn_2_object ()const{return Left_turn_2(vpm_,static_cast<const Btt*>(this)->left_turn_2_object() );}
    
    class Orientation_2:public Btt::Orientation_2
    {
      VertexPointMap vpm_;                                                           
      const typename Btt::Orientation_2& base;                                   
    public:                                                                          
      Orientation_2(const VertexPointMap& map,const typename Btt::Orientation_2& base):
        Btt::Orientation_2(base),vpm_(map), base(base){}                         
      
      typename CGAL::Orientation operator()(Point_2 e,Point_2 p, Point_2 q) const                                    
      {                                                                              
        return base(get(vpm_, e), get(vpm_, p), get(vpm_, q));                                     
      }
    };
    Orientation_2 orientation_2_object ()const{return Orientation_2(vpm_,static_cast<const Btt*>(this)->orientation_2_object() );}
  };
  
  typedef Proj_traits_3<typename Base_traits::Traits_xy_3> Traits_xy_3;
  typedef Proj_traits_3<typename Base_traits::Traits_yz_3> Traits_yz_3;
  typedef Proj_traits_3<typename Base_traits::Traits_xz_3> Traits_xz_3;
  
  Traits_xy_3 construct_traits_xy_3_object()const
  {return Traits_xy_3(vpm_, static_cast<const Base_traits*>(this)->construct_traits_xy_3_object());}
  Traits_yz_3 construct_traits_yz_3_object()const
  {return Traits_yz_3(vpm_, static_cast<const Base_traits*>(this)->construct_traits_yz_3_object());}
  Traits_xz_3 construct_traits_xz_3_object()const
  {return Traits_xz_3(vpm_, static_cast<const Base_traits*>(this)->construct_traits_xz_3_object());}

  typename boost::property_traits<VertexPointMap>::reference
  get_point(const typename boost::property_traits<VertexPointMap>::key_type& k) const
  {
    return get(vpm_, k);
  }

};
}//end CGAL

#endif // CGAL_VERTEX_TO_POINT_TRAITS_ADAPTER_3_H
