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

#include "swow_curl.h"
#include "swow_hook.h"

#ifdef CAT_CURL

void swow_curl_module_info(zend_module_entry *zend_module);
zend_result swow_curl_interface_module_init(INIT_FUNC_ARGS);

zend_result swow_curl_module_init(INIT_FUNC_ARGS)
{
    if (!cat_curl_module_init()) {
        return FAILURE;
    }

    zend_module_entry *php_curl_module = zend_hash_str_find_ptr(&module_registry, ZEND_STRL("curl"));
    zend_class_entry *php_curl_ce;
    php_curl_ce = (zend_class_entry *) zend_hash_str_find_ptr(CG(class_table), ZEND_STRL("curlhandle"));
    if (php_curl_ce == NULL) {
        if (php_curl_module != NULL) {
                zend_error(E_WARNING,
                    "Swow extension must be loaded after curl extension in PHP ini, for example:\n"
                    "   extension=curl\n"
                    "   extension=swow\n");
                return FAILURE;
        }
    } else {
        swow_clean_module_constants(php_curl_module->module_number);
        swow_clean_module_classes(php_curl_module->module_number);
        swow_clean_module_functions(php_curl_module->module_number);
        php_curl_module->info_func = swow_curl_module_info;
    }

    if (php_curl_module != NULL && php_curl_module->type != MODULE_TEMPORARY) {
        zend_module_entry *previous_current_module = EG(current_module);
        EG(current_module) = php_curl_module;
        if (swow_curl_interface_module_init(php_curl_module->type, php_curl_module->module_number) != SUCCESS) {
            return FAILURE;
        }
        EG(current_module) = previous_current_module;
        return SUCCESS;
    } else {
        if (swow_curl_interface_module_init(INIT_FUNC_ARGS_PASSTHRU) != SUCCESS) {
            return FAILURE;
        }
    }

    return SUCCESS;
}

zend_result swow_curl_module_shutdown(INIT_FUNC_ARGS)
{
    if (!cat_curl_module_shutdown()) {
        return FAILURE;
    }

    return SUCCESS;
}

zend_result swow_curl_runtime_init(INIT_FUNC_ARGS)
{
    if (!cat_curl_runtime_init()) {
        return FAILURE;
    }

    return SUCCESS;
}

zend_result swow_curl_runtime_close(void)
{
    if (!cat_curl_runtime_close()) {
        return FAILURE;
    }

    return SUCCESS;
}

#endif /* CAT_CURL */
