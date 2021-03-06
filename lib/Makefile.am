
AM_CPPFLAGS = -I$(top_srcdir)/include @BOOST_CPPFLAGS@

RUST_FILES = mp4/Cargo.lock \
	mp4/Cargo.toml \
	mp4/lib.rs \
	mp4/mp4parse_capi/src/lib.rs \
	mp4/mp4parse_capi/build.rs \
	mp4/mp4parse_capi/Cargo.toml \
	mp4/mp4parse/src/boxes.rs \
	mp4/mp4parse/src/lib.rs \
	mp4/mp4parse/src/tests.rs \
	mp4/mp4parse/src/craw.rs \
	mp4/mp4parse/Cargo.toml \
	$(NULL)

EXTRA_DIST = libopenraw.sym io/testfile.tmp \
	$(RUST_FILES)

pkgconfig_DATA = libopenraw-0.2.pc

TESTS = teststream

check_PROGRAMS = teststream

teststream_SOURCES = io/teststream.cpp
teststream_LDADD = libopenraw.la

noinst_HEADERS = \
	trace.hpp	\
	option.hpp \
	rawcontainer.hpp \
	ifdfile.hpp \
	tiffepfile.hpp \
	rawfilefactory.hpp \
	cr2file.hpp \
	cr3file.hpp \
	neffile.hpp \
	orffile.hpp \
	arwfile.hpp \
	dngfile.hpp \
	peffile.hpp \
	crwfile.hpp \
	erffile.hpp \
	mrwfile.hpp \
	rw2file.hpp \
	raffile.hpp \
	rawfile.hpp \
	bitmapdata.hpp \
	thumbnail.hpp \
	rawdata.hpp \
	cfapattern.hpp \
	metavalue.hpp \
	ifd.hpp \
	ifdfilecontainer.hpp \
	ifddir.hpp ifdentry.hpp \
	isomediacontainer.hpp \
	orfcontainer.hpp \
	rw2container.hpp \
	mrwcontainer.hpp \
	ciffcontainer.hpp \
	jfifcontainer.hpp \
	rafcontainer.hpp \
	rafmetacontainer.hpp \
	decompressor.hpp \
	ljpegdecompressor.hpp \
	ljpegdecompressor_priv.hpp \
	crwdecompressor.hpp \
	olympusdecompressor.hpp \
	canon.hpp \
	exception.hpp \
	endianutils.hpp \
	unpack.hpp \
	$(NULL)

lib_LTLIBRARIES = libopenraw.la

if DEBUG
CARGO_RELEASE_ARGS=
else
CARGO_RELEASE_ARGS=--release
endif

CARGO_TARGET_DIR=@abs_top_builddir@/lib/mp4/target
RUST_LIB=$(CARGO_TARGET_DIR)/@CARGO_TARGET_SUBDIR@/libmp4.a

$(RUST_LIB): $(RUST_FILES)
	cd $(srcdir)/mp4 && \
	CARGO_TARGET_DIR=$(CARGO_TARGET_DIR) cargo build $(CARGO_VERBOSE) $(CARGO_RELEASE_ARGS)

clean-local:
	cd $(srcdir)/mp4 && \
	CARGO_TARGET_DIR=$(CARGO_TARGET_DIR) cargo clean $(CARGO_VERBOSE) $(CARGO_RELEASE_ARGS)

libopenraw_la_LDFLAGS = \
	-version-info @LIBOPENRAW_VERSION_INFO@
libopenraw_la_LIBADD = -ljpeg $(RUST_LIB)
libopenraw_la_SOURCES = \
	io/io.c io/posix_io.h \
	io/posix_io.c io/posix_io.h \
	io/stream.cpp io/stream.hpp \
	io/streamclone.cpp io/streamclone.hpp \
	io/memstream.cpp io/memstream.hpp \
	io/file.cpp io/file.hpp \
	io/io_private.h \
	capi/capi.cpp \
	capi/debug.cpp \
	capi/rawdata.cpp \
	capi/rawfile.cpp \
	capi/bitmapdata.cpp \
	capi/cfapattern.cpp \
	capi/metadata.cpp \
	mp4/mp4parse.h \
	trace.cpp \
	bititerator.hpp \
	bititerator.cpp \
	cfapattern.cpp \
	xtranspattern.hpp \
	xtranspattern.cpp \
	huffman.hpp \
	huffman.cpp \
	nefdiffiterator.hpp \
	nefdiffiterator.cpp \
	nefcfaiterator.hpp \
	nefcfaiterator.cpp \
	rawfile_private.hpp \
	rawfile.cpp \
	ifdfile.cpp \
	tiffepfile.cpp \
	rawfilefactory.cpp \
	cr2file.cpp \
	cr3file.cpp \
	neffile.cpp \
	orffile.cpp \
	arwfile.cpp \
	dngfile.cpp \
	peffile.cpp \
	crwfile.cpp \
	erffile.cpp \
	mrwfile.cpp \
	rw2file.cpp \
	raffile.cpp \
	bitmapdata.cpp \
	thumbnail.cpp \
	rawdata.cpp \
	ifdfilecontainer.cpp \
	ifddir.cpp ifdentry.cpp \
	isomediacontainer.cpp \
	makernotedir.hpp makernotedir.cpp \
	rawcontainer.cpp \
	orfcontainer.cpp \
	rw2container.cpp \
	rafcontainer.cpp \
	rafmetacontainer.cpp \
	mrwcontainer.cpp \
	ciffcontainer.cpp \
	jfifcontainer.cpp \
	decompressor.cpp \
	ljpegdecompressor.cpp \
	crwdecompressor.cpp \
	olympusdecompressor.cpp \
	canon.cpp \
	metavalue.cpp \
	unpack.cpp \
	render/bimedian_demosaic.cpp render/bimedian_demosaic.hpp \
	render/grayscale.hpp render/grayscale.cpp
	$(NULL)
