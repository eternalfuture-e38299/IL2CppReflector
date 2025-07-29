/*******************************************************************************
 * 文件名称: api_ptr
 * 项目名称: IL2CppReflector
 * 创建时间: 25-7-22
 * 作者: EternalFuture゙
 * Github: https://github.com/2079541547
 * 版权声明: Copyright © 2025 EternalFuture. All rights reserved.
 *
 * MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *******************************************************************************/

#pragma once

#include <unordered_map>

#include "array.hpp"
#include "assembly.hpp"
#include "class.hpp"
#include "class_user_data.hpp"
#include "custom_attributes.hpp"
#include "debug_metadata.hpp"
#include "debugger.hpp"
#include "domain.hpp"
#include "exception.hpp"
#include "field.hpp"
#include "gc.hpp"
#include "gchandle.hpp"
#include "il2cpp.hpp"
#include "image.hpp"
#include "liveness.hpp"
#include "logging.hpp"
#include "memory_information.hpp"
#include "method.hpp"
#include "monitor.hpp"
#include "object.hpp"
#include "property.hpp"
#include "runtime.hpp"
#include "stacktrace.hpp"
#include "stats.hpp"
#include "string.hpp"
#include "test.hpp"
#include "thread.hpp"
#include "tls_module.hpp"
#include "type.hpp"
#include "vm_runtime_info.hpp"

namespace Il2CppAPI {
    inline static std::unordered_map<const char *, void **> api_ptr = {
        {il2cpp_monitor_enter__name, reinterpret_cast<void **>(&il2cpp_monitor_enter)},
        {il2cpp_monitor_try_enter__name, reinterpret_cast<void **>(&il2cpp_monitor_try_enter)},
        {il2cpp_monitor_exit__name, reinterpret_cast<void **>(&il2cpp_monitor_exit)},
        {il2cpp_monitor_pulse__name, reinterpret_cast<void **>(&il2cpp_monitor_pulse)},
        {il2cpp_monitor_pulse_all__name, reinterpret_cast<void **>(&il2cpp_monitor_pulse_all)},
        {il2cpp_monitor_wait__name, reinterpret_cast<void **>(&il2cpp_monitor_wait)},
        {il2cpp_monitor_try_wait__name, reinterpret_cast<void **>(&il2cpp_monitor_try_wait)},
        {il2cpp_class_for_each__name, reinterpret_cast<void **>(&il2cpp_class_for_each)},
        {il2cpp_class_enum_basetype__name, reinterpret_cast<void **>(&il2cpp_class_enum_basetype)},
        {il2cpp_class_is_generic__name, reinterpret_cast<void **>(&il2cpp_class_is_generic)},
        {il2cpp_class_is_inflated__name, reinterpret_cast<void **>(&il2cpp_class_is_inflated)},
        {il2cpp_class_is_assignable_from__name, reinterpret_cast<void **>(&il2cpp_class_is_assignable_from)},
        {il2cpp_class_is_subclass_of__name, reinterpret_cast<void **>(&il2cpp_class_is_subclass_of)},
        {il2cpp_class_has_parent__name, reinterpret_cast<void **>(&il2cpp_class_has_parent)},
        {il2cpp_class_from_il2cpp_type__name, reinterpret_cast<void **>(&il2cpp_class_from_il2cpp_type)},
        {il2cpp_class_from_name__name, reinterpret_cast<void **>(&il2cpp_class_from_name)},
        {il2cpp_class_from_system_type__name, reinterpret_cast<void **>(&il2cpp_class_from_system_type)},
        {il2cpp_class_get_element_class__name, reinterpret_cast<void **>(&il2cpp_class_get_element_class)},
        {il2cpp_class_get_events__name, reinterpret_cast<void **>(&il2cpp_class_get_events)},
        {il2cpp_class_get_fields__name, reinterpret_cast<void **>(&il2cpp_class_get_fields)},
        {il2cpp_class_get_nested_types__name, reinterpret_cast<void **>(&il2cpp_class_get_nested_types)},
        {il2cpp_class_get_interfaces__name, reinterpret_cast<void **>(&il2cpp_class_get_interfaces)},
        {il2cpp_class_get_properties__name, reinterpret_cast<void **>(&il2cpp_class_get_properties)},
        {il2cpp_class_get_property_from_name__name, reinterpret_cast<void **>(&il2cpp_class_get_property_from_name)},
        {il2cpp_class_get_field_from_name__name, reinterpret_cast<void **>(&il2cpp_class_get_field_from_name)},
        {il2cpp_class_get_methods__name, reinterpret_cast<void **>(&il2cpp_class_get_methods)},
        {il2cpp_class_get_method_from_name__name, reinterpret_cast<void **>(&il2cpp_class_get_method_from_name)},
        {il2cpp_class_get_name__name, reinterpret_cast<void **>(&il2cpp_class_get_name)},
        {il2cpp_type_get_name_chunked__name, reinterpret_cast<void **>(&il2cpp_type_get_name_chunked)},
        {il2cpp_class_get_namespace__name, reinterpret_cast<void **>(&il2cpp_class_get_namespace)},
        {il2cpp_class_get_parent__name, reinterpret_cast<void **>(&il2cpp_class_get_parent)},
        {il2cpp_class_get_declaring_type__name, reinterpret_cast<void **>(&il2cpp_class_get_declaring_type)},
        {il2cpp_class_instance_size__name, reinterpret_cast<void **>(&il2cpp_class_instance_size)},
        {il2cpp_class_num_fields__name, reinterpret_cast<void **>(&il2cpp_class_num_fields)},
        {il2cpp_class_is_valuetype__name, reinterpret_cast<void **>(&il2cpp_class_is_valuetype)},
        {il2cpp_class_value_size__name, reinterpret_cast<void **>(&il2cpp_class_value_size)},
        {il2cpp_class_is_blittable__name, reinterpret_cast<void **>(&il2cpp_class_is_blittable)},
        {il2cpp_class_get_flags__name, reinterpret_cast<void **>(&il2cpp_class_get_flags)},
        {il2cpp_class_is_abstract__name, reinterpret_cast<void **>(&il2cpp_class_is_abstract)},
        {il2cpp_class_is_interface__name, reinterpret_cast<void **>(&il2cpp_class_is_interface)},
        {il2cpp_class_array_element_size__name, reinterpret_cast<void **>(&il2cpp_class_array_element_size)},
        {il2cpp_class_from_type__name, reinterpret_cast<void **>(&il2cpp_class_from_type)},
        {il2cpp_class_get_type__name, reinterpret_cast<void **>(&il2cpp_class_get_type)},
        {il2cpp_class_get_type_token__name, reinterpret_cast<void **>(&il2cpp_class_get_type_token)},
        {il2cpp_class_has_attribute__name, reinterpret_cast<void **>(&il2cpp_class_has_attribute)},
        {il2cpp_class_has_references__name, reinterpret_cast<void **>(&il2cpp_class_has_references)},
        {il2cpp_class_is_enum__name, reinterpret_cast<void **>(&il2cpp_class_is_enum)},
        {il2cpp_class_get_image__name, reinterpret_cast<void **>(&il2cpp_class_get_image)},
        {il2cpp_class_get_assemblyname__name, reinterpret_cast<void **>(&il2cpp_class_get_assemblyname)},
        {il2cpp_class_get_rank__name, reinterpret_cast<void **>(&il2cpp_class_get_rank)},
        {il2cpp_class_get_data_size__name, reinterpret_cast<void **>(&il2cpp_class_get_data_size)},
        {il2cpp_class_get_static_field_data__name, reinterpret_cast<void **>(&il2cpp_class_get_static_field_data)},
        {il2cpp_debug_get_method_info__name, reinterpret_cast<void **>(&il2cpp_debug_get_method_info)},
        {
            il2cpp_unity_install_unitytls_interface__name,
            reinterpret_cast<void **>(&il2cpp_unity_install_unitytls_interface)
        },
        {il2cpp_init__name, reinterpret_cast<void **>(&il2cpp_init)},
        {il2cpp_init_utf16__name, reinterpret_cast<void **>(&il2cpp_init_utf16)},
        {il2cpp_shutdown__name, reinterpret_cast<void **>(&il2cpp_shutdown)},
        {il2cpp_set_config_dir__name, reinterpret_cast<void **>(&il2cpp_set_config_dir)},
        {il2cpp_set_data_dir__name, reinterpret_cast<void **>(&il2cpp_set_data_dir)},
        {il2cpp_set_temp_dir__name, reinterpret_cast<void **>(&il2cpp_set_temp_dir)},
        {il2cpp_set_commandline_arguments__name, reinterpret_cast<void **>(&il2cpp_set_commandline_arguments)},
        {
            il2cpp_set_commandline_arguments_utf16__name,
            reinterpret_cast<void **>(&il2cpp_set_commandline_arguments_utf16)
        },
        {il2cpp_set_config_utf16__name, reinterpret_cast<void **>(&il2cpp_set_config_utf16)},
        {il2cpp_set_config__name, reinterpret_cast<void **>(&il2cpp_set_config)},
        {il2cpp_set_memory_callbacks__name, reinterpret_cast<void **>(&il2cpp_set_memory_callbacks)},
        {il2cpp_get_corlib__name, reinterpret_cast<void **>(&il2cpp_get_corlib)},
        {il2cpp_add_internal_call__name, reinterpret_cast<void **>(&il2cpp_add_internal_call)},
        {il2cpp_resolve_icall__name, reinterpret_cast<void **>(&il2cpp_resolve_icall)},
        {il2cpp_alloc__name, reinterpret_cast<void **>(&il2cpp_alloc)},
        {il2cpp_free__name, reinterpret_cast<void **>(&il2cpp_free)},
        {il2cpp_method_get_return_type__name, reinterpret_cast<void **>(&il2cpp_method_get_return_type)},
        {il2cpp_method_get_declaring_type__name, reinterpret_cast<void **>(&il2cpp_method_get_declaring_type)},
        {il2cpp_method_get_name__name, reinterpret_cast<void **>(&il2cpp_method_get_name)},
        {il2cpp_method_get_from_reflection__name, reinterpret_cast<void **>(&il2cpp_method_get_from_reflection)},
        {il2cpp_method_get_object__name, reinterpret_cast<void **>(&il2cpp_method_get_object)},
        {il2cpp_method_is_generic__name, reinterpret_cast<void **>(&il2cpp_method_is_generic)},
        {il2cpp_method_is_inflated__name, reinterpret_cast<void **>(&il2cpp_method_is_inflated)},
        {il2cpp_method_is_instance__name, reinterpret_cast<void **>(&il2cpp_method_is_instance)},
        {il2cpp_method_get_param_count__name, reinterpret_cast<void **>(&il2cpp_method_get_param_count)},
        {il2cpp_method_get_param__name, reinterpret_cast<void **>(&il2cpp_method_get_param)},
        {il2cpp_method_get_class__name, reinterpret_cast<void **>(&il2cpp_method_get_class)},
        {il2cpp_method_has_attribute__name, reinterpret_cast<void **>(&il2cpp_method_has_attribute)},
        {il2cpp_method_get_flags__name, reinterpret_cast<void **>(&il2cpp_method_get_flags)},
        {il2cpp_method_get_token__name, reinterpret_cast<void **>(&il2cpp_method_get_token)},
        {il2cpp_method_get_param_name__name, reinterpret_cast<void **>(&il2cpp_method_get_param_name)},
        {
            il2cpp_current_thread_walk_frame_stack__name,
            reinterpret_cast<void **>(&il2cpp_current_thread_walk_frame_stack)
        },
        {il2cpp_thread_walk_frame_stack__name, reinterpret_cast<void **>(&il2cpp_thread_walk_frame_stack)},
        {il2cpp_current_thread_get_top_frame__name, reinterpret_cast<void **>(&il2cpp_current_thread_get_top_frame)},
        {il2cpp_thread_get_top_frame__name, reinterpret_cast<void **>(&il2cpp_thread_get_top_frame)},
        {il2cpp_current_thread_get_frame_at__name, reinterpret_cast<void **>(&il2cpp_current_thread_get_frame_at)},
        {il2cpp_thread_get_frame_at__name, reinterpret_cast<void **>(&il2cpp_thread_get_frame_at)},
        {
            il2cpp_current_thread_get_stack_depth__name,
            reinterpret_cast<void **>(&il2cpp_current_thread_get_stack_depth)
        },
        {il2cpp_thread_get_stack_depth__name, reinterpret_cast<void **>(&il2cpp_thread_get_stack_depth)},
        {il2cpp_override_stack_backtrace__name, reinterpret_cast<void **>(&il2cpp_override_stack_backtrace)},
        {il2cpp_class_get_bitmap_size__name, reinterpret_cast<void **>(&il2cpp_class_get_bitmap_size)},
        {il2cpp_class_get_bitmap__name, reinterpret_cast<void **>(&il2cpp_class_get_bitmap)},
        {il2cpp_property_get_flags__name, reinterpret_cast<void **>(&il2cpp_property_get_flags)},
        {il2cpp_property_get_get_method__name, reinterpret_cast<void **>(&il2cpp_property_get_get_method)},
        {il2cpp_property_get_set_method__name, reinterpret_cast<void **>(&il2cpp_property_get_set_method)},
        {il2cpp_property_get_name__name, reinterpret_cast<void **>(&il2cpp_property_get_name)},
        {il2cpp_property_get_parent__name, reinterpret_cast<void **>(&il2cpp_property_get_parent)},
        {il2cpp_class_set_userdata__name, reinterpret_cast<void **>(&il2cpp_class_set_userdata)},
        {il2cpp_class_get_userdata_offset__name, reinterpret_cast<void **>(&il2cpp_class_get_userdata_offset)},
        {il2cpp_set_default_thread_affinity__name, reinterpret_cast<void **>(&il2cpp_set_default_thread_affinity)},
        {il2cpp_string_length__name, reinterpret_cast<void **>(&il2cpp_string_length)},
        {il2cpp_string_chars__name, reinterpret_cast<void **>(&il2cpp_string_chars)},
        {il2cpp_string_new__name, reinterpret_cast<void **>(&il2cpp_string_new)},
        {il2cpp_string_new_len__name, reinterpret_cast<void **>(&il2cpp_string_new_len)},
        {il2cpp_string_new_utf16__name, reinterpret_cast<void **>(&il2cpp_string_new_utf16)},
        {il2cpp_string_new_wrapper__name, reinterpret_cast<void **>(&il2cpp_string_new_wrapper)},
        {il2cpp_string_intern__name, reinterpret_cast<void **>(&il2cpp_string_intern)},
        {il2cpp_string_is_interned__name, reinterpret_cast<void **>(&il2cpp_string_is_interned)},
        {il2cpp_raise_exception__name, reinterpret_cast<void **>(&il2cpp_raise_exception)},
        {il2cpp_exception_from_name_msg__name, reinterpret_cast<void **>(&il2cpp_exception_from_name_msg)},
        {il2cpp_get_exception_argument_null__name, reinterpret_cast<void **>(&il2cpp_get_exception_argument_null)},
        {il2cpp_format_exception__name, reinterpret_cast<void **>(&il2cpp_format_exception)},
        {il2cpp_format_stack_trace__name, reinterpret_cast<void **>(&il2cpp_format_stack_trace)},
        {il2cpp_unhandled_exception__name, reinterpret_cast<void **>(&il2cpp_unhandled_exception)},
        {il2cpp_native_stack_trace__name, reinterpret_cast<void **>(&il2cpp_native_stack_trace)},
        {il2cpp_type_get_object__name, reinterpret_cast<void **>(&il2cpp_type_get_object)},
        {il2cpp_type_get_type__name, reinterpret_cast<void **>(&il2cpp_type_get_type)},
        {
            il2cpp_type_get_class_or_element_class__name,
            reinterpret_cast<void **>(&il2cpp_type_get_class_or_element_class)
        },
        {il2cpp_type_get_name__name, reinterpret_cast<void **>(&il2cpp_type_get_name)},
        {il2cpp_type_is_byref__name, reinterpret_cast<void **>(&il2cpp_type_is_byref)},
        {il2cpp_type_get_attrs__name, reinterpret_cast<void **>(&il2cpp_type_get_attrs)},
        {il2cpp_type_equals__name, reinterpret_cast<void **>(&il2cpp_type_equals)},
        {
            il2cpp_type_get_assembly_qualified_name__name,
            reinterpret_cast<void **>(&il2cpp_type_get_assembly_qualified_name)
        },
        {il2cpp_type_is_static__name, reinterpret_cast<void **>(&il2cpp_type_is_static)},
        {il2cpp_type_is_pointer_type__name, reinterpret_cast<void **>(&il2cpp_type_is_pointer_type)},
        {il2cpp_thread_current__name, reinterpret_cast<void **>(&il2cpp_thread_current)},
        {il2cpp_thread_attach__name, reinterpret_cast<void **>(&il2cpp_thread_attach)},
        {il2cpp_thread_detach__name, reinterpret_cast<void **>(&il2cpp_thread_detach)},
        {
            il2cpp_thread_get_all_attached_threads__name,
            reinterpret_cast<void **>(&il2cpp_thread_get_all_attached_threads)
        },
        {il2cpp_is_vm_thread__name, reinterpret_cast<void **>(&il2cpp_is_vm_thread)},
        {il2cpp_object_get_class__name, reinterpret_cast<void **>(&il2cpp_object_get_class)},
        {il2cpp_object_get_size__name, reinterpret_cast<void **>(&il2cpp_object_get_size)},
        {il2cpp_object_get_virtual_method__name, reinterpret_cast<void **>(&il2cpp_object_get_virtual_method)},
        {il2cpp_object_new__name, reinterpret_cast<void **>(&il2cpp_object_new)},
        {il2cpp_object_unbox__name, reinterpret_cast<void **>(&il2cpp_object_unbox)},
        {il2cpp_value_box__name, reinterpret_cast<void **>(&il2cpp_value_box)},
        {il2cpp_field_get_flags__name, reinterpret_cast<void **>(&il2cpp_field_get_flags)},
        {il2cpp_field_get_name__name, reinterpret_cast<void **>(&il2cpp_field_get_name)},
        {il2cpp_field_get_parent__name, reinterpret_cast<void **>(&il2cpp_field_get_parent)},
        {il2cpp_field_get_offset__name, reinterpret_cast<void **>(&il2cpp_field_get_offset)},
        {il2cpp_field_get_type__name, reinterpret_cast<void **>(&il2cpp_field_get_type)},
        {il2cpp_field_get_value__name, reinterpret_cast<void **>(&il2cpp_field_get_value)},
        {il2cpp_field_get_value_object__name, reinterpret_cast<void **>(&il2cpp_field_get_value_object)},
        {il2cpp_field_has_attribute__name, reinterpret_cast<void **>(&il2cpp_field_has_attribute)},
        {il2cpp_field_set_value__name, reinterpret_cast<void **>(&il2cpp_field_set_value)},
        {il2cpp_field_static_get_value__name, reinterpret_cast<void **>(&il2cpp_field_static_get_value)},
        {il2cpp_field_static_set_value__name, reinterpret_cast<void **>(&il2cpp_field_static_set_value)},
        {il2cpp_field_set_value_object__name, reinterpret_cast<void **>(&il2cpp_field_set_value_object)},
        {il2cpp_field_is_literal__name, reinterpret_cast<void **>(&il2cpp_field_is_literal)},
        {il2cpp_runtime_invoke__name, reinterpret_cast<void **>(&il2cpp_runtime_invoke)},
        {il2cpp_runtime_invoke_convert_args__name, reinterpret_cast<void **>(&il2cpp_runtime_invoke_convert_args)},
        {il2cpp_runtime_class_init__name, reinterpret_cast<void **>(&il2cpp_runtime_class_init)},
        {il2cpp_runtime_object_init__name, reinterpret_cast<void **>(&il2cpp_runtime_object_init)},
        {il2cpp_runtime_object_init_exception__name, reinterpret_cast<void **>(&il2cpp_runtime_object_init_exception)},
        {
            il2cpp_runtime_unhandled_exception_policy_set__name,
            reinterpret_cast<void **>(&il2cpp_runtime_unhandled_exception_policy_set)
        },
        {il2cpp_capture_memory_snapshot__name, reinterpret_cast<void **>(&il2cpp_capture_memory_snapshot)},
        {il2cpp_free_captured_memory_snapshot__name, reinterpret_cast<void **>(&il2cpp_free_captured_memory_snapshot)},
        {il2cpp_set_find_plugin_callback__name, reinterpret_cast<void **>(&il2cpp_set_find_plugin_callback)},
        {il2cpp_stats_dump_to_file__name, reinterpret_cast<void **>(&il2cpp_stats_dump_to_file)},
        {il2cpp_stats_get_value__name, reinterpret_cast<void **>(&il2cpp_stats_get_value)},
        {il2cpp_gchandle_new__name, reinterpret_cast<void **>(&il2cpp_gchandle_new)},
        {il2cpp_gchandle_new_weakref__name, reinterpret_cast<void **>(&il2cpp_gchandle_new_weakref)},
        {il2cpp_gchandle_get_target__name, reinterpret_cast<void **>(&il2cpp_gchandle_get_target)},
        {il2cpp_gchandle_free__name, reinterpret_cast<void **>(&il2cpp_gchandle_free)},
        {il2cpp_gchandle_foreach_get_target__name, reinterpret_cast<void **>(&il2cpp_gchandle_foreach_get_target)},
        {il2cpp_domain_get__name, reinterpret_cast<void **>(&il2cpp_domain_get)},
        {il2cpp_domain_assembly_open__name, reinterpret_cast<void **>(&il2cpp_domain_assembly_open)},
        {il2cpp_domain_get_assemblies__name, reinterpret_cast<void **>(&il2cpp_domain_get_assemblies)},
        {il2cpp_debugger_set_agent_options__name, reinterpret_cast<void **>(&il2cpp_debugger_set_agent_options)},
        {il2cpp_is_debugger_attached__name, reinterpret_cast<void **>(&il2cpp_is_debugger_attached)},
        {
            il2cpp_register_debugger_agent_transport__name,
            reinterpret_cast<void **>(&il2cpp_register_debugger_agent_transport)
        },
        {il2cpp_array_class_get__name, reinterpret_cast<void **>(&il2cpp_array_class_get)},
        {il2cpp_array_length__name, reinterpret_cast<void **>(&il2cpp_array_length)},
        {il2cpp_array_get_byte_length__name, reinterpret_cast<void **>(&il2cpp_array_get_byte_length)},
        {il2cpp_array_new__name, reinterpret_cast<void **>(&il2cpp_array_new)},
        {il2cpp_array_new_specific__name, reinterpret_cast<void **>(&il2cpp_array_new_specific)},
        {il2cpp_array_new_full__name, reinterpret_cast<void **>(&il2cpp_array_new_full)},
        {il2cpp_bounded_array_class_get__name, reinterpret_cast<void **>(&il2cpp_bounded_array_class_get)},
        {il2cpp_array_element_size__name, reinterpret_cast<void **>(&il2cpp_array_element_size)},
        {il2cpp_custom_attrs_from_class__name, reinterpret_cast<void **>(&il2cpp_custom_attrs_from_class)},
        {il2cpp_custom_attrs_from_method__name, reinterpret_cast<void **>(&il2cpp_custom_attrs_from_method)},
        {il2cpp_custom_attrs_get_attr__name, reinterpret_cast<void **>(&il2cpp_custom_attrs_get_attr)},
        {il2cpp_custom_attrs_has_attr__name, reinterpret_cast<void **>(&il2cpp_custom_attrs_has_attr)},
        {il2cpp_custom_attrs_construct__name, reinterpret_cast<void **>(&il2cpp_custom_attrs_construct)},
        {il2cpp_custom_attrs_free__name, reinterpret_cast<void **>(&il2cpp_custom_attrs_free)},
        {il2cpp_gc_collect__name, reinterpret_cast<void **>(&il2cpp_gc_collect)},
        {il2cpp_gc_collect_a_little__name, reinterpret_cast<void **>(&il2cpp_gc_collect_a_little)},
        {
            il2cpp_gc_start_incremental_collection__name,
            reinterpret_cast<void **>(&il2cpp_gc_start_incremental_collection)
        },
        {il2cpp_gc_disable__name, reinterpret_cast<void **>(&il2cpp_gc_disable)},
        {il2cpp_gc_enable__name, reinterpret_cast<void **>(&il2cpp_gc_enable)},
        {il2cpp_gc_is_disabled__name, reinterpret_cast<void **>(&il2cpp_gc_is_disabled)},
        {il2cpp_gc_set_mode__name, reinterpret_cast<void **>(&il2cpp_gc_set_mode)},
        {il2cpp_gc_get_max_time_slice_ns__name, reinterpret_cast<void **>(&il2cpp_gc_get_max_time_slice_ns)},
        {il2cpp_gc_set_max_time_slice_ns__name, reinterpret_cast<void **>(&il2cpp_gc_set_max_time_slice_ns)},
        {il2cpp_gc_is_incremental__name, reinterpret_cast<void **>(&il2cpp_gc_is_incremental)},
        {il2cpp_gc_get_used_size__name, reinterpret_cast<void **>(&il2cpp_gc_get_used_size)},
        {il2cpp_gc_get_heap_size__name, reinterpret_cast<void **>(&il2cpp_gc_get_heap_size)},
        {il2cpp_gc_wbarrier_set_field__name, reinterpret_cast<void **>(&il2cpp_gc_wbarrier_set_field)},
        {il2cpp_gc_has_strict_wbarriers__name, reinterpret_cast<void **>(&il2cpp_gc_has_strict_wbarriers)},
        {
            il2cpp_gc_set_external_allocation_tracker__name,
            reinterpret_cast<void **>(&il2cpp_gc_set_external_allocation_tracker)
        },
        {
            il2cpp_gc_set_external_wbarrier_tracker__name,
            reinterpret_cast<void **>(&il2cpp_gc_set_external_wbarrier_tracker)
        },
        {il2cpp_gc_foreach_heap__name, reinterpret_cast<void **>(&il2cpp_gc_foreach_heap)},
        {il2cpp_stop_gc_world__name, reinterpret_cast<void **>(&il2cpp_stop_gc_world)},
        {il2cpp_start_gc_world__name, reinterpret_cast<void **>(&il2cpp_start_gc_world)},
        {il2cpp_gc_alloc_fixed__name, reinterpret_cast<void **>(&il2cpp_gc_alloc_fixed)},
        {il2cpp_gc_free_fixed__name, reinterpret_cast<void **>(&il2cpp_gc_free_fixed)},
        {il2cpp_image_get_assembly__name, reinterpret_cast<void **>(&il2cpp_image_get_assembly)},
        {il2cpp_image_get_name__name, reinterpret_cast<void **>(&il2cpp_image_get_name)},
        {il2cpp_image_get_filename__name, reinterpret_cast<void **>(&il2cpp_image_get_filename)},
        {il2cpp_image_get_entry_point__name, reinterpret_cast<void **>(&il2cpp_image_get_entry_point)},
        {il2cpp_image_get_class_count__name, reinterpret_cast<void **>(&il2cpp_image_get_class_count)},
        {il2cpp_image_get_class__name, reinterpret_cast<void **>(&il2cpp_image_get_class)},
        {
            il2cpp_unity_liveness_allocate_struct__name,
            reinterpret_cast<void **>(&il2cpp_unity_liveness_allocate_struct)
        },
        {
            il2cpp_unity_liveness_calculation_from_root__name,
            reinterpret_cast<void **>(&il2cpp_unity_liveness_calculation_from_root)
        },
        {
            il2cpp_unity_liveness_calculation_from_statics__name,
            reinterpret_cast<void **>(&il2cpp_unity_liveness_calculation_from_statics)
        },
        {il2cpp_unity_liveness_finalize__name, reinterpret_cast<void **>(&il2cpp_unity_liveness_finalize)},
        {il2cpp_unity_liveness_free_struct__name, reinterpret_cast<void **>(&il2cpp_unity_liveness_free_struct)},
        {il2cpp_assembly_get_image__name, reinterpret_cast<void **>(&il2cpp_assembly_get_image)},
        {il2cpp_register_log_callback__name, reinterpret_cast<void **>(&il2cpp_register_log_callback)},
        {il2cpp_object_header_size__name, reinterpret_cast<void **>(&il2cpp_object_header_size)},
        {il2cpp_array_object_header_size__name, reinterpret_cast<void **>(&il2cpp_array_object_header_size)},
        {
            il2cpp_offset_of_array_length_in_array_object_header__name,
            reinterpret_cast<void **>(&il2cpp_offset_of_array_length_in_array_object_header)
        },
        {
            il2cpp_offset_of_array_bounds_in_array_object_header__name,
            reinterpret_cast<void **>(&il2cpp_offset_of_array_bounds_in_array_object_header)
        },
        {il2cpp_allocation_granularity__name, reinterpret_cast<void **>(&il2cpp_allocation_granularity)},
    };
}
