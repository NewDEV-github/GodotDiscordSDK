#ifndef UTIL_H_
#define UTIL_H_

#include "types.h"

#include <stdlib.h>
#include <stdbool.h>
#include <gdnative_api_struct.gen.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define INIT_OBJECT(Name, Class, InternalClass, Lib, Instance)     \
    Class *Name = Lib->api->godot_alloc(sizeof(Class));            \
    memset(Name, 0, sizeof(Class));                                \
                                                                   \
    Name->internal = Lib->api->godot_alloc(sizeof(InternalClass)); \
    memset(Name->internal, 0, sizeof(InternalClass));              \
                                                                   \
    Name->object = Instance;

godot_string get_script_path(godot_string *name,
                             Library *p_lib);

godot_object *instantiate_custom_class(const char *p_class_name, const char *p_base,
                                       Library *p_lib);

godot_variant_call_error object_emit_signal(godot_object *p_object,
                                            godot_string *p_signal_name,
                                            int p_num_args, godot_variant **p_args,
                                            Library *p_lib);

godot_variant_call_error object_call(godot_object *p_object,
                                     godot_string *p_method_name,
                                     int p_num_args, godot_variant **p_args,
                                     Library *p_lib);

void godot_reference(godot_object *p_object, Library *p_lib);
void godot_unreference(godot_object *p_object, Library *p_lib);

#endif