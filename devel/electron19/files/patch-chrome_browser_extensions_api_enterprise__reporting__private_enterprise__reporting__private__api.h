--- chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.h.orig	2022-05-19 05:17:37 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.h
@@ -45,7 +45,7 @@ class EnterpriseReportingPrivateGetDeviceIdFunction : 
   ~EnterpriseReportingPrivateGetDeviceIdFunction() override;
 };
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 
 class EnterpriseReportingPrivateGetPersistentSecretFunction
     : public ExtensionFunction {
