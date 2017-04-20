# Ardutils
A simple lightweight utility library intended for use with Arduino and Arduboy projects.

**_Work In Progress_**
(i.e. Please don't complain if a change breaks your code)

## About

This library provides highly generic utilities to that should be suitable for all kinds of programs.
Most of the classes and functions provided are templated so that they're only instantiated as required.
Many classes are also designed to favour size over speed as they are designed for embedded environments.

## Aims

- Code should feature primarily general purpose utilities rather than domain-specific utilities.
- Compiled code should be as small as possible so that the library is lightweight.
- Code should be templated to provide flexibility and genericity.
- All code should be const correct.

## Planned Features

- [ ] WrappedValue.h
- [ ] StaticWrappedValue.h
- [x] TypeTraits.h
- [ ] CStdDef.h
- [ ] Possibly Rename Vector2 to Vector
- [ ] Possibly Rename Point2 to Point
- [x] Rectangle.h
- [ ] Circle.h
- [ ] Dequeue

## To Do

- [ ] Fix Rectangle's Offset function for unsigned numbers.

***

# Features

## Point2 & Vector2

Simple point and vector classes.
To use these properly, remember that a point represents a point in space and a vector represents a direction,
therefore it only makes sense to add a vector to a point, and it does not make sense to add a point to a vector.

## List, Stack, Queue

Simple fixed-capacity, variable content collection classes.
Lists are add-to end, remove anywhere, resize on removal.
Stacks are first-in last-out.
Queues are first-in first-out.

## Clamped Values

Used for numeric types where the acceptable range of values must be clamped between a minimum and a maximum.
Available in two forms, one where min and max can vary and one where min and max are defined at compile time in the template itself.

## Range

A simple means of expressing a range of integer values.

## Rectangle

Represents a rectangle with its origin at the top left corner.

## Type Traits

A minimal implementation of some of the traits normally available via the C++ stdlib (which Arduino doesn't have).
These are mainly used for compile time assertions, optimisations and other advanced techniques.

***

# Notices

## Ardutils/Details

Please do not touch the things in the Details folder.
These are implementation details that are both unfinished and are very likely to change so they will probably break your code.

## Ardutils/TypeTraits

It is also considered bad to try to include anything from the TypeTraits folder in your own code.
It probably won't break in most cases, but it has the potential to break in the future due to changing dependencies.
