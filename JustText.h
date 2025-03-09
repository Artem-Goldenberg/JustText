#ifndef JustText_h
#define JustText_h

#include "Internal/Internal.h"
#include "Internal/Sequences.h"

/// Simulates an if condition on a macro level.
#define JTIf(detecter, onTrue, onFalse) JTGetThird(detecter, onTrue, onFalse)

/// Converts all args to one string
#define JTString(...) JTApp(JTGetStringForReal, __VA_ARGS__)

/// Counts it's arguments
#define JTCount(...) JTMap(JTOne, +, __VA_ARGS__)

// MARK: - Maps

/// Applies it's first argument to all the rest
#define JTForEach(mapper, ...) JTMap(mapper, JTPseudoNewLine, __VA_ARGS__)

/// Applies first argument to all the rest, and custom glue the results
#define JTMap(mapper, sep, ...) JTMapPlain(mapper, sep, __VA_ARGS__)

/// Maps arguments using a simple separator in-between
#define JTMapPlain(mapper, sep, ...) \
    JTCommonMap(mapper, sep, JTPlainSepExtractor, __VA_ARGS__)

/// Maps arguments, putting comma in-between
#define JTMapComma(mapper, ...) JTMapParenSep(mapper, (,), __VA_ARGS__)

/// Maps arguments, putting unpacked separator in-between
#define JTMapParenSep(mapper, sep, ...) \
    JTCommonMap(mapper, sep, JTParensSepExtractor, __VA_ARGS__)

/// Maps arguments, putting a specifically produced separator in-between
#define JTMapMakeSep(mapper, sep, ...) \
    JTCommonMap(mapper, sep, JTSepProducerExtractor, __VA_ARGS__)

// MARK: - Zips

/// Sequentially applies first argument to two elements from the lists, customly gluing the results.
#define JTZip(zipper, sep, xs, ys) JTZipPlain(zipper, sep, xs, ys)

/// Zips two argument lists, putting user-provided separator in-between
#define JTZipPlain(zipper, sep, xs, ys) \
    JTCommonZip(zipper, sep, JTPlainSepExtractor, xs, JTExpand ys)

/// Zips two argument lists, separating the results by a comma
#define JTZipComma(zipper, xs, ys) \
    JTCommonZip(zipper, (,), JTParensSepExtractor, xs, JTExpand ys)


#endif /* JustText_h */
