#define DO_EXPAND(VAL)  VAL ## 1
#define EXPAND(VAL)     DO_EXPAND(VAL)

#if (EXPAND(DEBUG_SKETCH) == 1)
  #undef DEBUG_SKETCH
  #define DEBUG_SKETCH Serial
#endif

#if defined(DEBUG_SKETCH)
  #define DPRINT(...)   DEBUG_SKETCH.print(__VA_ARGS__)
  #define DPRINTLN(...) DEBUG_SKETCH.println(__VA_ARGS__)
#else
  #define DPRINT(...)
  #define DPRINTLN(...)
#endif