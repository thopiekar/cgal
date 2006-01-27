#ifndef CGAL_POLYNOMIAL_INTERNAL_WRAPPED_DOUBLE_H
#define CGAL_POLYNOMIAL_INTERNAL_WRAPPED_DOUBLE_H
#include <CGAL/Polynomial/basic.h>

CGAL_POLYNOMIAL_BEGIN_INTERNAL_NAMESPACE

 template <bool S, bool Q>
  struct Double_with_infinity_default {
    static double value(){return std::numeric_limits<double>::max();};
  };
  template<bool O>
  struct Double_with_infinity_default<true,O> {
    static double value(){return std::numeric_limits<double>::signaling_NaN();};
  };
  template<>
  struct Double_with_infinity_default<false,true> {
    static double value(){return std::numeric_limits<double>::quiet_NaN();};
  };

struct Double_with_infinity {
  static double get_default() {
    return Double_with_infinity_default<std::numeric_limits<double>::has_signaling_NaN,
      std::numeric_limits<double>::has_quiet_NaN>::value();
      
  }
  
  Double_with_infinity(): d_(get_default()){}
  Double_with_infinity(double d): d_(d){}
  operator const double&() const {
    return d_;
  }
protected:
  double d_;
};

CGAL_POLYNOMIAL_END_INTERNAL_NAMESPACE

namespace std {
  template <>
  struct numeric_limits<CGAL_POLYNOMIAL_NS::internal::Double_with_infinity >: public numeric_limits<double>
  {
    static const bool is_specialized = true;
    static const bool has_infinity=true;
    static double infinity() throw() {return std::numeric_limits<double>::max();}
  };
};


CGAL_BEGIN_NAMESPACE

double to_double(CGAL_POLYNOMIAL_NS::internal::Double_with_infinity d) {
  return to_double(static_cast<double>(d));
}

CGAL_END_NAMESPACE
  
#endif
