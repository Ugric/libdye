
/**
 * @file    dye.h
 * @brief   Definitions of libdye functions, types and constants
 * @author  Aleksey Kuznetsov (kalexey89)
 */

#pragma once

#ifndef LIBDYE_H
#define LIBDYE_H

#include <stdio.h>

#ifndef __cplusplus
#include <stdbool.h>
#ifndef __bool_true_false_are_defined
/** @internal */
#define __bool_true_false_are_defined 1
#define bool int
#define true 1
#define false 0
#endif // !__bool_true_false_are_defined
#endif // !__cplusplus

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/** Color list */
enum dye_color {
  DYE_CURRENT = -2, ///< Use current color
  DYE_RESET = -1,   ///< Reset to default color
  DYE_BLACK = 0,    ///< Black
  DYE_NAVYBLUE = 1, ///< Navy Blue
  DYE_GREEN = 2,    ///< Green
  DYE_CYAN = 3,     ///< Cyan
  DYE_MAROON = 4,   ///< Maroon
  DYE_PURPLE = 5,   ///< Purple
  DYE_OLIVE = 6,    ///< Olive
  DYE_SILVER = 7,   ///< Silver
  DYE_GREY = 8,     ///< Grey
  DYE_GRAY = 8,     ///< Grey
  DYE_BLUE = 9,     ///< Blue
  DYE_LIME = 10,    ///< Lime
  DYE_TEAL = 11,    ///< Teal
  DYE_RED = 12,     ///< Red
  DYE_MAGENTA = 13, ///< Magenta
  DYE_YELLOW = 14,  ///< Yellow
  DYE_WHITE = 15    ///< White
};

enum dye_style {
  DYE_STYLE_RESET = 0,
  DYE_STYLE_BOLD = 1,
  DYE_STYLE_ITALIC = 3,
  DYE_STYLE_UNDER = 4,
  DYE_STYLE_REVERSE = 7,
  DYE_STYLE_STRIKE = 9
};

/** Output stream color id */
typedef enum dye_color dye_color_t;
/** Output stream style id */
typedef enum dye_style dye_style_t;
/** Output stream handle */
typedef FILE *dye_tty_t;

/**
 * @brief Applies the given text style to the specified @c tty output stream
 * @param[in] tty   Output stream (e.g., @c stdout or @c stderr)
 * @param[in] style Text style from the @c dye_style_t enum (e.g., bold, italic,
 * underline)
 * @return true if the style was successfully applied (i.e., ANSI sequences were
 * emitted and flushed); false if the terminal doesn't support styles, the write
 * failed, or on unsupported platforms (e.g., Windows)
 *
 * On POSIX systems, this emits the corresponding ANSI escape sequence to enable
 * the style if the terminal supports it. On unsupported platforms, this function
 * does nothing and returns false.
 */
bool dye_style(dye_tty_t tty, dye_style_t style);

/**
 * @brief Sets @c fg and @c bg colors respectively as foreground and background
 * to the @c tty output stream
 * @param[in] tty Output stream
 * @param[in] fg  Foreground color
 * @param[in] bg  Background color
 * @return true if success, false othervise
 */
extern bool dye(dye_tty_t tty, dye_color_t fg, dye_color_t bg);

/**
 * @def dyefg(tty, fg)
 * @brief Sets @c fg as foreground color to the @c tty output stream
 * @param[in] tty Output stream
 * @param[in] fg  Foreground color
 * @return true if success, false othervise
 */
#define dyefg(tty, fg) dye((tty), (fg), DYE_CURRENT);

/**
 * @def dyebg(tty, bg)
 * @brief Sets @c bg as a background color to the @c tty output stream
 * @param[in] tty Output stream
 * @param[in] bg  Background color
 * @return true if success, false othervise
 */
#define dyebg(tty, bg) dye((tty), DYE_CURRENT, (bg));

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !LIBDYE_H
