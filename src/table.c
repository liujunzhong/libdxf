/*!
 * \file table.c
 *
 * \author Copyright (C) 2009, 2010, 2011, 2014, 2015, 2017, 2018
 * by Bert Timmerman <bert.timmerman@xs4all.nl>.
 *
 * \author Copyright (C) 2010 by Luis Matos <gass@otiliamatos.ath.cx>.
 *
 * \brief Functions for a DXF table entry (\c TABLE).
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


#include "table.h"


/*!
 * \brief Allocate memory for a DXF \c TABLE cell.
 *
 * Fill the memory contents with zeros.
 *
 * \return \c NULL when no memory was allocated, a pointer to the
 * allocated memory when successful.
 */
DxfTableCell *
dxf_table_cell_new ()
{
#if DEBUG
        DXF_DEBUG_BEGIN
#endif
        DxfTableCell *cell = NULL;
        size_t size;

        size = sizeof (DxfTableCell);
        /* avoid malloc of 0 bytes */
        if (size == 0) size = 1;
        if ((cell = malloc (size)) == NULL)
        {
                fprintf (stderr,
                  (_("Error in %s () could not allocate memory for a DxfTableCell struct.\n")),
                  __FUNCTION__);
                cell = NULL;
        }
        else
        {
                memset (cell, 0, size);
        }
#if DEBUG
        DXF_DEBUG_END
#endif
        return (cell);
}


/*!
 * \brief Allocate memory for a DXF \c TABLE.
 *
 * Fill the memory contents with zeros.
 *
 * \return \c NULL when no memory was allocated, a pointer to the
 * allocated memory when successful.
 */
DxfTable *
dxf_table_new ()
{
#if DEBUG
        DXF_DEBUG_BEGIN
#endif
        DxfTable *table = NULL;
        size_t size;

        size = sizeof (DxfTable);
        /* avoid malloc of 0 bytes */
        if (size == 0) size = 1;
        if ((table = malloc (size)) == NULL)
        {
                fprintf (stderr,
                  (_("Error in %s () could not allocate memory for a DxfTable struct.\n")),
                  __FUNCTION__);
                table = NULL;
        }
        else
        {
                memset (table, 0, size);
        }
#if DEBUG
        DXF_DEBUG_END
#endif
        return (table);
}


/*!
 * \brief Allocate memory and initialize data fields in a DXF \c TABLE
 * cell.
 * 
 * \return \c NULL when no memory was allocated, a pointer to the
 * allocated memory when successful.
 */
DxfTableCell *
dxf_table_cell_init
(
        DxfTableCell *cell
                /*!< a pointer to a DXF \c TABLE cell. */
)
{
#if DEBUG
        DXF_DEBUG_BEGIN
#endif
        int i;

        /* Do some basic checks. */
        if (cell == NULL)
        {
                fprintf (stderr,
                  (_("Warning in %s () a NULL pointer was passed.\n")),
                  __FUNCTION__);
                cell = dxf_table_cell_new ();
        }
        if (cell == NULL)
        {
                fprintf (stderr,
                  (_("Error in %s () could not allocate memory for a DxfTableCell struct.\n")),
                  __FUNCTION__);
                return (NULL);
        }
        cell->text_string = strdup ("");
        for (i = 0; i < DXF_MAX_PARAM; i++)
        {
                cell->optional_text_string[i] = strdup ("");
                cell->attdef_soft_pointer[i] = strdup ("");
        }
        cell->text_style_name = strdup (DXF_DEFAULT_TEXTSTYLE);
        cell->color_bg = 0;
        cell->color_fg = DXF_COLOR_BYLAYER;
        cell->border_color_right = DXF_COLOR_BYLAYER;
        cell->border_color_bottom = DXF_COLOR_BYLAYER;
        cell->border_color_left = DXF_COLOR_BYLAYER;
        cell->border_color_top = DXF_COLOR_BYLAYER;
        cell->text_height = 1.0;
        cell->block_scale = 1.0;
        cell->block_rotation = 0.0;
        cell->alignment = 0;
        cell->type = 0;
        cell->flag = 0;
        cell->merged = 0;
        cell->autofit = 0;
        cell->border_width = 0.0;
        cell->border_height = 0.0;
        cell->override = 0;
        cell->virtual_edge = 0;
        cell->number_of_block_attdefs = 0;
        cell->border_lineweight_right = 1.0;
        cell->border_lineweight_bottom = 1.0;
        cell->border_lineweight_left = 1.0;
        cell->border_lineweight_top = 1.0;
        cell->color_fill_override = 0;
        cell->border_visibility_override_right = 0;
        cell->border_visibility_override_bottom = 0;
        cell->border_visibility_override_left = 0;
        cell->border_visibility_override_top = 0;
        cell->attdef_text_string = strdup ("");
        cell->block_table_record_hard_pointer = strdup ("");
        cell->field_object_pointer = strdup ("");
        cell->next = NULL;
#if DEBUG
        DXF_DEBUG_END
#endif
        return (cell);
}


/*!
 * \brief Allocate memory and initialize data fields in a DXF \c TABLE
 * entity.
 * 
 * \return \c NULL when no memory was allocated, a pointer to the
 * allocated memory when successful.
 */
DxfTable *
dxf_table_init
(
        DxfTable *table
                /*!< a pointer to a DXF \c TABLE entity. */
)
{
#if DEBUG
        DXF_DEBUG_BEGIN
#endif
        int i;

        /* Do some basic checks. */
        if (table == NULL)
        {
                fprintf (stderr,
                  (_("Warning in %s () a NULL pointer was passed.\n")),
                  __FUNCTION__);
                table = dxf_table_new ();
        }
        if (table == NULL)
        {
                fprintf (stderr,
                  (_("Error in %s () could not allocate memory for a DxfTable struct.\n")),
                  __FUNCTION__);
                return (NULL);
        }
        table->id_code = 0;
        table->linetype = strdup (DXF_DEFAULT_LINETYPE);
        table->layer = strdup (DXF_DEFAULT_LAYER);
        table->elevation = 0.0;
        table->thickness = 0.0;
        table->visibility = 0;
        table->color = DXF_COLOR_BYLAYER;
        table->paperspace = DXF_MODELSPACE;
        table->graphics_data_size = 0;
        for (i = 0; i < DXF_MAX_PARAM; i++)
        {
                table->binary_graphics_data[i] = strdup ("");
                table->row_height[i] = 0.0;
                table->column_height[i] = 0.0;
        }
        table->dictionary_owner_soft = strdup ("");
        table->dictionary_owner_hard = strdup ("");
        table->block_name = strdup ("");
        table->table_text_style_name = strdup ("");
        table->x0 = 0.0;
        table->y0 = 0.0;
        table->z0 = 0.0;
        table->x1 = 0.0;
        table->y1 = 0.0;
        table->z1 = 0.0;
        table->horizontal_cell_margin = 0.0;
        table->vertical_cell_margin = 0.0;
        table->table_cell_color_bg = 0;
        table->table_cell_color_fg = 0;
        table->table_cell_border_color_horizontal = DXF_COLOR_BYLAYER;
        table->table_cell_border_color_bottom = DXF_COLOR_BYLAYER;
        table->table_cell_border_color_vertical = DXF_COLOR_BYLAYER;
        table->table_cell_border_color_right = DXF_COLOR_BYLAYER;
        table->flow_direction = 0;
        table->table_value_flag = 0;
        table->number_of_rows = 0;
        table->number_of_columns = 0;
        table->override_flag = 0;
        table->border_color_override_flag = 0;
        table->border_lineweight_override_flag = 0;
        table->border_visibility_override_flag = 0;
        table->table_text_height = 0.0;
        table->table_cell_alignment = 0;
        table->table_cell_border_lineweight_right = 0.0;
        table->suppress_table_title = 0;
        table->suppress_header_row = 0;
        table->table_cell_color_fill_override = 0;
        table->tablestyle_object_pointer = strdup ("");
        table->owning_block_pointer = strdup ("");
        table->cells = NULL;
        table->next = NULL;
#if DEBUG
        DXF_DEBUG_END
#endif
        return (table);
}


/*!
 * \brief Read data from a DXF file into a DXF \c TABLE entity.
 *
 * The last line read from file contained the string "TABLE". \n
 * Now follows some data for the \c TABLE, to be terminated with a "  0"
 * string announcing the following table record, or the end of the
 * \c TABLE section marker \c ENDTAB. \n
 * While parsing the DXF file store data in \c table. \n
 *
 * \return a pointer to \c table.
 */
DxfTable *
dxf_table_read
(
        DxfFile *fp,
                /*!< DXF file pointer to an input file (or device). */
        DxfTable *table
                /*!< a pointer to a DXF \c TABLE entity. */
)
{
#if DEBUG
        DXF_DEBUG_BEGIN
#endif
        char *temp_string = NULL;
        int i;
        int j;
        int k;
        int l;

        /* Do some basic checks. */
        if (fp == NULL)
        {
                fprintf (stderr,
                  (_("Error in %s () a NULL file pointer was passed.\n")),
                  __FUNCTION__);
                /* Clean up. */
                free (temp_string);
                return (NULL);
        }
        if (table == NULL)
        {
                fprintf (stderr,
                  (_("Warning in %s () a NULL pointer was passed.\n")),
                  __FUNCTION__);
                table = dxf_table_new ();
                table = dxf_table_init (table);
        }
        i = 0;
        j = 0;
        k = 0;
        l = 0;
        (fp->line_number)++;
        fscanf (fp->fp, "%[^\n]", temp_string);
        while (strcmp (temp_string, "0") != 0)
        {
                if (ferror (fp->fp))
                {
                        fprintf (stderr,
                          (_("Error in %s () while reading from: %s in line: %d.\n")),
                          __FUNCTION__, fp->filename, fp->line_number);
                        fclose (fp->fp);
                        /* Clean up. */
                        free (temp_string);
                        return (NULL);
                }
                else if (strcmp (temp_string, "2") == 0)
                {
                        /* Now follows a string containing a block name;
                         * an anonymous block begins with a *T value. */
                        fscanf (fp->fp, "%s\n", table->block_name);
                }
                if (strcmp (temp_string, "5") == 0)
                {
                        /* Now follows a string containing a sequential
                         * id number. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%x\n", &table->id_code);
                }
                else if (strcmp (temp_string, "10") == 0)
                {
                        /* Now follows a string containing the
                         * X-coordinate of the insertion point. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%lf\n", &table->x0);
                }
                else if (strcmp (temp_string, "11") == 0)
                {
                        /* Now follows a string containing the
                         * X-coordinate of the horizontal direction
                         * vector. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%lf\n", &table->x1);
                }
                else if (strcmp (temp_string, "20") == 0)
                {
                        /* Now follows a string containing the
                         * Y-coordinate of the insertion point. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%lf\n", &table->y0);
                }
                else if (strcmp (temp_string, "21") == 0)
                {
                        /* Now follows a string containing the
                         * Y-coordinate of the horizontal direction
                         * vector. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%lf\n", &table->y1);
                }
                else if (strcmp (temp_string, "30") == 0)
                {
                        /* Now follows a string containing the
                         * Z-coordinate of the insertion point. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%lf\n", &table->z0);
                }
                else if (strcmp (temp_string, "31") == 0)
                {
                        /* Now follows a string containing the
                         * Z-coordinate of the horizontal direction
                         * vector. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%lf\n", &table->z1);
                }
                else if (strcmp (temp_string, "90") == 0)
                {
                        /* Now follows a string containing the flag for
                         * table value (unsigned integer). */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%d\n", &table->table_value_flag);
                }
                else if (strcmp (temp_string, "91") == 0)
                {
                        /* Now follows a string containing the number of
                         * rows. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%d\n", &table->number_of_rows);
                }
                else if ((strcmp (temp_string, "92") == 0)
                  && (i == 0))
                {
                        /* Now follows a string containing the
                         * number of bytes in the proxy entity graphics. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%d\n", &table->graphics_data_size);
                        i++;
                }
                else if ((strcmp (temp_string, "92") == 0)
                  && (i == 1))
                {
                        /* Now follows a string containing the number of
                         * columns. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%d\n", &table->number_of_columns);
                }
                else if (strcmp (temp_string, "93") == 0)
                {
                        /* Now follows a string containing the flag for
                         * an override. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%d\n", &table->override_flag);
                }
                else if (strcmp (temp_string, "94") == 0)
                {
                        /* Now follows a string containing the flag for
                         * an override of the border color. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%d\n", &table->border_color_override_flag);
                }
                else if (strcmp (temp_string, "95") == 0)
                {
                        /* Now follows a string containing the flag for
                         * an override of the border lineweight. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%d\n", &table->border_lineweight_override_flag);
                }
                else if (strcmp (temp_string, "96") == 0)
                {
                        /* Now follows a string containing the flag for
                         * an override of the border visibility. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%d\n", &table->border_visibility_override_flag);
                }
                else if ((fp->acad_version_number >= AutoCAD_13)
                        && (strcmp (temp_string, "100") == 0))
                {
                        /* Now follows a string containing the
                         * subclass marker value. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%s\n", temp_string);
                        if ((strcmp (temp_string, "AcDbEntity") != 0)
                        && ((strcmp (temp_string, "AcDbBlockReference") != 0))
                        && ((strcmp (temp_string, "AcDbBlockTable") != 0)))
                        {
                                fprintf (stderr,
                                  (_("Warning in %s () found a bad subclass marker in: %s in line: %d.\n")),
                                  __FUNCTION__, fp->filename, fp->line_number);
                        }
                }
                else if (strcmp (temp_string, "141") == 0)
                {
                        /* Now follows a string containing the row
                         * height. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%lf\n", &table->row_height[k]);
                        k++;
                }
                else if (strcmp (temp_string, "142") == 0)
                {
                        /* Now follows a string containing the column
                         * height. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%lf\n", &table->column_height[l]);
                        l++;
                }
                else if (strcmp (temp_string, "310") == 0)
                {
                        /* Now follows a string containing binary
                         * graphics data. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%s\n", table->binary_graphics_data[j]);
                        j++;
                }
                else if (strcmp (temp_string, "330") == 0)
                {
                        /* Now follows a string containing a soft-pointer
                         * ID/handle to owner dictionary. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%s\n", table->dictionary_owner_soft);
                }
                else if (strcmp (temp_string, "342") == 0)
                {
                        /* Now follows a string containing a hard pointer
                         * ID of the TABLESTYLE object. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%s\n", table->tablestyle_object_pointer);
                }
                else if (strcmp (temp_string, "343") == 0)
                {
                        /* Now follows a string containing a hard pointer
                         * ID of the owning BLOCK record. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%s\n", table->owning_block_pointer);
                }
                else if (strcmp (temp_string, "360") == 0)
                {
                        /* Now follows a string containing a hard owner
                         * ID/handle to owner dictionary. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%s\n", table->dictionary_owner_hard);
                }
                else if (strcmp (temp_string, "999") == 0)
                {
                        /* Now follows a string containing a comment. */
                        (fp->line_number)++;
                        fscanf (fp->fp, "%s\n", temp_string);
                        fprintf (stdout, "DXF comment: %s\n", temp_string);
                }
                else
                {
                        fprintf (stderr,
                          (_("Warning in %s () unknown string tag found while reading from: %s in line: %d.\n")),
                          __FUNCTION__, fp->filename, fp->line_number);
                }
        }
        /* Clean up. */
        free (temp_string);
#if DEBUG
        DXF_DEBUG_END
#endif
        return (table);
}


/*!
 * \brief Write DXF output to a file for a DXF \c TABLE cell.
 * 
 * \return \c EXIT_SUCCESS when done, or \c EXIT_FAILURE when an error
 * occurred.
 */
int
dxf_table_cell_write
(
        DxfFile *fp,
                /*!< DXF file pointer to an output file (or device). */
        DxfTableCell *cell
                /*!< a pointer to a DXF \c TABLE entity. */
)
{
#if DEBUG
        DXF_DEBUG_BEGIN
#endif
        int i;

        /* Do some basic checks. */
        if (fp == NULL)
        {
                fprintf (stderr,
                  (_("Error in %s () a NULL file pointer was passed.\n")),
                  __FUNCTION__);
                return (EXIT_FAILURE);
        }
        if (cell == NULL)
        {
                fprintf (stderr,
                  (_("Error in %s () a NULL pointer was passed.\n")),
                  __FUNCTION__);
                return (EXIT_FAILURE);
        }
        /* Start writing output. */
        fprintf (fp->fp, "171\n%d\n", cell->type);
        fprintf (fp->fp, "172\n%d\n", cell->flag);
        fprintf (fp->fp, "173\n%d\n", cell->merged);
        fprintf (fp->fp, "174\n%d\n", cell->autofit);
        fprintf (fp->fp, "175\n%lf\n", cell->border_width);
        fprintf (fp->fp, "176\n%lf\n", cell->border_height);
        fprintf (fp->fp, " 91\n%d\n", cell->override_flag);
        fprintf (fp->fp, "178\n%d\n", cell->virtual_edge);
        fprintf (fp->fp, "145\n%lf\n", cell->block_rotation);
        fprintf (fp->fp, "344\n%s\n", cell->field_object_pointer);
        i = 0;
        while ((cell->optional_text_string[i] != NULL)
          && (strcmp (cell->optional_text_string[i], "") != 0))
        {
                fprintf (fp->fp, "  2\n%s\n", cell->optional_text_string[i]);
                i++;
        }
        fprintf (fp->fp, "  1\n%s\n", cell->text_string);
        fprintf (fp->fp, "340\n%s\n", cell->block_table_record_hard_pointer);
        fprintf (fp->fp, "144\n%lf\n", cell->block_scale);
        fprintf (fp->fp, "179\n%d\n", cell->number_of_block_attdefs);
        i = 0;
        while ((cell->attdef_soft_pointer[i] != NULL)
          && (strcmp (cell->attdef_soft_pointer[i], "") != 0))
        {
                fprintf (fp->fp, "331\n%s\n", cell->attdef_soft_pointer[i]);
                i++;
        }
        if (cell->number_of_block_attdefs < (i + 1))
        {
                fprintf (stderr,
                  (_("Warning in %s () more attdefs encountered than expected.\n")),
                  __FUNCTION__);
        }
        else if (cell->number_of_block_attdefs > (i + 1))
        {
                fprintf (stderr,
                  (_("Warning in %s () less attdefs encountered than expected.\n")),
                  __FUNCTION__);
        }

#if DEBUG
        DXF_DEBUG_END
#endif
        return (EXIT_SUCCESS);
}


/*!
 * \brief Write DXF output to a file for a DXF \c TABLE entity.
 * 
 * \return \c EXIT_SUCCESS when done, or \c EXIT_FAILURE when an error
 * occurred.
 */
int
dxf_table_write
(
        DxfFile *fp,
                /*!< DXF file pointer to an output file (or device). */
        DxfTable *table
                /*!< a pointer to a DXF \c TABLE entity. */
)
{
#if DEBUG
        DXF_DEBUG_BEGIN
#endif
        char *dxf_entity_name = strdup ("ACAD_TABLE");
        int i;

        /* Do some basic checks. */
        if (fp == NULL)
        {
                fprintf (stderr,
                  (_("Error in %s () a NULL file pointer was passed.\n")),
                  __FUNCTION__);
                /* Clean up. */
                free (dxf_entity_name);
                return (EXIT_FAILURE);
        }
        if (table == NULL)
        {
                fprintf (stderr,
                  (_("Error in %s () a NULL pointer was passed.\n")),
                  __FUNCTION__);
                /* Clean up. */
                free (dxf_entity_name);
                return (EXIT_FAILURE);
        }
        /* Start writing output. */
        fprintf (fp->fp, "  0\n%s\n", dxf_entity_name);
        if (table->id_code != -1)
        {
                fprintf (fp->fp, "  5\n%x\n", table->id_code);
        }
        fprintf (fp->fp, "330\n%s\n", table->dictionary_owner_soft);
        if (fp->acad_version_number >= AutoCAD_13)
        {
                fprintf (fp->fp, "100\nAcDbEntity\n");
        }
        fprintf (fp->fp, " 92\n%d\n", table->graphics_data_size);
        i = 0;
        while (strlen (table->binary_graphics_data[i]) > 0)
        {
                fprintf (fp->fp, "310\n%s\n", table->binary_graphics_data[i]);
                i++;
        }
        if (fp->acad_version_number >= AutoCAD_13)
        {
                fprintf (fp->fp, "100\nAcDbBlockReference\n");
        }
        fprintf (fp->fp, "  2\n%s\n", table->block_name);
        fprintf (fp->fp, " 10\n%f\n", table->x0);
        fprintf (fp->fp, " 20\n%f\n", table->y0);
        fprintf (fp->fp, " 30\n%f\n", table->z0);
        if (fp->acad_version_number >= AutoCAD_13)
        {
                fprintf (fp->fp, "100\nAcDbTable\n");
        }
        fprintf (fp->fp, "280\n%d\n", table->table_data_version);
        fprintf (fp->fp, "342\n%s\n", table->tablestyle_object_pointer);
        fprintf (fp->fp, "343\n%s\n", table->owning_block_pointer);
        fprintf (fp->fp, " 11\n%f\n", table->x1);
        fprintf (fp->fp, " 21\n%f\n", table->y1);
        fprintf (fp->fp, " 31\n%f\n", table->z1);
        fprintf (fp->fp, " 90\n%d\n", table->table_value_flag);
        fprintf (fp->fp, " 91\n%d\n", table->number_of_rows);
        fprintf (fp->fp, " 92\n%d\n", table->number_of_columns);
        fprintf (fp->fp, " 93\n%d\n", table->override_flag);
        fprintf (fp->fp, " 94\n%d\n", table->border_color_override_flag);
        fprintf (fp->fp, " 95\n%d\n", table->border_lineweight_override_flag);
        fprintf (fp->fp, " 96\n%d\n", table->border_visibility_override_flag);
        for (i = 0; i < table->number_of_rows; i++)
        {
                fprintf (fp->fp, "141\n%f\n", table->row_height[i]);
        }
        for (i = 0; i < table->number_of_columns; i++)
        {
                fprintf (fp->fp, "142\n%f\n", table->column_height[i]);
        }

        /* Clean up. */
        free (dxf_entity_name);
#if DEBUG
        DXF_DEBUG_END
#endif
        return (EXIT_SUCCESS);
}


/*!
 * \brief Free the allocated memory for a DXF \c TABLE cell and all it's
 * data fields.
 *
 * \return \c EXIT_SUCCESS when done, or \c EXIT_FAILURE when an error
 * occurred.
 */
int
dxf_table_cell_free
(
        DxfTableCell *cell
                /*!< a pointer to a DXF \c TABLE cell. */
)
{
#if DEBUG
        DXF_DEBUG_BEGIN
#endif
        int i;

        /* Do some basic checks. */
        if (cell == NULL)
        {
                fprintf (stderr,
                  (_("Error in %s () a NULL pointer was passed.\n")),
                  __FUNCTION__);
                return (EXIT_FAILURE);
        }
        if (cell->next != NULL)
        {
              fprintf (stderr,
                (_("Error in %s () pointer to next was not NULL.\n")),
                __FUNCTION__);
              return (EXIT_FAILURE);
        }
        free (cell->text_string);
        for (i = 0; i < DXF_MAX_PARAM; i++)
        {
                free (cell->optional_text_string[i]);
                free (cell->attdef_soft_pointer[i]);
        }
        free (cell->text_style_name);
        free (cell->attdef_text_string);
        free (cell->block_table_record_hard_pointer);
        free (cell->field_object_pointer);
        free (cell);
        cell = NULL;
#if DEBUG
        DXF_DEBUG_END
#endif
        return (EXIT_SUCCESS);
}


/*!
 * \brief Free the allocated memory for a DXF \c TABLE and all it's
 * data fields.
 *
 * \return \c EXIT_SUCCESS when done, or \c EXIT_FAILURE when an error
 * occurred.
 */
int
dxf_table_free
(
        DxfTable *table
                /*!< a pointer to a DXF \c TABLE entity. */
)
{
#if DEBUG
        DXF_DEBUG_BEGIN
#endif
        int i;

        /* Do some basic checks. */
        if (table == NULL)
        {
                fprintf (stderr,
                  (_("Error in %s () a NULL pointer was passed.\n")),
                  __FUNCTION__);
                return (EXIT_FAILURE);
        }
        if (table->next != NULL)
        {
              fprintf (stderr,
                (_("Error in %s () pointer to next was not NULL.\n")),
                __FUNCTION__);
              return (EXIT_FAILURE);
        }
        free (table->linetype);
        free (table->layer);
        for (i = 0; i < DXF_MAX_PARAM; i++)
        {
                free (table->binary_graphics_data[i]);
        }
        free (table->dictionary_owner_soft);
        free (table->dictionary_owner_hard);
        free (table->block_name);
        free (table->table_text_style_name);
        free (table->tablestyle_object_pointer);
        free (table->owning_block_pointer);
//        dxf_table_cells_free_list (table->cells);
        free (table);
        table = NULL;
#if DEBUG
        DXF_DEBUG_END
#endif
        return (EXIT_SUCCESS);
}


/*!
 * \brief Free the allocated memory for a single linked list of DXF
 * \c TABLE cells and all their data fields.
 */
void
dxf_table_cell_free_list
(
        DxfTableCell *cells
                /*!< pointer to the single linked list of DXF \c TABLE
                 * cells. */
)
{
#ifdef DEBUG
        DXF_DEBUG_BEGIN
#endif
        /* Do some basic checks. */
        if (cells == NULL)
        {
                fprintf (stderr,
                  (_("Warning in %s () a NULL pointer was passed.\n")),
                  __FUNCTION__);
        }
        while (cells != NULL)
        {
                DxfTableCell *iter = (DxfTableCell *) cells->next;
                dxf_table_cell_free (cells);
                cells = (DxfTableCell *) iter;
        }
#if DEBUG
        DXF_DEBUG_END
#endif
}


/*!
 * \brief Free the allocated memory for a single linked list of DXF
 * \c TABLE entities and all their data fields.
 */
void
dxf_table_free_list
(
        DxfTable *tables
                /*!< pointer to the single linked list of DXF
                 * \c TABLE entities. */
)
{
#ifdef DEBUG
        DXF_DEBUG_BEGIN
#endif
        /* Do some basic checks. */
        if (tables == NULL)
        {
                fprintf (stderr,
                  (_("Warning in %s () a NULL pointer was passed.\n")),
                  __FUNCTION__);
        }
        while (tables != NULL)
        {
                struct DxfTable *iter = tables->next;
                dxf_table_free (tables);
                tables = (DxfTable *) iter;
        }
#if DEBUG
        DXF_DEBUG_END
#endif
}


/* EOF */
