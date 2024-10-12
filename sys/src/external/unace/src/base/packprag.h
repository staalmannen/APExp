/**************************************************************************/
/* (this is not used)                                                      */
/* packprag.h: declares pragmas for alignment settings                    */
/*                                                                        */
/**************************************************************************/

#ifdef SETALIGNMENT
  #undef SETALIGNMENT

  #if ( defined(__MACOSX__) || defined(__sun__) )
    #define RESTOREALIGNMENTOFF
    #pragma pack(4)
  #elif defined(__WATCOMC__) || defined(__GNUC__)
    #pragma pack(push, 4)
  #endif
#endif


#ifdef SETNOALIGNMENT
  #undef SETNOALIGNMENT

  #if defined( __MACOSX__ ) || defined( __sun__ )
    #define RESTOREALIGNMENTON
    #pragma pack(1)
  #elif defined(__WATCOMC__) || defined(__GNUC__)
    #pragma pack(push, 1)
  #endif
#endif


#ifdef RESTOREALIGNMENT
  #undef RESTOREALIGNMENT
  #if defined(__MACOSX__) || defined(__sun__)
    #ifdef RESTOREALIGNMENTOFF
      #undef RESTOREALIGNMENTOFF
      #pragma pack(1)
    #endif
    #ifdef RESTOREALIGNMENTON
      #undef RESTOREALIGNMENTON
      #pragma pack(4)
    #endif
  #elif defined(__WATCOMC__) || defined(__GNUC__)
    #pragma pack(pop)
  #endif
#endif
