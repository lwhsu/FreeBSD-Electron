--- third_party/blink/public/common/renderer_preferences/renderer_preferences.h.orig	2024-02-21 00:20:53 UTC
+++ third_party/blink/public/common/renderer_preferences/renderer_preferences.h
@@ -63,7 +63,7 @@ struct BLINK_COMMON_EXPORT RendererPreferences {
   UserAgentOverride user_agent_override;
   std::string accept_languages;
   bool send_subresource_notification{false};
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::string system_font_family_name;
 #endif
 #if BUILDFLAG(IS_WIN)
