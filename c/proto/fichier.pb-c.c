/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: fichier.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "fichier.pb-c.h"
void   battery_level__init
                     (BatteryLevel         *message)
{
  static const BatteryLevel init_value = BATTERY_LEVEL__INIT;
  *message = init_value;
}
size_t battery_level__get_packed_size
                     (const BatteryLevel *message)
{
  assert(message->base.descriptor == &battery_level__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t battery_level__pack
                     (const BatteryLevel *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &battery_level__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t battery_level__pack_to_buffer
                     (const BatteryLevel *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &battery_level__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
BatteryLevel *
       battery_level__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (BatteryLevel *)
     protobuf_c_message_unpack (&battery_level__descriptor,
                                allocator, len, data);
}
void   battery_level__free_unpacked
                     (BatteryLevel *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &battery_level__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor battery_level__field_descriptors[1] =
{
  {
    "level",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(BatteryLevel, level),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned battery_level__field_indices_by_name[] = {
  0,   /* field[0] = level */
};
static const ProtobufCIntRange battery_level__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor battery_level__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "BatteryLevel",
  "BatteryLevel",
  "BatteryLevel",
  "",
  sizeof(BatteryLevel),
  1,
  battery_level__field_descriptors,
  battery_level__field_indices_by_name,
  1,  battery_level__number_ranges,
  (ProtobufCMessageInit) battery_level__init,
  NULL,NULL,NULL    /* reserved[123] */
};
