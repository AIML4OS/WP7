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

#ifndef otb_shark_h
#define otb_shark_h

#include "otbConfigure.h"

#ifndef OTB_USE_SHARK
#  error "You need to enable Shark to compile this file"
#endif


/* These defines are taken from shark CMakeLists.txt.
 * I am not sure they are required when linking shark which 
 * link with boost. But the fact that they are not optional 
 * in shark puts them here.
 */
#define BOOST_PARAMETER_MAX_ARITY 15
#define BOOST_FILESYSTEM_VERSION 3
 
/* without having a compile definition will give an linker error
 * when build otbapp_TrainImagesClassifier or this header test.
 * So define them depending on wheather you have static or shared
 * build of boost.
 *
 * Below is an error message if you don't have define
 * LINK : fatal error LNK1104: cannot open file 'libboost_serialization-vc140-mt-1_60.lib'
 * and in the install directory there is no libboost_serialization-vc140-mt-1_60.lib
 * but only boost_serialization-vc140-mt-1_60.lib and this is the cause of boost's
 * auto-linking.
 */


/* #undef Boost_USE_STATIC_LIBS */

#if !defined(Boost_USE_STATIC_LIBS) && !defined(BOOST_ALL_DYN_LINK)
  #define BOOST_ALL_DYN_LINK
#endif

/* disable autolinking in boost on windows */
#if defined(_WIN32) && !defined(BOOST_ALL_NO_LIB)
  #define BOOST_ALL_NO_LIB
#endif


/* see which libraries are being linked in case of auto-linking,
 * BOOST_LIB_DIAGNOSTIC will emit a #pragma message each time 
 * a library is selected for linking.
 *
 * #if defined(_MSC_VER) && defined(OTB_DEBUG) && !defined(BOOST_LIB_DIAGNOSTIC)
 * #define BOOST_LIB_DIAGNOSTIC
 * #endif
 *
 */

#endif /* otb_shark_h */
