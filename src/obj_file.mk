#######################################################################
#         functions for converting source file to object file         #
#######################################################################

# When creating object file names we replace `..` with this value
REL_DIR_SUBST ?= D..

# This function takes a source file path and converts it to a build file path.
#
# For example:
# source_file: ../../src/test.c
# obj_file: $(OBJ_DIR)/D../D...src/test.c.o
#
# $1: source file to manipulate
# $2: object file extension to be appended
define obj_file_name
$(OBJ_DIR)/$(strip $(subst ..,$(REL_DIR_SUBST),$(1).$(2)))
endef

# Apply `obj_file_name` to a list of source files
# $1: list of source files
# $2: object file extension
define obj_file_list
$(foreach src_file, $(1), $(call obj_file_name, $(src_file),$(2)))
endef

# This function provides a build rule for a source file.
#
# $1: source file to manipulate
# $2: recipe code
# $3: obj file extension
define define_compile_rule
$(call obj_file_name,$(1),$(3)): $(1)
	@mkdir -p $$(dir $$@)
$(call $(2))
endef

# $1: src file list
# $2: recipe function
# $3: obj file extension
define create_recipes
$(foreach src_file, $(1), \
	$(eval $(call define_compile_rule,$(src_file),$(2),$(3)) ) \
)
endef
