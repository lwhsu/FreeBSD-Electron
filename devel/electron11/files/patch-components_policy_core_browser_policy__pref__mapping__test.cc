--- components/policy/core/browser/policy_pref_mapping_test.cc.orig	2021-01-07 00:36:30 UTC
+++ components/policy/core/browser/policy_pref_mapping_test.cc
@@ -270,6 +270,8 @@ class PolicyTestCase {
     const std::string os("chromeos");
 #elif defined(OS_LINUX)
     const std::string os("linux");
+#elif defined(OS_FREEBSD)
+    const std::string os("freebsd");
 #else
 #error "Unknown platform"
 #endif
