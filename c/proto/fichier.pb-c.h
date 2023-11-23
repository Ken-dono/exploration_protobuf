/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: fichier.proto */

#ifndef PROTOBUF_C_fichier_2eproto__INCLUDED
#define PROTOBUF_C_fichier_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003003 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _MessageType MessageType;
typedef struct _ArretUrgence ArretUrgence;
typedef struct _StopMarco StopMarco;
typedef struct _BatteryLevel BatteryLevel;
typedef struct _DeplacementManuel DeplacementManuel;
typedef struct _StatusExplo StatusExplo;
typedef struct _SetExploAlgo SetExploAlgo;
typedef struct _Position Position;
typedef struct _SetExploParam SetExploParam;


/* --- enums --- */


/* --- messages --- */

struct  _MessageType
{
  ProtobufCMessage base;
  uint32_t id;
  ProtobufCBinaryData payload;
};
#define MESSAGE_TYPE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&message_type__descriptor) \
    , 0, {0,NULL} }


struct  _ArretUrgence
{
  ProtobufCMessage base;
  /*
   * État de l'arrêt d'urgence
   */
  uint32_t state;
};
#define ARRET_URGENCE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&arret_urgence__descriptor) \
    , 0 }


struct  _StopMarco
{
  ProtobufCMessage base;
  /*
   * État de l'arrêt de MARCO
   */
  uint32_t state;
};
#define STOP_MARCO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&stop_marco__descriptor) \
    , 0 }


struct  _BatteryLevel
{
  ProtobufCMessage base;
  /*
   * Niveau de la batterie
   */
  uint32_t level;
};
#define BATTERY_LEVEL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&battery_level__descriptor) \
    , 0 }


struct  _DeplacementManuel
{
  ProtobufCMessage base;
  /*
   * Direction du déplacement
   */
  uint32_t direction;
  /*
   * Vitesse du déplacement
   */
  uint32_t speed;
};
#define DEPLACEMENT_MANUEL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&deplacement_manuel__descriptor) \
    , 0, 0 }


struct  _StatusExplo
{
  ProtobufCMessage base;
  /*
   * StatusEnum
   */
  uint32_t status;
  /*
   * pourcentage
   */
  uint32_t pourcentage;
  /*
   * temps
   */
  uint32_t temps;
};
#define STATUS_EXPLO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&status_explo__descriptor) \
    , 0, 0, 0 }


struct  _SetExploAlgo
{
  ProtobufCMessage base;
  /*
   * Algo
   */
  uint32_t algo;
};
#define SET_EXPLO_ALGO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&set_explo_algo__descriptor) \
    , 0 }


struct  _Position
{
  ProtobufCMessage base;
  /*
   * Position X (mm)
   */
  uint32_t x;
  /*
   * Position Y (mm)
   */
  uint32_t y;
};
#define POSITION__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&position__descriptor) \
    , 0, 0 }


struct  _SetExploParam
{
  ProtobufCMessage base;
  /*
   * Type
   */
  uint32_t type;
  /*
   * isEnable
   */
  uint32_t isenable;
  /*
   * value
   */
  uint32_t value;
};
#define SET_EXPLO_PARAM__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&set_explo_param__descriptor) \
    , 0, 0, 0 }


/* MessageType methods */
void   message_type__init
                     (MessageType         *message);
size_t message_type__get_packed_size
                     (const MessageType   *message);
size_t message_type__pack
                     (const MessageType   *message,
                      uint8_t             *out);
size_t message_type__pack_to_buffer
                     (const MessageType   *message,
                      ProtobufCBuffer     *buffer);
MessageType *
       message_type__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   message_type__free_unpacked
                     (MessageType *message,
                      ProtobufCAllocator *allocator);
/* ArretUrgence methods */
void   arret_urgence__init
                     (ArretUrgence         *message);
size_t arret_urgence__get_packed_size
                     (const ArretUrgence   *message);
size_t arret_urgence__pack
                     (const ArretUrgence   *message,
                      uint8_t             *out);
size_t arret_urgence__pack_to_buffer
                     (const ArretUrgence   *message,
                      ProtobufCBuffer     *buffer);
ArretUrgence *
       arret_urgence__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   arret_urgence__free_unpacked
                     (ArretUrgence *message,
                      ProtobufCAllocator *allocator);
/* StopMarco methods */
void   stop_marco__init
                     (StopMarco         *message);
size_t stop_marco__get_packed_size
                     (const StopMarco   *message);
size_t stop_marco__pack
                     (const StopMarco   *message,
                      uint8_t             *out);
size_t stop_marco__pack_to_buffer
                     (const StopMarco   *message,
                      ProtobufCBuffer     *buffer);
StopMarco *
       stop_marco__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   stop_marco__free_unpacked
                     (StopMarco *message,
                      ProtobufCAllocator *allocator);
/* BatteryLevel methods */
void   battery_level__init
                     (BatteryLevel         *message);
size_t battery_level__get_packed_size
                     (const BatteryLevel   *message);
size_t battery_level__pack
                     (const BatteryLevel   *message,
                      uint8_t             *out);
size_t battery_level__pack_to_buffer
                     (const BatteryLevel   *message,
                      ProtobufCBuffer     *buffer);
BatteryLevel *
       battery_level__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   battery_level__free_unpacked
                     (BatteryLevel *message,
                      ProtobufCAllocator *allocator);
/* DeplacementManuel methods */
void   deplacement_manuel__init
                     (DeplacementManuel         *message);
size_t deplacement_manuel__get_packed_size
                     (const DeplacementManuel   *message);
size_t deplacement_manuel__pack
                     (const DeplacementManuel   *message,
                      uint8_t             *out);
size_t deplacement_manuel__pack_to_buffer
                     (const DeplacementManuel   *message,
                      ProtobufCBuffer     *buffer);
DeplacementManuel *
       deplacement_manuel__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   deplacement_manuel__free_unpacked
                     (DeplacementManuel *message,
                      ProtobufCAllocator *allocator);
/* StatusExplo methods */
void   status_explo__init
                     (StatusExplo         *message);
size_t status_explo__get_packed_size
                     (const StatusExplo   *message);
size_t status_explo__pack
                     (const StatusExplo   *message,
                      uint8_t             *out);
size_t status_explo__pack_to_buffer
                     (const StatusExplo   *message,
                      ProtobufCBuffer     *buffer);
StatusExplo *
       status_explo__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   status_explo__free_unpacked
                     (StatusExplo *message,
                      ProtobufCAllocator *allocator);
/* SetExploAlgo methods */
void   set_explo_algo__init
                     (SetExploAlgo         *message);
size_t set_explo_algo__get_packed_size
                     (const SetExploAlgo   *message);
size_t set_explo_algo__pack
                     (const SetExploAlgo   *message,
                      uint8_t             *out);
size_t set_explo_algo__pack_to_buffer
                     (const SetExploAlgo   *message,
                      ProtobufCBuffer     *buffer);
SetExploAlgo *
       set_explo_algo__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   set_explo_algo__free_unpacked
                     (SetExploAlgo *message,
                      ProtobufCAllocator *allocator);
/* Position methods */
void   position__init
                     (Position         *message);
size_t position__get_packed_size
                     (const Position   *message);
size_t position__pack
                     (const Position   *message,
                      uint8_t             *out);
size_t position__pack_to_buffer
                     (const Position   *message,
                      ProtobufCBuffer     *buffer);
Position *
       position__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   position__free_unpacked
                     (Position *message,
                      ProtobufCAllocator *allocator);
/* SetExploParam methods */
void   set_explo_param__init
                     (SetExploParam         *message);
size_t set_explo_param__get_packed_size
                     (const SetExploParam   *message);
size_t set_explo_param__pack
                     (const SetExploParam   *message,
                      uint8_t             *out);
size_t set_explo_param__pack_to_buffer
                     (const SetExploParam   *message,
                      ProtobufCBuffer     *buffer);
SetExploParam *
       set_explo_param__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   set_explo_param__free_unpacked
                     (SetExploParam *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*MessageType_Closure)
                 (const MessageType *message,
                  void *closure_data);
typedef void (*ArretUrgence_Closure)
                 (const ArretUrgence *message,
                  void *closure_data);
typedef void (*StopMarco_Closure)
                 (const StopMarco *message,
                  void *closure_data);
typedef void (*BatteryLevel_Closure)
                 (const BatteryLevel *message,
                  void *closure_data);
typedef void (*DeplacementManuel_Closure)
                 (const DeplacementManuel *message,
                  void *closure_data);
typedef void (*StatusExplo_Closure)
                 (const StatusExplo *message,
                  void *closure_data);
typedef void (*SetExploAlgo_Closure)
                 (const SetExploAlgo *message,
                  void *closure_data);
typedef void (*Position_Closure)
                 (const Position *message,
                  void *closure_data);
typedef void (*SetExploParam_Closure)
                 (const SetExploParam *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor message_type__descriptor;
extern const ProtobufCMessageDescriptor arret_urgence__descriptor;
extern const ProtobufCMessageDescriptor stop_marco__descriptor;
extern const ProtobufCMessageDescriptor battery_level__descriptor;
extern const ProtobufCMessageDescriptor deplacement_manuel__descriptor;
extern const ProtobufCMessageDescriptor status_explo__descriptor;
extern const ProtobufCMessageDescriptor set_explo_algo__descriptor;
extern const ProtobufCMessageDescriptor position__descriptor;
extern const ProtobufCMessageDescriptor set_explo_param__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_fichier_2eproto__INCLUDED */
