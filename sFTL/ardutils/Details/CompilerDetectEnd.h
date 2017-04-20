//
// Cleanup all the defines
// because they're implementation details
// that the users shouldn't have to
// care about or know about.
//

#ifdef ADRUTILS_COMPILER_DETECT_H
#undef ARDUTILS_COMPILER_DETECT_H
#endif

#undef COMPILER_IS_VS
#undef USE_IF_COMPILER_IS_VS

#undef COMPILER_IS_GCC
#undef USE_IF_COMPILER_IS_GCC

#undef HAS_PRAGMA_PUSH_MACRO
#undef HAS_PRAGMA_POP_MACRO
