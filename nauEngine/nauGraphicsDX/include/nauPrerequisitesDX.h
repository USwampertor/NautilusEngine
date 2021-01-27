/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauPrerequisitesDX.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/31 2018
 * @brief Direct X Prerequisites
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#pragma once

#include <nauPrerequisitesCore.h>

#include <CL/cl_d3d11.h>
#include <CL/cl.hpp>

#include <d3d11.h>
#include <d3dcompiler.h>

/**
 * Library export specifics
 */
#if NAU_PLATFORM == NAU_PLATFORM_WIN32
# if NAU_COMPILER == NAU_COMPILER_MSVC
#   if defined( NAU_STATIC_LIB )
#     define NAU_DIRECTX_EXPORT
#   else
#     if defined( NAU_DIRECTX_EXPORTS )
#       define NAU_DIRECTX_EXPORT __declspec( dllexport )
#     else
#       define NAU_DIRECTX_EXPORT __declspec( dllimport )
#     endif
#   endif
# else //Any other compiler
#   if defined( NAU_STATIC_LIB )
#     define NAU_DIRECTX_EXPORT
#   else
#     if defined( NAU_DIRECTX_EXPORTS )
#       define NAU_DIRECTX_EXPORT __attribute__ ((dllexport))
#     else
#       define NAU_DIRECTX_EXPORT __attribute__ ((dllimport))
#     endif
#   endif
# endif
# define NAU_DIRECTX_HIDDEN
#else //Linux/Mac Settings
# define NAU_DIRECTX_EXPORT __attribute__ ((visibility ("default")))
# define NAU_DIRECTX_HIDDEN __attribute__ ((visibility ("hidden")))
#endif