--- chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.cc.orig	2023-08-10 01:48:35 UTC
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.cc
@@ -23,7 +23,7 @@
 #include "components/policy/core/common/management/management_service.h"
 #include "content/public/browser/browser_context.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/enterprise/connectors/device_trust/attestation/browser/browser_attestation_service.h"
 #include "chrome/browser/enterprise/connectors/device_trust/attestation/browser/device_attester.h"
@@ -55,7 +55,7 @@ bool IsProfileManaged(Profile* profile) {
   return management_service && management_service->IsManaged();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 policy::CloudPolicyStore* GetUserCloudPolicyStore(Profile* profile) {
   policy::CloudPolicyManager* user_policy_manager =
       profile->GetUserCloudPolicyManager();
@@ -105,7 +105,7 @@ DeviceTrustServiceFactory::DeviceTrustServiceFactory()
   DependsOn(DeviceTrustConnectorServiceFactory::GetInstance());
   DependsOn(policy::ManagementServiceFactory::GetInstance());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Depends on this service via the SignalsService having a dependency on it.
   DependsOn(enterprise_signals::SignalsAggregatorFactory::GetInstance());
   // Depends on this service via the ProfileAttester having a dependency on it
