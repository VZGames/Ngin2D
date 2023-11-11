#ifndef COMMONDEFINE_H
#define COMMONDEFINE_H

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <typeinfo>
#include <assert.h>
#include <cstring>
#include <map>
#include <algorithm>
#include <optional>
#include <functional>
#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>

#include <Box2D/box2d.h>


#define ONE_SEC 1000

#define SCREEN_Z 1
#define POPUP_z 1000
#define NOTIFY_Z 1000000

#define SIZE_OF_ARRAY(arr) sizeof(arr)/sizeof(*(arr))
#define stringify(name) # name


#ifdef _WIN32
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#elif __unix
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

#define UNUSED(x) (void)x;

#define NOTHING do{ /*nothing*/ }while(0);

#define BEGIN_NAMESPACE(N) namespace N {
#define END_NAMESPACE }

#endif // COMMONDEFINE_H
