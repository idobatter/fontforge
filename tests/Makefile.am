# Copyright (C) 2000-2012 by George Williams
# Copyright (C) 2012 by Barry Schwartz
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# Redistributions of source code must retain the above copyright notice, this
# list of conditions and the following disclaimer.
#
# Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation
# and/or other materials provided with the distribution.
#
# The name of the author may not be used to endorse or promote products
# derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
# EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
# OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
# OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
# ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

# The `:;' works around a Bash 3.2 bug when the output is not writable.
$(srcdir)/package.m4: $(top_srcdir)/configure.ac
	:;{ \
		echo '# Signature of the current package.' && \
		echo 'm4_define([AT_PACKAGE_NAME],' && \
		echo '  [$(PACKAGE_NAME)])' && \
		echo 'm4_define([AT_PACKAGE_TARNAME],' && \
		echo '  [$(PACKAGE_TARNAME)])' && \
		echo 'm4_define([AT_PACKAGE_VERSION],' && \
		echo '  [$(PACKAGE_VERSION)])' && \
		echo 'm4_define([AT_PACKAGE_STRING],' && \
		echo '  [$(PACKAGE_STRING)])' && \
		echo 'm4_define([AT_PACKAGE_BUGREPORT],' && \
		echo '  [$(PACKAGE_BUGREPORT)])'; \
		echo 'm4_define([AT_PACKAGE_URL],' && \
		echo '  [$(PACKAGE_URL)])'; \
	} >'$(srcdir)/package.m4'

noinst_FILES = * fonts/* results/* results

EXTRA_DIST = testsuite.at $(srcdir)/package.m4 $(TESTSUITE) atlocal.in
TESTSUITE = $(builddir)/testsuite

FONTFORGE = $(top_builddir)/fontforgeexe/fontforge

check-local: $(builddir)/fonts atconfig atlocal $(TESTSUITE) $(FONTFORGE)
	$(MKDIR_P) $(builddir)/results
	$(SHELL) '$(TESTSUITE)' $(TESTSUITEFLAGS)

installcheck-local: atconfig atlocal $(TESTSUITE)
	$(MKDIR_P) $(builddir)/results
	$(SHELL) '$(TESTSUITE)' AUTOTEST_PATH='$(bindir)' $(TESTSUITEFLAGS)

clean-local:
	test ! -f '$(TESTSUITE)' || $(SHELL) '$(abs_builddir)/testsuite' --clean
	rm -fR $(builddir)/results/*

AUTOM4TE = $(SHELL) $(srcdir)/build-aux/missing --run autom4te
AUTOTEST = $(AUTOM4TE) --language=autotest
$(TESTSUITE): $(srcdir)/testsuite.at $(srcdir)/package.m4 $(GENERATED_INPUTS)
	$(AUTOTEST) -I '$(srcdir)' -o $@.tmp $@.at
	mv $@.tmp $@

# test fonts
EXTRA_DIST += fonts/AddExtremaTest2.sfd fonts/AddExtremumTest.sfd	\
	fonts/AHBugs.sfd fonts/Ambrosia.sfd fonts/AmbrosiaBold.sfd	\
	fonts/AmbrosiaItalic.sfd fonts/ayn+meem.init.svg		\
	fonts/Caliban.sfd fonts/CaslonMM.sfd fonts/DataURI.sfd		\
	fonts/DejaVuSerif.sfd fonts/DirectionTest.sfd			\
	fonts/dvng10a-crash.sfd fonts/feta20.pfb fonts/FormalScript.sfd	\
	fonts/Hinting.sfd fonts/ItalicHand.sfd				\
	fonts/NimbusLGCUni-Regular.sfd fonts/NumberPoints.sfd		\
	fonts/OmittedCharBugs.sfd fonts/OverlapBugs.sfd			\
	fonts/QuadOverlapBugs.sfd fonts/QuadraticConversionBug.sfd	\
	fonts/SimplifyBugs.sfd fonts/SplineOverlapBug1.sfd		\
	fonts/StrokeTests.sfd fonts/VKern.sfd README

# generated test inputs
GENERATED_INPUTS =							\
	fonts/MunhwaGothic-Bold						\
	fonts/mingliu.ttc						\
	fonts/Ambrosia.pt3

MAYBE_GENERATED_INPUTS =						\
	fonts/MinionPro-Regular.fea

# Inputs we can generate from files in git
fonts/Ambrosia.pt3: fonts/Ambrosia.sfd
	$(MKDIR_P) $(builddir)/fonts
	$(FONTFORGE) -c 'open(argv[1]).generate(argv[2])' $< $@

# Inputs we can download
fonts/MunhwaGothic-Bold:
	$(MKDIR_P) $(builddir)/fonts
	$(WGET) ftp://ftp.naist.jp/pub/NetBSD/packages/distfiles/adobe-cidfonts/MunhwaGothic-Bold -O $@

fonts/mingliu.ttc:
	$(MKDIR_P) $(builddir)/fonts
	$(WGET) http://www.fontsupply.com/fonts/mingliu.ttc -O $@

# Inputs we can generate from files that aren't available
fonts/MinionPro-Regular.fea: fonts/MinionPro-Regular.otf
	$(MKDIR_P) $(builddir)/fonts
	$(FONTFORGE) -c 'open(argv[1]).generateFeatureFile(argv[2])' $< $@

# native test scripts
EXTRA_DIST += helper107.pe helper118A.pe helper118B.pe		\
	svg2ttf.pe test001.pe test002.pe test003.pe		\
	test004.pe test005.pe test006.pe test007.pe		\
	test008.pe test009.pe test010.pe test101.pe		\
	test102.pe test103.pe test104.pe test105.pe		\
	test106.pe test107.pe test108.pe test109.pe		\
	test110.pe test111.pe test112.pe test113.pe		\
	test114.pe test115.pe test116.pe test117.pe		\
	test118.pe test119.pe test120.pe test121.pe		\
	test122.pe test123.pe test124.pe test125.pe		\
	test126.pe test127.pe

# python test scripts
EXTRA_DIST += findoverlapbugs.py test0001.py test0101.py	\
	test1001.py test1001a.py test1001b.py test1001c.py	\
	test1002.py test1003.py test1004.py test1005.py		\
	test1006.py test1007.py

EXTRA_DIST += link_test.c randomtest.c build-aux/missing

DISTCLEANFILES = atconfig randomtest $(GENERATED_INPUTS) fonts/*.afm $(TESTSUITE)

MAINTAINERCLEANFILES = package.m4 testsuite.dir testsuite.log results

GITIGNOREFILES = $(MAYBE_GENERATED_INPUTS)			\
	fonts/Zapfino-4.0d3.dfont				\
	fonts/Zapfino-4.1d6.dfont				\
	fonts/HanSans-Bold.otf					\
	fonts/GillSans.dfont					\
	fonts/CourierNew.ttf					\
	fonts/merged.cff					\
	fonts/MinionPro-Regular.otf				\
	fonts/LucidaGrande.ttc					\
	fonts/nuvo-medium-woff-demo.woff

-include $(top_srcdir)/git.mk
