--- v8/src/base/cpu.cc.orig	2021-09-14 01:58:38 UTC
+++ v8/src/base/cpu.cc
@@ -568,6 +568,7 @@ CPU::CPU()
 
 #if V8_OS_LINUX
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -601,6 +602,7 @@ CPU::CPU()
     }
     delete[] part;
   }
+#endif
 
   // Extract architecture from the "CPU Architecture" field.
   // The list is well-known, unlike the the output of
