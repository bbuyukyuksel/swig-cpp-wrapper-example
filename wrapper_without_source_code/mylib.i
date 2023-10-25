%module myclass
%include "std_string.i"
%include <std_shared_ptr.i>

%{
#include "mylib.hpp"
%}

%shared_ptr(Date);

%include "mylib.hpp"