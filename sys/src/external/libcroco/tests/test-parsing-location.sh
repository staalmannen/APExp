#!/bin/sh

. global-test-vars.sh

$CSSLINT --dump-location $TEST_INPUTS_DIR/parsing-location.css
