/**
 * \mainpage Shark Machine Learning Library Ver. 3.0.0.
 * Shark is a modular C++ library for the design and
 * optimization of adaptive systems. It provides methods for linear
 * and nonlinear optimization, in particular evolutionary and
 * gradient-based algorithms, kernel-based learning algorithms and
 * neural networks, and various other machine learning
 * techniques. SHARK serves as a toolbox to support real world
 * applications as well as research in different domains of
 * computational intelligence and machine learning. The sources are
 * compatible with the following platforms: Windows, Solaris, MacOS X,
 * and Linux.
 *
 *  \date    2011
 *
 * \par Copyright 1995-2015 Shark Development Team
 * 
 * <BR><HR>
 * This file is part of Shark.
 * <http://image.diku.dk/shark/>
 * 
 * Shark is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published 
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Shark is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with Shark.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef SHARK_CORE_SHARK_H
#define SHARK_CORE_SHARK_H

#include <boost/version.hpp>
#include <boost/static_assert.hpp>

/**
 * \brief Bails out the compiler if the boost version is < 1.44.
 */
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    BOOST_STATIC_ASSERT( BOOST_VERSION >= 104400 );
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
#include <boost/assign.hpp>
#include <boost/config.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <iostream>
#include <map>
#include <string>

namespace shark {

/**
 * \namespace General namespace of the whole Shark machine learning library.
 */

/**
 * \brief Models the build type.
 */
enum BuildType {
  RELEASE_BUILD_TYPE, ///< A release build.
  DEBUG_BUILD_TYPE ///< A debug build.
};

namespace tag {

/**
 * \namespace tag Tagging namespace for type-based dispatching.
 */

/**
 * \brief Tags the build type.
 */
struct BuildTypeTag {
  /**
   * \brief The build settings that the library has been compiled with.
   */
#if defined( _DEBUG ) || defined( DEBUG )
  static const BuildType VALUE = DEBUG_BUILD_TYPE;
#else
  static const BuildType VALUE = RELEASE_BUILD_TYPE;
#endif
};

/**
 * \brief Tags whether this is a dynamic build
 */
 #define SHARK_USE_DYNLIB
struct DynamicLibraryTag{
  /**
   * \brief Whether this is a dynamic or static build of Shark
   */
#ifdef SHARK_USE_DYNLIB
  static const bool VALUE = true;
#else
  static const bool VALUE = false;
#endif
};

/**
 * \brief Tags whether BLAS has been enabled.
 */
/* #undef SHARK_USE_CBLAS */

 /**
 * \brief Tags whether full LAPACK is available
 */
/* #undef SHARK_USE_LAPACK */

 /**
 * \brief Tags whether the LAPACK portion of ATLAS is used
 */
/* #undef SHARK_USE_ATLAS_LAPACK */

/**
 * \brief Tags whether OpenMP has been enabled.
 */
/* #undef SHARK_USE_OPENMP */
struct OpenMpTag {
#ifdef _OPENMP
  static const bool VALUE = true;
#else
  static const bool VALUE = false;
#endif
};

/**
 * \brief Tags official releases of the shark library.
 */
struct OfficialReleaseTag {
#ifdef SHARK_OFFICIAL_RELEASE
  static const bool VALUE = true;
#else
  static const bool VALUE = false;
#endif
};

}

/**
 * \brief Allows for querying compile settings at runtime. Provides the
 * current command line arguments to the rest of the library.
 */
class Shark {
 protected:
  // Not implemented
  Shark();
  Shark( const Shark & shark );
  Shark & operator=( const Shark & rhs );
 public:

  /**
   * \brief Models a version according to the major.minor.patch versioning scheme.
   */
  template<unsigned int major, unsigned int minor, unsigned int patch>
  struct Version {

    /** \brief Default printf-format for formatting version numbers. */
    static const char * DEFAULT_FORMAT() {
      return( "%d.%d.%d" );
    }

    /** @brief Returns the major revision number. */
    static unsigned int MAJOR() {
      return( major );
    }

    /** @brief Returns the minor revision number. */
    static unsigned int MINOR() {
      return( minor );
    }

    /** @brief Returns the patch revision number. */
    static unsigned int PATCH() {
      return( patch );
    }

  };

  /**
   * \brief Marks the current version of the Shark Machine Learning Library.
   */
  typedef Version<
    3,
    0,
    0
  > version_type;

  /**
   * \brief Marks the boost version Shark has been built against.
   */
  typedef Version<
    BOOST_VERSION / 100000,
    ((BOOST_VERSION / 100) % 1000),
    (BOOST_VERSION % 100)
    > boost_version_type;

  /**
   * \brief Accesses the build type of the library.
   */
  static BuildType buildType() {
    return( tag::BuildTypeTag::VALUE );
  }

  /**
   * \brief Queries whether Shark has been compiled with OpenMP enabled.
   */
  static bool hasOpenMp() {
    return( tag::OpenMpTag::VALUE );
  }
  
  /**
   * \brief Queries whether Shark has been compiled as dynamic library
   */
  static bool isDynamicLibrary() {
    return( tag::DynamicLibraryTag::VALUE );
  }

  /**
   * \brief Checks whether this is an official Shark release.
   */
  static bool isOfficialRelease() {
    return( tag::OfficialReleaseTag::VALUE );
  }

  /**
   * \brief Prints information about the Shark Machine Learning Library to the supplied stream.
   */
  template<typename Stream>
  static void info( Stream & s ) {
    std::map< BuildType, std::string > buildTypeMap = boost::assign::map_list_of( RELEASE_BUILD_TYPE, "Release" )( DEBUG_BUILD_TYPE, "Debug" );

    boost::property_tree::ptree pt, version;
    version.add("major", version_type::MAJOR());
    version.add("minor", version_type::MINOR());
    version.add("patch", version_type::PATCH());

    pt.add_child("version", version);
    pt.add("isOfficialRelease", isOfficialRelease());
    pt.add("platform", BOOST_PLATFORM);
    pt.add("compiler", BOOST_COMPILER);
    pt.add("stdLib", BOOST_STDLIB);
    version.put("major", boost_version_type::MAJOR());
    version.put("minor", boost_version_type::MINOR());
    version.put("patch", boost_version_type::PATCH());
    pt.add_child("boostVersion", version);
    pt.add("buildType", buildTypeMap[buildType()]);
    pt.add("dynamicBuild", isDynamicLibrary());
    pt.add("hasOpenMp", hasOpenMp());

    boost::property_tree::write_json(s, pt);
  }

};

}

#endif
