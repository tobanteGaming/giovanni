.PHONY: default
default: config build test

CONFIG ?= Debug
BUILD_DIR_BASE ?= build
BUILD_DIR = $(BUILD_DIR_BASE)_$(CONFIG)

.PHONY: config
config:
	cmake -S. -GNinja -B$(BUILD_DIR) -DCMAKE_BUILD_TYPE=$(CONFIG)

.PHONY: build
build:
	cmake --build $(BUILD_DIR) --config $(CONFIG)

.PHONY: test
test:
	cd $(BUILD_DIR) && ctest

.PHONY: coverage
coverage:
	cmake -S. -G"Unix Makefiles" $(CMAKE_FLAGS) -B $(BUILD_DIR_BASE)_coverage -DGIO_BUILD_COVERAGE=ON
	cd $(BUILD_DIR_BASE)_coverage && make -j3
	cd $(BUILD_DIR_BASE)_coverage && lcov -c -i -d . --base-directory . -o base_cov.info
	cd $(BUILD_DIR_BASE)_coverage && ctest
	cd $(BUILD_DIR_BASE)_coverage && lcov -c -d . --base-directory . -o test_cov.info
	cd $(BUILD_DIR_BASE)_coverage && lcov -a base_cov.info -a test_cov.info -o cov.info
	cd $(BUILD_DIR_BASE)_coverage && lcov --remove cov.info "*3rd_party/*" -o cov.info
	cd $(BUILD_DIR_BASE)_coverage && lcov --remove cov.info "*c++*" -o cov.info
	cd $(BUILD_DIR_BASE)_coverage && lcov --remove cov.info "*v1*" -o cov.info
	cd $(BUILD_DIR_BASE)_coverage && lcov --remove cov.info "*Xcode.app*" -o cov.info

.PHONY: report
report:
	cd $(BUILD_DIR_BASE)_coverage && genhtml cov.info --output-directory lcov

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: stats
stats:
	cloc giovanni

.PHONY: format
format:
	find giovanni -iname '*.h' -o -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
