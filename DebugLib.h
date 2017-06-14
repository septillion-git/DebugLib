#if defined ( ESP8266 )
  #include <pgmspace.h>
#else
  #include <avr/pgmspace.h>
#endif
#include "Arduino.h"

#define DEBUG_DO_EXPAND(VAL)  VAL ## 1
#define DEBUG_EXPAND(VAL)     DEBUG_DO_EXPAND(VAL)

#if (DEBUG_EXPAND(DEBUG_SKETCH) == 1)
  #undef DEBUG_SKETCH
  #define DEBUG_SKETCH Serial
#endif

#if defined(DEBUG_SKETCH)
  #define DBEGIN(...)       DEBUG_SKETCH.begin(__VA_ARGS__)
  #define DPRINT(...)       DEBUG_SKETCH.print(__VA_ARGS__)
  #define DPRINTLN(...)     DEBUG_SKETCH.println(__VA_ARGS__)
  #define DPRINTF(x,...)    DEBUG_SKETCH.print(F(x),##__VA_ARGS__)
  #define DPRINTFLN(x,...)  DEBUG_SKETCH.println(F(x),##__VA_ARGS__)
  
  #define DPRINTVAL(x,y)    DEBUG_SKETCH.print(F(x": "));\
                            DEBUG_SKETCH.println(y)
  #define DPRINTHVAL(x,y)   DebugLib::valFunction(F(x":"),(unsigned long)y,HEX)
  #define DPRINTBVAL(x,y)   DebugLib::valFunction(F(x":"),(unsigned long)y,BIN)
  #define DPRINTHBVAL(x,y)  DebugLib::valFunction(F(x":"),(unsigned long)y,DebugLib::HEXBIN)
#else
  #define DBEGIN(...)
  #define DPRINT(...)
  #define DPRINTLN(...)
  #define DPRINTF(x,...)
  #define DPRINTFLN(x,...)
  #define DPRINTVAL(x,y)
  #define DPRINTHVAL(x,y)
  #define DPRINTBVAL(x,y)
  #define DPRINTHBVAL(x,y)
#endif

#ifndef DEBUG_LIB_H
#define DEBUG_LIB_H
namespace DebugLib{
  const char HexTxt[] PROGMEM = " 0x";
  const char BinTxt[] PROGMEM = " 0b";
  enum varType{HEXBIN = 100};
  
  void valFunction(const __FlashStringHelper * Txt, unsigned long val, uint8_t type){
    DPRINT(Txt);
    if(type == HEX || type == HEXBIN){
      DPRINT((const __FlashStringHelper*)HexTxt);
      DPRINT(val, HEX);
    }
    if(type == BIN || type == HEXBIN){
      DPRINT((const __FlashStringHelper*)BinTxt);
      DPRINT(val, BIN);
    }
    DPRINTLN();
  }
}
#endif