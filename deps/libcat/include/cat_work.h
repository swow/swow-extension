/*
  +--------------------------------------------------------------------------+
  | libcat                                                                   |
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

#ifndef CAT_WORK_H
#define CAT_WORK_H
#ifdef __cplusplus
extern "C" {
#endif

#include "cat.h"
#include "cat_time.h"

typedef cat_data_callback_t cat_work_function_t;

CAT_API cat_bool_t cat_work(cat_work_function_t function, cat_data_t *data, cat_timeout_t timeout);

#ifdef __cplusplus
}
#endif
#endif /* CAT_WORK_H */
