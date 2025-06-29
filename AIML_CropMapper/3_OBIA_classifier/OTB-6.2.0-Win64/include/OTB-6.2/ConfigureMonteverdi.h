/*
 * Copyright (C) 2005-2017 Centre National d'Etudes Spatiales (CNES)
 *
 * This file is part of Orfeo Toolbox
 *
 *     https://www.orfeo-toolbox.org/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ConfigureMonteverdi_h
#define ConfigureMonteverdi_h

//
// Monteverdi project
#define PROJECT_NAME "Monteverdi"

//
// Monteverdi version.
#define Monteverdi_VERSION_MAJOR 6
#define Monteverdi_VERSION_MINOR 2
#define Monteverdi_VERSION_PATCH 0
#define Monteverdi_VERSION_SUFFIX 

#define Monteverdi_VERSION_STRING "6.2.0"

//
// Monteverdi data version.
#define Monteverdi_DATA_VERSION_MAJOR 
#define Monteverdi_DATA_VERSION_MINOR 
#define Monteverdi_DATA_VERSION_PATCH 

#define Monteverdi_DATA_VERSION_STRING ""

//
// Monteverdi data version.
#define Monteverdi_UI_VERSION 1

//
// Directories
#define Monteverdi_INSTALL_BIN_DIR ""
#define Monteverdi_INSTALL_INCLUDE_DIR "include/OTB-6.2"
#define Monteverdi_INSTALL_LIB_DIR ""
#define Monteverdi_INSTALL_DATA_DIR "share/OTB-6.2"

//
#define OTB_VERSION_CHECK( M, m, p )					\
  (OTB_VERSION_MAJOR>(M) ||						\
   (OTB_VERSION_MAJOR==(M) && (OTB_VERSION_MINOR>(m) ||			\
			       OTB_VERSION_MINOR==(m) && OTB_VERSION_PATH>=(p))))

//
#define QWT_IS_ABOVE_6_1 ( QWT_VERSION >= 0x060100 )

//
// Sub-directories
#define Monteverdi_INSTALL_DATA_I18N_DIR Monteverdi_INSTALL_DATA_DIR "/i18n"

//
// Files
#define Monteverdi_CONFIGURE_FILE "ConfigureMonteverdi.h"
#define Monteverdi_BUILD_DIR_FILE "CMakeCache.txt"

//
// Miscellaneous
#define Monteverdi_FLOATING_TYPE float
#define Monteverdi_DIMENSION int( 2 )

//
// Qt Message handling and logging.
#ifndef NO_QECHO
#define NO_QECHO        0
#endif

#ifndef NO_QDEBUG
#define NO_QDEBUG       0
#endif

#ifndef NO_QWARNING
#define NO_QWARNING     0
#endif

#ifndef NO_QCRITICAL
#define NO_QCRITICAL    0
#endif

#ifndef NO_QFATAL
#define NO_QFATAL       0
#endif

#ifndef NO_QLOG
#define NO_QLOG         0
#endif

#ifndef NO_QTHROW
#define NO_QTHROW       0
#endif

#ifndef ECHO_QDEBUG
#define ECHO_QDEBUG     ( ( !NO_QECHO && !NO_QDEBUG && defined( OTB_DEBUG ) && 1 ) || 0 )
#endif

#ifndef ECHO_QWARNING
#define ECHO_QWARNING   ( !NO_QECHO && !NO_QWARNING && 1 )
#endif

#ifndef ECHO_QCRITICAL
#define ECHO_QCRITICAL  ( !NO_QECHO && !NO_QCRITICAL && 1 )
#endif

#ifndef ECHO_QFATAL
#define ECHO_QFATAL     ( !NO_QECHO && !NO_QFATAL && 1 )
#endif

#ifndef LOG_QDEBUG
#define LOG_QDEBUG      ( !NO_QLOG && !NO_QDEBUG && defined( OTB_DEBUG ) && 0 )
#endif

#ifndef LOG_QWARNING
#define LOG_QWARNING    ( !NO_QLOG && !NO_QWARNING && 0 )
#endif

#ifndef LOG_QCRITICAL
#define LOG_QCRITICAL   ( !NO_QLOG && !NO_QCRITICAL && 0 )
#endif

#ifndef LOG_QFATAL
#define LOG_QFATAL      ( !NO_QLOG && !NO_QFATAL && 0 )
#endif

#ifndef THROW_QCRITICAL
#define THROW_QCRITICAL ( !NO_QTHROW && !NO_QCRITICAL && 1 )
#endif

#ifndef THROW_QFATAL
#define THROW_QFATAL    ( !NO_QTHROW && !NO_QFATAL && 1 )
#endif

#include "otbConfigure.h"
#include "otbMacro.h"

//
// Options

// #if (defined( OTB_DEBUG ) && FORCE_DISABLE) || FORCE_ENABLE
#define USE_OPTION_SAMPLE ((defined( OTB_DEBUG )  && 0) || 0)

//
// Macros

#endif // ConfigureMonteverdi_h
