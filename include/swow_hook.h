/*
  +--------------------------------------------------------------------------+
  | Swow                                                                     |
  +--------------------------------------------------------------------------+
  | Licensed under the Apache License, Version 2.0 (the "License");          |
  | you may not use this file except in compliance with the License.         |
  | You may obtain a copy of the License at                                  |
  | http://www.apache.org/licenses/LICENSE-2.0                               |
  | Unless required by applicable law or agreed to in writing, software      |
  | distributed under the License is distributed on an "AS IS" BASIS,        |
  | WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. |
  | See the License for the specific language governing permissions and      |
  | limitations under the License. See accompanying LICENSE file.            |
  +--------------------------------------------------------------------------+
  | Author: Twosee <twosee@php.net>                                          |
  +--------------------------------------------------------------------------+
 */

#ifndef SWOW_HOOK_H
#define SWOW_HOOK_H
#ifdef __cplusplus
extern "C" {
#endif

#include "swow.h"

/* functions */

SWOW_API cat_bool_t swow_hook_internal_function_handler(const char *name, size_t name_length, zif_handler handler);
SWOW_API cat_bool_t swow_hook_internal_function_handler_ex(const char *name, size_t name_length, zif_handler handler, zif_handler *original_handler);
SWOW_API cat_bool_t swow_hook_internal_function(const zend_function_entry *fe);
SWOW_API cat_bool_t swow_hook_internal_functions(const zend_function_entry *fes);


/* constant */

SWOW_API void swow_register_null_constant_force(const char *name, size_t name_len, int flags, int module_number);
SWOW_API void swow_register_bool_constant_force(const char *name, size_t name_len, zend_bool bval, int flags, int module_number);
SWOW_API void swow_register_long_constant_force(const char *name, size_t name_len, zend_long lval, int flags, int module_number);
SWOW_API void swow_register_double_constant_force(const char *name, size_t name_len, double dval, int flags, int module_number);
SWOW_API void swow_register_string_constant_force(const char *name, size_t name_len, const char *strval, int flags, int module_number);
SWOW_API void swow_register_stringl_constant_force(const char *name, size_t name_len, const char *strval, size_t strlen, int flags, int module_number);

#define SWOW_REGISTER_NULL_CONSTANT_FORCE(name, flags)  swow_register_null_constant_force(name, sizeof(name) - 1, flags, module_number)
#define SWOW_REGISTER_BOOL_CONSTANT_FORCE(name, bval, flags)  swow_register_bool_constant_force(name, sizeof(name) - 1, bval, flags, module_number)
#define SWOW_REGISTER_LONG_CONSTANT_FORCE(name, lval, flags)  swow_register_long_constant_force(name, sizeof(name) - 1, lval, flags, module_number)
#define SWOW_REGISTER_DOUBLE_CONSTANT_FORCE(name, dval, flags)  swow_register_double_constant_force(name, sizeof(name) - 1, dval, flags, module_number)
#define SWOW_REGISTER_STRING_CONSTANT_FORCE(name, str, flags)  swow_register_string_constant_force(name, sizeof(name) - 1, str, flags, module_number)
#define SWOW_REGISTER_STRINGL_CONSTANT_FORCE(name, str, len, flags)  swow_register_stringl_constant_force(name, sizeof(name) - 1, str, len, flags, module_number)

/* module */

SWOW_API void swow_clean_module_constants(int module_number);
SWOW_API void swow_clean_module_classes(int module_number);
SWOW_API void swow_clean_module_functions(int module_number);

#ifdef __cplusplus
}
#endif
#endif /* SWOW_HOOK_H */
