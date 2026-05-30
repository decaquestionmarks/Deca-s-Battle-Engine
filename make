

CXX = g++
CXXFLAGS = -std=c++17 -I./Tests -I./Types -I./Conditions
PYTHON ?= python

SRCS = Types/Type.cpp
DATA_CPPS := $(wildcard Types/Data/*.cpp)

# discover test sources (subdirectories and root Tests)
TEST_SRCS := $(wildcard Tests/*/*.cpp) $(wildcard Tests/*.cpp)

# map Tests/<suite>/<file>.cpp -> Tests/bin/<suite>
TEST_BINS := $(patsubst Tests/%/%.cpp,Tests/bin/%,$(TEST_SRCS))

.PHONY: test
test: $(TEST_BINS)
	@echo Running all tests...
	@for t in $(TEST_BINS); do \
		echo "== Running $$t =="; \
		"$$t" || exit $$?; \
	done

# build rule for Tests/bin/<suite> from Tests/<suite>/<file>.cpp
Tests/bin/%: Tests/%/%.cpp $(SRCS)
	@mkdir -p $(dir $@)
	$(MAKE) $(ALL_HEADER)
	$(CXX) $(CXXFLAGS) -o $@ $< $(SRCS)

# build rule for Tests/bin/<name> from Tests/<name>.cpp (flat tests)
Tests/bin/%: Tests/%.cpp $(SRCS)
	@mkdir -p $(dir $@)
	$(MAKE) $(ALL_HEADER)
	$(CXX) $(CXXFLAGS) -o $@ $< $(SRCS)

# generate consolidated All.hpp from Types/Data .cpp files
$(ALL_HEADER): $(DATA_CPPS) scripts/generate_all_hpp.py
	@echo "Generating Types/Data/All.hpp..."
	$(PYTHON) scripts/generate_all_hpp.py Types

