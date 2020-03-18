.PHONY: default
default: config build test

CONFIG ?= Debug
BUILD_DIR ?= build

.PHONY: config
config:
	cmake -S. -GNinja -B$(BUILD_DIR)

.PHONY: build
build:
	cmake --build $(BUILD_DIR)

.PHONY: test
test:
	cd $(BUILD_DIR) && ctest

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
