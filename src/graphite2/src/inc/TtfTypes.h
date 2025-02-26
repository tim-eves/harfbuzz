// SPDX-License-Identifier: MIT
// Copyright 2010, SIL International, All rights reserved.

#pragma once
#include <cstdint>
/*
Responsibility: Tim Eves
Last reviewed: Not yet.

Description:
Provides types required to represent the TTF basic types.
*/


//**********************************************************************************************
//  Include files
//**********************************************************************************************
namespace graphite2
{
namespace TtfUtil
{
//**********************************************************************************************
//  Forward declarations
//**********************************************************************************************


//**********************************************************************************************
//  Type declarations
//**********************************************************************************************
typedef uint8_t           byte;
typedef int             int32_t;

typedef int16_t   short_frac;
typedef int32_t   fixed;
typedef int16_t   fword;
typedef uint16_t  ufword;
typedef int16_t   f2dot14;
typedef uint32_t  long_date_time[2];

//**********************************************************************************************
//  Constants and enum types
//**********************************************************************************************/
enum
{
    OneFix = 1<<16
};

//**********************************************************************************************
//  Table declarations
//**********************************************************************************************
namespace Sfnt
{
#pragma pack(push,1) // We need this or the structure members aren't aligned
                        // correctly.  Fortunately this form of pragma is supposed
                        // to be recognised by VS C++ too (at least according to
                        // MSDN).

    struct OffsetSubTable
    {
        uint32_t  scaler_type;
        uint16_t  num_tables,
            search_range,
            entry_selector,
            range_shift;
        struct Entry
        {
            uint32_t  tag,
                checksum,
                offset,
                length;
        } table_directory[1];

        enum ScalerType
        {
            TrueTypeMac = 0x74727565U,
            TrueTypeWin = 0x00010000U,
            Type1   = 0x74797031U
        };
    };




    struct CharacterCodeMap
    {
        uint16_t  version,
            num_subtables;
        struct
        {
            uint16_t  platform_id,
                platform_specific_id;
            uint32_t  offset;
        } encoding[1];
    };

    struct CmapSubTable
    {
        uint16_t  format,
            length,
            language;
    };

    struct CmapSubTableFormat4 : CmapSubTable
    {
        uint16_t  seg_count_x2,
            search_range,
            entry_selector,
            range_shift,
            end_code[1];
        // There are arrarys after this which need their
        // start positions calculated since end_code is
        // seg_count uint16s long.
    };

    struct CmapSubTableFormat12
    {
        fixed   format;
        uint32_t  length,
            language,
            num_groups;
        struct
        {
            uint32_t  start_char_code,
                end_char_code,
                start_glyph_id;
        } group[1];
    };



    struct FontHeader
    {
        fixed   version,
            font_revision;
        uint32_t  check_sum_adjustment,
            magic_number;
        uint16_t  flags,
            units_per_em;
        long_date_time  created,
                modified;
        fword   x_min,
            y_min,
            x_max,
            y_max;
        uint16_t  mac_style,
            lowest_rec_ppem;
        int16_t   font_direction_hint,
            index_to_loc_format,
            glyph_data_format;
        enum
        {
            MagicNumber = 0x5F0F3CF5,
            GlypDataFormat = 0
        };
        enum {ShortIndexLocFormat, LongIndexLocFormat};
    };




    struct PostScriptGlyphName
    {
        fixed   format,
            italic_angle;
        fword   underline_position,
            underline_thickness;
        uint32_t  is_fixed_pitch,
            min_mem_type42,
            max_mem_type42,
            min_mem_type1,
            max_mem_type1;
        enum
        {
            Format1  = 0x10000,
            Format2  = 0x20000,
            Format25 = 0x28000,
            Format3  = 0x30000,
            Format4  = 0x40000
        };
    };

    struct PostScriptGlyphName2 : PostScriptGlyphName
    {
        uint16_t  number_of_glyphs,
            glyph_name_index[1];
    };

    struct PostScriptGlyphName25 : PostScriptGlyphName
    {
        uint16_t  number_of_glyphs;
        int8_t    offset[1];
    };

    struct PostScriptGlyphName3 : PostScriptGlyphName {};

    struct PostScriptGlyphName4 : PostScriptGlyphName
    {
        uint16_t glyph_to_char_map[1];
    };


    struct HorizontalHeader
    {
        fixed   version;
        fword   ascent,
            descent,
            line_gap;
        ufword  advance_width_max;
        fword   min_left_side_bearing,
            max_left_side_bearing,
            x_max_element;
        int16_t   caret_slope_rise,
            caret_slope_run;
        fword   caret_offset;
        int16_t   reserved[4],
            metric_data_format;
        uint16_t  num_long_hor_metrics;
    };

    struct MaximumProfile
    {
        fixed   version;
        uint16_t  num_glyphs,
            max_points,
            max_contours,
            max_component_points,
            max_component_contours,
            max_zones,
            max_twilight_points,
            max_storage,
            max_function_defs,
            max_instruction_defs,
            max_stack_elements,
            max_size_of_instructions,
            max_component_elements,
            max_component_depth;
    };


    typedef byte    Panose[10];

    struct Compatibility0
    {
        uint16_t  version;
        int16_t   x_avg_char_width;
        uint16_t  weight_class,
            width_class;
        int16_t   fs_type,
            y_subscript_x_size,
            y_subscript_y_size,
            y_subscript_x_offset,
            y_subscript_y_offset,
            y_superscript_x_size,
            y_superscript_y_size,
            y_superscript_x_offset,
            y_superscript_y_offset,
            y_strikeout_size,
            y_strikeout_position,
            family_class;
        Panose  panose;
        uint32_t  unicode_range[4];
        int8_t    ach_vend_id[4];
        uint16_t  fs_selection,
            fs_first_char_index,
            fs_last_char_index, // Acording to Apple's spec this is where v0 should end
            typo_ascender,
            typo_descender,
            type_linegap,
            win_ascent,
            win_descent;

        enum
        {
            Italic    =0x01,
            Underscore=0x02,
            Negative  =0x04,
            Outlined  =0x08,
            StrikeOut =0x10,
            Bold      =0x20
        };
    };

    struct Compatibility1 : Compatibility0
    {
        uint32_t  codepage_range[2];
    };

    struct Compatibility2 : Compatibility1
    {
            int16_t   x_height,
                cap_height;
            uint16_t  default_char,
                break_char,
                max_context;
    };

    struct Compatibility3 : Compatibility2 {};

    typedef Compatibility3  Compatibility;


    struct NameRecord
    {
        uint16_t  platform_id,
            platform_specific_id,
            language_id,
            name_id,
            length,
            offset;
        enum    {Unicode, Mactintosh, Reserved, Microsoft};
        enum
        {
            Copyright, Family, Subfamily, UniqueSubfamily,
            Fullname, Version, PostScript
        };
    };

    struct LangTagRecord
    {
        uint16_t length,
            offset;
    };

    struct FontNames
    {
        uint16_t  format,
            count,
            string_offset;
        NameRecord name_record[1];
    };


    struct HorizontalMetric
    {
        uint16_t  advance_width;
        int16_t   left_side_bearing;
    };


    struct Glyph
    {
        int16_t   number_of_contours;
        fword   x_min,
            y_min,
            x_max,
            y_max;
    };

    struct SimpleGlyph : Glyph
    {
        uint16_t  end_pts_of_contours[1];
        enum
        {
            OnCurve = 0x01,
            XShort  = 0x02,
            YShort  = 0x04,
            Repeat  = 0x08,
            XIsSame = 0x10,
            XIsPos  = 0x10,
            YIsSame = 0x20,
            YIsPos  = 0x20
        };
    };

    struct CompoundGlyph : Glyph
    {
        uint16_t  flags,
            glyph_index;
        enum
        {
            Arg1Arg2Words   = 0x01,
            ArgsAreXYValues = 0x02,
            RoundXYToGrid   = 0x04,
            HaveScale       = 0x08,
            MoreComponents  = 0x20,
            HaveXAndYScale  = 0x40,
            HaveTwoByTwo    = 0x80,
            HaveInstructions = 0x100,
            UseMyMetrics    = 0x200,
            OverlapCompund  = 0x400,
            ScaledOffset    = 0x800,
            UnscaledOffset  = 0x1000
        };
    };

#pragma pack(pop)
} // end of namespace Sfnt

} // end of namespace TtfUtil
} // end of namespace graphite2
