/**
 * @file Wex.ixx
 * @author Alex Vergara (alejandromarc@ext.inditex.com)
 * @version 0.1.0
 * @date 2022-01-07
 * @copyright Copyright (c) 2022
 * @brief The core module of the whole framework
 * 
 * This file provides contains the nucleus of the fwk. Here will be documented the most relevant 
 * operations, behaviours and designs relative to the entire project, and declared the structural parts
 * that conforms the core of the FWK.
 */

/// Disabling specific compiler warnings
#pragma warning( disable: 5050 ) 

#include <iostream>

export module Wex;

export {
    [[trying_out::annotations]]
    int foo();
}