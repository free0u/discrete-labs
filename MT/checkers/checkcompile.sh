#!/bin/bash
rm -rf __tmp
mkdir __tmp
cp testlib4j.jar __tmp
javac -classpath "__tmp/testlib4j.jar" -sourcepath . -d __tmp Check.java
pushd __tmp
jar xf testlib4j.jar
echo Main-Class: ru.ifmo.testlib.CheckerFramework> META-INF/manifest.1
echo Checker-Class: Check>> META-INF/manifest.1
rm testlib4j.jar
jar cfm Check.jar META-INF/manifest.1 *.class ru
cp Check.jar .. > nul
popd
rm -rf __tmp
