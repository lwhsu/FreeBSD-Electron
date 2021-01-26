--- printing/printing_features.h.orig	2021-01-07 00:36:39 UTC
+++ printing/printing_features.h
@@ -37,10 +37,10 @@ PRINTING_EXPORT bool IsXpsPrintCapabilityRequired();
 PRINTING_EXPORT bool ShouldPrintUsingXps(bool source_is_pdf);
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 PRINTING_EXPORT extern const base::Feature kEnableOopPrintDrivers;
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 }  // namespace features
