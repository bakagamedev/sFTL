#ifndef ADRUTILS_COMPILER_TRAITS_H
#define ARDUTILS_COMPILER_TRAITS_H

//
// Certain type traits require
// compiler extensions.
//

#include "CompilerDetectStart.h"

#if COMPILER_IS_GCC

// Ref Here: https://gcc.gnu.org/onlinedocs/gcc/Type-Traits.html

#define COMPILER_TRAIT_HAS_NOTHROW_ASSIGN(type) __has_nothrow_assign(type)
#define HAS_COMPILER_TRAIT_HAS_NOTHROW_ASSIGN true

#define COMPILER_TRAIT_HAS_NOTHROW_COPY(type) __has_nothrow_copy(type)
#define HAS_COMPILER_TRAIT_HAS_NOTHROW_COPY true

#define COMPILER_TRAIT_HAS_NOTHROW_CONSTRUCTOR(type) __has_nothrow_constructor(type)
#define HAS_COMPILER_TRAIT_HAS_NOTHROW_CONSTRUCTOR true


#define COMPILER_TRAIT_HAS_TRIVIAL_ASSIGN(type) __has_trivial_assign(type)
#define HAS_COMPILER_TRAIT_HAS_TRIVIAL_ASSIGN true

#define COMPILER_TRAIT_HAS_TRIVIAL_COPY(type) __has_trivial_copy(type)
#define HAS_COMPILER_TRAIT_HAS_TRIVIAL_COPY true

#define COMPILER_TRAIT_HAS_TRIVIAL_CONSTRUCTOR(type) __has_trivial_constructor(type)
#define HAS_COMPILER_TRAIT_HAS_TRIVIAL_CONSTRUCTOR true

#define COMPILER_TRAIT_HAS_TRIVIAL_DESTRUCTOR(type) __has_trivial_destructor(type)
#define HAS_COMPILER_TRAIT_HAS_TRIVIAL_DESTRUCTOR true


#define COMPILER_TRAIT_HAS_VIRTUAL_DESTRUCTOR(type) __has_virtual_destructor(type)
#define HAS_COMPILER_TRAIT_HAS_VIRTUAL_DESTRUCTOR true


#define COMPILER_TRAIT_IS_ABSTRACT(type) __is_abstract(type)
#define HAS_COMPILER_TRAIT_IS_ABSTRACT true

#define COMPILER_TRAIT_IS_BASE_OF(baseType, derivedType) __is_base_of(baseType, derivedType)
#define HAS_COMPILER_TRAIT_IS_BASE_OF true

#define COMPILER_TRAIT_IS_CLASS(type) __is_class(type)
#define HAS_COMPILER_TRAIT_IS_CLASS true

#define COMPILER_TRAIT_IS_EMPTY(type) __is_empty(type)
#define HAS_COMPILER_TRAIT_IS_EMPTY true

#define COMPILER_TRAIT_IS_ENUM(type) __is_enum(type)
#define HAS_COMPILER_TRAIT_IS_ENUM true

#define COMPILER_TRAIT_IS_LITERAL_TYPE(type) __is_literal_type(type)
#define HAS_COMPILER_TRAIT_IS_LITERAL_TYPE true

#define COMPILER_TRAIT_IS_POD(type) __is_pod(type)
#define HAS_COMPILER_TRAIT_IS_POD true

#define COMPILER_TRAIT_IS_POLYMORPHIC(type) __is_polymorphic(type)
#define HAS_COMPILER_TRAIT_IS_POLYMORPHIC true

#define COMPILER_TRAIT_IS_STANDARD_LAYOUT(type) __is_standard_layout(type)
#define HAS_COMPILER_TRAIT_IS_STANDARD_LAYOUT true

#define COMPILER_TRAIT_IS_TRIVIAL(type) __is_trivial(type)
#define HAS_COMPILER_TRAIT_IS_TRIVIAL true

#define COMPILER_TRAIT_IS_UNION(type) __is_union(type)
#define HAS_COMPILER_TRAIT_IS_UNION true

#define COMPILER_TRAIT_UNDERLYING_TYPE(type) __underlying_type(type)
#define HAS_COMPILER_TRAIT_UNDERLYING_TYPE true

#define COMPILER_TRAIT_ALIGNOF(type) __alignof__(type)
#define HAS_COMPILER_TRAIT_ALIGNOF true

#elif COMPILER_IS_VS

// Ref Here: https://msdn.microsoft.com/en-us/library/ms177194.aspx

#define COMPILER_TRAIT_HAS_NOTHROW_ASSIGN(type) __has_nothrow_assign(type)
#define HAS_COMPILER_TRAIT_HAS_NOTHROW_ASSIGN true

#define COMPILER_TRAIT_HAS_NOTHROW_COPY(type) __has_nothrow_copy(type)
#define HAS_COMPILER_TRAIT_HAS_NOTHROW_COPY true

#define COMPILER_TRAIT_HAS_NOTHROW_CONSTRUCTOR(type) __has_nothrow_constructor(type)
#define HAS_COMPILER_TRAIT_HAS_NOTHROW_CONSTRUCTOR true


#define COMPILER_TRAIT_HAS_TRIVIAL_ASSIGN(type) __has_trivial_assign(type)
#define HAS_COMPILER_TRAIT_HAS_TRIVIAL_ASSIGN true

#define COMPILER_TRAIT_HAS_TRIVIAL_COPY(type) __has_trivial_copy(type)
#define HAS_COMPILER_TRAIT_HAS_TRIVIAL_COPY true

#define COMPILER_TRAIT_HAS_TRIVIAL_CONSTRUCTOR(type) __has_trivial_constructor(type)
#define HAS_COMPILER_TRAIT_HAS_TRIVIAL_CONSTRUCTOR true

#define COMPILER_TRAIT_HAS_TRIVIAL_DESTRUCTOR(type) __has_trivial_destructor(type)
#define HAS_COMPILER_TRAIT_HAS_TRIVIAL_DESTRUCTOR true


#define COMPILER_TRAIT_HAS_VIRTUAL_DESTRUCTOR(type) __has_virtual_destructor(type)
#define HAS_COMPILER_TRAIT_HAS_VIRTUAL_DESTRUCTOR true


#define COMPILER_TRAIT_IS_ABSTRACT(type) __is_abstract(type)
#define HAS_COMPILER_TRAIT_IS_ABSTRACT true

#define COMPILER_TRAIT_IS_BASE_OF(baseType, derivedType) __is_base_of(baseType, derivedType)
#define HAS_COMPILER_TRAIT_IS_BASE_OF true

#define COMPILER_TRAIT_IS_CLASS(type) __is_class(type)
#define HAS_COMPILER_TRAIT_IS_CLASS true

#define COMPILER_TRAIT_IS_EMPTY(type) __is_empty(type)
#define HAS_COMPILER_TRAIT_IS_EMPTY true

#define COMPILER_TRAIT_IS_ENUM(type) __is_enum(type)
#define HAS_COMPILER_TRAIT_IS_ENUM true

#define COMPILER_TRAIT_IS_LITERAL_TYPE(type) __is_literal_type(type)
#define HAS_COMPILER_TRAIT_IS_LITERAL_TYPE true

#define COMPILER_TRAIT_IS_POD(type) __is_pod(type)
#define HAS_COMPILER_TRAIT_IS_POD true

#define COMPILER_TRAIT_IS_POLYMORPHIC(type) __is_polymorphic(type)
#define HAS_COMPILER_TRAIT_IS_POLYMORPHIC true

#define COMPILER_TRAIT_IS_STANDARD_LAYOUT(type) __is_standard_layout(type)
#define HAS_COMPILER_TRAIT_IS_STANDARD_LAYOUT true

#define COMPILER_TRAIT_IS_TRIVIAL(type) __is_trivial(type)
#define HAS_COMPILER_TRAIT_IS_TRIVIAL true

#define COMPILER_TRAIT_IS_UNION(type) __is_union(type)
#define HAS_COMPILER_TRAIT_IS_UNION true

#define COMPILER_TRAIT_UNDERLYING_TYPE(type) __underlying_type(type)
#define HAS_COMPILER_TRAIT_UNDERLYING_TYPE true

#if _MSC_VER >= 1900
#define COMPILER_TRAIT_ALIGNOF(type) alignof(type)
#define HAS_COMPILER_TRAIT_ALIGNOF true
#else
#define COMPILER_TRAIT_ALIGNOF(type) __alignof(type)
#define HAS_COMPILER_TRAIT_ALIGNOF true
#endif

#define COMPILER_TRAIT_IS_CONVERTIBLE_TO(from, to) __is_convertible_to(from, to)
#define HAS_COMPILER_TRAIT_IS_CONVERTIBLE_TO true

//#define COMPILER_TRAIT_HAS_ASSIGN(type) __has_assign(type)
//#define COMPILER_TRAIT_HAS_COPY(type) __has_copy(type)

// #define COMPILER_TRAIT_IS_DELEGATE(type) __is_delegate(type)
// #define COMPILER_TRAIT_HAS_USER_DESTRUCTOR(type) __has_user_destructor(type)
// #define COMPILER_TRAIT_IS_INTERFACE_CLASS(type) __is_interface_class
// #define COMPILER_TRAIT_IS_REF_ARRAY(type) __is_ref_array(type)
// #define COMPILER_TRAIT_IS_REF_CLASS(type) __is_ref_class(type)
// #define COMPILER_TRAIT_IS_SEALED(type) __is_sealed(type)

#endif

#if !defined(HAS_COMPILER_TRAIT_HAS_NOTHROW_ASSIGN)
#define HAS_COMPILER_TRAIT_HAS_NOTHROW_ASSIGN false
#endif

#if !defined(HAS_COMPILER_TRAIT_HAS_NOTHROW_COPY)
#define HAS_COMPILER_TRAIT_HAS_NOTHROW_COPY false
#endif

#if !defined(HAS_COMPILER_TRAIT_HAS_NOTHROW_CONSTRUCTOR)
#define HAS_COMPILER_TRAIT_HAS_NOTHROW_CONSTRUCTOR false
#endif


#if !defined(HAS_COMPILER_TRAIT_HAS_TRIVIAL_ASSIGN)
#define HAS_COMPILER_TRAIT_HAS_TRIVIAL_ASSIGN false
#endif

#if !defined(HAS_COMPILER_TRAIT_HAS_TRIVIAL_COPY)
#define HAS_COMPILER_TRAIT_HAS_TRIVIAL_COPY false
#endif

#if !defined(HAS_COMPILER_TRAIT_HAS_TRIVIAL_CONSTRUCTOR)
#define HAS_COMPILER_TRAIT_HAS_TRIVIAL_CONSTRUCTOR false
#endif

#if !defined(HAS_COMPILER_TRAIT_HAS_TRIVIAL_DESTRUCTOR)
#define HAS_COMPILER_TRAIT_HAS_TRIVIAL_DESTRUCTOR false
#endif


#if !defined(HAS_COMPILER_TRAIT_HAS_VIRTUAL_DESTRUCTOR)
#define HAS_COMPILER_TRAIT_HAS_VIRTUAL_DESTRUCTOR false
#endif


#if !defined(HAS_COMPILER_TRAIT_IS_ABSTRACT)
#define HAS_COMPILER_TRAIT_IS_ABSTRACT false
#endif

#if !defined(HAS_COMPILER_TRAIT_IS_BASE_OF)
#define HAS_COMPILER_TRAIT_IS_BASE_OF false
#endif

#if !defined(HAS_COMPILER_TRAIT_IS_CLASS)
#define HAS_COMPILER_TRAIT_IS_CLASS false
#endif

#if !defined(HAS_COMPILER_TRAIT_IS_EMPTY)
#define HAS_COMPILER_TRAIT_IS_EMPTY false
#endif

#if !defined(HAS_COMPILER_TRAIT_IS_ENUM)
#define HAS_COMPILER_TRAIT_IS_ENUM false
#endif

#if !defined(HAS_COMPILER_TRAIT_IS_LITERAL_TYPE)
#define HAS_COMPILER_TRAIT_IS_LITERAL_TYPE false
#endif

#if !defined(HAS_COMPILER_TRAIT_IS_POD)
#define HAS_COMPILER_TRAIT_IS_POD false
#endif

#if !defined(HAS_COMPILER_TRAIT_IS_POLYMORPHIC)
#define HAS_COMPILER_TRAIT_IS_POLYMORPHIC false
#endif

#if !defined(HAS_COMPILER_TRAIT_IS_STANDARD_LAYOUT)
#define HAS_COMPILER_TRAIT_IS_STANDARD_LAYOUT false
#endif

#if !defined(HAS_COMPILER_TRAIT_IS_TRIVIAL)
#define HAS_COMPILER_TRAIT_IS_TRIVIAL false
#endif

#if !defined(HAS_COMPILER_TRAIT_IS_UNION)
#define HAS_COMPILER_TRAIT_IS_UNION false
#endif

#if !defined(HAS_COMPILER_TRAIT_UNDERLYING_TYPE)
#define HAS_COMPILER_TRAIT_UNDERLYING_TYPE false
#endif

#if !defined(HAS_COMPILER_TRAIT_ALIGNOF)
#define HAS_COMPILER_TRAIT_ALIGNOF false
#endif

#if !defined(HAS_COMPILER_TRAIT_IS_CONVERTIBLE_TO)
#define HAS_COMPILER_TRAIT_IS_CONVERTIBLE_TO false
#endif

#endif
