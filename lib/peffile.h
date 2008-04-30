/*
 * libopenraw - peffile.h
 *
 * Copyright (C) 2006-2007 Hubert Figuiere
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




#ifndef __PEFFILE_H_
#define __PEFFILE_H_

#include "ifdfile.h"

namespace OpenRaw {

	class Thumbnail;

	namespace Internals {
		class IOFile;
		class IFDFileContainer;

		class PEFFile
			: public IFDFile
		{
		public:
			static RawFile *factory(const char* _filename);
			PEFFile(const char* _filename);
			virtual ~PEFFile();

		protected:
			virtual IFDDir::Ref  _locateCfaIfd();
			virtual IFDDir::Ref  _locateMainIfd();
		protected:
			virtual ::or_error _getRawData(RawData & data, uint32_t options);

		private:

			PEFFile(const PEFFile&);
			PEFFile & operator=(const PEFFile &);

		};
	}

}

#endif
