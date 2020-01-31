# A simple example to demonstrate using ApprovalTests.cpp with the Conan package manager.

## Build

Build the example with the following commands:
```shell script
mkdir build
conan install . -if build
cd build
cmake ..
make
```

## Run
From the build directory, you can run the test by executing:
```shell script
bin/AT_demo
```

## Results
The test passes because the expected output is stored in `hello.HelloApproval.approved.txt`

You can delete or edit this file to cause a failure.
For example, if I delete the "approved" file, on the next run I get:
```shell script
$ bin/AT_demo 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AT_demo is a Catch v2.11.0 host application.
Run with -? for options

-------------------------------------------------------------------------------
HelloApproval
-------------------------------------------------------------------------------
/home/dheater/src/AT-demo/hello.cpp:4
...............................................................................

/home/dheater/src/AT-demo/hello.cpp:4: FAILED:
due to unexpected exception with message:
  Failed Approval: 
  Approval File Not Found 
  File: "/home/dheater/src/AT-demo/hello.HelloApproval.approved.txt"

===============================================================================
test cases: 1 | 1 failed
assertions: 1 | 1 failed
```

If I copy the contents of `hello.HelloApproval.approved.txt` to `hello.HelloApproval.approved.txt` and run again, the test will pass

```shell script
$ ./build/bin/AT_demo 
===============================================================================
test cases: 1 | 1 passed
assertions: - none -
```

## WTF?
Read the documentation at [ApprovalTests.cpp](https://github.com/approvals/ApprovalTests.cpp)
