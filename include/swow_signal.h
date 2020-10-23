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

#ifndef SWOW_SIGNAL_H
#define SWOW_SIGNAL_H
#ifdef __cplusplus
extern "C" {
#endif

#include "swow.h"

#include "cat_signal.h"

extern SWOW_API zend_class_entry *swow_signal_ce;
extern SWOW_API zend_object_handlers swow_signal_handlers;

extern SWOW_API zend_class_entry *swow_signal_exception_ce;

/* loader */

int swow_signal_module_init(INIT_FUNC_ARGS);

#ifdef __cplusplus
}
#endif
#endif /* SWOW_SIGNAL_H */
