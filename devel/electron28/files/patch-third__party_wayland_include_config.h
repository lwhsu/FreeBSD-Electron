--- third_party/wayland/include/config.h.orig	2023-12-13 00:27:58 UTC
+++ third_party/wayland/include/config.h
@@ -25,7 +25,11 @@
 
 #undef HAVE_SYS_PROCCTL_H
 
+#if defined(__FreeBSD__)
+#define HAVE_SYS_UCRED_H
+#else
 #undef HAVE_SYS_UCRED_H
+#endif
 
 #define HAVE_XUCRED_CR_PID 0
 
