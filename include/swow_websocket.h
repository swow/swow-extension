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

#ifndef SWOW_WEBSOCKET_H
#define SWOW_WEBSOCKET_H
#ifdef __cplusplus
extern "C" {
#endif

#include "swow.h"
#include "swow_buffer.h"

#include "cat_websocket.h"

extern SWOW_API zend_class_entry *swow_websocket_websocket_ce;
extern SWOW_API zend_class_entry *swow_websocket_opcode_ce;
extern SWOW_API zend_class_entry *swow_websocket_status_ce;
extern SWOW_API zend_class_entry *swow_websocket_header_ce;

/* loader */

zend_result swow_websocket_module_init(INIT_FUNC_ARGS);

#ifdef __cplusplus
}
#endif
#endif /* SWOW_WEBSOCKET_H */
