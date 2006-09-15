/*
 * libopenraw - thumbnails.h
 *
 * Copyright (C) 2005-2006 Hubert Figuiere
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
/**
 * @brief the libopenraw public API header for thumbnails
 * @author Hubert Figuiere <hub@figuiere.net>
 */


#ifndef __LIBOPENRAW_THUMBNAILS_H_
#define __LIBOPENRAW_THUMBNAILS_H_

#include <libopenraw/consts.h>

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct _Thumbnail *ORThumbnailRef;

	/** Extract thumbnail for raw file
	 *	@param filename the file name to extract from
	 *	@param preferred_size preferred thumnail size
	 *	@param thumb the thumbnail object ref to store it in
	 *	If the ref is NULL, then a new one is allocated. It is
	 *	the responsibility of the caller to release it.
	 *	@return error code
	 */
	or_error or_get_extract_thumbnail(const char* filename,
					 or_thumb_size preferred_size,
					 ORThumbnailRef *thumb);
	
	/** Allocate a thumbnail
	 */
	extern ORThumbnailRef 
	or_thumbnail_new(void);

	/** Release a thumbnail object
	 */
	extern or_error 
	or_thumbnail_release(ORThumbnailRef thumb);

	/** Return the thumbnail format
	 */
	extern or_data_type 
	or_thumbnail_format(ORThumbnailRef thumb);

	extern int
	or_thumbnail_size(ORThumbnailRef thumb);

	extern void *
	or_thumbnail_data(ORThumbnailRef thumb);

	extern size_t
	or_thumbnail_data_size(ORThumbnailRef thumb);


#ifdef __cplusplus
}
#endif


#endif
