/*!
 * \file tables.c
 *
 * \author Copyright (C) 2014 by Bert Timmerman <bert.timmerman@xs4all.nl>.
 *
 * \brief Functions for a DXF tables section (\c TABLES).
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


#include "tables.h"
#include "section.h"


/*!
 * \brief Allocate memory for a DXF \c TABLES section.
 *
 * Fill the memory contents with zeros.
 *
 * \return \c NULL when no memory was allocated, a pointer to the
 * allocated memory when succesful.
 */
DxfTables *
dxf_tables_new ()
{
#if DEBUG
        DXF_DEBUG_BEGIN
#endif
        DxfTables *dxf_tables = NULL;
        size_t size;

        size = sizeof (DxfTables);
        /* avoid malloc of 0 bytes */
        if (size == 0) size = 1;
        if ((dxf_tables = malloc (size)) == NULL)
        {
                fprintf (stderr,
                  (_("Error in %s () could not allocate memory for a DxfTables struct.\n")),
                  __FUNCTION__);
                dxf_tables = NULL;
        }
        else
        {
                memset (dxf_tables, 0, size);
        }
#if DEBUG
        DXF_DEBUG_END
#endif
        return (dxf_tables);
}


/*!
 * \brief Allocate memory and initialize data fields in a DXF \c TABLES
 * section.
 * 
 * \return \c NULL when no memory was allocated, a pointer to the
 * allocated memory when succesful.
 */
DxfTables *
dxf_tables_init
(
        DxfTables *dxf_tables
                /*!< DXF tables section. */
)
{
#if DEBUG
        DXF_DEBUG_BEGIN
#endif
        /* Do some basic checks. */
        if (dxf_tables == NULL)
        {
                fprintf (stderr,
                  (_("Warning in %s () a NULL pointer was passed.\n")),
                  __FUNCTION__);
                dxf_tables = dxf_tables_new ();
        }
        if (dxf_tables == NULL)
        {
                fprintf (stderr,
                  (_("Error in %s () could not allocate memory for a DxfTables struct.\n")),
                  __FUNCTION__);
                return (NULL);
        }
        dxf_tables->appids = NULL;
        //dxf_table->block_records = NULL;
        dxf_tables->dimstyles = NULL;
        dxf_tables->layers = NULL;
        dxf_tables->ltypes = NULL;
        dxf_tables->styles = NULL;
        dxf_tables->ucss = NULL;
        dxf_tables->views = NULL;
        dxf_tables->vports = NULL;
#if DEBUG
        DXF_DEBUG_END
#endif
        return (dxf_tables);
}


/*!
 * \brief Write DXF output to a file for a table section.
 * 
 * \return \c EXIT_SUCCESS when done, or \c EXIT_FAILURE when an error
 * occurred.
 */
int
dxf_tables_write
(
        DxfFile *fp,
                /*!< DXF file pointer to an output file (or device). */
        DxfTables *dxf_tables
                /*!< DXF table section. */
)
{
#if DEBUG
        DXF_DEBUG_BEGIN
#endif
        char *dxf_section_name = strdup ("TABLES");

        dxf_section_write (fp, dxf_section_name);
        /*! \todo Add code here */
        dxf_section_write_endsection (fp);
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
dxf_tables_free
(
        DxfTables *dxf_tables
                /*!< DXF table section. */
)
{
#if DEBUG
        DXF_DEBUG_BEGIN
#endif
        if (dxf_tables == NULL)
        {
                fprintf (stderr,
                  (_("Error in %s () a NULL pointer was passed.\n")),
                  __FUNCTION__);
                return (EXIT_FAILURE);
        }
        free (dxf_tables->appids);
        //free (dxf_tables->block_records);
        free (dxf_tables->dimstyles);
        free (dxf_tables->layers);
        free (dxf_tables->ltypes);
        free (dxf_tables->styles);
        free (dxf_tables->ucss);
        free (dxf_tables->views);
        free (dxf_tables->vports);
        dxf_tables = NULL;
#if DEBUG
        DXF_DEBUG_END
#endif
        return (EXIT_SUCCESS);
}


/* EOF */
