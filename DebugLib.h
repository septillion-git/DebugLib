#define DO_EXPAND(VAL)  VAL ## 1
#define EXPAND(VAL)     DO_EXPAND(VAL)

#if (EXPAND(DEBUG_SKETCH) == 1)
  #undef DEBUG_SKETCH
  #define DEBUG_SKETCH Serial
#endif

#if defined(DEBUG_SKETCH)
  #define DBEGIN(...)       DEBUG_SKETCH.begin(__VA_ARGS__)
  #define DPRINT(...)       DEBUG_SKETCH.print(__VA_ARGS__)
  #define DPRINTLN(...)     DEBUG_SKETCH.println(__VA_ARGS__)
  #define DPRINTF(x,...)    DEBUG_SKETCH.print(F(x),##__VA_ARGS__)
  #define DPRINTFLN(x,...)  DEBUG_SKETCH.println(F(x),##__VA_ARGS__)
#else
  #define DBEGIN(...)
  #define DPRINT(...)
  #define DPRINTLN(...)
  #define DPRINTF(x,...)
  #define DPRINTFLN(x,...)
#endif