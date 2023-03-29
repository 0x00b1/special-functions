#ifndef SPECIAL_FUNCTIONS_COMPLETE_CARLSON_ELLIPTIC_R_G_H
#define SPECIAL_FUNCTIONS_COMPLETE_CARLSON_ELLIPTIC_R_G_H

#include <special_functions/detail/complete_carlson_elliptic_r_g.h>

namespace special_functions {
    template<typename _Tx, typename _Ty>
    inline special_functions::fp_promote_t<_Tx, _Ty>
    complete_carlson_elliptic_r_g(_Tx x, _Ty y)
    {
        using type = special_functions::fp_promote_t<_Tx, _Ty>;
        return special_functions::detail::complete_carlson_elliptic_r_g<type>(x, y);
    }
}

#endif // SPECIAL_FUNCTIONS_COMPLETE_CARLSON_ELLIPTIC_R_G_H
