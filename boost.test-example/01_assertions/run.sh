
make
# shows warning message (otherwise silenced)
./test --log_level=all
# other ways of running
# ./test --log_level=test_suites
# ./test --log_level=all --report_format=XML --report_level=detailed
# To run all test cases in the suite named "MyTest" (with more detailed report), use: --log_level=test_suite --run_test=SQLiteDatabaseTest/*.