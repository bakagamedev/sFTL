#ifndef ADRUTILS_COMPILER_DETECT_H
#define ARDUTILS_COMPILER_DETECT_H

//
// Was hoping to not need one of these,
// but since Arduino isn't quite C++17
// and since I don't want extra work later on
// I'm using macros for future-proofing.
//

#if defined(__GNUC__) && !defined(_MSC_VER) && !defined(__clang__)
#define COMPILER_IS_GCC true

#define USE_IF_COMPILER_IS_GCC(code) code

// Ref Here: https://gcc.gnu.org/onlinedocs/gcc-4.4.1/gcc/Push_002fPop-Macro-Pragmas.html
#define HAS_PRAGMA_PUSH_MACRO true
#define HAS_PRAGMA_POP_MACRO true

#endif

#define COMPILER_IS_GCC false

#define USE_IF_COMPILER_IS_GCC(code)


#if defined(_MSC_VER) && !defined(__GNUC__) && !defined(__clang__)
#define COMPILER_IS_VS true

#define USE_IF_COMPILER_IS_VS(code) code

// Ref Here: https://msdn.microsoft.com/en-us/library/2bs04eza.aspx
#define HAS_PRAGMA_PUSH_MACRO true
// Ref Here: https://msdn.microsoft.com/en-us/library/hsttss76.aspx
#define HAS_PRAGMA_POP_MACRO true

#else

#define COMPILER_IS_VS false

#define USE_IF_COMPILER_IS_VS(code)

#endif

#if !defined(HAS_PRAGMA_PUSH_MACRO)
#define HAS_PRAGMA_PUSH_MACRO false
#endif

#if !defined(HAS_PRAGMA_POP_MACRO)
#define HAS_PRAGMA_POP_MACRO false
#endif

#endif
