/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: fichier.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "fichier.pb-c.h"
void   message_type__init
                     (MessageType         *message)
{
  static const MessageType init_value = MESSAGE_TYPE__INIT;
  *message = init_value;
}
size_t message_type__get_packed_size
                     (const MessageType *message)
{
  assert(message->base.descriptor == &message_type__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t message_type__pack
                     (const MessageType *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &message_type__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t message_type__pack_to_buffer
                     (const MessageType *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &message_type__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
MessageType *
       message_type__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (MessageType *)
     protobuf_c_message_unpack (&message_type__descriptor,
                                allocator, len, data);
}
void   message_type__free_unpacked
                     (MessageType *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &message_type__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   arret_urgence__init
                     (ArretUrgence         *message)
{
  static const ArretUrgence init_value = ARRET_URGENCE__INIT;
  *message = init_value;
}
size_t arret_urgence__get_packed_size
                     (const ArretUrgence *message)
{
  assert(message->base.descriptor == &arret_urgence__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t arret_urgence__pack
                     (const ArretUrgence *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &arret_urgence__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t arret_urgence__pack_to_buffer
                     (const ArretUrgence *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &arret_urgence__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
ArretUrgence *
       arret_urgence__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (ArretUrgence *)
     protobuf_c_message_unpack (&arret_urgence__descriptor,
                                allocator, len, data);
}
void   arret_urgence__free_unpacked
                     (ArretUrgence *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &arret_urgence__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   stop_marco__init
                     (StopMarco         *message)
{
  static const StopMarco init_value = STOP_MARCO__INIT;
  *message = init_value;
}
size_t stop_marco__get_packed_size
                     (const StopMarco *message)
{
  assert(message->base.descriptor == &stop_marco__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t stop_marco__pack
                     (const StopMarco *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &stop_marco__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t stop_marco__pack_to_buffer
                     (const StopMarco *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &stop_marco__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
StopMarco *
       stop_marco__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (StopMarco *)
     protobuf_c_message_unpack (&stop_marco__descriptor,
                                allocator, len, data);
}
void   stop_marco__free_unpacked
                     (StopMarco *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &stop_marco__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
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
void   deplacement_manuel__init
                     (DeplacementManuel         *message)
{
  static const DeplacementManuel init_value = DEPLACEMENT_MANUEL__INIT;
  *message = init_value;
}
size_t deplacement_manuel__get_packed_size
                     (const DeplacementManuel *message)
{
  assert(message->base.descriptor == &deplacement_manuel__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t deplacement_manuel__pack
                     (const DeplacementManuel *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &deplacement_manuel__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t deplacement_manuel__pack_to_buffer
                     (const DeplacementManuel *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &deplacement_manuel__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
DeplacementManuel *
       deplacement_manuel__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (DeplacementManuel *)
     protobuf_c_message_unpack (&deplacement_manuel__descriptor,
                                allocator, len, data);
}
void   deplacement_manuel__free_unpacked
                     (DeplacementManuel *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &deplacement_manuel__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   status_explo__init
                     (StatusExplo         *message)
{
  static const StatusExplo init_value = STATUS_EXPLO__INIT;
  *message = init_value;
}
size_t status_explo__get_packed_size
                     (const StatusExplo *message)
{
  assert(message->base.descriptor == &status_explo__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t status_explo__pack
                     (const StatusExplo *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &status_explo__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t status_explo__pack_to_buffer
                     (const StatusExplo *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &status_explo__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
StatusExplo *
       status_explo__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (StatusExplo *)
     protobuf_c_message_unpack (&status_explo__descriptor,
                                allocator, len, data);
}
void   status_explo__free_unpacked
                     (StatusExplo *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &status_explo__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   set_explo_algo__init
                     (SetExploAlgo         *message)
{
  static const SetExploAlgo init_value = SET_EXPLO_ALGO__INIT;
  *message = init_value;
}
size_t set_explo_algo__get_packed_size
                     (const SetExploAlgo *message)
{
  assert(message->base.descriptor == &set_explo_algo__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t set_explo_algo__pack
                     (const SetExploAlgo *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &set_explo_algo__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t set_explo_algo__pack_to_buffer
                     (const SetExploAlgo *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &set_explo_algo__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
SetExploAlgo *
       set_explo_algo__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (SetExploAlgo *)
     protobuf_c_message_unpack (&set_explo_algo__descriptor,
                                allocator, len, data);
}
void   set_explo_algo__free_unpacked
                     (SetExploAlgo *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &set_explo_algo__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   position__init
                     (Position         *message)
{
  static const Position init_value = POSITION__INIT;
  *message = init_value;
}
size_t position__get_packed_size
                     (const Position *message)
{
  assert(message->base.descriptor == &position__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t position__pack
                     (const Position *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &position__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t position__pack_to_buffer
                     (const Position *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &position__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Position *
       position__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Position *)
     protobuf_c_message_unpack (&position__descriptor,
                                allocator, len, data);
}
void   position__free_unpacked
                     (Position *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &position__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   set_explo_param__init
                     (SetExploParam         *message)
{
  static const SetExploParam init_value = SET_EXPLO_PARAM__INIT;
  *message = init_value;
}
size_t set_explo_param__get_packed_size
                     (const SetExploParam *message)
{
  assert(message->base.descriptor == &set_explo_param__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t set_explo_param__pack
                     (const SetExploParam *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &set_explo_param__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t set_explo_param__pack_to_buffer
                     (const SetExploParam *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &set_explo_param__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
SetExploParam *
       set_explo_param__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (SetExploParam *)
     protobuf_c_message_unpack (&set_explo_param__descriptor,
                                allocator, len, data);
}
void   set_explo_param__free_unpacked
                     (SetExploParam *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &set_explo_param__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor message_type__field_descriptors[2] =
{
  {
    "id",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(MessageType, id),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "payload",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    offsetof(MessageType, payload),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned message_type__field_indices_by_name[] = {
  0,   /* field[0] = id */
  1,   /* field[1] = payload */
};
static const ProtobufCIntRange message_type__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor message_type__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "message_type",
  "MessageType",
  "MessageType",
  "",
  sizeof(MessageType),
  2,
  message_type__field_descriptors,
  message_type__field_indices_by_name,
  1,  message_type__number_ranges,
  (ProtobufCMessageInit) message_type__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor arret_urgence__field_descriptors[1] =
{
  {
    "state",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(ArretUrgence, state),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned arret_urgence__field_indices_by_name[] = {
  0,   /* field[0] = state */
};
static const ProtobufCIntRange arret_urgence__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor arret_urgence__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "arret_urgence",
  "ArretUrgence",
  "ArretUrgence",
  "",
  sizeof(ArretUrgence),
  1,
  arret_urgence__field_descriptors,
  arret_urgence__field_indices_by_name,
  1,  arret_urgence__number_ranges,
  (ProtobufCMessageInit) arret_urgence__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor stop_marco__field_descriptors[1] =
{
  {
    "state",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(StopMarco, state),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned stop_marco__field_indices_by_name[] = {
  0,   /* field[0] = state */
};
static const ProtobufCIntRange stop_marco__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor stop_marco__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "stop_marco",
  "StopMarco",
  "StopMarco",
  "",
  sizeof(StopMarco),
  1,
  stop_marco__field_descriptors,
  stop_marco__field_indices_by_name,
  1,  stop_marco__number_ranges,
  (ProtobufCMessageInit) stop_marco__init,
  NULL,NULL,NULL    /* reserved[123] */
};
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
  "battery_level",
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
static const ProtobufCFieldDescriptor deplacement_manuel__field_descriptors[2] =
{
  {
    "direction",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(DeplacementManuel, direction),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "speed",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(DeplacementManuel, speed),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned deplacement_manuel__field_indices_by_name[] = {
  0,   /* field[0] = direction */
  1,   /* field[1] = speed */
};
static const ProtobufCIntRange deplacement_manuel__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor deplacement_manuel__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "deplacement_manuel",
  "DeplacementManuel",
  "DeplacementManuel",
  "",
  sizeof(DeplacementManuel),
  2,
  deplacement_manuel__field_descriptors,
  deplacement_manuel__field_indices_by_name,
  1,  deplacement_manuel__number_ranges,
  (ProtobufCMessageInit) deplacement_manuel__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor status_explo__field_descriptors[3] =
{
  {
    "status",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(StatusExplo, status),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "pourcentage",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(StatusExplo, pourcentage),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "temps",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(StatusExplo, temps),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned status_explo__field_indices_by_name[] = {
  1,   /* field[1] = pourcentage */
  0,   /* field[0] = status */
  2,   /* field[2] = temps */
};
static const ProtobufCIntRange status_explo__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor status_explo__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "status_explo",
  "StatusExplo",
  "StatusExplo",
  "",
  sizeof(StatusExplo),
  3,
  status_explo__field_descriptors,
  status_explo__field_indices_by_name,
  1,  status_explo__number_ranges,
  (ProtobufCMessageInit) status_explo__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor set_explo_algo__field_descriptors[1] =
{
  {
    "algo",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(SetExploAlgo, algo),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned set_explo_algo__field_indices_by_name[] = {
  0,   /* field[0] = algo */
};
static const ProtobufCIntRange set_explo_algo__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor set_explo_algo__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "set_explo_algo",
  "SetExploAlgo",
  "SetExploAlgo",
  "",
  sizeof(SetExploAlgo),
  1,
  set_explo_algo__field_descriptors,
  set_explo_algo__field_indices_by_name,
  1,  set_explo_algo__number_ranges,
  (ProtobufCMessageInit) set_explo_algo__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor position__field_descriptors[2] =
{
  {
    "x",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(Position, x),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "y",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(Position, y),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned position__field_indices_by_name[] = {
  0,   /* field[0] = x */
  1,   /* field[1] = y */
};
static const ProtobufCIntRange position__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor position__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "position",
  "Position",
  "Position",
  "",
  sizeof(Position),
  2,
  position__field_descriptors,
  position__field_indices_by_name,
  1,  position__number_ranges,
  (ProtobufCMessageInit) position__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor set_explo_param__field_descriptors[3] =
{
  {
    "type",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(SetExploParam, type),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "isEnable",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(SetExploParam, isenable),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "value",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(SetExploParam, value),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned set_explo_param__field_indices_by_name[] = {
  1,   /* field[1] = isEnable */
  0,   /* field[0] = type */
  2,   /* field[2] = value */
};
static const ProtobufCIntRange set_explo_param__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor set_explo_param__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "set_explo_param",
  "SetExploParam",
  "SetExploParam",
  "",
  sizeof(SetExploParam),
  3,
  set_explo_param__field_descriptors,
  set_explo_param__field_indices_by_name,
  1,  set_explo_param__number_ranges,
  (ProtobufCMessageInit) set_explo_param__init,
  NULL,NULL,NULL    /* reserved[123] */
};
