#ifndef _H_LIB_OSU_INC
#define _H_LIB_OSU_INC

#ifdef __cplusplus
#define OSU_NAMESPACE_BEGIN \
namespace osu { \
extern "C" {
#define OSU_NAMESPACE_END \
} \
}
#else
#define OSU_NAMESPACE_BEGIN
#define OSU_NAMESPACE_END
#endif

#endif