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
- [ ] TypeTraits.h
- [ ] CStdDef.h
- [ ] Possibly Rename Vector2 to Vector
- [ ] Possibly Rename Point2 to Point
- [ ] Rectangle.h
- [ ] Circle.h
