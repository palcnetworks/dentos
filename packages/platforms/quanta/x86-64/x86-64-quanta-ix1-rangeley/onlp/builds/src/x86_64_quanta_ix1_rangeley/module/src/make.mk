###############################################################################
#
#
#
###############################################################################

LIBRARY := x86_64_quanta_ix1_rangeley
$(LIBRARY)_SUBDIR := $(dir $(lastword $(MAKEFILE_LIST)))
include $(BUILDER)/lib.mk