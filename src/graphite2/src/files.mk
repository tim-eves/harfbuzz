# SPDX-License-Identifier: MIT
# Copyright 2011, SIL International, All rights reserved.

# Makefile helper file for those wanting to build Graphite2 using make
# The including makefile should set the following variables
# _NS               Prefix to all variables this file creates (namespace)
# $(_NS)_MACHINE    Set to direct or call. Set to direct if using gcc else
#                   set to call
# $(_NS)_BASE       path to root of graphite2 project
#
# Returns:
# $(_NS)_SOURCES    List of source files (with .cpp extension)
# $(_NS)_PRIVATE_HEADERS    List of private header files (with .h extension)
# $(_NS)_PUBLIC_HEADERS     List of public header files (with .h extension)


$(_NS)_SOURCES = \
    $($(_NS)_BASE)/src/$($(_NS)_MACHINE)_machine.cpp \
    $($(_NS)_BASE)/src/gr_char_info.cpp \
    $($(_NS)_BASE)/src/gr_face.cpp \
    $($(_NS)_BASE)/src/gr_features.cpp \
    $($(_NS)_BASE)/src/gr_font.cpp \
    $($(_NS)_BASE)/src/gr_logging.cpp \
    $($(_NS)_BASE)/src/gr_segment.cpp \
    $($(_NS)_BASE)/src/gr_slot.cpp \
    $($(_NS)_BASE)/src/json.cpp \
    $($(_NS)_BASE)/src/CmapCache.cpp \
    $($(_NS)_BASE)/src/Code.cpp \
    $($(_NS)_BASE)/src/Collider.cpp \
    $($(_NS)_BASE)/src/Decompressor.cpp \
    $($(_NS)_BASE)/src/Face.cpp \
    $($(_NS)_BASE)/src/FeatureMap.cpp \
    $($(_NS)_BASE)/src/FileFace.cpp \
    $($(_NS)_BASE)/src/Font.cpp \
    $($(_NS)_BASE)/src/GlyphCache.cpp \
    $($(_NS)_BASE)/src/GlyphFace.cpp \
    $($(_NS)_BASE)/src/Intervals.cpp \
    $($(_NS)_BASE)/src/Justifier.cpp \
    $($(_NS)_BASE)/src/NameTable.cpp \
    $($(_NS)_BASE)/src/Pass.cpp \
    $($(_NS)_BASE)/src/Position.cpp \
    $($(_NS)_BASE)/src/Segment.cpp \
    $($(_NS)_BASE)/src/Silf.cpp \
    $($(_NS)_BASE)/src/Slot.cpp \
    $($(_NS)_BASE)/src/Sparse.cpp \
    $($(_NS)_BASE)/src/TtfUtil.cpp \
    $($(_NS)_BASE)/src/UtfCodec.cpp

$(_NS)_PRIVATE_HEADERS = \
    $($(_NS)_BASE)/src/inc/bits.h \
    $($(_NS)_BASE)/src/inc/debug.h \
    $($(_NS)_BASE)/src/inc/json.h \
    $($(_NS)_BASE)/src/inc/CharInfo.h \
    $($(_NS)_BASE)/src/inc/CmapCache.h \
    $($(_NS)_BASE)/src/inc/Code.h \
    $($(_NS)_BASE)/src/inc/Collider.h \
    $($(_NS)_BASE)/src/inc/Compression.h \
    $($(_NS)_BASE)/src/inc/Decompressor.h \
    $($(_NS)_BASE)/src/inc/Endian.h \
    $($(_NS)_BASE)/src/inc/Error.h \
    $($(_NS)_BASE)/src/inc/Face.h \
    $($(_NS)_BASE)/src/inc/FeatureMap.h \
    $($(_NS)_BASE)/src/inc/FeatureVal.h \
    $($(_NS)_BASE)/src/inc/FileFace.h \
    $($(_NS)_BASE)/src/inc/Font.h \
    $($(_NS)_BASE)/src/inc/GlyphCache.h \
    $($(_NS)_BASE)/src/inc/GlyphFace.h \
    $($(_NS)_BASE)/src/inc/Intervals.h \
    $($(_NS)_BASE)/src/inc/list.hpp \
    $($(_NS)_BASE)/src/inc/locale2lcid.h \
    $($(_NS)_BASE)/src/inc/Machine.h \
    $($(_NS)_BASE)/src/inc/Main.h \
    $($(_NS)_BASE)/src/inc/NameTable.h \
    $($(_NS)_BASE)/src/inc/opcode_table.h \
    $($(_NS)_BASE)/src/inc/opcodes.h \
    $($(_NS)_BASE)/src/inc/Pass.h \
    $($(_NS)_BASE)/src/inc/Position.h \
    $($(_NS)_BASE)/src/inc/Rule.h \
    $($(_NS)_BASE)/src/inc/Segment.h \
    $($(_NS)_BASE)/src/inc/Silf.h \
    $($(_NS)_BASE)/src/inc/Slot.h \
    $($(_NS)_BASE)/src/inc/Sparse.h \
    $($(_NS)_BASE)/src/inc/TtfTypes.h \
    $($(_NS)_BASE)/src/inc/TtfUtil.h \
    $($(_NS)_BASE)/src/inc/UtfCodec.h \
    $($(_NS)_BASE)/src/inc/vector.hpp

$(_NS)_PUBLIC_HEADERS = \
    $($(_NS)_BASE)/include/graphite2/Font.h \
    $($(_NS)_BASE)/include/graphite2/Log.h \
    $($(_NS)_BASE)/include/graphite2/Segment.h \
    $($(_NS)_BASE)/include/graphite2/Types.h
