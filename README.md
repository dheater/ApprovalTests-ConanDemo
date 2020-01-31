# A simple example to demonstrate using ApprovalTests.cpp with the Conan package manager.

## Build

Build the example with the following commands:
```shell script
mkdir build
cd build
conan install ..
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

## Using different unit test frameworks
ApprovalTests.cpp also supports other test frameworks
To install another unit test framework using this Conan recipe, change the option in `conanfile.txt`. For example, to switch from Catch2 to Google Test:

```yaml
[options]
approvaltests.cpp:with_gtest=True
```

Of course you will have to modify the test code now to use Google Test instead of Catch2. I'll leave that as an exercise for the reader.

If you do not specify a test framework option, then none will be installed by this recipe. You will have to satisfy ApprovalTests.cpp's dependency on a unit test framework by some other means. For example, I could choose to use a Catch2 Conan package, but a different version than the ApprovalTests.cpp Conan recipe provides by making it an explicit requirement in my `conanfile.txt` file like so:

```yaml
[requires]
approvaltests.cpp/8.1.0
Catch2/2.11.1@catchorg/stable
```

I could also use a supported test framework for which there is no Conan package or without using a Conan package. I would just have to install it by other means.

## Learn More
[Conan](https://docs.conan.io/en/latest/)

[ApprovalTests.cpp](https://github.com/approvals/ApprovalTests.cpp)

