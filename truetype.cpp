// Template Meta programming
// 1. Values space  : 42, "Hello World"
// 2. Type Space : int float
// 3. SFINAE space : Well formed or Ill Formed 

# include <iostream>

// To Move True and False Bool values from Value space to Type space
template  <class Ty, Ty v>  // 2 Parameter
struct integral_constant 
{
	static constexpr Ty value = v;
};

template  <bool B>
using bool_constant = integral_constant<bool, B>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;
