/* -*- tab-width:4; c-basic-offset:4 -*- */
/*
 * libopenraw - rafcontainer.cpp
 *
 * Copyright (C) 2011 Hubert Figuiere
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef __OPENRAW_RAFMETACONTAINER_H__
#define __OPENRAW_RAFMETACONTAINER_H__

#include <tr1/memory>
#include <map>

#include "rawcontainer.h"
#include "metavalue.h"

namespace OpenRaw {

namespace IO {
class Stream;
}

namespace Internals {

enum {
	RAF_TAG_INVALID = 0,
	RAF_TAG_SENSOR_DIMENSION = 0x100,    // the RAW dimensions
	RAF_TAG_IMG_TOP_LEFT = 0x110,
	RAF_TAG_IMG_HEIGHT_WIDTH = 0x111,
	RAF_TAG_OUTPUT_HEIGHT_WIDTH = 0x121, // this is the one dcraw use for the active area
	RAF_TAG_RAW_INFO = 0x130,            // some info about the RAW.
	_RAF_TAG_LAST
};
	
class RafMetaValue
{
public:
	typedef std::tr1::shared_ptr<RafMetaValue> Ref;
	RafMetaValue(uint16_t tag, uint16_t size, const MetaValue & v);
	~RafMetaValue();
	
	const MetaValue & get() const
	{
		return m_value;
	}
private:
	uint16_t m_tag;
	uint16_t m_size;
	MetaValue m_value;
};
	
class RafMetaContainer
: public RawContainer
{
public:
	RafMetaContainer(IO::Stream *_file);
	
	uint32_t count();
	RafMetaValue::Ref getValue(uint16_t tag);
private:
	void _read();
	uint32_t m_count;
	std::map<uint16_t, RafMetaValue::Ref> m_tags;
};

}
}

#endif
