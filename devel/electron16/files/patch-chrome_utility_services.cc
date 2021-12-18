--- chrome/utility/services.cc.orig	2021-11-19 04:25:12 UTC
+++ chrome/utility/services.cc
@@ -64,7 +64,7 @@
 #include "chrome/services/file_util/file_util_service.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (defined(OS_LINUX) || defined(OS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD))
 #include "chrome/services/file_util/document_analysis_service.h"  // nogncheck
 #endif
 
@@ -211,7 +211,7 @@ auto RunCupsIppParser(
 }
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (defined(OS_LINUX) || defined(OS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD))
 auto RunDocumentAnalysis(
     mojo::PendingReceiver<chrome::mojom::DocumentAnalysisService> receiver) {
   return std::make_unique<DocumentAnalysisService>(std::move(receiver));
@@ -375,7 +375,7 @@ void RegisterMainThreadServices(mojo::ServiceFactory& 
   services.Add(RunFileUtil);
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (defined(OS_LINUX) || defined(OS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD))
   services.Add(RunDocumentAnalysis);
 #endif
 
