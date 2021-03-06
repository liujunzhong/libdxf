/*!
 * \file table.h
 *
 * \author Copyright (C) 2009, 2012, 2014, 2015, 2016, 2017, 2018
 * by Bert Timmerman <bert.timmerman@xs4all.nl>.
 *
 * \author Copyright (C) 2010 by Luis Matos <gass@otiliamatos.ath.cx>.
 *
 * \brief Header file for of a DXF table entry (\c TABLE).
 *
 * \since The \c TABLE entity was introduced in DXF R2005.
 *
 * \version According to DXF R10 (backward compatibility).
 * \version According to DXF R11 (backward compatibility).
 * \version According to DXF R12 (backward compatibility).
 * \version According to DXF R13 (backward compatibility).
 * \version According to DXF R14 (backward compatibility).
 * \version According to DXF R2005.
 *
 * <hr>
 * <h1><b>Copyright Notices.</b></h1>\n
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.\n\n
 * This program is distributed in the hope that it will be useful, but
 * <b>WITHOUT ANY WARRANTY</b>; without even the implied warranty of
 * <b>MERCHANTABILITY</b> or <b>FITNESS FOR A PARTICULAR PURPOSE</b>.\n
 * See the GNU General Public License for more details.\n\n
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to:\n
 * Free Software Foundation, Inc.,\n
 * 59 Temple Place,\n
 * Suite 330,\n
 * Boston,\n
 * MA 02111 USA.\n
 * \n
 * Drawing eXchange Format (DXF) is a defacto industry standard for the
 * exchange of drawing files between various Computer Aided Drafting
 * programs.\n
 * DXF is an industry standard designed by Autodesk(TM).\n
 * For more details see http://www.autodesk.com.
 * <hr>
 */

#ifndef LIBDXF_SRC_TABLE_H
#define LIBDXF_SRC_TABLE_H


#include "global.h"


#ifdef __cplusplus
extern "C" {
#endif


/*!
 * \brief DXF definition of a table entity cell.
 */
typedef struct
dxf_table_cell_struct
{
        char *text_string;
                /*!< Text string in a cell.\n
                 * If the string is shorter than 250 characters, all
                 * characters appear in code 1.\n
                 * If the string is longer than 250 characters, it is
                 * divided into chunks of 250 characters.\n
                 * The chunks are contained in one or more code 3 codes.\n
                 * If code 3 codes are used, the last group is a code 1
                 * and is shorter than 250 characters.\n
                 * This value applies only to text-type cells and is
                 * repeated, 1 value per cell.\n
                 * Group code = 1. */
        char *optional_text_string[DXF_MAX_PARAM];
                /*!< Text string in a cell, in 250-character chunks;
                 * optional.\n
                 * This value applies only to text-type cells and is
                 * repeated, 1 value per cell.\n
                 * Group code = 3. */
        char *text_style_name;
                /*!< Text style name (string); override applied at the
                 * cell level.\n
                 * Group code = 7. */
        int color_bg;
                /*!< Value for the background (fill) color of cell
                 * content; override applied at the cell level.\n
                 * Group code = 63. */
        int color_fg;
                /*!< Value for the color of cell content; override
                 * applied at the cell level.\n
                 * Group code = 64. */
        int border_color_right;
                /*!< True color value for the right border of the cell;
                 * override applied at the cell level.\n
                 * Group code = 65. */
        int border_color_bottom;
                /*!< True color value for the bottom border of the cell;
                 * override applied at the cell level.\n
                 * Group code = 66. */
        int border_color_left;
                /*!< True color value for the left border of the cell;
                 * override applied at the cell level.\n
                 * Group code = 68. */
        int border_color_top;
                /*!< True color value for the top border of the cell;
                 * override applied at the cell level.\n
                 * Group code = 69. */
        int override_flag;
                /*!< Cell override flag; this value is repeated, 1 value
                 * per cell (from AutoCAD 2007).\n
                 * Group code = 91.
                 *
                 * \warning Multiple entries with Group code 91. */
        double text_height;
                /*!< Text height value; override applied at the cell
                 * level.\n
                 * Group code = 140. */
        double block_scale;
                /*!< Block scale (real).\n
                 * This value applies only to block-type cells and is
                 * repeated, 1 value per cell.\n
                 * Group code = 144. */
        double block_rotation;
                /*!< Rotation value (real; applicable for a block-type
                 * cell and a text-type cell).\n
                 * Group code = 145. */
        int alignment;
                /*!< Cell alignment value; override applied at the cell
                 * level.\n
                 * Group code = 170. */
        int type;
                /*!< Cell type; this value is repeated, 1 value per cell:
                 * <ol>
                 * <li value = "1"> Text type.</li>
                 * <li value = "2"> Block type.</li>
                 * </ol>
                 * Group code = 171. */
        int flag;
                /*!< Cell flag value; this value is repeated, 1 value
                 * per cell.\n
                 * Group code = 172. */
        int merged;
                /*!< Cell merged value; this value is repeated, 1 value
                 * per cell.\n
                 * Group code = 173. */
        int autofit;
                /*!< Boolean flag indicating if the autofit option is
                 * set for the cell; this value is repeated, 1 value per
                 * cell.\n
                 * Group code = 174. */
        double border_width;
                /*!< Cell border width (applicable only for merged
                 * cells); this value is repeated, 1 value per cell.\n
                 * Group code = 175. */
        double border_height;
                /*!< Cell border height (applicable only for merged
                 * cells); this value is repeated, 1 value per cell.\n
                 * Group code = 176. */
        int override;
                /*!< Cell override flag; this value is repeated, 1 value
                 * per cell.\n
                 * Group code = 177. */
        int virtual_edge;
                /*!< Flag value for a virtual edge.\n
                 *
                 * \note Group code 178 is a flag value for a virtual
                 * edge.\n
                 * A virtual edge is used when a grid line is shared by
                 * two cells.\n
                 * For example, if a table contains one row and two
                 * columns and it contains cell A and cell B, the
                 * central grid line contains the right edge of cell A
                 * and the left edge of cell B.\n
                 * One edge is real, and the other edge is virtual.\n
                 * The virtual edge points to the real edge; both edges
                 * have the same set of properties, including color,
                 * lineweight, and visibility.\n
                 *
                 * Group code = 178. */
        int number_of_block_attdefs;
                /*!< Number of attribute definitions in the block table
                 * record (applicable only to a block-type cell).\n
                 * Group code = 179. */
        double border_lineweight_right;
                /*!< Lineweight for the right border of the cell;
                 * override applied at the cell level.\n
                 * Group code = 275. */
        double border_lineweight_bottom;
                /*!< Lineweight for the bottom border of the cell;
                 * override applied at the cell level.\n
                 * Group code = 276. */
        double border_lineweight_left;
                /*!< Lineweight for the left border of the cell;
                 * override applied at the cell level.\n
                 * Group code = 278. */
        double border_lineweight_top;
                /*!< Lineweight for the top border of the cell; override
                 * applied at the cell level.\n
                 * Group code = 279. */
        int color_fill_override;
                /*!< Boolean flag for whether the fill color is on;
                 * override applied at the cell level.\n
                 * Group code = 283. */
        int border_visibility_override_right;
                /*!< Boolean flag for the visibility of the right border
                 * of the cell; override applied at the cell level.\n
                 * Group code = 285. */
        int border_visibility_override_bottom;
                /*!< Boolean flag for the visibility of the bottom
                 * border of the cell; override applied at the cell
                 * level.\n
                 * Group code = 286. */
        int border_visibility_override_left;
                /*!< Boolean flag for the visibility of the left border
                 * of the cell; override applied at the cell level.\n
                 * Group code = 288. */
        int border_visibility_override_top;
                /*!< Boolean flag for the visibility of the top border
                 * of the cell; override applied at the cell level.\n
                 * Group code = 289. */
        char *attdef_text_string;
                /*!< Text string value for an attribute definition,
                 * repeated once per attribute definition and applicable
                 * only for a block-type cell.\n
                 * Group code = 300. */
        char *attdef_soft_pointer[DXF_MAX_PARAM];
                /*!< Soft pointer ID of the attribute definition in the
                 * block table record, referenced by group code 179
                 * (applicable only for a block-type cell).\n
                 * This value is repeated once per attribute definition.\n
                 * Group code = 331. */
        char *block_table_record_hard_pointer;
                /*!< Hard-pointer ID of the block table record.\n
                 * This value applies only to block-type cells and is
                 * repeated, 1 value per cell.\n
                 * Group code = 340. */
        char *field_object_pointer;
                /*!< Hard pointer ID of the \c FIELD object.\n
                 * This applies only to a text-type cell.\n
                 * If the text in the cell contains one or more fields,
                 * only the ID of the \c FIELD object is saved.\n
                 * The text string (group codes 1 and 3) is ignored.\n
                 * Group code = 344. */
        struct DxfTableCell *next;
                /*!< Pointer to the next DxfTableCell.\n
                 * \c NULL in the last DxfTableCell. */
} DxfTableCell;


/*!
 * \brief DXF definition of a table entity.
 */
typedef struct
dxf_table_struct
{
        int id_code;
                /*!< Identification number for the entity.\n
                 * This is to be an unique (sequential) number in the DXF
                 * file.\n
                 * Group code = 5. */
        char *linetype;
                /*!< The linetype of the entity.\n
                 * Defaults to \c BYLAYER if ommitted in the DXF file.\n
                 * Group code = 6. */
        char *layer;
                /*!< Layer on which the entity is drawn.\n
                 * Defaults to layer "0" if no valid layername is given.\n
                 * Group code = 8. */
        double elevation;
                /*!< Elevation of the arc in the local Z-direction.\n
                 * Defaults to 0.0 if omitted in the DXF file, or prior
                 * to DXF version R12, or DXF_FLATLAND equals 0
                 * (default).\n
                 * (default).\n
                 * Group code = 38. */
        double thickness;
                /*!< Thickness of the arc in the local Z-direction.\n
                 * Defaults to 0.0 if ommitted in the DXF file.\n
                 * Group code = 39. */
        double linetype_scale;
                /*!< Linetype scale (optional).\n
                 * Group code = 48. */
        int16_t visibility;
                /*!< Object visibility (optional):
                 * <ol>
                 * <li value = "0"> Visible;</li>
                 * <li value = "1"> Invisible.</li>
                 * </ol>
                 * Group code = 60. */
        int color;
                /*!< Color of the entity.\n
                 * Defaults to \c BYLAYER if ommitted in the DXF file.\n
                 * Note that entities encapsulated in a block with the
                 * color \c BYBLOCK are represented in the "native"
                 * color of the \c BLOCK entity.\n
                 * Group code = 62. */
        int paperspace;
                /*!< Entities are to be drawn on either \c PAPERSPACE or
                 * \c MODELSPACE.\n
                 * Optional, defaults to \c DXF_MODELSPACE (0).\n
                 * Group code = 67. */
        int graphics_data_size;
                /*!< The number of bytes in the image (and subsequent
                 * binary chunk records) (optional).\n
                 * Group code = 92.
                 *
                 * \warning Multiple entries with Group code 92. */
        char *binary_graphics_data[DXF_MAX_PARAM];
                /*!< Proxy entity graphics data.\n
                 * Multiple lines of 256 characters maximum per line
                 * (optional).\n
                 * Group code = 310. */
        char *dictionary_owner_soft;
                /*!< Soft-pointer ID/handle to owner dictionary
                 * (optional).\n
                 * Group code = 330. */
        char *dictionary_owner_hard;
                /*!< Hard owner ID/handle to owner dictionary
                 * (optional).\n
                 * Group code = 360. */
        /* Specific members for a DXF table. */
        char *block_name;
                /*!< Block name; an anonymous block begins with a *T
                 * value.\n
                 * Group code = 2. */
        char *table_text_style_name;
                /*!< Text style name (string); override applied at the
                 * table entity level.\n
                 * There may be one entry for each cell type.\n
                 * Group code = 7. */
        double x0;
                /*!< X-value of the insertion point coordinate.\n
                 * Group code = 10. */
        double y0;
                /*!< Y-value of the insertion point coordinate.\n
                 * Group code = 20. */
        double z0;
                /*!< Z-value of the insertion point coordinate.\n
                 * Group code = 30. */
        double x1;
                /*!< X-value of the horizontal direction vector.\n
                 * Group code = 11. */
        double y1;
                /*!< Y-value of the horizontal direction vector.\n
                 * Group code = 21. */
        double z1;
                /*!< Z-value of the horizontal direction vector.\n
                 * Group code = 31. */
        double horizontal_cell_margin;
                /*!< Horizontal cell margin; override applied at the
                 * table entity level.\n
                 * Group code = 40. */
        double vertical_cell_margin;
                /*!< Vertical cell margin; override applied at the
                 * table entity level.\n
                 * Group code = 41. */
        int table_cell_color_bg;
                /*!< Color value for cell background or for the vertical,
                 * left border of the table; override applied at the
                 * table entity level.\n
                 * There may be one entry for each cell type.\n
                 * Group code = 63. */
        int table_cell_color_fg;
                /*!< Color value for cell content or for the horizontal,
                 * top border of the table; override applied at the
                 * table entity level.\n
                 * There may be one entry for each cell type.\n
                 * Group code = 64. */
        int table_cell_border_color_horizontal;
                /*!< Color value for the horizontal, inside border lines;
                 * override applied at the table entity level.\n
                 * Group code = 65. */
        int table_cell_border_color_bottom;
                /*!< Color value for the horizontal, bottom border lines;
                 * override applied at the table entity level.\n
                 * Group code = 66. */
        int table_cell_border_color_vertical;
                /*!< Color value for the vertical, inside border lines;
                 * override applied at the table entity level.\n
                 * Group code = 68. */
        int table_cell_border_color_right;
                /*!< Color value for the vertical, right border lines;
                 * override applied at the table entity level.\n
                 * Group code = 69. */
        int flow_direction;
                /*!< Flow direction; override applied at the table
                 * entity level.\n
                 * Group code = 70. */
        int32_t table_value_flag;
                /*!< Flag for table value (unsigned integer).\n
                 * Group code = 90. */
        int number_of_rows;
                /*!< Number of rows.\n
                 * Group code = 91.
                 *
                 * \warning Multiple entries with Group code 91. */
        int number_of_columns;
                /*!< Number of columns.\n
                 * Group code = 92.
                 *
                 * \warning Multiple entries with Group code 92. */
        int override_flag;
                /*!< Flag for an override.\n
                 * Group code = 93. */
        int border_color_override_flag;
                /*!< Flag for an override of border color.\n
                 * Group code = 94. */
        int border_lineweight_override_flag;
                /*!< Flag for an override of border lineweight.\n
                 * Group code = 95. */
        int border_visibility_override_flag;
                /*!< Flag for an override of border visibility.\n
                 * Group code = 96. */
        double table_text_height;
                /*!< Text height (real); override applied at the table
                 * entity level.\n
                 * There may be one entry for each cell type.\n
                 * Group code = 140. */
        double row_height[DXF_MAX_PARAM];
                /*!< Row height; this value is repeated, 1 value per
                 * row.\n
                 * Group code = 141. */
        double column_height[DXF_MAX_PARAM];
                /*!< Column height; this value is repeated, 1 value per
                 * column.\n
                 * Group code = 142. */
        int table_cell_alignment;
                /*!< Cell alignment (integer); override applied at the
                 * table entity level.\n
                 * There may be one entry for each cell type.\n
                 * Group code = 170. */
        double table_cell_border_lineweight_right;
                /*!< Group code = 274. */
        int table_data_version;
                /*!< Table data version number:\n
                 * 0 = 2010.\n
                 * Group code = 280.
                 *
                 * \warning Multiple entries with Group code 280. */
        int suppress_table_title;
                /*!< Flag for whether the title is suppressed; override
                 * applied at the table entity level.\n
                 * Group code = 280.
                 *
                 * \warning Multiple entries with Group code 280. */
        int suppress_header_row;
                /*!< Flag for whether the header row is suppressed;
                 * override applied at the table entity level.\n
                 * Group code = 281. */
        int table_cell_color_fill_override;
                /*!< Flag for whether background color is enabled
                 * (default = 0); override applied at the table entity
                 * level.\n
                 * There may be one entry for each cell type:
                 * <ol>
                 * <li value = "0"> Disabled.</li>
                 * <li value = "1"> Enabled.</li>
                 * </ol>
                 * Group code = 283. */
        char *tablestyle_object_pointer;
                /*!< Hard pointer ID of the \c TABLESTYLE object.\n
                 * Group code = 342. */
        char *owning_block_pointer;
                /*!< Hard pointer ID of the owning \c BLOCK record.\n
                 * Group code = 343. */
        struct DxfTableCell *cells;
                /*!< Pointer to the first DxfTableCell of a linked list
                 * of table cells. */
        struct DxfTable *next;
                /*!< Pointer to the next DxfTable.\n
                 * \c NULL in the last DxfTable. */
} DxfTable;


DxfTableCell *dxf_table_cell_new ();
DxfTable *dxf_table_new ();
DxfTableCell *dxf_table_cell_init (DxfTableCell *cell);
DxfTable *dxf_table_init (DxfTable *table);
DxfTable *dxf_table_read (DxfFile *fp, DxfTable *table);
int dxf_table_cell_write (DxfFile *fp, DxfTableCell *cell);
int dxf_table_write (DxfFile *fp, DxfTable *table);
int dxf_table_cell_free (DxfTableCell *cell);
int dxf_table_free (DxfTable *table);
void dxf_table_cell_free_list (DxfTableCell *cells);
void dxf_table_free_list (DxfTable *tables);


#ifdef __cplusplus
}
#endif


#endif /* LIBDXF_SRC_TABLE_H */


/* EOF */
