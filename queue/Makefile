# Group 4
# Sam Millikan <smillikan@scu.edu>
# Ameen Ahmed <aahmed5@scu.edu>
# Samuel Reiter <sreiter@scu.edu>
# Isaac Amedie <iamedie@scu.edu>

CXX=c++
OPT=-g
STD=-std=c++20
CXXFLAGS=$(OPT) $(STD)

%.o:	%.cxx
	$(CXX) -c $(CXXFLAGS) $<

SRCS=bag.cxx bagtest.cxx
OBJS=$(SRCS:.cxx=.o)

all: bag

bag:	$(OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $+

clean:
	/bin/rm bag $(OBJS)
	/bin/rm -rf $(ALL:=.dSYM)

depend: $(SRCS)
	TMP=`mktemp -p .`; export TMP; \
	sed -e '/^# DEPENDENTS/,$$d' Makefile > $$TMP; \
	echo '# DEPENDENTS' >> $$TMP; \
	$(CXX) -MM $+ >> $$TMP; \
	/bin/mv -f $$TMP Makefile

# DEPENDENTS
bag.o: bag.cxx bag.h
bagtest.o: bagtest.cxx bag.h
