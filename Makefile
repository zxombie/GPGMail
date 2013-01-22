PROJECT = GPGMail
TARGET = GPGMail
PRODUCT = GPGMail.mailbundle

include Dependencies/GPGTools_Core/newBuildSystem/Makefile.default


$(PRODUCT): Source/* Resources/* Resources/*/* GPGMail.xcodeproj
	@xcodebuild -project $(PROJECT).xcodeproj -target $(TARGET) -configuration $(CONFIG) build $(XCCONFIG)


# TODO: Check the following targets!

check-all-warnings: clean
	make | grep "warning: "

check-warnings: clean
	make | grep "warning: "|grep -v "#warning"

check: clean
	@if [ "`which scan-build`" == "" ]; then echo 'usage: PATH=$$PATH:path_to_scan_build make check'; echo "see: http://clang-analyzer.llvm.org/"; exit; fi
	@echo "";
	@echo "Have a closer look at these warnings:";
	@echo "=====================================";
	@echo "";
	@scan-build -analyzer-check-objc-missing-dealloc \
	            -analyzer-check-dead-stores \
	            -analyzer-check-idempotent-operations \
	            -analyzer-check-llvm-conventions \
	            -analyzer-check-objc-mem \
	            -analyzer-check-objc-methodsigs \
	            -analyzer-check-objc-missing-dealloc \
	            -analyzer-check-objc-unused-ivars \
	            -analyzer-check-security-syntactic \
	            --use-cc clang -o build/report xcodebuild \
	            -project GPGMail.xcodeproj -target GPGMail \
	            -configuration Release build 2>error.log|grep "is deprecated"
	@echo "";
	@echo "Now have a look at build/report/ or at error.log";

style:
	@if [ "`which uncrustify`" == "" ]; then echo 'usage: PATH=$$PATH:path_to_uncrustify make style'; echo "see: https://github.com/bengardner/uncrustify"; exit; fi
	uncrustify -c Utilities/uncrustify.cfg --no-backup Source/*.h
	uncrustify -c Utilities/uncrustify.cfg --no-backup Source/*.m
	uncrustify -c Utilities/uncrustify.cfg --no-backup Source/PrivateHeaders/*
	uncrustify -c Utilities/uncrustify.cfg --no-backup Source/GPG.subproj/*

