/*
 * @file export.h
 * @authors { MaXin , MateBook13 , gzy }
 * @date 2023-04-30
 * @email 2073147469@qq.com
 * @github https://github.com/messi-gzy/Trench.git
 * @brief .
 *
 */
#ifndef TRENCH_EXPORT_H
#define TRENCH_EXPORT_H

#if !defined(TRENCH_EXPORT)

#if defined(TRENCH_SHARED_LIBRARY)
#if defined(_WIN32)

#if defined(TRENCH_COMPILE_LIBRARY)
#define TRENCH_EXPORT __declspec(dllexport)
#else
#define TRENCH_EXPORT __declspec(dllimport)
#endif  // defined(TRENCH_COMPILE_LIBRARY)

#else   // defined(_WIN32)
#if defined(TRENCH_COMPILE_LIBRARY)
#define TRENCH_EXPORT __attribute__((visibility("default")))
#else
#define TRENCH_EXPORT
#endif
#endif  // defined(_WIN32)

#else   // defined(TRENCH_SHARED_LIBRARY)
#define TRENCH_EXPORT
#endif

#endif  // !defined(TRENCH_EXPORT)

#endif  // !TRENCH_EXPORT_H
