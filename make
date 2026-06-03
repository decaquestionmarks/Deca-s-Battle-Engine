

CXX = g++
CATCH_INC ?= C:/Users/natey/C++ projects/catchorg-Catch2-31b1109

# prefer workspace-local Catch2 if present (common layouts)
# Prefer `.../src` (sources) or `.../single_include` (single-header) directories.
LOCAL_CATCH_SRC := $(firstword $(wildcard catchorg-Catch2-*/src))
LOCAL_CATCH_SINGLE := $(firstword $(wildcard catchorg-Catch2-*/single_include))
LOCAL_CATCH_DIR := $(firstword $(wildcard catchorg-Catch2-*))
ifneq ($(LOCAL_CATCH_SRC),)
CATCH_INC := $(LOCAL_CATCH_SRC)
else ifneq ($(LOCAL_CATCH_SINGLE),)
CATCH_INC := $(LOCAL_CATCH_SINGLE)
else ifneq ($(LOCAL_CATCH_DIR),)
CATCH_INC := $(LOCAL_CATCH_DIR)
endif
CXXFLAGS = -std=c++17 -I./Tests -I./Types -I./Conditions

ifneq ($(CATCH_INC),)
CXXFLAGS += -I"$(CATCH_INC)"
endif
PYTHON ?= python

SRCS = Types/Type.cpp
DATA_CPPS := $(wildcard Types/Data/*.cpp)
# If Catch2 source tree is vendored, compile its implementation units so tests link.
# Collect all .cpp files under the vendored Catch2 `src/catch2` tree recursively.
CATCH_SRCS := $(shell find catchorg-Catch2-* -type f -name '*.cpp' -path '*/src/catch2/*' ! -name 'catch_main.cpp' 2>/dev/null)

# discover test sources (subdirectories and root Tests)
# Exclude Tests/main.cpp to avoid building it as a standalone test binary
TEST_SRCS := $(wildcard Tests/*/*.cpp) $(filter-out Tests/main.cpp,$(wildcard Tests/*.cpp))

# map Tests/<suite>/<file>.cpp -> Tests/bin/<suite>
# and flat Tests/<name>.cpp -> Tests/bin/<name>
TEST_BINS := $(patsubst Tests/%/%.cpp,Tests/bin/%,$(wildcard Tests/*/*.cpp)) \
			$(patsubst Tests/%.cpp,Tests/bin/%,$(filter-out Tests/main.cpp,$(wildcard Tests/*.cpp)))

.PHONY: test
test: $(TEST_BINS)
	@echo Running all tests...
	@for t in $(TEST_BINS); do \
		echo "== Running $$t =="; \
		./scripts/run_win_cmd.sh "$$t" || exit $$?; \
	done

# build rule for Tests/bin/<name>
# This rule chooses between `Tests/<suite>/<name>.cpp` and `Tests/<name>.cpp`
# at recipe time so `make` always has a rule it can use for `Tests/bin/%` targets.
Tests/bin/%:
	@mkdir -p $(dir $@)
	$(MAKE) ALL_HEADER
	@src=""; \
	if [ -f "Tests/$*/$*.cpp" ]; then src="Tests/$*/$*.cpp"; \
	elif [ -f "Tests/$*.cpp" ]; then src="Tests/$*.cpp"; \
	else echo "No test source for $@"; exit 1; fi; \
	$(CXX) $(CXXFLAGS) -o $@ $$src $(SRCS) $(wildcard Tests/main.cpp) $(CATCH_SRCS)

# generate consolidated All.hpp from Types/Data .cpp files
ALL_HEADER: $(DATA_CPPS) scripts/generate_all_hpp.py
	@echo "Generating Types/Data/All.hpp..."
	$(PYTHON) scripts/generate_all_hpp.py Types

print-vars:
	@echo TEST_SRCS=$(TEST_SRCS)
	@echo TEST_BINS=$(TEST_BINS)